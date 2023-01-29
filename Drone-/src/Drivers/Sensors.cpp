/*!
 *  @file Sensors.cpp
 *
 * 	Sensors Functions encapsulation drivers
 *
 * 	Author: Giovanni Ferreira Raschietti
 *  Date: 28/01/2023
 *
 */

#include "Sensors.h"

Adafruit_MPU6050 mpu;
sensors_event_t a, g, temp;

void vReadData();
void vCalibSensor(unsigned int res);


float   Calib[3] = {0};
long    acc_total_vector;
float   angle_pitch, angle_roll;
int     angle_pitch_buffer, angle_roll_buffer;
boolean set_gyro_angles=false;
float   angle_roll_acc, angle_pitch_acc;

bool bSensorInit(void)
{
    if(!mpu.begin())
    {
        return false;
        while(1){
            //TODO Sensor error treatment
            delay(10);
        }
    }

    mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
    mpu.setGyroRange(MPU6050_RANGE_500_DEG);
    mpu.setFilterBandwidth(MPU6050_BAND_5_HZ);

    vCalibSensor(500);

    return true;
}

void vCalibSensor(unsigned int res)
{ 
    for(int cal=0; cal<res; cal++)
    {
        vReadData();
        Calib[0] += g.gyro.x;
        Calib[1] += g.gyro.y;
        Calib[2] += g.gyro.z; 
        delay(3);
    }

    for(int i=0; i<3; i++) Calib[i] /= (float)res;
}

void vReadData()
{
    mpu.getEvent(&a, &g, &temp);
}

void vCalculateAngle()
{
    vReadData();

    g.gyro.x -= Calib[0];
    g.gyro.y -= Calib[1];
    g.gyro.z -= Calib[2];

 /* ====== Calculo de angulo ====== */

    // 0.0000611 = 1 / (250Hz / 65.5 )
    angle_pitch += g.gyro.x * 61.1e-6;
    angle_roll  += g.gyro.y * 61.1e-6;

    //0.000001066 = 0.0000611 * (3.142(PI) / 180degr) The Arduino sin function esta em radianos
    angle_pitch += angle_roll  * sin(g.gyro.z * 1.066e-6);
    angle_roll  -= angle_pitch * sin(g.gyro.z * 1.066e-6);
    
    acc_total_vector = sqrt((g.acceleration.x*g.acceleration.x) + (g.acceleration.y*g.acceleration.y) + (g.acceleration.z*g.acceleration.z));

    //57.296 = 1 / (3.142 / 180) The Arduino asin function esta em radianos
    angle_pitch_acc = asin((float)g.acceleration.y/acc_total_vector) * 57.296;
    angle_roll_acc  = asin((float)g.acceleration.x/acc_total_vector) * -57.296;

    //Place the MPU-6050 spirit level and note the values in the following two lines for calibration
    angle_pitch_acc -= 0.0;                                              //Accelerometer calibration value for pitch
    angle_roll_acc -= 0.0;                                               //Accelerometer calibration value for roll

    if(set_gyro_angles){                                                 //If the IMU is already started
    angle_pitch = angle_pitch * 0.9996 + angle_pitch_acc * 0.0004;       //Correct the drift of the gyro pitch angle with the accelerometer pitch angle
    angle_roll = angle_roll * 0.9996 + angle_roll_acc * 0.0004;          //Correct the drift of the gyro roll angle with the accelerometer roll angle
    }
    else{                                                                //At first start
    angle_pitch = angle_pitch_acc;                                       //Set the gyro pitch angle equal to the accelerometer pitch angle 
    angle_roll = angle_roll_acc;                                         //Set the gyro roll angle equal to the accelerometer roll angle 
    set_gyro_angles = true;                                              //Set the IMU started flag
    }

}

float fGetPitch()
{
    return angle_pitch;
}

float fGetRoll()
{
    return angle_roll;
}