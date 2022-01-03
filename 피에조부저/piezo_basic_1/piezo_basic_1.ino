int piezo = 3;

void setup() {
  
pinMode(piezo, OUTPUT);
}
 
void loop() {
   tone(piezo,261,500);
   delay(500);
}
