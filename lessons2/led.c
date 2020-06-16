void setup()
{
  for(int i=0;i<6;i++)
  {
   	pinMode(i, OUTPUT);
    digitalWrite(i,HIGH);
  }
}

void loop()
{
  for(int i=0;i<6;i++)
  {
    digitalWrite(i, LOW);
  	delay(250); // Wait for 20 millisecond(s)
  	digitalWrite(i, HIGH);
  	delay(250); // Wait for 20 millisecond(s)
  }
}