/**
 * @file    Ultra.h
 * @brief   Ultra header file
 * @details If you want to use Ultra sonic sensor methods, Include Ultra.h file.
*/

#include <project.h>
#include <stdio.h>
#include <Timer.h>

CY_ISR_PROTO(ultra_isr_handler);

void Ultra_Start();

/* [] END OF FILE */
