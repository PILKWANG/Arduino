#include "DFRobot_PH.h"
#include <EEPROM.h>

#define DELAY 500
#define PH_PIN A0
float voltage,phValue,temperature = 20;
DFRobot_PH ph;
unsigned long previousMillis = 0;

void setup()
{
    Serial.begin(9600);  
    ph.begin();
    
}

void loop()
{
    unsigned long currentMillis = millis();
    if(currentMillis-previousMillis>=DELAY){
        previousMillis=currentMillis;
        voltage = analogRead(PH_PIN)/1024.0*5000;  // read the voltage
        phValue = ph.readPH(voltage,temperature);  // convert voltage to pH with temperature compensation
         Serial.print("temperature:");
        Serial.print(temperature,1);
        Serial.print("^C  pH:");
        Serial.println(phValue,2);
    }
  ph.calibration(voltage,temperature);          // calibration process by Serail CMD
}