/**
 * @file    Ultra.h
 * @brief   Ultra sonic sensor header file
 * @details If you want to use Ultra sonic sensor methods, you need to include Ultra.h file. Declaring sensor interrupt for measuring ultra sonic outputs.
*/
#include <project.h>
#include <stdio.h>
#include <Timer.h>

#define NUMBER_OF_TICKS		 2400


CY_ISR_PROTO(ultra_isr_handler);
CY_ISR_PROTO(SYS_ISR);
void Ultra_Start();
