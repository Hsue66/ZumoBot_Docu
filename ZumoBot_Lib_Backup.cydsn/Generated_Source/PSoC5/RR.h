/*******************************************************************************
* File Name: RR.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_RR_H) /* Pins RR_H */
#define CY_PINS_RR_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "RR_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 RR__PORT == 15 && ((RR__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    RR_Write(uint8 value);
void    RR_SetDriveMode(uint8 mode);
uint8   RR_ReadDataReg(void);
uint8   RR_Read(void);
void    RR_SetInterruptMode(uint16 position, uint16 mode);
uint8   RR_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the RR_SetDriveMode() function.
     *  @{
     */
        #define RR_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define RR_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define RR_DM_RES_UP          PIN_DM_RES_UP
        #define RR_DM_RES_DWN         PIN_DM_RES_DWN
        #define RR_DM_OD_LO           PIN_DM_OD_LO
        #define RR_DM_OD_HI           PIN_DM_OD_HI
        #define RR_DM_STRONG          PIN_DM_STRONG
        #define RR_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define RR_MASK               RR__MASK
#define RR_SHIFT              RR__SHIFT
#define RR_WIDTH              1u

/* Interrupt constants */
#if defined(RR__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in RR_SetInterruptMode() function.
     *  @{
     */
        #define RR_INTR_NONE      (uint16)(0x0000u)
        #define RR_INTR_RISING    (uint16)(0x0001u)
        #define RR_INTR_FALLING   (uint16)(0x0002u)
        #define RR_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define RR_INTR_MASK      (0x01u) 
#endif /* (RR__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define RR_PS                     (* (reg8 *) RR__PS)
/* Data Register */
#define RR_DR                     (* (reg8 *) RR__DR)
/* Port Number */
#define RR_PRT_NUM                (* (reg8 *) RR__PRT) 
/* Connect to Analog Globals */                                                  
#define RR_AG                     (* (reg8 *) RR__AG)                       
/* Analog MUX bux enable */
#define RR_AMUX                   (* (reg8 *) RR__AMUX) 
/* Bidirectional Enable */                                                        
#define RR_BIE                    (* (reg8 *) RR__BIE)
/* Bit-mask for Aliased Register Access */
#define RR_BIT_MASK               (* (reg8 *) RR__BIT_MASK)
/* Bypass Enable */
#define RR_BYP                    (* (reg8 *) RR__BYP)
/* Port wide control signals */                                                   
#define RR_CTL                    (* (reg8 *) RR__CTL)
/* Drive Modes */
#define RR_DM0                    (* (reg8 *) RR__DM0) 
#define RR_DM1                    (* (reg8 *) RR__DM1)
#define RR_DM2                    (* (reg8 *) RR__DM2) 
/* Input Buffer Disable Override */
#define RR_INP_DIS                (* (reg8 *) RR__INP_DIS)
/* LCD Common or Segment Drive */
#define RR_LCD_COM_SEG            (* (reg8 *) RR__LCD_COM_SEG)
/* Enable Segment LCD */
#define RR_LCD_EN                 (* (reg8 *) RR__LCD_EN)
/* Slew Rate Control */
#define RR_SLW                    (* (reg8 *) RR__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define RR_PRTDSI__CAPS_SEL       (* (reg8 *) RR__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define RR_PRTDSI__DBL_SYNC_IN    (* (reg8 *) RR__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define RR_PRTDSI__OE_SEL0        (* (reg8 *) RR__PRTDSI__OE_SEL0) 
#define RR_PRTDSI__OE_SEL1        (* (reg8 *) RR__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define RR_PRTDSI__OUT_SEL0       (* (reg8 *) RR__PRTDSI__OUT_SEL0) 
#define RR_PRTDSI__OUT_SEL1       (* (reg8 *) RR__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define RR_PRTDSI__SYNC_OUT       (* (reg8 *) RR__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(RR__SIO_CFG)
    #define RR_SIO_HYST_EN        (* (reg8 *) RR__SIO_HYST_EN)
    #define RR_SIO_REG_HIFREQ     (* (reg8 *) RR__SIO_REG_HIFREQ)
    #define RR_SIO_CFG            (* (reg8 *) RR__SIO_CFG)
    #define RR_SIO_DIFF           (* (reg8 *) RR__SIO_DIFF)
#endif /* (RR__SIO_CFG) */

/* Interrupt Registers */
#if defined(RR__INTSTAT)
    #define RR_INTSTAT            (* (reg8 *) RR__INTSTAT)
    #define RR_SNAP               (* (reg8 *) RR__SNAP)
    
	#define RR_0_INTTYPE_REG 		(* (reg8 *) RR__0__INTTYPE)
#endif /* (RR__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_RR_H */


/* [] END OF FILE */
