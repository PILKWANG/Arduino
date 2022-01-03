int sensor = A0;
int val;

void setup() {
 Serial.begin(9600);
 
}

void loop() {
  
 val = analogRead(sensor);
 Serial.println(val);
 delay(1000);
 
 
}
