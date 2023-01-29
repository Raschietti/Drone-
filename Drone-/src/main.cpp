#include <Arduino.h>
#include "E:\Projetos\Drone-\Drone-\src\Cfg\Defines.h"
#include "E:\Projetos\Drone-\Drone-\src\Drivers\GPIO.h"
#include "E:\Projetos\Drone-\Drone-\src\Drivers\Sensors.h"
#include "E:\Projetos\Drone-\Drone-\src\Drivers\UART.h"

char received[MAX_BUFFER_LENGHT] = {'\0'}; 

void setup()
{
  vGpioInit();   
  vInitUART(115200);    
}

void loop()
{
  vUartWrite("Mother Gaia Help Us");
  vUartRead(received);

  for(int i=0; i<255; i++)
  {
    vPwmSet(4, i);
    delay(10);
  }

  vUartWrite("I received:");
  vUartWrite(received);
}