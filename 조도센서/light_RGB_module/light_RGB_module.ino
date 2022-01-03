int sensor = A0;
int val;
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
  
 val = analogRead(sensor);
 Serial.print(val);
 Serial.println("lux");
 delay(500);

 if (val > 900){
    analogWrite(R, 255);
    analogWrite(G, 0);
    analogWrite(B, 0);
  }
  else if (val > 500){
    analogWrite(R, 0);
    analogWrite(G, 255);
    analogWrite(B, 0);
  }
  else
  {
    analogWrite(R, 0);
    analogWrite(G, 0);
    analogWrite(B, 255); 
  }}
