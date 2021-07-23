#include <Adafruit_NeoPixel.h>
#define BRIGHTNESS 200
#define PIN     6
#define NUMPIXELS  30
#define DELAYVAL 500
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  pixels.begin();
  pixels.setBrightness(BRIGHTNESS);
}

void loop() {
while (Serial.available() >0) {
  char c = Serial.read();
  if(c=='r') {
      pixels.setPixelColor(5, pixels.Color(255,255,0));
      pixels.show();
      }
  }}
