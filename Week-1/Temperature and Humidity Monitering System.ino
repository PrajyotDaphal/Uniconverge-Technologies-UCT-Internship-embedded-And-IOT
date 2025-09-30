//Components = Arduino, DHT11, OLED SSD1306
#include <DHT.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN,DHTTYPE);
Adafruit_SSD1306 display(128,64,&Wire);
void setup()
{Serial.begin(9600);
    dht.begin();
    display.begin(SSD1306_SWITCHCAPVCC,0x3C);}
void loop(){
  float h=dht.readHumidity();
  float t=dht.readTemperature();
  display.clearDisplay();
  display.setTextSize(2);
  display.setCursor(0,0);
  display.print("T:");
  display.print(t);
  display.setCursor(0,30);
  display.print("H:");
  display.print(h);
  display.display();
  delay(2000);
}
