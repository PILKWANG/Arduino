int sensor = A0;
float val;
int count=0;

void setup() {
 Serial.begin(9600);
 Serial.println("CLEARDATA");
 Serial.println("LABEL, TIME, time, light(lux)");
 
}

void loop() {
  
 val = analogRead(sensor);
 count ++;
  Serial.print("DATA, TIME, ");
  Serial.print(count*1);
  Serial.print(",");
  Serial.println(val,1);
  delay(300);
}
