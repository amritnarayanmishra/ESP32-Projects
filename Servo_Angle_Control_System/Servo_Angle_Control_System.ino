#include <ESP32Servo.h>

Servo s;
#define POT A0

void setup() {
  s.attach(2);
}

void loop() {
  int x = analogRead(POT);
  int deg = map(x, 0, 4095, 0, 180);
  s.write(deg);
  delay(10);
}
