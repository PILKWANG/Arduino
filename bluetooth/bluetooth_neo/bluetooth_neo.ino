#include <SoftwareSerial.h> //시리얼통신 라이브러리 호출
#include <Adafruit_NeoPixel.h>
#define BRIGHTNESS 200
#define PIN     6
#define NUMPIXELS  30
#define DELAYVAL 500
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int blueTx=3;   //Tx (보내는핀 설정)
int blueRx=2;   //Rx (받는핀 설정)
SoftwareSerial mySerial(blueTx, blueRx);  //시리얼 통신을 위한 객체선언
String myString="";

void setup() 
{
  Serial.begin(9600);
  mySerial.begin(9600); //블루투스 시리얼
  pixels.begin();
  pixels.setBrightness(BRIGHTNESS);
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
    pixels.clear();
    for(int i=0; i<NUMPIXELS; i++){
    pixels.setPixelColor(i, pixels.Color(255,0,0));
    pixels.show();
    delay(DELAYVAL);}
   }
   if(myString=="rx")
   {
    pixels.clear();
    for(int i=0; i<NUMPIXELS; i++){
    pixels.setPixelColor(i, pixels.Color(0,0,0));
    pixels.show();
    }}
    if(myString=="g")
   {
    pixels.clear();
    for(int i=0; i<NUMPIXELS; i++){
    pixels.setPixelColor(i, pixels.Color(0,255,0));
    pixels.show();
    delay(DELAYVAL);}
   }
   if(myString=="gx")
   {
    pixels.clear();
    for(int i=0; i<NUMPIXELS; i++){
    pixels.setPixelColor(i, pixels.Color(0,0,0));
    pixels.show();
    }}
    if(myString=="b")
   {
    pixels.clear();
    for(int i=0; i<NUMPIXELS; i++){
    pixels.setPixelColor(i, pixels.Color(0,0,255));
    pixels.show();
    delay(DELAYVAL);}
   }
   if(myString=="bx")
   {
    pixels.clear();
    for(int i=0; i<NUMPIXELS; i++){
    pixels.setPixelColor(i, pixels.Color(0,0,0));
    pixels.show();
    }} 
  myString="";
 }}
