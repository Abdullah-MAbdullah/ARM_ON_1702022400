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
#ifndef STK_INTERFACE_H
#define STK_INTERFACE_H

void MSTK_voidInit(void);
void MSTK_voidSetBusyWait(u32 Copy_u32Ticks);

#endif