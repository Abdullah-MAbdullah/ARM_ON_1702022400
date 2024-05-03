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
#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H

void MSPI1_voidInit(void);
u8 MSPI1_u8TrancieveSynchronous(u8 Copy_u8Data);

#endif