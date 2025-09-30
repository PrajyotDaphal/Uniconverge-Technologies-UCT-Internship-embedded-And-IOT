//Components = Arduino, DC motor, PIR sensor, Ultrasonic sensor, Motor Driver L293D
int pirPin=2;
int trig=10;
int echoPin=11;
int enA=5;
int in1=6;
int in2=7;
void setup()
{pinMode(pirPin,INPUT);
    pinMode(trig,OUTPUT);
    pinMode(echoPin,INPUT);
    pinMode(enA,OUTPUT);
    pinMode(in1,OUTPUT);
    pinMode(in2,OUTPUT);
    digitalWrite(in1,LOW);
    digitalWrite(in2,LOW);
    analogWrite(enA,0);}
void openDoor()
{digitalWrite(in1,HIGH);
    digitalWrite(in2,LOW);
    analogWrite(enA,200);}
void closeDoor()
{digitalWrite(in1,LOW);
    digitalWrite(in2,HIGH);
    analogWrite(enA,200);}
void stopDoor()
{analogWrite(enA,0);}
long readUltrasonic()
{digitalWrite(trig,LOW);
    delayMicroseconds(2);
    digitalWrite(trig,HIGH);
    delayMicroseconds(10);
    digitalWrite(trig,LOW);
    long d=pulseIn(echoPin,HIGH);
    return d*0.034/2;}
void loop(){
  if(digitalRead(pirPin)==HIGH)
  {openDoor();delay(3000);
    closeDoor();
    delay(3000);
    stopDoor();}
  long dist=readUltrasonic();
  if(dist>0 && dist<30)
  {openDoor();
    delay(3000);
    closeDoor();
    delay(3000);
    stopDoor();}
  delay(200);
}
