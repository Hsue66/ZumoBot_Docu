/**
 * @file    Ultra.c
 * @brief   Ultra sonic sensor method file
 * @details 
*/

#include "Ultra.h"

uint16_t i = 0;
float distance = 0;
float cent = 0;

/**
* @brief    Ultra Sonic Sensor Interrupt Handler
* @details  measure reflecting time to decide distance between Zumobot and obstacle
*/
CY_ISR(ultra_isr_handler)
{
    Timer_Stop();
    
    Timer_ReadStatusRegister();
    
    if(!Echo_Read()) {
        i = Timer_ReadCounter();            // Read counter value of Timer
        distance = (float)i / 58;           // us / 58 = centimeters
        cent = 5 * (distance - 11) / 3;     // calibration for this Timer(650 kHz)
        printf("i = %6d, distance = %4d                \r\n", i, (int)cent);
        Timer_WriteCounter(0xFFFF);         // Counter initialization
    }
    else {
        
         Timer_WriteCounter(0xFFFF);
    }
    Timer_Start();
}

/**
* @brief    Start Ultra Sonic Sensor
* @details  
*/
void Ultra_Start()
{
    Timer_Start();
}

/* [] END OF FILE */
