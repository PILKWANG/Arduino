#include "VernierLib.h" //include Vernier functions in this sketch
VernierLib Vernier; //create an instance of the VernierLib library
int valve = 9; // The solenoid valve connect to Pin ~9
void setup() { // setup the initial condition
 Serial.begin(9600); // setup the baud rate
 Vernier.autoID(); //identify the sensor being used
 pinMode(valve, OUTPUT);
 digitalWrite(valve, HIGH);} // setup the solenoid valve initial condition
 
void loop() { // code indicating the valve condition by AI for speech recognition
 float Pressure = Vernier.readSensor()/103.325; // convert pressure units from kPa to atm
 Serial.println(Pressure); // print the pressure value
 while
 (Serial.available() >0) {
 char c = Serial.read();
 if(c=='r') {digitalWrite(valve, LOW);} // When ‘r’ is recognized, open the solenoid valve.
 else if (c == 'g') {digitalWrite(valve, HIGH); // When ‘g’ is recognized, close the solenoid valve.
 }}
 delay(500);} // pressure measurement at intervals of 0.5 seconds
