
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

// ---- AP Credentials (still used to receive data from Slave1/Slave2) ----
#define AP_SSID     "SuperSlave_AP"
#define AP_PASSWORD "12345678"

// ---- Web Server (Slave1/Slave2 -> SuperSlave, unchanged) ----
ESP8266WebServer server(80);

// ---- UART link to ESP32 MASTER ----
// Uses the ESP8266's default hardware UART0 pins (GPIO1 TX / GPIO3 RX) --
// the same pins used for USB programming/debug.
//
// ESP8266 GPIO3 (RX) <- ESP32 GPIO17 (TX1)
// ESP8266 GPIO1 (TX) -> ESP32 GPIO16 (RX1)
//
// IMPORTANT: Serial IS the master link here. Do NOT use Serial.print()
// for debug -- it will corrupt the JSON stream the ESP32 is parsing.
// Unplug this link (or the ESP32) before reflashing over USB.
#define masterLink Serial

#define MASTER_BAUD     9600
#define MASTER_SEND_MS  1000   // send status to ESP32 every 1s

// ---- Slave Data Store ----
struct SlaveData {
  bool r1 = false;
  bool r2 = false;
  float current = 0.0;
  bool online = false;
  unsigned long lastSeen = 0;
};

SlaveData slaves[3];  // index 1 and 2 used

// ---------------- HTTP HANDLERS (Slave1/Slave2 -> here, unchanged) ----------------
void handleUpdate() {
  if (server.hasArg("id") && server.hasArg("r1") &&
      server.hasArg("r2") && server.hasArg("cur")) {

    int id = server.arg("id").toInt();
    if (id >= 1 && id <= 2) {
      slaves[id].r1      = server.arg("r1") == "1";
      slaves[id].r2      = server.arg("r2") == "1";
      slaves[id].current = server.arg("cur").toFloat();
      slaves[id].online  = true;
      slaves[id].lastSeen = millis();
    }
    server.send(200, "text/plain", "OK");
  } else {
    server.send(400, "text/plain", "Bad Request");
  }
}

void handleRoot() {
  String html = "<!DOCTYPE html><html><head>"
    "<meta http-equiv='refresh' content='2'>"
    "<meta name='viewport' content='width=device-width'>"
    "<title>SuperSlave Dashboard</title>"
    "<style>body{font-family:monospace;background:#111;color:#0f0;padding:16px}"
    "table{border-collapse:collapse;width:100%}td,th{border:1px solid #0f0;padding:8px}"
    ".on{color:#0f0}.off{color:#555}</style></head><body>"
    "<h2>&#9889; SuperSlave Dashboard</h2><table>"
    "<tr><th>Slave</th><th>Status</th><th>R1</th><th>R2</th><th>Current</th></tr>";

  for (int s = 1; s <= 2; s++) {
    bool online = slaves[s].online && (millis() - slaves[s].lastSeen < 5000);
    html += "<tr><td>Slave " + String(s) + "</td>";
    html += "<td class='" + String(online ? "on" : "off") + "'>"
          + (online ? "ONLINE" : "OFFLINE") + "</td>";
    html += "<td class='" + String(slaves[s].r1 ? "on" : "off") + "'>"
          + (slaves[s].r1 ? "ON" : "OFF") + "</td>";
    html += "<td class='" + String(slaves[s].r2 ? "on" : "off") + "'>"
          + (slaves[s].r2 ? "ON" : "OFF") + "</td>";
    html += "<td>" + String(slaves[s].current, 2) + " A</td></tr>";
  }

  html += "</table><p style='color:#555'>Auto-refresh every 2s</p></body></html>";
  server.send(200, "text/html", html);
}

// ---------------- BUILD JSON FOR MASTER ----------------
// {"s1":{"online":1,"r1":0,"r2":1,"cur":1.23},"s2":{"online":0,"r1":0,"r2":0,"cur":0.00}}
String buildStatusJson() {
  unsigned long now = millis();
  String json = "{";

  for (int s = 1; s <= 2; s++) {
    bool online = slaves[s].online && (now - slaves[s].lastSeen < 5000);

    json += "\"s" + String(s) + "\":{";
    json += "\"online\":" + String(online ? 1 : 0) + ",";
    json += "\"r1\":"     + String(slaves[s].r1 ? 1 : 0) + ",";
    json += "\"r2\":"     + String(slaves[s].r2 ? 1 : 0) + ",";

    char curBuf[10];
    dtostrf(slaves[s].current, 4, 2, curBuf);
    json += "\"cur\":" + String(curBuf);
    json += "}";

    if (s < 2) json += ",";
  }

  json += "}";
  return json;
}

// ---------------- SETUP ----------------
void setup() {
  Serial.begin(MASTER_BAUD);   // default GPIO1(TX)/GPIO3(RX) -- master link

  WiFi.mode(WIFI_AP);
  WiFi.softAP(AP_SSID, AP_PASSWORD);

  server.on("/",       handleRoot);
  server.on("/update", HTTP_POST, handleUpdate);
  server.begin();
}

// ---------------- LOOP ----------------
void loop() {
  server.handleClient();

  // Send status to ESP32 master every MASTER_SEND_MS over UART
  static unsigned long tSend = 0;
  if (millis() - tSend >= MASTER_SEND_MS) {
    tSend = millis();
    String json = buildStatusJson();
    masterLink.println(json);   // newline-terminated for easy parsing
  }
}
