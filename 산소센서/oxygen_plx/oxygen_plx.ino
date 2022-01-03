#include "DFRobot_OxygenSensor.h"

#define COLLECT_NUMBER    10
#define Oxygen_IICAddress ADDRESS_3
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
  float oxygenData = Oxygen.ReadOxygenData(COLLECT_NUMBER);
  count ++;
  Serial.print("DATA, TIME, ");
  Serial.print(count*1);
  Serial.print(",");
  Serial.println(oxygenData);
  delay(300);
}
