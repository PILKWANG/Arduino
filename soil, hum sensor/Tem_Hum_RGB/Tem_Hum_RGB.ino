#include "DHT.h"
#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
int  R = 9;
int  G = 10;
int  B = 11;

void setup() {
  Serial.begin(9600);
  dht.begin();
  pinMode(R, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(B, OUTPUT);
}

void loop() {
  delay(500);
  int h = dht.readHumidity();
  int t = dht.readTemperature();
  Serial.print("Humidity: ");
  Serial.println(h);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.println(" ºC");

  if (t > 30){
    analogWrite(R, 255);
    analogWrite(G, 100);
    analogWrite(B, 10);
  }
  else
  {
    analogWrite(R, 10);
    analogWrite(G, 100);
    analogWrite(B, 255); 
  }}
