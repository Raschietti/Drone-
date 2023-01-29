/*!
 *  @file UART.cpp
 *
 * 	UART Functions encapsulation drivers
 *
 * 	Author: Giovanni Ferreira Raschietti
 *  Date: 29/01/2023
 *
 */

#include "UART.h"

void vFlushBuffer(char *buff);

void vInitUART(unsigned long br)
{
    Serial.begin(br);
}


void vUartWrite(const char *s)
{
    Serial.print(s);
}


void vUartRead(char *buffer)
{

    vFlushBuffer(buffer);
    int i = 0;

    while(Serial.available() > 0)
    {
        // Put data on buffer until new line is set
        while(buffer[i] != '\n' && i < MAX_BUFFER_LENGHT)
        {
            buffer[i] = Serial.read();
            i++;
        }

        buffer[i] = '\0';
    }
}

void vFlushBuffer(char *buff)
{
    for(int i=0; i<(strlen(buff)); i++) buff[i] = '\0';
}