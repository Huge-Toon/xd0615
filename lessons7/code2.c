#define IN1 7
#define IN2 4
#define IN3 5
#define IN4 6
#define pinInterrupt 2
#include <MsTimer2.h>
class Digitron
{
  public:
	void print(int num);
  	void begin();
  	Digitron(int in1,int in2,int in3,int in4);
  	Digitron(int in1,int in2,int in3,int in4,int sP);
  private:
  	int inPin1;
  	int inPin2;
  	int inPin3;
  	int inPin4;
  	int selectPin;
};
Digitron::Digitron(int in1,int in2,int in3,int in4)
{
  inPin1=in1;
  inPin2=in2;
  inPin3=in3;
  inPin4=in4;
  selectPin=-1;
}
Digitron::Digitron(int in1,int in2,int in3,int in4,int sP)
{
  inPin1=in1;
  inPin2=in2;
  inPin3=in3;
  inPin4=in4;
  selectPin=sP;
}
void Digitron::print(int num)
{
  digitalWrite(inPin1,num&0x1);
  digitalWrite(inPin2,(num>>1)&0x1);
  digitalWrite(inPin3,(num>>2)&0x1);
  digitalWrite(inPin4,(num>>3)&0x1);
}
void Digitron::begin()
{
  pinMode(inPin1,OUTPUT);
  pinMode(inPin2,OUTPUT);
  pinMode(inPin3,OUTPUT);
  pinMode(inPin4,OUTPUT);
}

unsigned count=0;
Digitron digitron0(IN1,IN2,IN3,IN4);

void setZero()
{
   count=0;
}
void countNum()
{
  digitron0.print(count);
  count++;
  count%=10;  
}
     
 
void setup()
{
   Serial.begin(9600); 
 
   pinMode(pinInterrupt, INPUT);
  
   MsTimer2::set(1000,countNum);
   MsTimer2::start();
  
   attachInterrupt( digitalPinToInterrupt(pinInterrupt), setZero, CHANGE);
}
 
void loop()
{
  //do something 
  for (int i = 0; i < 100; i++)
  {
    delay(10); 
  }
}