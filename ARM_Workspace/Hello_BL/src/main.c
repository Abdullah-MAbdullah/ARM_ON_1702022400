#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "UART_interface.h"
#include "STK_interface.h"
#include "BL_interface.h"
#include "FPEC_interface.h"

void Func(void);
static u8 u8ReceiveBuffer[100];
static u8 u8ReceiveCounter = 0;
static u8 u8BLWriteRequestFlag = 1;
u8 Local_u8ReceiveState = 0;

typedef void (*Function_t)(void);
Function_t addr_to_call = 0;

/*DO NOT FORGET TO CHANGE THE APPLICATION FLASH MEMORY OFFSET TO START FROM SECTOR 1,
AS THE BOOTLOADER WILL BE RESIDE AT SECTOR 0 (I.E, STARTS FROM @ 0X08000000) IN THE FLASH MEMORY*/

void main(void)
{
	RCC_voidInit();
	RCC_voidEnablePeripheralClock(RCC_AHB, RCC_AHB_GPIOAEN);
	RCC_voidEnablePeripheralClock(RCC_APB2, RCC_APB2_USART1EN);

	MUSART1_voidInit();

	MSTK_voidInit();
	MSTK_voidSetSingleInterval(10000000, &Func);

	while(1)
	{
		Local_u8ReceiveState = MUSART1_u8ReceiveDataIfReceived(&u8ReceiveBuffer[u8ReceiveCounter]);

		if (Local_u8ReceiveState == 1)
		{
			MSTK_voidSTKDisable();
			if (u8ReceiveBuffer[u8ReceiveCounter] == '\n')
			{
				/*Erasing the Flash memory before writing on it*/
				if (u8BLWriteRequestFlag == 1)
				{
					MFPEC_voidEraseAppArea();
					u8BLWriteRequestFlag = 0;
				}
				/*Parsing the Received Record*/
				MBL_voidParseRecord(&u8ReceiveBuffer);
				/*Send ok to the tool*/
				MUSART1_voidSendStringSynchronous("ok");
				/*Reset the ReceiveCounter variable*/
				u8ReceiveCounter = 0;
			}
			else
			{
				u8ReceiveCounter++;
			}
			MSTK_voidSetSingleInterval(10000000, &Func);
		}
	}
}
void Func(void)
{
	#define SCB_VTOR *((volatile u32 *)0xE000ED08)
	/*Set the offset of the Vector Table Offset Address Of The Application In The Flash Memory*/
	SCB_VTOR = 0x08004000;
	/*Declare a Pointer To Function to the Start function of the application*/
	addr_to_call = *(Function_t*)(0x08004004);
	/*Execute the Start Function of the application using Software Function Call*/
	addr_to_call();
}
