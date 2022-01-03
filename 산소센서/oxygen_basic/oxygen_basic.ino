#include "DFRobot_OxygenSensor.h"

#define COLLECT_NUMBER    10
#define Oxygen_IICAddress ADDRESS_3

DFRobot_OxygenSensor Oxygen;
void setup()
{
  Serial.begin(9600);
  while(!Oxygen.begin(Oxygen_IICAddress)) {
    Serial.println("I2c device number error !");
    delay(1000);
  }
  Serial.println("I2c connect success !");
}

void loop()
{
  float oxygenData = Oxygen.ReadOxygenData(COLLECT_NUMBER);
  Serial.print(" Oxygen concentration is ");
  Serial.print(oxygenData);
  Serial.println(" %vol");
  delay(300);
}
