#include "VernierLib.h" //include Vernier functions in this sketch
VernierLib Vernier; //create an instance of the VernierLib library
#include <Adafruit_NeoPixel.h>
#define BRIGHTNESS 200
#define PIN     6
#define NUMPIXELS  30
#define DELAYVAL 300
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
int count=0;

void setup() { // setup the initial condition
Serial.begin(9600);
Vernier.autoID(); //identify the sensor being used
pixels.begin();
pixels.setBrightness(BRIGHTNESS);
Serial.println("CLEARDATA");
Serial.println("LABEL, TIME, time, Pressure");
}

void loop() { //code in which the valve opens when the pressure drops below 0.25atm
count ++;
float Pressure = Vernier.readSensor()/103.325; // convert pressure units from kPa to atm
Serial.print("DATA, TIME, ");
Serial.print(count*DELAYVAL*0.001);
Serial.print(",");
Serial.println(Pressure);
delay(DELAYVAL);

if(Pressure < 0.25) {for(int i=0; i<NUMPIXELS; i++){
      pixels.setPixelColor(i, pixels.Color(255,255,0));
      pixels.show();}
    }
    else if(Pressure < 0.60) {for(int i=0; i<NUMPIXELS; i++){
      pixels.setPixelColor(i, pixels.Color(0,255,0));
      pixels.show();}
    }
    else {for(int i=0; i<NUMPIXELS; i++){
     pixels.setPixelColor(i, pixels.Color(0,0,255));
     pixels.show();}}
}
