#include <Wire.h>
#include <U8g2lib.h>
#include <PZEM004Tv30.h>
#include <DHT.h>

U8G2_SH1106_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, U8X8_PIN_NONE);

PZEM004Tv30 pzem(&Serial, 3, 1);

HardwareSerial ssSerial(1);
#define SS_RX_PIN     4
#define SS_TX_PIN     17
#define SS_BAUD       9600
#define SS_TIMEOUT_MS 5000

#define BUZZER_PIN  5
#define LED1_PIN    19
#define LED2_PIN    18
#define LDR_PIN     34
#define ZMPT1_PIN   32
#define ZMPT2_PIN   35
#define DHT_PIN     16
#define RELAY1_PIN  13
#define RELAY2_PIN  14
#define DHTTYPE     DHT11

DHT dht(DHT_PIN, DHTTYPE);

float ZMPT_CAL        = 0.403;
float NOISE_THRESHOLD = 8;
#define BUZZER_ON  LOW
#define BUZZER_OFF HIGH

float offset1 = 0, offset2 = 0;

#define EST_ESP32_CURRENT  0.24f
#define EST_SENSOR_CURRENT 0.05f

struct SlaveInfo {
  bool  online = false;
  bool  r1     = false;
  bool  r2     = false;
  float cur    = 0.0;
};
SlaveInfo slaveData[5];

bool          ssLinkUp       = false;
unsigned long lastSSMsg      = 0;
String        ssBuffer       = "";
uint8_t       oledPage       = 0;
unsigned long lastPageSwitch = 0;
#define PAGE_SWITCH_MS 4000

// ===== CALIBRATION =====
void calibrateOffset(int pin, float &offset) {
  long sum = 0;
  for (int i = 0; i < 800; i++) { sum += analogRead(pin); delay(2); }
  offset = sum / 800.0;
}

// ===== ZMPT =====
float readZMPT(int pin, float offset) {
  float sumSq = 0;
  for (int i = 0; i < 800; i++) {
    float c = analogRead(pin) - offset;
    sumSq += c * c;
    delayMicroseconds(200);
  }
  float rms = sqrt(sumSq / 800.0);
  return (rms < NOISE_THRESHOLD) ? 0 : rms * ZMPT_CAL;
}

// ===== BUZZER =====
void handleBuzzer(float z1, float z2) {
  static unsigned long lastBeep = 0;
  unsigned long now = millis();
  digitalWrite(BUZZER_PIN, BUZZER_OFF);
  if (z1 < 200 && z2 < 200) {
    if (now - lastBeep > 900) {
      digitalWrite(BUZZER_PIN, BUZZER_ON); delay(60);
      digitalWrite(BUZZER_PIN, BUZZER_OFF); lastBeep = now;
    }
  } else if (now - lastBeep > 1500) {
    digitalWrite(BUZZER_PIN, BUZZER_ON); delay(25);
    digitalWrite(BUZZER_PIN, BUZZER_OFF); lastBeep = now;
  }
}

// ===== JSON HELPERS =====
int extractInt(const String &json, const String &key) {
  int idx = json.indexOf("\"" + key + "\":");
  if (idx < 0) return 0;
  int s = idx + key.length() + 3;
  return json.substring(s, s + 1).toInt();
}
float extractFloat(const String &json, const String &key) {
  int idx = json.indexOf("\"" + key + "\":");
  if (idx < 0) return 0.0;
  int s = idx + key.length() + 3, e = s;
  while (e < (int)json.length() && (isDigit(json[e]) || json[e] == '.' || json[e] == '-')) e++;
  return json.substring(s, e).toFloat();
}
String extractSlaveBlock(const String &json, int s) {
  String key = "\"s" + String(s) + "\":{";
  int start = json.indexOf(key);
  if (start < 0) return "";
  start += key.length() - 1;
  int depth = 0, end = start;
  while (end < (int)json.length()) {
    if (json[end] == '{') depth++;
    else if (json[end] == '}') { if (--depth == 0) { end++; break; } }
    end++;
  }
  return json.substring(start, end);
}
void parseSuperSlaveStatus(const String &json) {
  for (int s = 1; s <= 4; s++) {
    String block = extractSlaveBlock(json, s);
    if (!block.length()) { slaveData[s].online = false; continue; }
    slaveData[s].online = extractInt(block, "online") == 1;
    slaveData[s].r1     = extractInt(block, "r1") == 1;
    slaveData[s].r2     = extractInt(block, "r2") == 1;
    slaveData[s].cur    = extractFloat(block, "cur");
  }
}
void readSuperSlaveUART() {
  while (ssSerial.available()) {
    char c = ssSerial.read();
    if (c == '\n') {
      if (ssBuffer.length() > 0) {
        parseSuperSlaveStatus(ssBuffer);
        lastSSMsg = millis(); ssLinkUp = true;
      }
      ssBuffer = "";
    } else if (c != '\r') {
      ssBuffer += c;
      if (ssBuffer.length() > 300) ssBuffer = "";
    }
  }
  if (ssLinkUp && (millis() - lastSSMsg > SS_TIMEOUT_MS)) {
    ssLinkUp = false;
    for (int s = 1; s <= 4; s++) slaveData[s].online = false;
  }
}

