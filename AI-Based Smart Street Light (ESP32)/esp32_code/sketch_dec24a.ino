#include <WiFi.h>
#include "randomforest_model.h"
#include <math.h>

// ---------- Pin Config ----------
#define LDR_PIN 32
#define TH_PIN 39
#define ZMCT_PIN 35

#define RED_PIN 2
#define GREEN_PIN 4
#define BLUE_PIN 13

// ---------- Constants ----------
const float VCC = 3.3;
const float ADC_MAX = 4095.0;
const float R_FIXED_TH = 10000.0;
const float R0 = 10000.0;
const float T0K = 298.15;
const float B = 3950.0;

// ---------- ZMCT ----------
#define ZMCT_SAMPLES 500
float zmctSensitivity = 0.25;  // Calibrate with known load

// ---------- Stability Variables ----------
int lastStableClass = -1;
int lastPredictedClass = -1;
unsigned long changeTime = 0;
bool waitingForStability = false;

// ---------- WiFi AP Config ----------
const char* ssid = "ESP32_Hotspot";
const char* password = "12345678";

WiFiServer server(1234);  // TCP server port

void setup() {
  Serial.begin(115200);
  delay(1000);

  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);

  analogReadResolution(12);
  analogSetPinAttenuation(LDR_PIN, ADC_11db);
  analogSetPinAttenuation(TH_PIN, ADC_11db);
  analogSetPinAttenuation(ZMCT_PIN, ADC_11db);

  // Start WiFi AP
  WiFi.softAP(ssid, password);
  IPAddress IP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(IP);

  server.begin();
  Serial.println("TCP server started on port 1234");
}

void loop() {
  WiFiClient client = server.available();  // Check for client connection

  if (client) {
    // ---- Read LDR ----
    int ldrADC = analogRead(LDR_PIN);

    // ---- Read Thermistor ----
    int thADC = analogRead(TH_PIN);
    float thVolt = thADC * (VCC / ADC_MAX);
    if (thVolt < 0.0001) thVolt = 0.0001;

    float Rth = R_FIXED_TH * ((VCC / thVolt) - 1.0);
    float Tk = 1.0 / ((1.0 / T0K) + (1.0 / B) * log(Rth / R0));
    float tempC = Tk - 273.15;

    // ---- ZMCT RMS (Dynamic Offset) ----
    float offset = 0;
    for (int i = 0; i < ZMCT_SAMPLES; i++) {
      offset += analogRead(ZMCT_PIN);
      delayMicroseconds(100);
    }
    offset /= ZMCT_SAMPLES;

    float sumSquares = 0;
    for (int i = 0; i < ZMCT_SAMPLES; i++) {
      float centered = analogRead(ZMCT_PIN) - offset;
      sumSquares += centered * centered;
      delayMicroseconds(200);
    }

    float rmsAdc = sqrt(sumSquares / ZMCT_SAMPLES);
    float rmsVoltage = (rmsAdc * VCC) / ADC_MAX;
    float rmsCurrent = rmsVoltage / zmctSensitivity;

    // ---- Prepare ML features ----
    float features[2] = { (float)ldrADC, tempC };

    // ---- Predict ----
    Eloquent::ML::Port::RandomForestModel classifier;

    unsigned long t_start = micros();
    int predictedClass = classifier.predict(features);
    unsigned long t_end = micros();

    // ---- STABLE CLASS LOGIC ----
    if (predictedClass != lastPredictedClass) {
      lastPredictedClass = predictedClass;
      changeTime = millis();
      waitingForStability = true;
    }

    if (waitingForStability) {
      if (millis() - changeTime >= 2000) {
        if (predictedClass == lastPredictedClass) {
          lastStableClass = predictedClass;
        }
        waitingForStability = false;
      }
    }

    // ---- LED Output ----
    switch (lastStableClass) {
      case 0:
        digitalWrite(RED_PIN, HIGH);
        digitalWrite(GREEN_PIN, LOW);
        digitalWrite(BLUE_PIN, LOW);
        break;
      case 1:
        digitalWrite(RED_PIN, HIGH);
        digitalWrite(GREEN_PIN, LOW);
        digitalWrite(BLUE_PIN, HIGH);
        break;
      case 2:
        digitalWrite(RED_PIN, LOW);
        digitalWrite(GREEN_PIN, HIGH);
        digitalWrite(BLUE_PIN, HIGH);
        break;
      default:
        digitalWrite(RED_PIN, LOW);
        digitalWrite(GREEN_PIN, LOW);
        digitalWrite(BLUE_PIN, LOW);
    }

    // ---- Prepare data string ----
    String dataString = "LDR=" + String(ldrADC) +
                        " | Temp=" + String(tempC, 2) +
                        " | Current=" + String(rmsCurrent, 3) +
                        " | Raw Class=" + String(predictedClass) +
                        " | Stable Class=" + String(lastStableClass) +
                        " | Inference=" + String(t_end - t_start);

    // ---- Send to client ----
    client.println(dataString);

    delay(500);  // Sampling interval
  }
}
