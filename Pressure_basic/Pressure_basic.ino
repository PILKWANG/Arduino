#include "VernierLib.h" //include Vernier functions in this sketch
VernierLib Vernier; //create an instance of the VernierLib library

void setup() { // setup the initial condition
Serial.begin(9600);
Vernier.autoID(); //identify the sensor being used
}

void loop() { //code in which the valve opens when the pressure drops below 0.25atm
float Pressure = Vernier.readSensor()/103.325; // convert pressure units from kPa to atm
Serial.print("Pressure : "); //count the time in 0.5 second intervals
Serial.print(Pressure);
Serial.println(" atm");
delay(500);
}
