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
  server.on("/", HTTP_POST, handleRoot);
  server.on("/sensor", HTTP_POST, getSensorData);

  server.begin();
}

void loop() {
  
}

void serveRoot() {
  
}

void handleRoot() {
  
}

void getSensorData() {
  if(!server.hasArg("data") || !server.hasArg("id") || server.hasArg("data")==NULL || server.hasArg("id")==NULL) {
    server.send(400, "text/plain", "400: Invalid Request");
  } else { // success
    
  }
}
