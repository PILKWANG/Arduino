void setup() {
Serial.begin(9600);
pinMode(6, OUTPUT);
pinMode(3, OUTPUT);
pinMode(5, OUTPUT);

}

void loop() {

while (Serial.available() >0) {
  char c = Serial.read();
  if(c=='r') {
    digitalWrite(3, HIGH);
  }
  else if (c == 'a'){
    digitalWrite(3, LOW);
  }

  if(c=='g') {
    digitalWrite(5, HIGH);
  }
  else if (c == 'a'){
    digitalWrite(5, LOW);
  }

  if(c=='b') {
    digitalWrite(6, HIGH);
  }
  else if (c == 'a'){
    digitalWrite(6, LOW);
  }
}
}
