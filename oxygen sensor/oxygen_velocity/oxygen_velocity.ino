#include "DFRobot_OxygenSensor.h"

#define COLLECT_NUMBER    10
#define Oxygen_IICAddress ADDRESS_3
#define DELAY 500
unsigned long previousMillis = 0;
int count=0;
DFRobot_OxygenSensor Oxygen;

void setup()
{
  Serial.begin(9600);
  while(!Oxygen.begin(Oxygen_IICAddress)) {
    delay(300);
  }
  Serial.println("CLEARDATA");
  Serial.println("LABEL, TIME, time, Oxygen(%vol)");
}

void loop()
{
  float oxygenData = Oxygen.getOxygenData(COLLECT_NUMBER);
  unsigned long currentMillis = millis();

 if (currentMillis-previousMillis>=DELAY){
  previousMillis=currentMillis;
  count ++;
  Serial.print("DATA, TIME, ");
  Serial.print(count*DELAY*0.001);
  Serial.print(",");
  Serial.println(oxygenData*100);}
}
