/*********************************************
 * Author:				Abdullah M. Abdullah
 * Creation Data:		02 Mar, 2024
 * Version:				v1.0
 * Compiler:			GNU ARM-GCC
 * Controller:			STM32F401CCU6
 * Layer:				MCAL
 ********************************************/
/*********************************************
 * Version	  Date				  Author				  Description
 * v1.0		  02 Mar, 2024	Abdullah M. Abdullah		  Initial Creation
*********************************************/
#ifndef STK_PRIVATE_H
#define STK_PRIVATE_H

#define     STK_AHB         0
#define     STK_AHB_DIV_8   1
#define     STK_ENABLE      0
#define     STK_DISABLE     1

#define     SINGLE_INTERVAL     0
#define     PERIODIC_INTERVAL   1

typedef struct
{
    volatile u32 CTRL;
    volatile u32 LOAD;
    volatile u32 VAL;
    volatile u32 CALIB;
}STK_t;

#define     STK         ((volatile STK_t *)0xE000E010)


#endif