#define IN1 2
#define IN2 3
#define IN3 4
#define IN4 5
#define S1 8
#define S2 9
#define S3 10
#define S4 11
#define LT 6
#define BT 7
void setup()
{
  for(int i=2;i<12;i++)
  {
    pinMode(i,OUTPUT);
  }
  digitalWrite(6,HIGH);
  digitalWrite(7,HIGH);
  Serial.begin(9600);
}
byte income=0;
void loop()
{
  if(Serial.available()>0)
  {
    for(unsigned i=0;i<4;i++)
    {
  	  income=Serial.read();
   	  digitalWrite(S1+i%4,LOW);
      digitalWrite(S1+(i+1)%4,HIGH);
      digitalWrite(S1+(i+2)%4,HIGH);
      digitalWrite(S1+(i+3)%4,HIGH);
      income=income-'0';
      digitalWrite(2,income&0x1);
      digitalWrite(3,(income>>1)&0x1);
      digitalWrite(4,(income>>2)&0x1);
      digitalWrite(5,(income>>3)&0x1);
      delay(10);
    }
  }
  
}