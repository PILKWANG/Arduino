#include "VernierLib.h" //include Vernier functions in this sketch
VernierLib Vernier; //create an instance of the VernierLib library
#define DELAYVAL 500
int count=0;
int  R = 3;
int  G = 5;
int  B = 6;

void setup() { // setup the initial condition
Serial.begin(9600);
pinMode(R, OUTPUT);
pinMode(G, OUTPUT);
pinMode(B, OUTPUT);
Vernier.autoID(); //identify the sensor being used
Serial.println("CLEARDATA");
Serial.println("LABEL, TIME, time, Pressure");
}

void loop() { //code in which the valve opens when the pressure drops below 0.25atm
count ++;
float Pressure = Vernier.readSensor()/103.325; // convert pressure units from kPa to atm
Serial.print("DATA, TIME, ");
Serial.print(count*DELAYVAL*0.001); //count the time in 0.5 second intervals
Serial.print(",");
Serial.println(Pressure);
delay(DELAYVAL);

if(Pressure < 0.25) {
      analogWrite(R, 255);
      analogWrite(G, 0);
      analogWrite(B, 0);
    }
    else if(Pressure < 0.60) { 
      analogWrite(R, 0);
      analogWrite(G, 255);
      analogWrite(B, 0);
    }
    else {
      analogWrite(R, 0);
      analogWrite(G, 0);
      analogWrite(B, 255);
      }
}