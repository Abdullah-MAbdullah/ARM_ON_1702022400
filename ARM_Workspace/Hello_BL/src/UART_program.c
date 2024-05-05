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

#include "UART_interface.h"
#include "UART_private.h"
#include "UART_config.h"

void MUSART1_voidInit(void)
{
    MGPIO_voidSetPinMode(GPIO_PORTA, GPIO_PIN9, GPIO_AF);  // Tx
    MGPIO_voidSetPinMode(GPIO_PORTA, GPIO_PIN10, GPIO_AF); // Rx

    MGPIO_voidSetAlternativeFunction(GPIO_PORTA, GPIO_PIN9, 7);
    MGPIO_voidSetAlternativeFunction(GPIO_PORTA, GPIO_PIN10, 7);

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

void MUSART1_voidSendStringSynchronous(u8 * Copy_pu8StringArray)
{
    u8 Local_u8LoopCounter = 0 ;
    /*Loop On The String till the null terminator*/
    while(Copy_pu8StringArray[Local_u8LoopCounter] != '\0')
    {
        /*Send The Array Element*/
        MUSART1_voidSendDataSynchronous(Copy_pu8StringArray[Local_u8LoopCounter]);
        Local_u8LoopCounter++;
    }
}

void MUSART1_voidSendNumberSynchronous(u32 Copy_u32Number)
{
    u8 Local_u8ArrayNumber[10];
    s8 Local_s8LoopCounter = 0;
    while(Copy_u32Number != 0)
    {
        Local_u8ArrayNumber[Local_s8LoopCounter] = Copy_u32Number % 10;
        Copy_u32Number /= 10;
        Local_s8LoopCounter++;
    }
    Local_s8LoopCounter--;
    while(Local_s8LoopCounter >= 0)
    {
        MUSART1_voidSendDataSynchronous(Local_u8ArrayNumber[Local_s8LoopCounter] + '0');
        Local_s8LoopCounter--;
    }
}


u8 MUSART1_u8ReceiveDataIfReceived(u8 * Copy_pu8ReceivedData)
{
    u8 Local_u8ReceiveState = 0;
    if(GET_BIT(USART1 -> SR, 5) == 1)
    {
        *Copy_pu8ReceivedData = USART1 -> DR;
        CLR_BIT(USART1 -> SR, 5);
        Local_u8ReceiveState = 1;
    }
    else
    {
        Local_u8ReceiveState = 0;
    }
    return Local_u8ReceiveState;
}
