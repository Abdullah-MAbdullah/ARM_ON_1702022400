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
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"

#include "USART_interface.h"
#include "USART_private.h"
#include "USART_config.h"

void MUSART1_voidInit(void)
{
    MGPIO_voidSetPinMode(MGPIO_PORTA, MGPIO_PIN9, MGPIO_AF);  // Tx
    MGPIO_voidSetPinMode(MGPIO_PORTA, MGPIO_PIN10, MGPIO_AF); // Rx

    MGPIO_voidSetAlternativeFunction(MGPIO_PORTA, MGPIO_PIN9, MGPIO_AF07);
    MGPIO_voidSetAlternativeFunction(MGPIO_PORTA, MGPIO_PIN10, MGPIO_AF07);

    USART1 -> CR1 = 0x200C;
    USART1 -> BRR = 0x341;
}

void MUSART1_voidSendDataSynchronous(u8 Copy_u8Data)
{
    USART1 -> DR = Copy_u8Data;
    while(GET_BIT(USART1 -> SR, 6) == 0);
    CLR_BIT(USART1 -> SR, 6);
}


void MUSART1_voidReceiveDataSynchronous(u8 * Copy_pu8ReceivedData)
{
    while(GET_BIT(USART1 -> SR, 5) == 0);
    *Copy_pu8ReceivedData = USART1 -> DR;
    CLR_BIT(USART1 -> SR, 5);
}
