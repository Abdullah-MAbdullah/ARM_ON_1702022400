#include "../include/STD_TYPES.h"
#include "../include/BIT_MATH.h"

#include "../include/RCC_interface.h"
#include "../include/GPIO_interface.h"

#include "../include/MyArray.h"


void main(void)
{
	/*Initialize System Clock*/
	/*Enable Peripheral Clock for GPIOA*/

	/*Initialize PA0 to PA7 To be output pins*/
	u32 Local_LoopCounter = 0;
	while(1)
	{
		for(Local_LoopCounter = 0; Local_LoopCounter < 39329; Local_LoopCounter++)
		{
			MGPIO_voidSetPinValue(GPIO_PORTA, GPIO_PIN0, GET_BIT(MyMusic_raw[Local_LoopCounter], 0));
			MGPIO_voidSetPinValue(GPIO_PORTA, GPIO_PIN1, GET_BIT(MyMusic_raw[Local_LoopCounter], 1));
			MGPIO_voidSetPinValue(GPIO_PORTA, GPIO_PIN2, GET_BIT(MyMusic_raw[Local_LoopCounter], 2));
			MGPIO_voidSetPinValue(GPIO_PORTA, GPIO_PIN3, GET_BIT(MyMusic_raw[Local_LoopCounter], 3));
			MGPIO_voidSetPinValue(GPIO_PORTA, GPIO_PIN4, GET_BIT(MyMusic_raw[Local_LoopCounter], 4));
			MGPIO_voidSetPinValue(GPIO_PORTA, GPIO_PIN5, GET_BIT(MyMusic_raw[Local_LoopCounter], 5));
			MGPIO_voidSetPinValue(GPIO_PORTA, GPIO_PIN6, GET_BIT(MyMusic_raw[Local_LoopCounter], 6));
			MGPIO_voidSetPinValue(GPIO_PORTA, GPIO_PIN7, GET_BIT(MyMusic_raw[Local_LoopCounter], 7));
		}
	}
}
