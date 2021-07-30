#include <Adafruit_NeoPixel.h>
#define BRIGHTNESS 100
#define PIN     6
#define NUMPIXELS  64
#define DELAYVAL 500
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  Serial.begin(9600);
  pixels.begin();
  pixels.setBrightness(BRIGHTNESS);
}

void loop() {
while (Serial.available() >0) {
  char c = Serial.read();
  if(c=='r') {for(int i=0; i<NUMPIXELS; i++){
      pixels.setPixelColor(i, pixels.Color(255,0,0));
      pixels.show();}
     
  }}}
