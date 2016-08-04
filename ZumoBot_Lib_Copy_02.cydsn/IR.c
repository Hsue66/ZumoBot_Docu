/**
 * @file IR.c
 * @brief IR receiver method file
 * @details 
*/
#include "IR.h"


/**
* @brief wait until signal goes up
* @details continue looping before IR_receiver value becomes 1
*/
void wait_going_up()
{
    while(!IR_receiver_Read()==1);
}    


/**
* @brief wait until signal goes down
* @details continue looping before IR_receiver value becomes 0
*/
void wait_going_down()
{
    while(IR_receiver_Read()==1);
}


/**
* @brief count signal down time
* @details count time until IR_receiver value goes up
* @return int
*   - returns count time
*/
int count_downtime()
{
    int cnt =0;
    while(!IR_receiver_Read()==1)
        cnt++;
    
    return cnt;
}


/**
* @brief    count signal up time
* @details  count time until IR_receiver value goes down
* @return   int
*   - returns count time
*/
int count_uptime()
{
    int cnt =0;
    while(IR_receiver_Read()==1)
        cnt++;
    
    return cnt;
}


/**
* @brief    get Remote Controller Value
* @details  get each of the value sended by Remote Controller
* @return   int
    - returns hex value
*/
int get_IR()
{
    uint8 bit[33]={0};
    unsigned int val=0;
    uint i;
    
    wait_going_down();
    printf("START \r\n");
    
    for(i = 0; i < 33; i++)     // loop 33times ( 1bit - Start bit, 32bits - Databit)
    {
        int t1, t2;
        t1 = 0;
        t2 = 0;
        
        t1 = count_downtime();
        t2 = count_uptime();
        
        // If up time is longer than down time, value of the bit becomes 1
        if(t2 > t1)
            bit[i]=1;
        else
            bit[i]=0; 
    } 
   
    /* // If you want to see binary value
    int cnt;
    for(cnt=0; cnt<33; cnt++)
    {
        printf("%d ",bit[cnt]);
    }
    printf("\r\n\n");
    */
   
    // make binary value to hex value
    for( i=0; i<32; i++)
        val += bit[i+1]*pow(2,i);
    
    return val;
}

/* [] END OF FILE */
