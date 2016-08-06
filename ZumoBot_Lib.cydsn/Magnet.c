/**
 * @file    Magnet.c
 * @brief   Basic methods for operating magnetometer
 * @details part number: LSM303D (simultaneously used with accelerometer and included in Zumo shield)
*/


#include <project.h>
#include <math.h>
#include <stdio.h>
#include <accel_magnet.h>

/**
* @brief    Heading
* @details  
* @param    double X_AXIS : X axis value
* @param    double Y_AXIS : Y axis value
*/
void heading(double X_AXIS, double Y_AXIS)          // defined as the angle between X axis and Y axis measured in a clockwise direction when viewing from the top of the device = -Z
{
    double heading;
    heading = 180 * atan2 (X_AXIS, Y_AXIS) / M_PI;
    
    if(heading < 0)
        heading += 360;
    printf("heading: %7.3f \r\n", heading);
    CyDelay(250);
}


//uint16 value_convert_magnet(uint8 AXIS_H, uint8 AXIS_L)