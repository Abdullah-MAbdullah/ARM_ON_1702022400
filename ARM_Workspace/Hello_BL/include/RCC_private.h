#ifndef RCC_PRIVATE_H
#define RCC_PRIVATE_H

#define 	RCC_CLK_HSI					0
#define		RCC_CLK_HSE					1
#define		RCC_CLK_PLL					2

#define		RCC_AHB_DIV_1				0b0000
#define		RCC_AHB_DIV_2				0b1000
#define		RCC_AHB_DIV_4				0b1001
// Complete The Options

#define		RCC_APB1_DIV_1				0b000
#define		RCC_APB1_DIV_2				0b100
#define		RCC_APB1_DIV_4				0b101
#define		RCC_APB1_DIV_8				0b110
#define		RCC_APB1_DIV_16				0b111

#define		RCC_APB2_DIV_1				0b000
#define		RCC_APB2_DIV_2				0b100
#define		RCC_APB2_DIV_4				0b101
#define		RCC_APB2_DIV_8				0b110
#define		RCC_APB2_DIV_16				0b111


#define 	RCC_AHB_PRESCALER_MASK		0b1111
#define		RCC_APB1_PRESCALER_MASK		0b111
#define		RCC_APB2_PRESCALER_MASK		0b111




#define		RCC_BASE_ADDRESS	0x40023800
#define		RCC_CR				*((volatile u32 *)(RCC_BASE_ADDRESS + 0x00))
#define		RCC_PLLCFGR			*((volatile u32 *)(RCC_BASE_ADDRESS + 0x04))
#define 	RCC_CFGR			*((volatile u32 *)(RCC_BASE_ADDRESS + 0x08))
#define 	RCC_AHB1ENR			*((volatile u32 *)(RCC_BASE_ADDRESS + 0x30))
#define 	RCC_APB1ENR			*((volatile u32 *)(RCC_BASE_ADDRESS + 0x40))
#define 	RCC_APB2ENR			*((volatile u32 *)(RCC_BASE_ADDRESS + 0x44))



#endif
