/**
 * @file    Motor.c
 * @brief   Motor method file
 * @details 
*/

#include "Motor.h"

/**
* @brief    Start motors
* @details
*/
void motor_Start()
{
    PWM_Start();
}


/**
* @brief    Stop motors
* @details
*/
void motor_Stop()
{
    PWM_Stop();
}

/**
* @brief    Move motors forward
* @details  gives same speed to PWM make motor goes forward
*/
void motor_forward(uint8 speed,uint32 delay)
{
    PWM_WriteCompare1(speed); 
    PWM_WriteCompare2(speed); 
    CyDelay(delay);
}

/**
* @brief    Move motors turn around
* @details  moving left when l_speed < r_speed or moving right when l_speed > r_speed
*/
void motor_turn(uint8 l_speed, uint8 r_speed, uint32 delay)
{
    PWM_WriteCompare1(l_speed); 
    PWM_WriteCompare2(r_speed); 
    CyDelay(delay);
}


/**
* @brief    Move motors backward
* @details  set backward mode to each motors and gives same speed to PWM
*/
void motor_backward(uint8 speed,uint32 delay)
{
    MotorDirLeft_Write(1);      // set LeftMotor backward mode
    MotorDirRight_Write(1);     // set RightMotor backward mode
    PWM_WriteCompare1(speed); 
    PWM_WriteCompare2(speed); 
    CyDelay(delay);
}
/* [] END OF FILE */
