/*********************************************
 * Author:				Abdullah M. Abdullah
 * Creation Data:		23 Feb, 2024
 * Version:				v1.0
 * Compiler:			GNU ARM-GCC
 * Controller:			STM32F401CCU6
 * Layer:				MCAL
 ********************************************/
/*********************************************
 * Version	  Date				  Author				  Description
 * v1.0		  23 Feb, 2024	Abdullah M. Abdullah		  Initial Creation
*********************************************/
#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H

#define		GPIO_PORTA		0
#define		GPIO_PORTB		1
#define		GPIO_PORTC		2

#define		GPIO_PIN0		0
#define		GPIO_PIN1		1
#define		GPIO_PIN2		2
#define		GPIO_PIN3		3
#define		GPIO_PIN4		4
#define		GPIO_PIN5		5
#define		GPIO_PIN6		6
#define		GPIO_PIN7		7
#define		GPIO_PIN8		8
#define		GPIO_PIN9		9
#define		GPIO_PIN10		10
#define		GPIO_PIN11		11
#define		GPIO_PIN12		12
#define		GPIO_PIN13		13
#define		GPIO_PIN14		14
#define		GPIO_PIN15		15

#define		GPIO_INPUT		0b00
#define		GPIO_OUTPUT		0b01
#define		GPIO_AF			0b10
#define		GPIO_ANALOG		0b11

#define		GPIO_LOW_SPEED		0b00
#define		GPIO_MED_SPEED		0b01
#define		GPIO_HIGH_SPEED		0b10
#define		GPIO_VHIGH_SPEED	0b11

#define		GPIO_OUTPUT_PP		0b00
#define		GPIO_OUTPUT_OD		0b01

#define		GPIO_PIN_LOW		0
#define		GPIO_PIN_HIGH		1

void MGPIO_voidSetPinMode(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8PinMode);
void MGPIO_voidSetPinOutputType(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8PinOutputType);
void MGPIO_voidSetPinOutputSpeed(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8PinSpeed);
void MGPIO_voidSetPinValue(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8PinValue);

#endif
