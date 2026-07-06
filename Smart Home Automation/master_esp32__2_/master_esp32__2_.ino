#include <Wire.h>
#include <U8g2lib.h>
#include <PZEM004Tv30.h>
#include <DHT.h>

// ================= OLED =================
U8G2_SH1106_128X64_NONAME_F_HW_I2C u8g2(
  U8G2_R0,
  U8X8_PIN_NONE
);

// ================= PZEM on its own UART =================
// ESP32 UART2 default pins are 16(RX2)/17(TX2) -- we need those FREE
// for the SuperSlave link, so PZEM is moved to UART1 on pins 26/27.
// PZEM TX -> ESP32 GPIO26 (RX1)
// PZEM RX -> ESP32 GPIO27 (TX1)
HardwareSerial pzemSerial(1);                     // UART1
PZEM004Tv30 pzem(&pzemSerial, 26, 27);            // RX=26, TX=27

// ================= SuperSlave link on UART2 =================
// ESP32 GPIO17 (TX2) -> ESP8266 D5 (GPIO14, SoftwareSerial RX)
// ESP32 GPIO16 (RX2) <- ESP8266 D6 (GPIO12, SoftwareSerial TX)
HardwareSerial ssSerial(2);                       // UART2
#define SS_BAUD 9600
#define SS_TIMEOUT_MS 5000   // if no message for this long, link considered down

// ================= PINS =================
#define BUZZER_PIN  5
#define LED1_PIN    19
#define LED2_PIN    18

#define LDR_PIN     34
#define ZMPT1_PIN   32
#define ZMPT2_PIN   35

#define DHT_PIN     4        // moved off GPIO16 (now UART2 RX)
#define RELAY1_PIN  13
#define RELAY2_PIN  14

#define DHTTYPE DHT11
DHT dht(DHT_PIN, DHTTYPE);

// ================= SETTINGS =================
float ZMPT_CAL = 0.403;
float NOISE_THRESHOLD = 8;

#define BUZZER_ON  LOW
#define BUZZER_OFF HIGH

// ================= OFFSETS =================
float offset1 = 0;
float offset2 = 0;

// ================= SLAVE DATA (from SuperSlave via UART2) =================
struct SlaveInfo {
  bool online  = false;
  bool r1      = false;
  bool r2      = false;
  float cur    = 0.0;
};
SlaveInfo slaveData[3];   // index 1 and 2 used

bool ssLinkUp = false;
unsigned long lastSSMsg = 0;
String ssBuffer = "";

// OLED page: 0 = local PZEM/ZMPT/DHT, 1 = slave status
uint8_t oledPage = 0;
unsigned long lastPageSwitch = 0;
#define PAGE_SWITCH_MS 3000   // flip OLED page every 3 seconds

// ================= OFFSET CALIBRATION =================
void calibrateOffset(int pin, float &offset) {
  long sum = 0;
  for (int i = 0; i < 800; i++) {
    sum += analogRead(pin);
    delay(2);
  }
  offset = sum / 800.0;
}

// ================= ZMPT RMS =================
float readZMPT(int pin, float offset) {
  float sumSq = 0;
  for (int i = 0; i < 800; i++) {
    int raw = analogRead(pin);
    float centered = raw - offset;
    sumSq += centered * centered;
    delayMicroseconds(200);
  }
  float rms = sqrt(sumSq / 800.0);
  if (rms < NOISE_THRESHOLD) return 0;
  return rms * ZMPT_CAL;
}

// ================= BUZZER =================
void handleBuzzer(float z1, float z2) {
  static unsigned long lastBeep = 0;
  unsigned long now = millis();

  bool low = (z1 < 200 && z2 < 200);
  bool ok  = (z1 >= 200 || z2 >= 200);

  digitalWrite(BUZZER_PIN, BUZZER_OFF);

  if (low) {
    if (now - lastBeep > 900) {
      digitalWrite(BUZZER_PIN, BUZZER_ON);
      delay(60);
      digitalWrite(BUZZER_PIN, BUZZER_OFF);
      lastBeep = now;
    }
  } else if (ok) {
    if (now - lastBeep > 1500) {
      digitalWrite(BUZZER_PIN, BUZZER_ON);
      delay(25);
      digitalWrite(BUZZER_PIN, BUZZER_OFF);
      lastBeep = now;
    }
  }
}

