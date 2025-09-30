//Components = Arduino, Ultrasonic sensor,IR sensor, Dc motor, Motor Driver L293D
int trig=10;
int echoPin=11;
int irLeft=A0;
int irRight=A1;
int enA=5,in1=6,in2=7,enB=9,in3=8,in4=4;
void setup()
{pinMode(trig,OUTPUT);
    pinMode(echoPin,INPUT);
    pinMode(irLeft,INPUT);
    pinMode(irRight,INPUT);
    pinMode(enA,OUTPUT);
    pinMode(in1,OUTPUT);
    pinMode(in2,OUTPUT);
    pinMode(enB,OUTPUT);
    pinMode(in3,OUTPUT);
    pinMode(in4,OUTPUT);}
long readUltrasonic()
{digitalWrite(trig,LOW);
    delayMicroseconds(2);
    digitalWrite(trig,HIGH);
    delayMicroseconds(10);
    digitalWrite(trig,LOW);
    long d=pulseIn(echoPin,HIGH);
    return d*0.034/2;}
void forward()
{digitalWrite(in1,HIGH);
    digitalWrite(in2,LOW);
    analogWrite(enA,220);
    digitalWrite(in3,HIGH);
    digitalWrite(in4,LOW);
    analogWrite(enB,220);}
void leftTurn()
{digitalWrite(in1,LOW);
    digitalWrite(in2,HIGH);
    analogWrite(enA,200);
    digitalWrite(in3,HIGH);
    digitalWrite(in4,LOW);
    analogWrite(enB,200);}
void rightTurn()
{digitalWrite(in1,HIGH);
    digitalWrite(in2,LOW);
    analogWrite(enA,200);
    digitalWrite(in3,LOW);
    digitalWrite(in4,HIGH);
    analogWrite(enB,200);}
void stopAll()
{analogWrite(enA,0);analogWrite(enB,0);}
void loop(){
  int l=analogRead(irLeft);
  int r=analogRead(irRight);
  long dist=readUltrasonic();
  if(dist>0 && dist<20)
   {stopAll();
    delay(300);
    leftTurn();
    delay(300);
    return;}
  int thresh=600;
  if(l>thresh && r>thresh) forward();
  else if(l>thresh) rightTurn();
  else if(r>thresh) leftTurn();
  else stopAll();
  delay(100);
}
