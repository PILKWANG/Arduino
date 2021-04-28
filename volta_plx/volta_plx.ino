int count=0;
int DELAY=1000;

void setup() 
{
  Serial.begin(9600);
  pinMode(A0,INPUT);
  Serial.println("CLEARDATA");
  Serial.println("LABEL, TIME, time, Voltage(V)");
 }
void loop() {
  int sensorValue = analogRead(A0);
  float voltage = sensorValue /40.96;
  
  count ++;
  Serial.print("DATA, TIME, ");
  Serial.print(count*0.001*DELAY);
  Serial.print(",");
  Serial.println(voltage);
  delay(DELAY);
 
}
