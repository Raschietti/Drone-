/*!
 *  @file UART.h
 *
 * 	UART Functions encapsulation drivers
 *
 * 	Author: Giovanni Ferreira Raschietti
 *  Date: 29/01/2023
 *
 */

#ifndef _UART_H
#define _UART_H

#include <Arduino.h>
#include "E:\Projetos\Drone-\Drone-\src\Cfg\Defines.h"

void vInitUART(unsigned long baudrate);
void vUartWrite(const char *s);
void vUartRead(char *buffer);

#endif