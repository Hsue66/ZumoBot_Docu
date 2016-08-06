/**
 * @file    Motor.c
 * @brief   Basic methods for operating motor sensor
 * @details included in Zumo shield
*/

#include "Motor.h"

/**
* @brief    Starting motor sensors
* @details  
*/
void motor_Start()
{
    PWM_Start();
}


/**
* @brief    Stopping motor sensors
* @details
*/
void motor_Stop()
{
    PWM_Stop();
}

/**
* @brief    Moving motors forward
* @details  giveing same speed to each side of PWM to make motors go forward
*/
void motor_forward(uint8 speed,uint32 delay)
{
    PWM_WriteCompare1(speed); 
    PWM_WriteCompare2(speed); 
    CyDelay(delay);
}

/**
* @brief    Moving motors to make a turn 
* @details  moving left when l_speed < r_speed or moving right when l_speed > r_speed
*/
void motor_turn(uint8 l_speed, uint8 r_speed, uint32 delay)
{
    PWM_WriteCompare1(l_speed); 
    PWM_WriteCompare2(r_speed); 
    CyDelay(delay);
}


/**
* @brief    Moving motors backward
* @details  setting backward mode to each motors and gives same speed to each side of PWM
*/
void motor_backward(uint8 speed,uint32 delay)
{
    MotorDirLeft_Write(1);      // set LeftMotor backward mode
    MotorDirRight_Write(1);     // set RightMotor backward mode
    PWM_WriteCompare1(speed); 
    PWM_WriteCompare2(speed); 
    CyDelay(delay);
}
