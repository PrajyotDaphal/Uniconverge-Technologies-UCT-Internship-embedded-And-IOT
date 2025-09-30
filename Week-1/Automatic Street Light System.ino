//Components = Ardiuno, LED, LDR sensor
int ldr=A0;
int ledPin=9;
int thresh=400;
void setup()
{pinMode(ledPin,OUTPUT);
    digitalWrite(ledPin,LOW);}
void loop(){
  int v=analogRead(ldr);
  if(v<thresh) 
   analogWrite(ledPin,255); 
  else analogWrite(ledPin,0);
  delay(200);
}
