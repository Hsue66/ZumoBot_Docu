/**
 * @file    Ambient.h
 * @brief   Ambient light sensor header file
 * @details If you want to use Ambient light sensor methods, Include Ambient.h file.
*/
#include <math.h>

#define CH0_L           0x8C
#define CH0_H           0x8D
#define CH1_L           0x8E
#define CH1_H           0x8F

double getLux(double CH0, double CH1);
/* [] END OF FILE */
