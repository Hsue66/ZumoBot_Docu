/**
 * @file    Gyro.c
 * @brief   Gyroscope method file
 * @details 
*/


#include <project.h>
#include <math.h>
#include <stdio.h>
#include <gyro.h>


uint16 value_convert_gyro(uint16 raw)            // ****THING TO DO : converting to angle!!!****
{
    float rate_result;
    float angle_result = 0.0;
    float G_GAIN = 0.07;        //FS = 2000 dps
    float DT = 0.02;           // by logic analyzer
    
  
    rate_result = (float)raw * G_GAIN;          // degrees per second for Gyroscope
    angle_result += rate_result * DT;
    
    return angle_result;
}


/* [] END OF FILE */

