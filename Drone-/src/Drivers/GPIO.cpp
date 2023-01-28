#include "E:\Projetos\Drone-\Drone-\src\Drivers\GPIO.h"


void vPinOn(char pin)
{
    digitalWrite(pin, HIGH);
}

void vPinOff(char pin)
{
    digitalWrite(pin, LOW);
}

void vGpioInit()
{
    pinMode(LedPin, OUTPUT);
    for(int i=0; i<4; i++) ledcSetup(i, freq, resolution);
    ledcAttachPin(m0, 0);
    ledcAttachPin(m1, 1);
    ledcAttachPin(m2, 2);
    ledcAttachPin(m3, 3);
}

void vPwmSet(char mot, int dty)
{
    if(mot <= 3 && mot > 0)
    {
        ledcWrite(mot+1, dty);
    }  
    else
    {
        //TODO error treatment
    }
}

void vPwmOff(char mot)
{
    if(mot <= 3 && mot > 0)
    {
        ledcWrite(mot, 0);
    }
    else
    {
        //TODO error treatment
    }
}