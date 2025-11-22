#include <WiFi.h>
#include <WebServer.h>
#include <DHT.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define DHTPIN 4
DHT d(DHTPIN, DHT11);
Adafruit_SSD1306 o(128,64,&Wire);

WebServer s(80);
const char* ssid="HOTSPOT";
const char* pass="12345678";

void sendWeb(){
  float t=d.readTemperature();
  float h=d.readHumidity();
  s.send(200,"text/html",
  String("T:")+t+" C<br>H:"+h+" %");
}

void setup(){
  d.begin();
  o.begin(SSD1306_SWITCHCAPVCC,0x3C);
  WiFi.begin(ssid,pass);
  while(WiFi.status()!=3) delay(200);

  s.on("/",sendWeb);
  s.begin();
}

void loop(){
  float t=d.readTemperature();
  float h=d.readHumidity();

  o.clearDisplay();
  o.setTextSize(2);
  o.setCursor(0,0);
  o.print("T:"); o.print(t);
  o.setCursor(0,25);
  o.print("H:"); o.print(h);
  o.display();

  s.handleClient();
  delay(1000);
}
