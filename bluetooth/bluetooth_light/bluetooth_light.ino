#include <SoftwareSerial.h> //시리얼통신 라이브러리 호출
 
int blueTx=3;   //Tx (보내는핀 설정)
int blueRx=2;   //Rx (받는핀 설정)
SoftwareSerial mySerial(blueTx, blueRx);  //시리얼 통신을 위한 객체선언

int cdspin = A0;

void setup() 
{
  Serial.begin(9600);   //시리얼모니터
  mySerial.begin(9600); //블루투스 시리얼
}
void loop()
{
  int m_cds = map(analogRead(cdspin),0,1023,0,255);
  Serial.print("CDS = ");
  Serial.println(m_cds);
  
  mySerial.print("CDS = ");
  mySerial.println(m_cds);
  delay(1000);
}
