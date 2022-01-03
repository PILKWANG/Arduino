#include "DFRobot_OxygenSensor.h"
#include <Adafruit_NeoPixel.h>
#define PIN 6 
#define NUMPIXELS 30
#define BRIGHTNESS 200
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
DFRobot_OxygenSensor Oxygen;

#define COLLECT_NUMBER    10
#define Oxygen_IICAddress ADDRESS_3
int count=0;


void setup()
{
  Serial.begin(9600);
  pixels.begin();
  pixels.setBrightness(BRIGHTNESS);
  while(!Oxygen.begin(Oxygen_IICAddress)) {
    delay(300);
  }
  Serial.println("CLEARDATA");
  Serial.println("LABEL, TIME, time, Oxygen(%vol)");
}

void loop()
{
  float oxygenData = Oxygen.ReadOxygenData(COLLECT_NUMBER);
  count ++;
  Serial.print("DATA, TIME, ");
  Serial.print(count*1);
  Serial.print(",");
  Serial.println(oxygenData);
  delay(300);

  if (oxygenData < 15){
    for(int i=0; i<NUMPIXELS; i++) { 
    pixels.setPixelColor(i, pixels.Color(255, 0, 0));
    pixels.show();
  }}
  else if (oxygenData < 18){
    for(int i=0; i<NUMPIXELS; i++) { 
    pixels.setPixelColor(i, pixels.Color(0, 0, 255));
    pixels.show();
  }}
  else
  {
    for(int i=0; i<NUMPIXELS; i++) { 
    pixels.setPixelColor(i, pixels.Color(0, 255, 0));
    pixels.show();
  }}
}
