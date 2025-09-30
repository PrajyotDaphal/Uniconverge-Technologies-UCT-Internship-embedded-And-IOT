//Components = Arduino, Buzzer, OLED SSD1306, MQ135
#include <SPI.h>
#include <Ethernet.h>
#include <PubSubClient.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
Adafruit_SSD1306 display(SCREEN_WIDTH,SCREEN_HEIGHT,&Wire);
int mqPin=A0;
int buz=6;
int threshold=400;
byte mac[]={0xDE,0xAD,0xBE,0xEF,0xFE,0xED};
IPAddress server(192,168,1,50);
EthernetClient ethClient;
PubSubClient client(ethClient);
void reconnect()
{while(!client.connected())
    {if(client.connect("arduinoAQ"))
        { }
    else{delay(2000);}}}
void setup()
{pinMode(buz,OUTPUT);
    display.begin(SSD1306_SWITCHCAPVCC,0x3C);
    Ethernet.begin(mac);
    client.setServer(server,1883);}
void loop(){
  if(!client.connected()) 
  reconnect();
  client.loop();
  int v=analogRead(mqPin);
  if(v>threshold)
   {digitalWrite(buz,HIGH);
    client.publish("home/air/alert","HIGH");}
  else{digitalWrite(buz,LOW);
    client.publish("home/air/alert","NORMAL");}
  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0,0);
  display.print("MQ:");
  display.print(v);
  display.display();
  delay(2000);
}
