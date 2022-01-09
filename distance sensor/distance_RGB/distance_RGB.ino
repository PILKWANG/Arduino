int echoPin = 12;
int trigPin = 13;
int  R = 9;
int  G = 10;
int  B = 11;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(R, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(B, OUTPUT);
}

void loop() {
  float duration, distance;
  digitalWrite(trigPin, HIGH);
  delay(10);
  digitalWrite(trigPin, LOW);
    
  duration = pulseIn(echoPin, HIGH); 
  distance = ((float)(340 * duration) / 10000) / 2;  

  if (distance > 50){
    analogWrite(R, 255);
    analogWrite(G, 0);
    analogWrite(B, 0);
  }
  else
  {
    analogWrite(R, 0);
    analogWrite(G, 255);
    analogWrite(B, 0); 
  }
  Serial.println(distance);
  delay(1000);
}
