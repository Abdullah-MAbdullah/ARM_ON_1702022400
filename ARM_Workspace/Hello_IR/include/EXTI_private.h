/*********************************************
 * Author:				Abdullah M. Abdullah
 * Creation Data:		29 Mar, 2024
 * Version:				v1.0
 * Compiler:			GNU ARM-GCC
 * Controller:			STM32F401CCU6
 * Layer:				MCAL
 ********************************************/
/*********************************************
 * Version	  Date				  Author				  Description
 * v1.0		  29 Mar, 2024	Abdullah M. Abdullah		  Initial Creation
*********************************************/
#ifndef EXTI_PRIVATE_H
#define EXTI_PRIVATE_H

// 0x40013C00
typedef struct
{
    volatile u32 IMR;
    volatile u32 EMR;
    volatile u32 RTSR;
    volatile u32 FTSR;
    volatile u32 SWIER;
    volatile u32 PR;
}EXTI_t;

#define     EXTI                     ((volatile EXTI_t *)0x40013C00)
#define     SYSCFG_EXTICR1          *((volatile u32 *)(0x40013800+0x08))

#endif