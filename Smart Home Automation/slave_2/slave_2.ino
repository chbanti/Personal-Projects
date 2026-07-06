#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>
#include "EmonLib.h"                    // ← add this

// ---- OLED ----
Adafruit_SSD1306 display(128, 32, &Wire, -1);

// ---- Buttons ----
#define BTN_UP    D6
#define BTN_DOWN  D7
#define BTN_ENTER D5

// ---- Relays ----
#define RELAY1 D0
#define RELAY2 3

// ---- WiFi ----
#define SLAVE_ID    2             // ← 2 for second slave
#define AP_SSID     "SuperSlave_AP"
#define AP_PASSWORD "12345678"
#define MASTER_IP   "192.168.4.1"

const char* items[2] = {"R1", "R2"};
bool state[2] = {false, false};
int selected = 0;

WiFiClient wifiClient;
EnergyMonitor emon1;               // ← add this

// ---------------- CURRENT ----------------
float readCurrent() {
  double Irms = emon1.calcIrms(1480);
  if (Irms < 0.10) Irms = 0.0;
  return (float)Irms;
}

// ---------------- RELAY ----------------
void applyRelay(int i) {
  if (i == 0) digitalWrite(RELAY1, state[0] ? LOW : HIGH);
  else        digitalWrite(RELAY2, state[1] ? LOW : HIGH);
}

// ---------------- SEND STATUS ----------------
void sendStatus() {
  if (WiFi.status() != WL_CONNECTED) return;

  HTTPClient http;
  String url = "http://" + String(MASTER_IP) + "/update";
  http.begin(wifiClient, url);
  http.addHeader("Content-Type", "application/x-www-form-urlencoded");

  float current = readCurrent();
  String body = "id=" + String(SLAVE_ID)
              + "&r1=" + (state[0] ? "1" : "0")
              + "&r2=" + (state[1] ? "1" : "0")
              + "&cur=" + String(current, 2);

  http.POST(body);
  http.end();
}

// ---------------- UI ----------------
void drawUI() {
  float current = readCurrent();

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.drawLine(64, 0, 64, 32, WHITE);

  for (int i = 0; i < 2; i++) {
    int y = i * 16;
    if (i == selected) {
      display.fillRect(0, y, 64, 16, WHITE);
      display.setTextColor(BLACK);
    } else {
      display.setTextColor(WHITE);
    }
    display.setCursor(3, y + 4);
    display.print(items[i]);
    display.setCursor(35, y + 4);
    display.print(state[i] ? "ON" : "OFF");
  }

  display.setTextColor(WHITE);
  display.setCursor(70, 2);
  display.print("I");
  display.setCursor(80, 2);
  display.print(current, 2);
  display.print("A");

  display.setCursor(70, 20);
  display.print(WiFi.status() == WL_CONNECTED ? "W:OK" : "W:--");

  display.display();
}

// ---------------- SETUP ----------------
void setup() {
  Wire.begin(D2, D1);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.setRotation(2);

  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setCursor(0, 8);
  display.print("Connecting WiFi..");
  display.display();

  pinMode(BTN_UP,    INPUT_PULLUP);
  pinMode(BTN_DOWN,  INPUT_PULLUP);
  pinMode(BTN_ENTER, INPUT_PULLUP);
  pinMode(RELAY1, OUTPUT);
  pinMode(RELAY2, OUTPUT);
  digitalWrite(RELAY1, HIGH);
  digitalWrite(RELAY2, HIGH);

  emon1.current(A0, 16.1);        // ← add this

  WiFi.mode(WIFI_STA);
  WiFi.begin(AP_SSID, AP_PASSWORD);
  unsigned long t = millis();
  while (WiFi.status() != WL_CONNECTED && millis() - t < 8000) {
    delay(300);
  }
}

// ---------------- LOOP ----------------
void loop() {
  if (digitalRead(BTN_UP) == LOW) {
    selected--;
    if (selected < 0) selected = 1;
    delay(200);
    drawUI();
  }

  if (digitalRead(BTN_DOWN) == LOW) {
    selected++;
    if (selected > 1) selected = 0;
    delay(200);
    drawUI();
  }

  if (digitalRead(BTN_ENTER) == LOW) {
    state[selected] = !state[selected];
    applyRelay(selected);
    sendStatus();
    delay(200);
    drawUI();
  }

  static unsigned long tDraw = 0;
  if (millis() - tDraw > 300) {
    tDraw = millis();
    drawUI();
  }

  static unsigned long tSend = 0;
  if (millis() - tSend > 2000) {
    tSend = millis();
    sendStatus();
  }
}