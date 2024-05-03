#include "../include/BIT_MATH.h"
#include "../include/STD_TYPES.h"

#include "../include/GPIO_interface.h"
#include "../include/RCC_interface.h"
#include "../include/SPI_interface.h"
#include "../include/STK_interface.h"

#include "../include/TFT_interface.h"
#include "../include/Image.h"

int main(void)
{
	// Initialize System Clock
	RCC_voidInit();
	// Enable Clock for GPIOA Peripheral
	RCC_voidEnablePeripheralClock(RCC_AHB, RCC_AHB_GPIOAEN);
	// Enable Clock For SPI1 Peripheral
	RCC_voidEnablePeripheralClock(RCC_APB2, RCC_APB2_SPI1EN);
	// Setup The SPI Pins
	MGPIO_voidSetPinMode(GPIO_PORTA, GPIO_PIN5, GPIO_AF); // PA5 (SCK1) To Be AF
	MGPIO_voidSetPinMode(GPIO_PORTA, GPIO_PIN4, GPIO_AF); // PA7 (MOSI1) To Be AF
	MGPIO_voidSetPinMode(GPIO_PORTA, GPIO_PIN7, GPIO_AF); // PA7 (MOSI1) To Be AF
	MGPIO_voidSetAlternativeFunction(GPIO_PORTA, GPIO_PIN5, 5); // PA5 To operate as SCK1
	MGPIO_voidSetAlternativeFunction(GPIO_PORTA, GPIO_PIN4, 5); // PA5 To operate as SCK1
	MGPIO_voidSetAlternativeFunction(GPIO_PORTA, GPIO_PIN7, 5); // PA7 To operate as MOSI1
	// Initialize SysTick
	MSTK_voidInit();
	// Initialize SPI1
	MSPI1_voidInit();
	//Initialize TFT
	HTFT_voidInit();
//	while(1)
//	{
		HTFT_voidDisplayImage(&Image);
//	}
}
