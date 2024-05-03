/*****************************************************************************************
 * Author:				Abdullah M. Abdullah
 * Creation Data:		03 Jun, 2023
 * Version:				v1.0
 * Compiler:			GNU ARM-GCC
 * Controller:			STM32F401CCU6 (32-bit Architecture)
 * Processor:			Cortex M4 (32-bit Architecture)
 * Layer:				MCAL Layer
 *****************************************************************************************/
/*****************************************************************************************
 * Version	  Date				  Author				  Description
 * v1.0		  03 Jun, 2023	Abdullah M. Abdullah		  Initial Creation
*****************************************************************************************/
#ifndef USART_PRIVATE_H
#define USART_PRIVATE_H


typedef struct
{
    volatile u32 SR;
    volatile u32 DR;
    volatile u32 BRR;
    volatile u32 CR1;
    volatile u32 CR2;
    volatile u32 CR3;
    volatile u32 GTPR;

}USART_t;

#define         USART1              ((volatile USART_t *)0x40011000)


#endif
