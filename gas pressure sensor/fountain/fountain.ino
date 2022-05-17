#include "VernierLib.h" //include Vernier functions in this sketch
VernierLib Vernier; //create an instance of the VernierLib library
int valve=9;
int count=0;
void setup() { // setup the initial condition
Serial.begin(9600);
Vernier.autoID(); //identify the sensor being used
pinMode(valve, OUTPUT);
Serial.println("CLEARDATA");
Serial.println("LABEL, TIME, time, Pressure");
digitalWrite(valve, HIGH);
}

void loop() { //code in which the valve opens when the pressure drops below 0.25atm
count ++;
float Pressure = Vernier.readSensor()/103.325; // convert pressure units from kPa to atm
Serial.print("DATA, TIME, ");
Serial.print(count*0.1); //count the time in 0.1 second intervals
Serial.print(",");
Serial.println(Pressure);
if (Pressure < 0.3) {
digitalWrite(valve, LOW);
}
delay(300);
}
