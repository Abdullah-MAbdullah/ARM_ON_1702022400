/*********************************************
 * Author:				Abdullah M. Abdullah
 * Creation Data:		23 Feb, 2024
 * Version:				v2.0
 * Compiler:			GNU ARM-GCC
 * Controller:			STM32F401CCU6
 * Layer:				MCAL
 ********************************************/
/*********************************************
 * Version	  Date				  Author				  Description
 * v1.0		  23 Feb, 2024	Abdullah M. Abdullah		  Initial Creation
 * v2.0		  01 Mar, 2024	Abdullah M. Abdullah		  Adding Some New APIs
*********************************************/
#include "../include/STD_TYPES.h"
#include "../include/BIT_MATH.h"

#include "../include/GPIO_interface.h"
#include "../include/GPIO_private.h"
#include "../include/GPIO_config.h"

void MGPIO_voidSetPinMode(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8PinMode)
{
	/* Check For The Port Name*/
	switch(Copy_u8PortName)
	{
		case GPIO_PORTA:
			// Bit Masking
			GPIOA_MODER &= ~(MODER_MASK << (Copy_u8PinNumber * PIN_OFFSET));
			GPIOA_MODER |= (Copy_u8PinMode << ((Copy_u8PinNumber * PIN_OFFSET)));
		break;
		
		case GPIO_PORTB:
		break;
		
		case GPIO_PORTC:
		break;
		
		default:
			// Error
		break;
	}
}

void MGPIO_voidSetPinOutputSpeed(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8PinSpeed)
{
	/* Check For The Port Name*/
	switch(Copy_u8PortName)
	{
		case GPIO_PORTA:
			// Bit Masking
			GPIOA_OSPEEDR &= ~(OSPEEDR_MASK << (Copy_u8PinNumber * PIN_OFFSET));
			GPIOA_OSPEEDR |= (Copy_u8PinSpeed << ((Copy_u8PinNumber * PIN_OFFSET)));
		break;
		
		case GPIO_PORTB:
		break;
		
		case GPIO_PORTC:
		break;
		
		default:
			// Error
		break;
	}
}



void MGPIO_voidSetPinOutputType(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8PinOutputType)
{
	/* Check For The Port Name*/
	switch(Copy_u8PortName)
	{
		case GPIO_PORTA:
			// Bit Masking
			GPIOA_OTYPER &= ~(OTYPE_MASK << Copy_u8PinNumber);
			GPIOA_OTYPER |= (Copy_u8PinOutputType << Copy_u8PinNumber);
		break;
		
		case GPIO_PORTB:
		break;
		
		case GPIO_PORTC:
		break;
		
		default:
			// Error
		break;
	}
}

void MGPIO_voidSetPinValue(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8PinValue)
{
/* Check For The Port Name*/
	switch(Copy_u8PortName)
	{
		case GPIO_PORTA:
			switch(Copy_u8PinValue)
			{
				case GPIO_PIN_LOW:
					//SET_BIT(GPIOA_BSRR, (Copy_u8PinNumber+16));
					GPIOA_BSRR = 1 << (Copy_u8PinNumber+16);
				break;
				
				case GPIO_PIN_HIGH:
					//SET_BIT(GPIOA_BSRR, Copy_u8PinNumber);
					GPIOA_BSRR = 1 << Copy_u8PinNumber;
				break;
				
				default:
					// Error
				break;
			}
		break;
		
		case GPIO_PORTB:
		break;
		
		case GPIO_PORTC:
		break;
		
		default:
			// Error
		break;
	}
}

