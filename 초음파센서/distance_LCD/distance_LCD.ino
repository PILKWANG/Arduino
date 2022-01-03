#include<LiquidCrystal_I2C.h>
#include<Wire.h>
int echoPin = 12;
int trigPin = 13;

LiquidCrystal_I2C lcd(0x27,16,2);

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  lcd.begin(16,2);
  lcd.clear();
  lcd.init();
  lcd.backlight();
}

void loop() {
  float duration, distance;
  digitalWrite(trigPin, HIGH);
  delay(10);
  digitalWrite(trigPin, LOW);
    
  duration=pulseIn(echoPin, HIGH); 
  distance = ((float)(340 * duration) / 10000) / 2;

  Serial.println(distance);
  delay(500);
  
  lcd.setCursor(0,0);
  lcd.print("Distance :");
  lcd.setCursor(11,0);
  lcd.print(distance,2);
}
