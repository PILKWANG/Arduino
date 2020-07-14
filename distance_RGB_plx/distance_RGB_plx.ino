int echoPin = 12;
int trigPin = 13;
int  R = 9;
int  G = 10;
int  B = 11;
int count=0;

void setup() {
  Serial.begin(9600);
  Serial.println("CLEARDATA");
  Serial.println("LABEL, TIME, time, distance(cm)");
  
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

  if (distance < 10){
    analogWrite(R, 255);
    analogWrite(G, 0);
    analogWrite(B, 0);
  }
  else if (distance < 20{
    analogWrite(R, 0);
    analogWrite(G, 255);
    analogWrite(B, 0);
  }
  else
  {
    analogWrite(R, 0);
    analogWrite(G, 0);
    analogWrite(B, 255); 
  }

  count ++;
  Serial.print("DATA, TIME, ");
  Serial.print(count*1);
  Serial.print(",");
  Serial.println(distance);

  delay(1000);
}
