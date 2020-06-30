int echoPin = 12;
int trigPin = 13;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  float duration, distance;
  digitalWrite(trigPin, HIGH);
  delay(10);
  digitalWrite(trigPin, LOW);
    
  duration=pulseIn(echoPin, HIGH); 
  distance = ((float)(340 * duration) / 10000) / 2;

  Serial.println(distance);
  delay(1000);
}
