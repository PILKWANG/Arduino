#include <SoftwareSerial.h> //시리얼통신 라이브러리 호출
#include<Wire.h>
#include<LiquidCrystal_I2C.h>

int blueTx=3;   //Tx (보내는핀 설정)
int blueRx=2;   //Rx (받는핀 설정)
SoftwareSerial mySerial(blueTx, blueRx);  //시리얼 통신을 위한 객체선언
LiquidCrystal_I2C lcd(0x27,16,2);

void setup() 
{
  mySerial.begin(9600); //블루투스 시리얼
  lcd.init();
  lcd.backlight();
}
void loop()
{
 if (mySerial.available())
 {
  lcd.clear();
  while (mySerial.available() > 0)
  {
    char inChar = (char)mySerial.read();
    Serial.write(inChar);
    lcd.write(inChar);
  }}
  }
 }
  
  mySerial.print("CDS = ");
  mySerial.println(m_cds);
  delay(1000);
}
