#include<LiquidCrystal_I2C.h>
#include<Wire.h>

LiquidCrystal_I2C lcd(0x27,16,2); 

void setup(){
  Serial.begin(9600);
    lcd.begin(16,2);
    lcd.clear();
    lcd.init();
    lcd.backlight();
  } 
void loop()
{
  lcd.setCursor(0,0);
  lcd.print("Chemistry");
  lcd.setCursor(10,0);
  lcd.print("Good!!");
  lcd.setCursor(0,1);
  lcd.print("Hello");
} 