// ===== OLED UTILS =====
void oledHLine(int y) { u8g2.drawHLine(0, y, 128); }

void oledCenterStr(const char *str, int y) {
  u8g2.drawStr((128 - u8g2.getStrWidth(str)) / 2, y, str);
}
void oledRightStr(const char *str, int rightX, int y) {
  u8g2.drawStr(rightX - u8g2.getStrWidth(str), y, str);
}

// Draw corner bracket at (x,y), dir: 0=TL 1=TR 2=BL 3=BR
void drawCorner(int x, int y, int dir) {
  int len = 6;
  // horizontal
  int hx = (dir == 1 || dir == 3) ? x - len : x;
  u8g2.drawHLine(hx, y, len);
  // vertical
  int vy = (dir == 2 || dir == 3) ? y - len : y;
  u8g2.drawVLine(x, vy, len);
}

// ================================================================
//  SPLASH SCREEN
//  Shown once at boot with animated dots, then fades to page 0
// ================================================================
void drawSplash(int frame) {
  u8g2.clearBuffer();

  // Corner brackets
  drawCorner(0,   0,  0);   // TL
  drawCorner(127, 0,  1);   // TR
  drawCorner(0,   63, 2);   // BL
  drawCorner(127, 63, 3);   // BR

  // Top micro label
  u8g2.setFont(u8g2_font_4x6_tr);
  oledCenterStr("* FYP PROJECT *", 8);

  // Project title line 1
  u8g2.setFont(u8g2_font_7x13B_tr);
  oledCenterStr("IOT BASED SMART", 22);

  // Project title line 2 — slightly smaller
  u8g2.setFont(u8g2_font_6x10_tr);
  oledCenterStr("DISTRIBUTION SYSTEM", 33);

  // Divider dashes
  u8g2.setFont(u8g2_font_4x6_tr);
  oledCenterStr("- - - - - - - -", 39);

  // Developer name
  u8g2.setFont(u8g2_font_5x7_tr);
  oledCenterStr("Hafiz Luqman Riaz", 48);

  // Dev role
  u8g2.setFont(u8g2_font_4x6_tr);
  oledCenterStr(">> DEVELOPER <<", 56);

  // Animated init dots at bottom
  char dots[16] = "INIT";
  int d = frame % 4;
  for (int i = 0; i < d; i++) strcat(dots, ".");
  oledCenterStr(dots, 63);

  u8g2.sendBuffer();
}

