char ch='\0';
void setup()
{
	Serial.begin(9600);
	for(int i=2;i<8;i++)
    {
  	    pinMode(i,OUTPUT);
    }
    digitalWrite(6,HIGH);
    digitalWrite(7,HIGH);
    Serial.println("init succeed!");
}

/*
'f':move forward
'b':move backward
'r':turn right
'l':turn left
's':stop
*/
void loop()
{
    if(Serial.available()>0)
    {
  	    ch=Serial.read();
        switch(ch)
        {
            case 'f':
                digitalWrite(2,HIGH);
                digitalWrite(3,LOW);
                digitalWrite(4,HIGH);
                digitalWrite(5,LOW);
                break;
            case 'b':
                digitalWrite(3,HIGH);
                digitalWrite(2,LOW);
                digitalWrite(5,HIGH);
                digitalWrite(4,LOW);
                break;
            case 'r':
                digitalWrite(3,HIGH);
                digitalWrite(2,LOW);
                digitalWrite(4,HIGH);
                digitalWrite(5,LOW);
                break;
            case 'l':
                digitalWrite(2,HIGH);
                digitalWrite(3,LOW);
                digitalWrite(5,HIGH);
                digitalWrite(4,LOW);
                break;
            case 's':
                digitalWrite(2,LOW);
                digitalWrite(3,LOW);
                digitalWrite(4,LOW);
                digitalWrite(5,LOW);
                break;
            default:
                break;
        }
    }
}