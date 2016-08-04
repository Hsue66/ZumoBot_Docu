/**
 * @file    I2C_made.c
 * @brief   I2C_made method file
 * @details 
*/

#include <I2C_made.h>

/**
* @brief    Write function of I2C communication
* @details  writing value to slave register by I2C communication
* @param    uint8 device_addr : Slave Device address
* @param    uint8 Reg : register address
* @param    uint8 value : value to write
*/
void I2C_write(uint8 device_addr, uint8 Reg, uint8 value)             // Gyroscope: you need to change the value of PD of CTRL1 register(20h) to power on 
{
    uint8 write_buf[2] = {};
    write_buf[0] = Reg;                //register address that you want to write
    write_buf[1] = value;                //value that you want to write to register
    
    I2C_MasterClearStatus();
    I2C_MasterWriteBuf(device_addr, write_buf, 2, I2C_MODE_COMPLETE_XFER);
    while(((I2C_MasterStatus()) & I2C_MSTAT_WR_CMPLT) == 0);
    
    return;
}

/**
* @brief    Read function of I2C communication
* @details  read value from slave register by I2C communication
* @param    uint8 device_addr : Slave Device address
* @param    uint8 Reg : register address
*/
uint8 I2C_read(uint8 device_addr, uint8 Reg) 
{
   
    uint8 write_buf[1] = {};
    write_buf[0] = Reg;
    
    uint8 read_buf[1] = {};
    
    I2C_MasterClearStatus();
    CyDelay(100);
    I2C_MasterWriteBuf(device_addr, write_buf, 1, I2C_MODE_COMPLETE_XFER);
    while((I2C_MasterStatus() & I2C_MSTAT_WR_CMPLT) == 0);
    CyDelay(50);
    I2C_MasterClearStatus();
    I2C_MasterReadBuf(device_addr, read_buf, 1, I2C_MODE_COMPLETE_XFER);
    while((I2C_MasterStatus() & I2C_MSTAT_RD_CMPLT) == 0);
   
    return read_buf[0];
}

/* [] END OF FILE */