// ================================================================
//  PAGE 0  —  POWER MONITOR
//
//  Row 0  (y=8)   header bar: "[ POWER MONITOR ]"   SS status right
//  Line   (y=10)
//  Row 1  (y=11-25) TOTAL CURRENT  —  big centred
//  Line   (y=27)
//  Row 2  (y=28-38) VOLTAGE card | FREQ card | PF card
//  Line   (y=40)
//  Row 3  (y=41-48) POWER label+value          page indicator
//  Line   (y=50)
// ================================================================
void drawOledPage0(float v, float p, float pf, float freq, float totalCur) {
  char buf[20];

  // ── Header ──
  u8g2.setFont(u8g2_font_4x6_tr);
  oledCenterStr("[  POWER MONITOR  ]", 7);
  oledRightStr(ssLinkUp ? "OK" : "--", 128, 7);
  u8g2.drawStr(0, 7, "SS:");
  oledHLine(9);

  // ── TOTAL CURRENT label ──
  u8g2.setFont(u8g2_font_4x6_tr);
  oledCenterStr("TOTAL  CURRENT", 16);

  // ── Big current value ──
  u8g2.setFont(u8g2_font_10x20_tr);
  if (totalCur >= 0) {
    dtostrf(totalCur, 5, 2, buf); strcat(buf, "A");
  } else {
    strcpy(buf, "--.--A");
  }
  oledCenterStr(buf, 33);

  oledHLine(35);

  // ── Three metric cards: VOLTAGE | FREQ | PF ──
  // Each card ~42px wide. x: 0, 43, 86
  const int cx[3] = {0, 43, 86};
  const int cw    = 41;

  // Card borders
  u8g2.drawRFrame(cx[0], 36, cw, 16, 2);
  u8g2.drawRFrame(cx[1], 36, cw, 16, 2);
  u8g2.drawRFrame(cx[2], 36, cw, 16, 2);

  // Card labels
  u8g2.setFont(u8g2_font_4x6_tr);
  // center label inside each card
  const char *lbl0 = "VOLT";
  const char *lbl1 = "FREQ";
  const char *lbl2 = "P.F.";
  u8g2.drawStr(cx[0] + (cw - u8g2.getStrWidth(lbl0)) / 2, 42, lbl0);
  u8g2.drawStr(cx[1] + (cw - u8g2.getStrWidth(lbl1)) / 2, 42, lbl1);
  u8g2.drawStr(cx[2] + (cw - u8g2.getStrWidth(lbl2)) / 2, 42, lbl2);

  // Card values
  u8g2.setFont(u8g2_font_5x7_tr);
  char v0[10], v1[10], v2[10];
  if (!isnan(v) && v > 1)       { dtostrf(v,    5, 0, v0); strcat(v0, "V");  } else strcpy(v0, "--V");
  if (!isnan(freq) && freq > 0) { dtostrf(freq, 4, 1, v1); strcat(v1, "Hz"); } else strcpy(v1, "--Hz");
  if (!isnan(pf) && pf >= 0)    { dtostrf(pf,   4, 2, v2);                   } else strcpy(v2, "--.--");

  u8g2.drawStr(cx[0] + (cw - u8g2.getStrWidth(v0)) / 2, 50, v0);
  u8g2.drawStr(cx[1] + (cw - u8g2.getStrWidth(v1)) / 2, 50, v1);
  u8g2.drawStr(cx[2] + (cw - u8g2.getStrWidth(v2)) / 2, 50, v2);

  oledHLine(53);

  // ── Bottom row: POWER + page tag ──
  u8g2.setFont(u8g2_font_4x6_tr);
  u8g2.drawStr(0, 60, "PWR:");
  u8g2.setFont(u8g2_font_5x7_tr);
  if (!isnan(p) && p >= 0) { dtostrf(p, 5, 0, buf); strcat(buf, "W"); }
  else strcpy(buf, "---W");
  u8g2.drawStr(20, 60, buf);

  u8g2.setFont(u8g2_font_4x6_tr);
  oledRightStr("PG:1/2 >>", 128, 60);
}

// ================================================================
//  PAGE 1  —  NODE STATUS
//
//  Row 0  (y=8)   header "[ NODE STATUS ]"  SS right
//  Line   (y=10)
//  Col hdr(y=16)
//  Line   (y=18)
//  S1-S4  rows (y=25,33,41,49)
//  Line   (y=52)
//  Env    (y=59-63)
// ================================================================
void drawOledPage1(float temp, float hum, int ldr) {
  char buf[24];

  // ── Header ──
  u8g2.setFont(u8g2_font_4x6_tr);
  oledCenterStr("[  NODE STATUS  ]", 7);
  u8g2.drawStr(0, 7, "SS:");
  oledRightStr(ssLinkUp ? "OK" : "--", 128, 7);
  oledHLine(9);

  // ── Column headers ──
  // ID:0  STATE:14  R1:62  R2:78  CUR:96
  u8g2.drawStr(0,  16, "ID");
  u8g2.drawStr(14, 16, "STATE");
  u8g2.drawStr(62, 16, "R1");
  u8g2.drawStr(78, 16, "R2");
  u8g2.drawStr(96, 16, "CURRENT");
  oledHLine(18);

  // ── Slave rows ──
  for (int s = 1; s <= 4; s++) {
    int y = 18 + s * 8;   // 26, 34, 42, 50

    // ID
    buf[0] = 'S'; buf[1] = '0' + s; buf[2] = '\0';
    u8g2.setFont(u8g2_font_5x7_tr);
    u8g2.drawStr(0, y, buf);

    u8g2.setFont(u8g2_font_4x6_tr);
    if (slaveData[s].online) {
      // State badge — draw small box
      u8g2.drawRFrame(14, y - 6, 26, 8, 1);
      u8g2.drawStr(16, y, "ONLINE");

      // Relay indicators
      u8g2.setFont(u8g2_font_5x7_tr);
      u8g2.drawStr(62, y, slaveData[s].r1 ? "1" : "0");
      u8g2.drawStr(78, y, slaveData[s].r2 ? "1" : "0");

      // Current
      u8g2.setFont(u8g2_font_4x6_tr);
      dtostrf(slaveData[s].cur, 5, 2, buf); strcat(buf, "A");
      u8g2.drawStr(96, y, buf);
    } else {
      u8g2.drawStr(14, y, "OFFLN");
      u8g2.drawStr(62, y, "-");
      u8g2.drawStr(78, y, "-");
      u8g2.drawStr(96, y, " -.--A");
    }
  }

  oledHLine(52);

  // ── Environment strip ──
  u8g2.setFont(u8g2_font_4x6_tr);

  // TEMP
  u8g2.drawStr(0, 59, "T:");
  if (!isnan(temp)) { dtostrf(temp, 4, 1, buf); strcat(buf, "C"); }
  else strcpy(buf, "--.-C");
  u8g2.drawStr(8, 59, buf);

  // HUM
  u8g2.drawStr(48, 59, "H:");
  if (!isnan(hum)) { dtostrf(hum, 3, 0, buf); strcat(buf, "%"); }
  else strcpy(buf, "---%");
  u8g2.drawStr(56, 59, buf);

  // LDR
  u8g2.drawStr(82, 59, "L:");
  sprintf(buf, "%d", ldr);
  u8g2.drawStr(90, 59, buf);

  // Page tag
  oledRightStr("PG:2/2", 128, 59);
}

