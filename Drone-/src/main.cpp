#include <Arduino.h>
#include "E:\Projetos\Drone-\Drone-\src\Cfg\Defines.h"
#include "E:\Projetos\Drone-\Drone-\src\Drivers\GPIO.h"
#include "E:\Projetos\Drone-\Drone-\src\Drivers\Sensors.h"
#include "E:\Projetos\Drone-\Drone-\src\Drivers\UART.h"


struct sAngle
{
  float pitch;
  float roll;
  char b[100];
};

char    received[MAX_BUFFER_LENGHT] = {'\0'}; 
//float   pitch=0.0;
//float   roll=0.0;

sAngle angle;

void setup()
{
  vGpioInit();   
  vInitUART(115200);
  if(!bSensorInit()) vUartWrite("Error on MPU  \n");
  else vUartWrite("Sensor conected!!! \n"); 
}

void loop()
{

  vCalculateAngle();
  delay(1);
  angle.pitch = fGetPitch();
  angle.roll  = fGetRoll();

  dtostrf(angle.pitch, 4, 4, angle.b);
  vUartWrite("Pitch: ");
  vUartWrite(angle.b);
  
  dtostrf(angle.roll, 4, 4, angle.b);
  vUartWrite(", Roll: ");
  vUartWrite(angle.b);
  vUartWrite("\n");
  //vUartRead(received);

  for(int i=0; i<255; i++)
  {
    vPwmSet(4, i);
    delay(1);
  }

  

  
}