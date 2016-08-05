/**
 * @file    Ultra.c
 * @brief   Basic methods for operating ultrasonic sensor
 * @details part number: HC-SR04
*/

#include "Ultra.h"

uint16_t time = 0;
float distance = 0;
float cent = 0;

/**
* @brief    Systick Interrupt Handler
* @details  Counting system ticks to occur trigger
*/
int cnt=0;
CY_ISR(SYS_ISR)
{
    cnt++;
  
    if(cnt==1)
       Trig_Write(1);           // Trigger High
    else if(cnt==100)
        Trig_Write(0);           // Trigger Low
    else if(cnt==1100)
        cnt=0;  
}


/**
* @brief    Ultra Sonic Sensor Interrupt Handler
* @details  Measuring reflecting time to decide distance between Zumobot and obstacle
*/
CY_ISR(ultra_isr_handler)
{
    Timer_Stop();
    
    Timer_ReadStatusRegister();
    
    if(!Echo_Read()) {
        time = Timer_ReadCounter();             // Read counter value of Timer
        
        distance = (float)time / 58;            // us / 58 = centimeters
        cent = 5 * (distance - 16) / 4;         // calibration for this Timer(800 kHz)
        printf("i = %6d, distance = %4d                \r\n", time, (int)cent);
        Timer_WriteCounter(0xFFFF);             // Counter initialization
    }
    else {
         Timer_WriteCounter(0xFFFF);            // Counter initialization
    }
    Timer_Start();
}


/**
* @brief    Starting Ultra Sonic Sensor
* @details  
*/
void Ultra_Start()
{
    CyIntSetSysVector((SysTick_IRQn + 16), SYS_ISR);    // Map systick ISR to SYS_ISR
SysTick_Config(NUMBER_OF_TICKS);                    // Enable Systick Timer
    ultra_isr_StartEx(ultra_isr_handler);               // Start ultra sonic interrupt
    Timer_Start();                                      // Start Timer
}






