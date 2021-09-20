#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

#define LED_PIN D4
#define SENSOR_PIN A0

const char* ssid = "ESPHub";
const char* password = "esphub_sensor";

ESP8266WebServer server(80);

void handleRoot();
void handleCalibrateGet();
void handleCalibratePost();
void handleSensorPost();

void setup() {
  Serial.begin(115200);
  delay(50);
  
  boolean result = false;
  Serial.print("Setting up AP");
  WiFi.mode(WIFI_AP);
  while(!result) {
    Serial.print(".");
    result = WiFi.softAP(ssid, password);
  }
  Serial.println("success");
  IPAddress ip = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(ip);

  server.on("/", HTTP_GET, handleRoot);
  server.on("/calibrate", HTTP_GET, handleCalibrateGet);
  server.on("/calibrate", HTTP_POST, handleCalibratePost);
  server.on("/sensor", HTTP_POST, handleSensorPost);

  server.begin();
  Serial.println("HTTP server started");
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
  Serial.print("Args: ");
  Serial.println(server.args());
  if(!server.hasArg("data") || !server.hasArg("id") || server.arg("data")==NULL || server.arg("id")==NULL) {
    server.send(400, "text/plain", "400: Invalid Request");
  } else { // success
    server.send(200, "text/plain", "data_sent_ok");
  }
}
