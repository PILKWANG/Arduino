#define pHsensor 0
#define OFFSET 0.00

int count=0;

void setup() {
 Serial.begin(9600);
 Serial.println("CLEARDATA");
 Serial.println("LABEL, TIME, count, pH");
 }

void loop() {

count ++;

int sensorvalue = analogRead(pHsensor);
float voltage=(float)sensorvalue*0.5/1024;
float pHvalue=(voltage*35)+OFFSET;
Serial.print("DATA,TIME,");
Serial.print (count);
Serial.print(",");
Serial.println(pHvalue,2);
delay(500);
}