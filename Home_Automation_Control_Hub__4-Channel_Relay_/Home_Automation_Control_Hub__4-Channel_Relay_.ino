#include <WiFi.h>
#include <WebServer.h>

WebServer s(80);
const char* ssid="HOTSPOT";
const char* pass="12345678";

int r[4]={2,4,5,18};

void rel(int i,int st){
  digitalWrite(r[i],st);
  s.send(200,"text/html",
  String("R")+i+"="+(st?"ON":"OFF"));
}

void setup(){
  for(int i=0;i<4;i++) pinMode(r[i],1);
  WiFi.begin(ssid,pass);
  while(WiFi.status()!=3) delay(200);

  s.on("/r0on", [](){rel(0,1);});
  s.on("/r0off", [](){rel(0,0);});
  s.on("/r1on", [](){rel(1,1);});
  s.on("/r1off", [](){rel(1,0);});
  s.on("/r2on", [](){rel(2,1);});
  s.on("/r2off", [](){rel(2,0);});
  s.on("/r3on", [](){rel(3,1);});
  s.on("/r3off", [](){rel(3,0);});
  s.begin();
}

void loop(){
  s.handleClient();
}
