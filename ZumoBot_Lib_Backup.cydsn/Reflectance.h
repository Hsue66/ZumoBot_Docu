/**
 * @file    Reflectance.h
 * @brief   Reflectance header file
 * @details If you want to use Reflectance sensor methods, you need to include Reflectance.h file. 
*/
#include <stdio.h>
#include <project.h>


volatile struct sensors_ {
    uint16_t ll;
    //uint16_t lc; // not used at the moment
    uint16_t lr;
    uint16_t rl;
    //uint16_t rc; // not used at the moment
    uint16_t rr;
} sensors;

volatile struct digital_sensor_value_ {         //digital value for recognizing black or white
    uint16_t ll;
    //uint16_t lc; // not used at the moment
    uint16_t lr;
    uint16_t rl;
    //uint16_t rc; // not used at the moment
    uint16_t rr;
} digital_sensor_value;

void Refelctance_Start();
void reflectance_period();
void reflectance_digital();

CY_ISR_PROTO(sensor_isr_handler);

/* [] END OF FILE */
