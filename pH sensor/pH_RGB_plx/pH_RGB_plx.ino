#define SensorPin 0
#define OFFSET 0.10
#define DELAYVAL 300
int count=0;
int  R = 9;
int  G = 10;
int  B = 11;

unsigned long int avgValue;
int buf[10], temp;

void setup() {
 Serial.begin(9600);
 Serial.println("CLEARDATA");
 Serial.println("LABEL, TIME, time, pH");
 pinMode(R, OUTPUT);
 pinMode(G, OUTPUT);
 pinMode(B, OUTPUT);
 }

void loop() {
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
      }}}      
  avgValue=0;
  for(int i=2;i<8;i++)
    avgValue+=buf[i];
  float pHvalue=(float)avgValue*5.0/1024/6;
  pHvalue=3.5*pHvalue+OFFSET;  
  count ++;
  Serial.print("DATA, TIME, ");
  Serial.print(count*DELAYVAL/1000);
  Serial.print(",");
  Serial.println(pHvalue);
  delay(DELAYVAL);
  
  if (pHvalue < 6.0){
    analogWrite(R, 255);
    analogWrite(G, 255);
    analogWrite(B, 0);
  }
  else if (pHvalue > 7.5){
    analogWrite(R, 0);
    analogWrite(G, 255);
    analogWrite(B, 0);
  else
  {
    analogWrite(R, 0);
    analogWrite(G, 0);
    analogWrite(B, 255); 
  }}
