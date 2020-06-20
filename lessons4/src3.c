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
  pinMode(IN1, OUTPUT);//输入1
  pinMode(IN2, OUTPUT);//输入2
  pinMode(IN3, OUTPUT);//输入3
  pinMode(IN4, OUTPUT);//输入4
  pinMode(S1, OUTPUT);//片选1
  pinMode(S2, OUTPUT);//片选2
  pinMode(S3, OUTPUT);//片选3
  pinMode(S4, OUTPUT);//片选4
  
  pinMode(LT,OUTPUT);//测试
  pinMode(BT,OUTPUT);//消隐
  
  digitalWrite(LT,HIGH);
  digitalWrite(BT,HIGH);
  Serial.begin(9600);
  while(Serial.read()>=0){}//clear serial buffer
  Serial.println("init succeed!");
}

char nums[50]={'\0'};
String temp;
unsigned offset=0;
void loop()
{
  if(Serial.available()>0)
  {
    Serial.readString().toCharArray(nums,50);
  }
  if(strlen(nums))
  {
    offset%=strlen(nums);
    for(unsigned i=0;i<4;i++)
    {
   	  digitalWrite(S1+i%4,LOW);
      digitalWrite(S1+(i+1)%4,HIGH);
      digitalWrite(S1+(i+2)%4,HIGH);
      digitalWrite(S1+(i+3)%4,HIGH);
      byte bNum=nums[(i+offset)%strlen(nums)]-'0';
      digitalWrite(2,bNum&0x1);
      digitalWrite(3,(bNum>>1)&0x1);
      digitalWrite(4,(bNum>>2)&0x1);
      digitalWrite(5,(bNum>>3)&0x1);
      //delay(10);
    }
    delay(500);
    offset++;
  }
}


