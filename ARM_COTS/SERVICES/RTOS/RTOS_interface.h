/****************************************************************************************
* Author:				Abdullah M. Abdullah
* Creation Data:		18 May, 2024
* Version:				v1.0
* Compiler:				GNU ARM-GCC
* Controller:			STM32F401CCU6
* Layer:				SERVICE
****************************************************************************************/
/***************************************************************************************
* Version	  Date				  	Author				  			Description
* v1.0		  18 May, 2024			Abdullah M. Abdullah		  	Initial Creation
***************************************************************************************/
#ifndef RTOS_INTERFACE_H
#define RTOS_INTERFACE_H

void SRTOS_voidInit(void);
void SRTOS_voidCreateTask(u8 Copy_u8Priority, u32 Copy_u32Periodicity, void (*TaskFunction)(void));
void SRTOS_voidDeleteTask(u8 Copy_u8Priority);


#endif