#include <SoftwareSerial.h> //시리얼통신 라이브러리 호출

int blueTx=3;   //Tx (보내는핀 설정)
int blueRx=2;   //Rx (받는핀 설정)
SoftwareSerial mySerial(blueTx, blueRx);  //시리얼 통신을 위한 객체선언
String myString="";

int ledRed = 9;
int ledGreen = 10;
int ledBlue = 11;

void setup() 
{
  Serial.begin(9600);
  mySerial.begin(9600); //블루투스 시리얼
  pinMode(ledRed, OUTPUT);
  pinMode(ledGreen, OUTPUT);
  pinMode(ledBlue, OUTPUT);
}
void loop(){
  while (mySerial.available() > 0)
  {
    char myChar = (char)mySerial.read();
    myString+=myChar;
    delay(5);
  }
 if(!myString.equals(""))
 {
  Serial.println("input value: "+myString);
   
   if(myString=="r")
   {
    digitalWrite(ledRed,HIGH);
   }
   if(myString=="rx")
   {
    digitalWrite(ledRed,LOW);
   }
    if(myString=="g")
   {
    digitalWrite(ledGreen,HIGH);
   }
   if(myString=="gx")
   {
    digitalWrite(ledGreen,LOW);
   }
  if(myString=="b")
   {
    digitalWrite(ledBlue,HIGH);
   }
   if(myString=="bx")
   {
    digitalWrite(ledBlue,LOW);
   }
  myString="";
 }
 }
