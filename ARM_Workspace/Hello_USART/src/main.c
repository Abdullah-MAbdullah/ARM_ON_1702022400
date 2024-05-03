#include "../include/BIT_MATH.h"
#include "../include/STD_TYPES.h"

#include "../include/GPIO_interface.h"
#include "../include/RCC_interface.h"
#include "../include/USART_interface.h"

void main(void)
{
	RCC_voidInit();
	RCC_voidEnablePeripheralClock(RCC_AHB, RCC_AHB_GPIOAEN);
	RCC_voidEnablePeripheralClock(RCC_APB2, RCC_APB2_USART1EN);
	MUSART1_voidInit();
	u8 ReceivedData;
	while(1)
	{
		MUSART1_voidReceiveDataSynchronous(&ReceivedData);
		MUSART1_voidSendDataSynchronous(ReceivedData);
	}
}
