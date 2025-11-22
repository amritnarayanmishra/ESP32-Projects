#define LDR A0
#define LED 2

void setup() {
  pinMode(LED, OUTPUT);
}

void loop() {
  int x = analogRead(LDR);
  if(x < 200) digitalWrite(LED, HIGH);
  else digitalWrite(LED, LOW);
  delay(100);
}
