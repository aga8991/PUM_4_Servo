#include "Servo.h"

Servo Sev1;
Servo Sev2;
Servo Sev3;
Servo Sev4;

void setup() 
{
  Sev1.attach(7);
  Sev2.attach(5);
  Sev3.attach(6);
  Sev4.attach(4);
}

void loop() 
{
  // put your main code here, to run repeatedly:

}

void move_CW(Servo sev, int deg)
{
  for(int i = sev.read(); i <= (sev.read()+deg); i++)
  {
    int j = 0;
    if(i < 360) j = i;
    else 
    {
      int x = i/360;
      j = i - (x*360);
    }
    sev.write(j);
    delay(10);
  }
}

void move_CCW(Servo sev, int deg)
{
    for(int i = sev.read(); i >= (sev.read()-deg); i--)
  {
    int j = 0;
    if(i >= 0) j = i;
    else 
    {
      int x = i/360;
      j = i + (x*360);
      j = 360 + j;
    }
    sev.write(j);
    delay(10);
  }
}

void stand_straight()
{
  Sev1.write(315);
  Sev2.write(45);
  Sev3.write(45);
  Sev4.write(315);
}
