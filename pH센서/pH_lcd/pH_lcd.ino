#include<LiquidCrystal_I2C.h>
#include<Wire.h>
#define SensorPin 0
#define OFFSET -0.78
unsigned long int avgValue;
int buf[10], temp;

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
  for(int i=0;i<10;i++)
  { 
    buf[i]=analogRead(SensorPin);
    delay(10);
  }
  for(int i=0;i<9;i++)
  {
    for(int j=i+1;j<10;j++)
    {
      if(buf[i]>buf[j])
       {
        temp=buf[i];
        buf[i]=buf[j];
        buf[j]=temp;
      }
    }
  }      
  avgValue=0;
  for(int i=2;i<8;i++)
    avgValue+=buf[i];
  float pHvalue=(float)avgValue*5.0/1024/6;
  pHvalue=3.5*pHvalue+OFFSET;
  Serial.println(pHvalue);
  delay(500);

  lcd.setCursor(2,0);
  lcd.print("pH :");
  lcd.setCursor(8,0);
  lcd.print(pHvalue,2);
  } 
