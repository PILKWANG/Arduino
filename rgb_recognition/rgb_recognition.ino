void setup() {
Serial.begin(9600);
pinMode(9, OUTPUT);
pinMode(10, OUTPUT);
pinMode(11, OUTPUT);

}

void loop() {

while (Serial.available() >0) {
  char c = Serial.read();
  if(c=='r') {
    digitalWrite(9, HIGH);
  }
  else if (c == 'a'){
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
  }

  if(c=='g') {
    digitalWrite(10, HIGH);
  }
  else if (c == 'a'){
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
  }

  if(c=='b') {
    digitalWrite(11, HIGH);
  }
  else if (c == 'a'){
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
  }
}}
