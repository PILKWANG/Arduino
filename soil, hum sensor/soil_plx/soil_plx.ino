int count=0;

void setup() {

  Serial.begin(9600);
  Serial.println("CLEARDATA");
  Serial.println("LABEL, TIME, time, soil");

}

void loop() {

  int soil = analogRead(A0);

  count ++;
  Serial.print("DATA, TIME, ");
  Serial.print(count*1);
  Serial.print(",");
  Serial.println(soil);


  delay(1000);

}