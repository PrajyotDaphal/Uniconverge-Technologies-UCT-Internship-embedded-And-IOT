//Components = 3 relay, arduino , LED, Buzzer
int r1=2;
int r2=3;
int r3=4;
int ledPin=5;
int buzz=6;
int R1=7;
int R2=8;
int R3=9;
void setup(){
  pinMode(r1,OUTPUT);
  pinMode(r2,OUTPUT);
  pinMode(r3,OUTPUT);
  pinMode(ledPin,OUTPUT);
  pinMode(buzz,OUTPUT);
  pinMode(R1,INPUT_PULLUP);
  pinMode(R2,INPUT_PULLUP);
  pinMode(R3,INPUT_PULLUP);
  digitalWrite(r1,LOW);
  digitalWrite(r2,LOW);
  digitalWrite(r3,LOW);
  digitalWrite(ledPin,LOW);
  digitalWrite(buzz,LOW);
}
void loop(){
  if(digitalRead(R1)==LOW)
   {digitalWrite(r1,!digitalRead(r1));
    digitalWrite(ledPin,digitalRead(r1));
    digitalWrite(buzz,HIGH);
    delay(200);
    digitalWrite(buzz,LOW);
    delay(300);}
  if(digitalRead(R2)==LOW)
   {digitalWrite(r2,!digitalRead(r2));
    digitalWrite(ledPin,digitalRead(r2));
    digitalWrite(buzz,HIGH);
    delay(200);
    digitalWrite(buzz,LOW);
    delay(300);}
  if(digitalRead(R3)==LOW)
   {digitalWrite(r3,!digitalRead(r3));
    digitalWrite(ledPin,digitalRead(r3));
    digitalWrite(buzz,HIGH);
    delay(200);
    digitalWrite(buzz,LOW);
    delay(300);}
}
