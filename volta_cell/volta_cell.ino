int DELAY=1000;

void setup() 
{
  Serial.begin(9600);
  pinMode(A0,INPUT);
 
 }
void loop() {
  int sensorValue = analogRead(A0);
  float voltage = sensorValue /40.96;
  Serial.print("  Voltage : ");
  Serial.print(voltage);
  Serial.println("(V)");
  delay(DELAY);
 
}
