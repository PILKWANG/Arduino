#include <OneWire.h>
#include <DallasTemperature.h>
 
#define ONE_WIRE_BUS 2

float tem;

OneWire ourWire(ONE_WIRE_BUS);
DallasTemperature sensors(&ourWire);

float tempSensor;

void setup(){
  Serial.begin(9600);
  sensors.begin();
  
  Serial.println("CLEARDATA");
  Serial.println("LABEL,Time,Temp");
}

 
void loop()
{ 
  sensors.requestTemperatures(); 
  tempSensor = sensors.getTempCByIndex(0);
  tem = tempSensor;
   
  Serial.print("DATA,TIME,");
  Serial.println(tem);
  delay(1000);
 }

int getTemp(){
  int tempVal = 0;
  return tempVal;
}
