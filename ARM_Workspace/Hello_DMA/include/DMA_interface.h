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
#ifndef DMA_INTERFACE_H
#define DMA_INTERFACE_H

void MDMA1_voidInit(void);
void MDMA1_voidStartTransfer(u32 * Copy_pu32SourceAddress, u32 * Copy_pu32DestinationAddress, u16 Copy_u16BlockSize);

// MUST BE PRIVATE FUNCTION
void MDMA1_voidClearAllFlags(void);

#endif