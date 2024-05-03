#include "../include/STD_TYPES.h"
#include "../include/BIT_MATH.h"

#include "../include/RCC_interface.h"
#include "../include/GPIO_interface.h"
#include "../include/STK_interface.h"


void main(void)
{
	// Initialize The System Clock
	RCC_voidInit();
	// Enable Clock For GPIOA
	RCC_voidEnablePeripheralClock(RCC_AHB, RCC_AHB_GPIOAEN);
	// Set PA0 To Be Output pin
	MGPIO_voidSetPinMode(GPIO_PORTA, GPIO_PIN0, GPIO_OUTPUT);
	// Set PA0 To Be Output Push Pull
	MGPIO_voidSetPinOutputType(GPIO_PORTA, GPIO_PIN0, GPIO_OUTPUT_PP);
	// Set PA0 To Be Low Speed
	MGPIO_voidSetPinOutputSpeed(GPIO_PORTA, GPIO_PIN0, GPIO_LOW_SPEED);
	// Initialize SysTick
	MSTK_voidInit();
	while(1)
	{
		MGPIO_voidSetPinValue(GPIO_PORTA, GPIO_PIN0, GPIO_PIN_HIGH);
		MSTK_voidSetBusyWait(1000000);
		MGPIO_voidSetPinValue(GPIO_PORTA, GPIO_PIN0, GPIO_PIN_LOW);
		MSTK_voidSetBusyWait(1000000);
	}
}
