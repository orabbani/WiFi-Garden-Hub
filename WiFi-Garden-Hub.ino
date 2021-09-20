#include <ESP8266WiFi.h>

#define LED_PIN D4
#define SENSOR_PIN A0

const char* ssid = "ESPHub";
const char* password = "esphub_sensor";

WiFiServer server(80);

void setup() {
  Serial.begin(9600);
  boolean result = false;
  Serial.print("Setting up AP");
  while(!result) {
    Serial.print(".");
    result = WiFi.softAP(ssid, password);
  }
  Serial.println("success");
  IPAddress ip = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(ip);

  server.on("/", HTTP_GET, serveRoot);
  server.on("/calibrate", HTTP_GET, handleCalibrateGet);
  server.on("/calibrate", HTTP_POST, handleCalibratePost);
  server.on("/sensor", HTTP_POST, handleSensorPost);

  server.begin();
}

void loop() {
  server.handleClient();
}

void handleRoot() {
  
}

void handleCalibrateGet() {
  
}

void handleCalibratePost() {
  
}

void handleSensorPost() {
  if(!server.hasArg("data") || !server.hasArg("id") || server.arg("data")==NULL || server.arg("id")==NULL) {
    server.send(400, "text/plain", "400: Invalid Request");
  } else { // success
    server.send(200, "text/plain", "data_sent_ok");
  }
}
