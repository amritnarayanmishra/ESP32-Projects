#include <DHT.h>
#define DHTPIN 4
#define DHTTYPE DHT11

DHT d(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  d.begin();
}

void loop() {
  float t = d.readTemperature();
  float h = d.readHumidity();
  Serial.print("T: "); Serial.print(t);
  Serial.print(" H: "); Serial.println(h);
  delay(1000);
}
