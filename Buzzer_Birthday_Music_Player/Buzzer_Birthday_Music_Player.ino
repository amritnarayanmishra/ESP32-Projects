#define BZ 2

int notes[] = {262,262,294,262,349,330,0,
               262,262,294,262,392,349,0};
int dur=300;

void setup(){
  pinMode(BZ,OUTPUT);
}
void loop(){
  for(int i=0;i<14;i++){
    if(notes[i]==0) delay(dur);
    else {
      tone(BZ, notes[i], dur);
      delay(dur);
    }
  }
  delay(2000);
}
