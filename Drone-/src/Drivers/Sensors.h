/*!
 *  @file Sensors.h
 *
 * 	Sensors Functions encapsulation drivers
 *
 * 	Author: Giovanni Ferreira Raschietti
 *  Date: 28/01/2023
 *
 *  I2C Standard Pinout -> SDA = 21; SCL = 22
 */

#ifndef _SENSORS_H
#define _SENSORS_H

#include <Arduino.h>
#include "E:\Projetos\Drone-\Drone-\src\Cfg\Defines.h"
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>

bool bSensorInit(void);
float fGetPitch();
float fGetRoll();
void vCalculateAngle();

#endif