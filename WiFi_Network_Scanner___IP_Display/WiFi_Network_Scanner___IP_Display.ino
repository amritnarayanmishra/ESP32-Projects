#include <WiFi.h>

const char* ssid = "Your_Hotspot_Name";
const char* pass = "Your_Hotspot_Password";

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, pass);

  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  Serial.println("\nConnected!");
  Serial.print("IP: ");
  Serial.println(WiFi.localIP());
}

void loop() {
}
