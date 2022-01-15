int  R = 9;
int  G = 10;
int  B = 11;

void setup() {
  Serial.begin(9600);
  pinMode(R, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(B, OUTPUT);

}

void loop() {

while (Serial.available() >0) {
  char c = Serial.read();
  if(c=='r') {
    digitalWrite(R, HIGH);
  }
  else if (c == 'a'){
    digitalWrite(R, LOW);
  }

  if(c=='g') {
    digitalWrite(G, HIGH);
  }
  else if (c == 'a'){
    digitalWrite(G, LOW);
  }

  if(c=='b') {
    digitalWrite(B, HIGH);
  }
  else if (c == 'a'){
    digitalWrite(B, LOW);
  }
}
}
