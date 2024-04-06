/****************************************************************************************
* Author:				Abdullah M. Abdullah
* Creation Data:		06 Apr, 2024
* Version:				v1.0
* Compiler:				GNU ARM-GCC
* Controller:			STM32F401CCU6
* Layer:				MCAL
****************************************************************************************/
/***************************************************************************************
* Version	  Date				  	Author				  			Description
* v1.0		  06 Apr, 2024			Abdullah M. Abdullah		  	Initial Creation
***************************************************************************************/
#include "../include/STD_TYPES.h"
#include "../include/BIT_MATH.h"

#include "../include/SPI_interface.h"
#include "../include/SPI_private.h"
#include "../include/SPI_config.h"

// Pre-build configuration (Task)
void MSPI1_voidInit(void)
{
    /*Setup GPIO Pins (delayed)*/
}

u8 MSPI1_u8TrancieveSynchronous(u8 Copy_u8Data)
{
    u8 Local_u8ReceivedData;
    MSPI1 -> DR = Copy_u8Data;
    while(GET_BIT(MSPI1 -> SR, 7));        // while(GET_BIT(MSPI1 -> SR, 7) == 1);
    Local_u8ReceivedData = MSPI1 -> DR;
    return Local_u8ReceivedData;
}

/*
* Tasks:
*       - Complete Init function 
*       - Implement ISR of SPI1, SPI2, SPI3, and SPI4
*       - Implement Callbacks
*/