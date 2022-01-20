#include<LiquidCrystal_I2C.h>
#include<Wire.h>

LiquidCrystal_I2C lcd(0x27,16,2); 

int echoPin = 12;
int trigPin = 13;

void setup() {
 Serial.begin(9600);
    lcd.begin(16,2);
    lcd.clear();
    lcd.init();
    lcd.backlight();
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  float duration, distance;
  digitalWrite(trigPin, HIGH);
  delay(10);
  digitalWrite(trigPin, LOW);
    
  duration = pulseIn(echoPin, HIGH); 
  distance = ((float)(340 * duration) / 10000) / 2;  

  lcd.setCursor(0,0);
  lcd.print("Distance:");
  lcd.setCursor(10,0);
  lcd.print(distance,2);
    
  delay(500);
}
