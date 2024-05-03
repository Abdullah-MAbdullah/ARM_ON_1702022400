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
#include "../include/STD_TYPES.h"
#include "../include/BIT_MATH.h"

#include "../include/DMA_interface.h"
#include "../include/DMA_private.h"
#include "../include/DMA_config.h"

void MDMA1_voidInit(void)
{
    MDMA1->Channel[0].SCR = 0x35694;
}

void MDMA1_voidStartTransfer(   u32 * Copy_pu32SourceAddress, 
                                u32 * Copy_pu32DestinationAddress,
                                u16 Copy_u16BlockSize
                            )
{
    /*Make Sure that DMA Channel is Disabled*/
    CLR_BIT(DMA1->Channel[0].SCR, 0);
    /*Load The Source Address*/
    DMA1->Channel[0].SPAR = Copy_pu32SourceAddress;
    /*Load The Destination Address*/
    DMA1->Channel[0].SM0AR = Copy_pu32DestinationAddress;
    /*Set the Block Size*/
    DMA1->Channel[0].SNDTR = Copy_u16BlockSize;
    /*Enable The DMA Channel*/
    SET_BIT(DMA1->Channel[0].SCR, 0);
}

// MUST BE PRIVATE FUNCTION
void MDMA1_voidClearAllFlags(void)
{
    SET_BIT(DMA1 -> LIFCR, 0);
    SET_BIT(DMA1 -> LIFCR, 2);
    SET_BIT(DMA1 -> LIFCR, 3);
    SET_BIT(DMA1 -> LIFCR, 4);
    SET_BIT(DMA1 -> LIFCR, 5);
}



// ISR SHOULD BE IMPLEMENTED HERE + SETCALLBACK
