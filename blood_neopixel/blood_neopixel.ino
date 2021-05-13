#include <Adafruit_NeoPixel.h>
#define PIN 6 
#define NUMPIXELS 30
#define BRIGHTNESS 200
#define DELAYVAL 500
 
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  pixels.begin();
  pixels.setBrightness(BRIGHTNESS);
  }

void loop() {
  
  pixels.clear();
  for(int i=0; i<15; i++) { 
    pixels.setPixelColor(i, pixels.Color(255, 0, 0));
    pixels.show();
    delay(DELAYVAL);
  }
  for(int i=15; i<NUMPIXELS; i++) { 
    pixels.setPixelColor(i, pixels.Color(0, 0, 255));
    pixels.show();
    delay(DELAYVAL);
  }}
