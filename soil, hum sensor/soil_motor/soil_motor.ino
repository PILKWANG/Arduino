#define DELAY 500
const int motorpin = 9;
unsigned long previousMillis = 0;
int count=0;

void setup() {

  Serial.begin(9600);
  Serial.println("CLEARDATA");
  Serial.println("LABEL, TIME, time, soil");

}

void loop() {

  int soil = analogRead(A0);

unsigned long currentMillis = millis();
 if (currentMillis-previousMillis>=DELAY){
  previousMillis=currentMillis;
  count ++;
  Serial.print("DATA, TIME, ");
  Serial.print(count*DELAY*0.001);
  Serial.print(",");
  Serial.println(soil);}

 if (soil =< 65){
  analogWrite(motorpin,255)
 }
  

}