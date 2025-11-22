#include <WiFi.h>
#include <WebServer.h>

const char* ssid = "ESP32";
const char* pass = "12345678";

WebServer server(80);
#define LED 2

void handleRoot() {
  server.send(200, "text/html",
  "<h2>LED Control</h2>"
  "<a href='/on'>ON</a><br>"
  "<a href='/off'>OFF</a>");
}

void handleOn() {
  digitalWrite(LED, HIGH);
  server.send(200, "text/html", "LED ON");
}

void handleOff() {
  digitalWrite(LED, LOW);
  server.send(200, "text/html", "LED OFF");
}

void setup() {
  pinMode(LED, OUTPUT);
  WiFi.begin(ssid, pass);
  while(WiFi.status()!=WL_CONNECTED) delay(200);
  server.on("/", handleRoot);
  server.on("/on", handleOn);
  server.on("/off", handleOff);
  server.begin();
}

void loop() {
  server.handleClient();
}
