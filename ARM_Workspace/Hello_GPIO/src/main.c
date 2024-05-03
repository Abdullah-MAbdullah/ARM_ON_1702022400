#include "../include/STD_TYPES.h"
#include "../include/BIT_MATH.h"

#include "../include/RCC_interface.h"
#include "../include/GPIO_interface.h"


void main(void)
{
	RCC_voidInit();
	RCC_voidEnablePeripheralClock(RCC_AHB, RCC_AHB_GPIOAEN);
	// Set PA0 To Be Output Pin
	MGPIO_voidSetPinMode(GPIO_PORTA, GPIO_PIN0, GPIO_OUTPUT);
	// Set PA0 To Be Low Speed
	MGPIO_voidSetPinOutputSpeed(GPIO_PORTA, GPIO_PIN0, GPIO_LOW_SPEED);
	// Set PA0 To Be Output Push Pull
	MGPIO_voidSetPinOutputType(GPIO_PORTA, GPIO_PIN0, 0);
	while(1)
	{
		// Set PA0 To High
		MGPIO_voidSetPinValue(GPIO_PORTA, GPIO_PIN0, GPIO_PIN_HIGH);
	}
}
