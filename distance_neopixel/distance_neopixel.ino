#include <Adafruit_NeoPixel.h>
#define PIN 6 
#define NUMPIXELS 30
#define BRIGHTNESS 200
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int echoPin = 12;
int trigPin = 13;


void setup() {
  Serial.begin(9600);
 
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pixels.begin();
  pixels.setBrightness(BRIGHTNESS);
}

void loop() {
  float duration, distance;
  digitalWrite(trigPin, HIGH);
  delay(10);
  digitalWrite(trigPin, LOW);
    
  duration = pulseIn(echoPin, HIGH); 
  distance = ((float)(340 * duration) / 10000) / 2;  

  if (distance < 10){
    for(int i=0; i<NUMPIXELS; i++) { 
    pixels.setPixelColor(i, pixels.Color(255, 0, 0));
    pixels.show();
  }}
  else if (distance < 20{
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
 delay(1000);
}
