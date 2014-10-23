#include <Servo.h> 

int data[3], v[2];
int i=0, j=0, n=0, prov=320, num, plus=320, plus1=240, aum=45, aum1=45;
char c;
Servo servo1;
Servo servo2;

void setup()
{
  servo1.attach(2); 
  servo2.attach(3);  
  Serial.begin(115200);
}

void loop()
{  
  //Read Serial bus data received from Python and write them into servo position
  if(Serial.available())
  {
    prov=Serial.read()-48;
    if(prov!=72)
    {
      data[i]=prov;
      i++;
    }
    else
    {
      if(i==0)
        num=0;
      if(i==1)
        num=data[0];
      if(i==2)
        num=data[1]+data[0]*10;
      if(i==3)
        num=data[2]+data[1]*10+data[0]*100;
      i=0;
      v[n]=num;
      n++;
      if(n==2)
      {
        //Start X axis
        while(plus>0)
        {
          if((v[0]<=plus) && (v[0]>(plus-10)))
          {
            servo1.write(aum-5);
            delay(15);
            plus=0;
          }
          else
          {
            plus=plus-10;
            aum=aum+3;
          }
        }
        plus=320;
        aum=45;
        //Start Y axis
        while(plus1>0)
        {
          if((v[1]<=plus1) && (v[1]>(plus1-10)))
          {
            servo2.write(aum1);
            delay(15);
            plus1=0;
          }
          else
          {
            plus1=plus1-10;
            aum1=aum1+3;
          }
        }
        plus1=240;
        aum1=45;
        n=0;
      }
    }
  }
}
