#include <Adafruit_NeoPixel.h>
#define PIN 6 
#define NUMPIXELS 30
#define BRIGHTNESS 200
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
#define SensorPin 0
#define OFFSET 0.10

unsigned long int avgValue;
int buf[10], temp;
int count=0;

void setup() {
 Serial.begin(9600);
 pixels.begin();
 pixels.setBrightness(BRIGHTNESS);
 Serial.println("CLEARDATA");
  Serial.println("LABEL, TIME, time, pH");
 }

void loop() {
     for(int i=0;i<10;i++)
  { 
    buf[i]=analogRead(SensorPin);
    delay(10);
  }
  for(int i=0;i<9;i++)
  {
    for(int j=i+1;j<10;j++)
    {
      if(buf[i]>buf[j])
       {
        temp=buf[i];
        buf[i]=buf[j];
        buf[j]=temp;
      }}}
  count ++;      
  avgValue=0;
  for(int i=2;i<8;i++)
    avgValue+=buf[i];
  float pHvalue=(float)avgValue*5.0/1024/6;
  pHvalue=3.5*pHvalue+OFFSET;  
  Serial.print("DATA, TIME, ");
  Serial.print(count*1);
  Serial.print(",");
  Serial.println(pHvalue);
  delay(300);
  
  if (pHvalue < 6.0){
    for(int i=0; i<NUMPIXELS; i++) { 
    pixels.setPixelColor(i, pixels.Color(255, 255, 0));
    pixels.show();
  }}
  else if (pHvalue < 7.6){
    for(int i=0; i<NUMPIXELS; i++) { 
    pixels.setPixelColor(i, pixels.Color(0, 255, 0));
    pixels.show();
  }}
  else
  {
    for(int i=0; i<NUMPIXELS; i++) { 
    pixels.setPixelColor(i, pixels.Color(0, 0, 255));
    pixels.show();
  }} 
  }
