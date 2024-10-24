#define SensorPin 0
#define OFFSET 0.00

unsigned long int avgValue;
int buf[10], temp;

int count=0;

void setup() {
 Serial.begin(9600);
 Serial.println("CLEARDATA");
 Serial.println("LABEL, TIME, count, pH");
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
  count ++;      
  avgValue=0;
  for(int i=2;i<8;i++)
    avgValue+=buf[i];
  float pHvalue=(float)avgValue*5.0/1024/6;
  pHvalue=3.5*pHvalue+OFFSET;  
  Serial.print("DATA, TIME, ");
  Serial.print(count*1);
  Serial.print(",");
  Serial.println(pHvalue);
  delay(500);
}