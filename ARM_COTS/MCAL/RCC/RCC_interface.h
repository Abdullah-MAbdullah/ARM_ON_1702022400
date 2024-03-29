// Header Guard File
#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H

#define		RCC_HSI		0
#define		RCC_HSE		1
#define		RCC_PLL		2

#define 	RCC_AHB		0
#define 	RCC_APB1	1
#define 	RCC_APB2	2

#define 	RCC_AHB_GPIOAEN		0
#define 	RCC_AHB_GPIOBEN		1
#define 	RCC_AHB_GPIOCEN		2
#define 	RCC_AHB_DMA1EN		21
#define 	RCC_AHB_DMA2EN		22
	
#define		RCC_APB1_TIM2EN		0
#define		RCC_APB1_TIM3EN		1
#define		RCC_APB1_TIM4EN		2
	
#define 	RCC_APB2_TIM1EN		0
#define 	RCC_APB2_USART1EN	4
#define 	RCC_APB2_SPI1EN		12

void RCC_voidInit(void);
void RCC_voidEnableClockSource(u8 Copy_u8ClockSource);
void RCC_voidDisableClockSource(u8 Copy_u8ClockSource);
void RCC_voidEnablePeripheralClock(u8 Copy_u8BusName, u8 Copy_u8PeripheralName);

#endif
