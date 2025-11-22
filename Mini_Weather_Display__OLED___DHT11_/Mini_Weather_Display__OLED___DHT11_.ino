#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <DHT.h>

#define DHTPIN 4
#define DHTTYPE DHT11
DHT d(DHTPIN, DHTTYPE);

Adafruit_SSD1306 s(128, 64, &Wire);

void setup() {
  d.begin();
  s.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  s.clearDisplay();
  s.setTextSize(2);
  s.setTextColor(WHITE);
}

void loop() {
  float t = d.readTemperature();
  float h = d.readHumidity();

  s.clearDisplay();
  s.setCursor(0,0);
  s.print("T: "); s.print(t);
  s.setCursor(0,20);
  s.print("H: "); s.print(h);
  s.display();

  delay(1000);
}
