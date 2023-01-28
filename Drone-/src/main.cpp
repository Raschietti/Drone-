#include <Arduino.h>
#include "E:\Projetos\Drone-\Drone-\src\Cfg\Defines.h"
#include "E:\Projetos\Drone-\Drone-\src\Drivers\GPIO.h"

void setup()
{
  vGpioInit();
}

void loop()
{
  vPinOn(LedPin);
  delay(250);
  vPinOff(LedPin);
  delay(250);
}