// ================= PARSE SUPER SLAVE JSON =================
// Expected line: {"s1":{"online":1,"r1":0,"r2":1,"cur":1.23},"s2":{"online":0,"r1":0,"r2":0,"cur":0.00}}

int extractInt(const String &json, const String &key) {
  int idx = json.indexOf("\"" + key + "\":");
  if (idx < 0) return 0;
  int start = idx + key.length() + 3;
  return json.substring(start, start + 1).toInt();
}

float extractFloat(const String &json, const String &key) {
  int idx = json.indexOf("\"" + key + "\":");
  if (idx < 0) return 0.0;
  int start = idx + key.length() + 3;
  int end = start;
  while (end < (int)json.length() && (isDigit(json[end]) || json[end] == '.' || json[end] == '-')) end++;
  return json.substring(start, end).toFloat();
}

// Extract the sub-object for slave s (1 or 2)
String extractSlaveBlock(const String &json, int s) {
  String key = "\"s" + String(s) + "\":{";
  int start = json.indexOf(key);
  if (start < 0) return "";
  start += key.length() - 1;   // include the '{'
  int depth = 0, end = start;
  while (end < (int)json.length()) {
    if (json[end] == '{') depth++;
    else if (json[end] == '}') { depth--; if (depth == 0) { end++; break; } }
    end++;
  }
  return json.substring(start, end);
}

void parseSuperSlaveStatus(const String &json) {
  for (int s = 1; s <= 2; s++) {
    String block = extractSlaveBlock(json, s);
    if (block.length() == 0) {
      slaveData[s].online = false;
      continue;
    }
    slaveData[s].online = extractInt(block, "online") == 1;
    slaveData[s].r1     = extractInt(block, "r1")     == 1;
    slaveData[s].r2     = extractInt(block, "r2")     == 1;
    slaveData[s].cur    = extractFloat(block, "cur");
  }
}

// ================= READ FROM SUPERSLAVE UART2 (non-blocking) =================
void readSuperSlaveUART() {
  while (ssSerial.available()) {
    char c = ssSerial.read();

    if (c == '\n') {
      if (ssBuffer.length() > 0) {
        parseSuperSlaveStatus(ssBuffer);
        lastSSMsg = millis();
        ssLinkUp = true;
        Serial.print("[SS] ");
        Serial.println(ssBuffer);
      }
      ssBuffer = "";
    } else if (c != '\r') {
      ssBuffer += c;
      if (ssBuffer.length() > 200) ssBuffer = "";  // overflow guard
    }
  }

  // Mark link down if nothing received for SS_TIMEOUT_MS
  if (ssLinkUp && (millis() - lastSSMsg > SS_TIMEOUT_MS)) {
    ssLinkUp = false;
    slaveData[1].online = false;
    slaveData[2].online = false;
  }
}

// ================= OLED DRAW =================
void drawOledPage0(float v, float i_pzem, float p,
                   float z1, float z2, float temp, float hum) {
  char buf[32];
  u8g2.setFont(u8g2_font_6x10_tr);

  if (!isnan(v) && v > 0) {
    sprintf(buf, "V:%.1fV I:%.2fA", v, i_pzem);
    u8g2.drawStr(0, 12, buf);
    sprintf(buf, "P:%.1fW", p);
    u8g2.drawStr(0, 24, buf);
  } else {
    u8g2.drawStr(0, 18, "PZEM ERROR");
  }

  sprintf(buf, "Z1:%.0f Z2:%.0f", z1, z2);
  u8g2.drawStr(0, 36, buf);

  sprintf(buf, "T:%.1f H:%.0f%%", temp, hum);
  u8g2.drawStr(0, 48, buf);

  // SuperSlave link indicator top-right
  u8g2.setFont(u8g2_font_4x6_tr);
  u8g2.drawStr(94, 8, ssLinkUp ? "SS:OK" : "SS:--");
}

