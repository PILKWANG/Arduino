int  R = 9;
int  G = 10;
int  B = 11;

void setup() {
  pinMode(R, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(B, OUTPUT);
}

void loop() {
  analogWrite(R, 255);
  delay(1000);
  analogWrite(R, 0);
  delay(1000);
  analogWrite(G, 255);
  delay(1000);
  analogWrite(G, 0);
  delay(1000);
  analogWrite(B, 255); 
  delay(1000);
  analogWrite(B, 0); 
  delay(1000); 
}
