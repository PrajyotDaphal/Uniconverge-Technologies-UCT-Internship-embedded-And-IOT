//Components = Arduino, 2 IR, OLED SSD1306
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
Adafruit_SSD1306 display(SCREEN_WIDTH,SCREEN_HEIGHT,&Wire);
int sensorA=A0;
int sensorB=A1;
unsigned long countA=0;
unsigned long countB=0;
void setup()
{pinMode(sensorA,INPUT);
    pinMode(sensorB,INPUT);
    display.begin(SSD1306_SWITCHCAPVCC,0x3C);
    display.clearDisplay();
    display.setTextSize(2);
    display.setTextColor(SSD1306_WHITE);}
void loop(){
  static int lastA=0,lastB=0;
  int vA=analogRead(sensorA);
  int vB=analogRead(sensorB);
  int thresh=600;
  if(lastA>thresh && vA<=thresh) countA++;
  if(lastB>thresh && vB<=thresh) countB++;
  lastA=vA;lastB=vB;
  display.clearDisplay();
  display.setCursor(0,0);
  display.print("A:");
  display.print(countA);
  display.setCursor(0,30);
  display.print("B:");
  display.print(countB);
  display.display();
  delay(150);
}