void drawOledPage1() {
  char buf[32];
  u8g2.setFont(u8g2_font_6x10_tr);
  u8g2.drawStr(0, 10, "-- SLAVE STATUS --");

  for (int s = 1; s <= 2; s++) {
    int y = 10 + s * 18;
    if (slaveData[s].online) {
      sprintf(buf, "S%d R1:%s R2:%s", s,
              slaveData[s].r1 ? "ON " : "OFF",
              slaveData[s].r2 ? "ON " : "OFF");
      u8g2.drawStr(0, y, buf);

      char cbuf[16];
      sprintf(cbuf, "   %.2fA", slaveData[s].cur);
      u8g2.drawStr(0, y + 9, cbuf);
    } else {
      sprintf(buf, "S%d  OFFLINE", s);
      u8g2.drawStr(0, y, buf);
    }
  }
}

// ================= SETUP =================
void setup() {
  Serial.begin(115200);    // USB debug

  // PZEM on UART1, remapped pins 26(RX)/27(TX)
  pzemSerial.begin(9600, SERIAL_8N1, 26, 27);

  // SuperSlave link on UART2, default pins 16(RX2)/17(TX2)
  ssSerial.begin(SS_BAUD, SERIAL_8N1, 16, 17);

  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(LED1_PIN,   OUTPUT);
  pinMode(LED2_PIN,   OUTPUT);
  pinMode(RELAY1_PIN, OUTPUT);
  pinMode(RELAY2_PIN, OUTPUT);
  pinMode(LDR_PIN,    INPUT);

  dht.begin();

  Wire.begin(21, 22);
  Wire.setClock(100000);

  u8g2.begin();
  u8g2.setContrast(255);

  // Calibrate ZMPT offsets
  calibrateOffset(ZMPT1_PIN, offset1);
  calibrateOffset(ZMPT2_PIN, offset2);

  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_ncenB08_tr);
  u8g2.drawStr(10, 25, "SYSTEM READY");
  u8g2.sendBuffer();
  delay(1500);
}

// ================= LOOP =================
void loop() {
  unsigned long now = millis();

  // ---- Sensor Reads ----
  float z1 = readZMPT(ZMPT1_PIN, offset1);
  float z2 = readZMPT(ZMPT2_PIN, offset2);

  float temp = dht.readTemperature();
  float hum  = dht.readHumidity();

  float v      = pzem.voltage();
  float i_pzem = pzem.current();
  float p      = pzem.power();

  // ---- Read SuperSlave status over UART2 (non-blocking) ----
  readSuperSlaveUART();

  // ---- Relay Logic (unchanged) ----
  bool z1_ok = (z1 >= 200);
  bool z2_ok = (z2 >= 200);

  if (!z1_ok && !z2_ok) {
    digitalWrite(RELAY1_PIN, HIGH);
    digitalWrite(RELAY2_PIN, HIGH);
  } else if (z1_ok && !z2_ok) {
    digitalWrite(RELAY1_PIN, LOW);
    digitalWrite(RELAY2_PIN, HIGH);
  } else if (!z1_ok && z2_ok) {
    digitalWrite(RELAY1_PIN, HIGH);
    digitalWrite(RELAY2_PIN, LOW);
  } else {
    if (z1 >= z2) {
      digitalWrite(RELAY1_PIN, LOW);
      digitalWrite(RELAY2_PIN, HIGH);
    } else {
      digitalWrite(RELAY1_PIN, HIGH);
      digitalWrite(RELAY2_PIN, LOW);
    }
  }

  // ---- LED Heartbeat ----
  static bool st = false;
  st = !st;
  digitalWrite(LED1_PIN,  st);
  digitalWrite(LED2_PIN, !st);

  // ---- Buzzer ----
  handleBuzzer(z1, z2);

  // ---- OLED page flip ----
  if (now - lastPageSwitch >= PAGE_SWITCH_MS) {
    lastPageSwitch = now;
    oledPage = 1 - oledPage;   // toggle 0 <-> 1
  }

  u8g2.clearBuffer();

  if (oledPage == 0) {
    drawOledPage0(v, i_pzem, p, z1, z2, temp, hum);
  } else {
    drawOledPage1();
  }

  u8g2.sendBuffer();

  delay(200);   // shorter delay so UART2 buffer doesn't overflow between reads
}
