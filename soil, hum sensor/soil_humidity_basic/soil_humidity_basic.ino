void setup() {

  Serial.begin(9600);

}

void loop() {

  int soil = analogRead(A0);

  Serial.println(soil);

  delay(1000);

}
