int count=0;
int DELAY=1000;
unsigned long previousMillis = 0;

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
  
unsigned long currentMillis = millis();
 if (currentMillis-previousMillis>=DELAY){
  previousMillis=currentMillis;
    count ++;
  Serial.print("DATA, TIME, ");
  Serial.print(count*0.001*DELAY);
  Serial.print(",");
  Serial.println(voltage);}
 }