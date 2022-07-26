#include "DHT.h"
#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
int count=0;

void setup() {
  Serial.begin(9600);
  dht.begin();
  Serial.println("CLEARDATA");
  Serial.println("LABEL, TIME, time, Humidity, temperature");
}
void loop() {
  int h = dht.readHumidity();
  int t = dht.readTemperature();
  count ++;
  Serial.print("DATA, TIME, ");
  Serial.print(count*1);
  Serial.print(",");
  Serial.print(h);
  Serial.print(",");
  Serial.println(t);
  delay(1000);
}
