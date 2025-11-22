#include <WiFi.h>
#include "time.h"

const char* ssid="HOTSPOT";
const char* pass="12345678";
const char* ntp="pool.ntp.org";

void setup(){
  Serial.begin(115200);
  WiFi.begin(ssid, pass);
  while(WiFi.status()!=WL_CONNECTED) delay(200);
  configTime(19800,0,ntp); // IST
}

void loop(){
  struct tm t;
  if(!getLocalTime(&t)) return;
  Serial.printf("%02d:%02d:%02d %02d/%02d/%04d\n",
    t.tm_hour,t.tm_min,t.tm_sec,
    t.tm_mday,t.tm_mon+1,t.tm_year+1900);
  delay(1000);
}
