#define LED 2
#define BTN 4

bool ledState = LOW;
bool last = HIGH;
unsigned long tm = 0;

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(BTN, INPUT_PULLUP);
}

void loop() {
  bool now = digitalRead(BTN);
  if(now != last) tm = millis();
  if(millis() - tm > 50) {
    if(now == LOW) {
      ledState = !ledState;
      digitalWrite(LED, ledState);
      delay(200);
    }
  }
  last = now;
}
