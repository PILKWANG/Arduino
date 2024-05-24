#define pHsensor 0
#define photo 2
#define OFFSET 0.00
int count=0;

void setup() {
pinMode(photo, INPUT);
Serial.begin(9600);
Serial.println("CLEARDATA");
Serial.println("LABEL,TIME,COUNT,pH"); 
}

void loop() {
while(digitalRead(photo));
while(!digitalRead(photo));

count ++;

int sensorvalue = analogRead(pHsensor);
float voltage=(float)sensorvalue*0.5/1024;
float pHvalue=(voltage*35)+OFFSET;
Serial.print("DATA,TIME,");
Serial.print (count);
Serial.print(",");
Serial.println(pHvalue,2);   
}