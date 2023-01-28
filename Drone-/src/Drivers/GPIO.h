/*!
 *  @file GPIO.h
 *
 * 	GPIO Functions encapsulation drivers
 *
 * 	Author: Giovanni Ferreira Raschietti
 *  Date: 28/01/2023
 *
 */

#ifndef _GPIO_H
#define _GPIO_H

#include <Arduino.h>
#include "E:\Projetos\Drone-\Drone-\src\Cfg\Defines.h"

void vGpioInit(void);

void vPinOn(char pin);
void vPinOff(char pin);
void vPwmSet(char mot, int dty);
void vPwmOff(char mot);

#endif