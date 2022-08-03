#include <OneWire.h>
#include <DallasTemperature.h>
#define ONE_WIRE_BUS 2

int  R = 9;
int  G = 10;
int  B = 11;
float tem;

OneWire ourWire(ONE_WIRE_BUS);
DallasTemperature sensors(&ourWire);

float tempSensor;

void setup(){
  Serial.begin(9600);
  pinMode(R, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(B, OUTPUT);
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
  if(tem < 30) {
    analogWrite(R, 255);
    analogWrite(G, 0);
    analogWrite(B, 0);
     }
   else {
      analogWrite(R, 0);
    analogWrite(G, 255);
    analogWrite(B, 0);   
    }
 }

int getTemp(){
  int tempVal = 0;
  return tempVal;
}
