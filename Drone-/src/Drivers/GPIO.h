#include <Arduino.h>
#include "E:\Projetos\Drone-\Drone-\src\Cfg\Defines.h"

void vGpioInit(void);

void vPinOn(char pin);
void vPinOff(char pin);
void vPwmSet(char mot, int dty);
void vPwmOff(char mot);

