/****************************************************************************************
* Author:				Abdullah M. Abdullah
* Creation Data:		20 Apr, 2024
* Version:				v1.0
* Compiler:				GNU ARM-GCC
* Controller:			STM32F401CCU6
* Layer:				MCAL
****************************************************************************************/
/***************************************************************************************
* Version	  Date				  	Author				  			Description
* v1.0		  20 Apr, 2024			Abdullah M. Abdullah		  	Initial Creation
***************************************************************************************/
#ifndef DMA_PIRVATE_H
#define DMA_PIRVATE_H

typedef struct
{
    volatile u32 SCR;
    volatile u32 SNDTR;
    volatile u32 SPAR;
    volatile u32 SM0AR;
    volatile u32 SM1AR;
    volatile u32 SFCR;
}DMA_CHANNEL_t;

typedef struct
{
    volatile u32        LISR;
    volatile u32        HISR;
    volatile u32        LIFCR;
    volatile u32        HIFCR;
    DMA_CHANNEL_t       Channel[8];
}DMA_t;

#define         MDMA1            ((volatile DMA_t *)0x40026000)
#define         MDMA2            ((volatile DMA_t *)0x40026400)

#endif