// ===== SETUP =====
void setup() {
  Serial.begin(9600);
  ssSerial.begin(SS_BAUD, SERIAL_8N1, SS_RX_PIN, SS_TX_PIN);

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

  calibrateOffset(ZMPT1_PIN, offset1);
  calibrateOffset(ZMPT2_PIN, offset2);

  // ── Splash animation: 12 frames × 250ms = 3 seconds ──
  for (int f = 0; f < 12; f++) {
    drawSplash(f);
    delay(250);
  }
}

// ===== LOOP =====
void loop() {
  unsigned long now = millis();

  float z1   = readZMPT(ZMPT1_PIN, offset1);
  float z2   = readZMPT(ZMPT2_PIN, offset2);
  float temp = dht.readTemperature();
  float hum  = dht.readHumidity();
  int   ldr  = analogRead(LDR_PIN);

  float v    = pzem.voltage();
  float p    = pzem.power();
  float pf   = pzem.pf();
  float freq = pzem.frequency();

  readSuperSlaveUART();

  // ── Total current: slaves + ESP32 overhead + sensor overhead ──
  float slavesCur = 0.0;
  for (int s = 1; s <= 4; s++) {
    if (slaveData[s].online) slavesCur += slaveData[s].cur;
  }
  float totalCur = slavesCur + EST_ESP32_CURRENT + EST_SENSOR_CURRENT;

  // ── Relay Logic ──
  bool z1_ok = (z1 >= 200), z2_ok = (z2 >= 200);
  if      (!z1_ok && !z2_ok) { digitalWrite(RELAY1_PIN, HIGH); digitalWrite(RELAY2_PIN, HIGH); }
  else if ( z1_ok && !z2_ok) { digitalWrite(RELAY1_PIN, LOW);  digitalWrite(RELAY2_PIN, HIGH); }
  else if (!z1_ok &&  z2_ok) { digitalWrite(RELAY1_PIN, HIGH); digitalWrite(RELAY2_PIN, LOW);  }
  else if (z1 >= z2)         { digitalWrite(RELAY1_PIN, LOW);  digitalWrite(RELAY2_PIN, HIGH); }
  else                       { digitalWrite(RELAY1_PIN, HIGH); digitalWrite(RELAY2_PIN, LOW);  }

  // ── LED Heartbeat ──
  static bool st = false;
  st = !st;
  digitalWrite(LED1_PIN,  st);
  digitalWrite(LED2_PIN, !st);

  handleBuzzer(z1, z2);

  // ── OLED Page Flip ──
  if (now - lastPageSwitch >= PAGE_SWITCH_MS) {
    lastPageSwitch = now;
    oledPage = 1 - oledPage;
  }

  u8g2.clearBuffer();
  if (oledPage == 0) drawOledPage0(v, p, pf, freq, totalCur);
  else               drawOledPage1(temp, hum, ldr);
  u8g2.sendBuffer();

  delay(200);
}