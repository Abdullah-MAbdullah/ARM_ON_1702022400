#include "../include/STD_TYPES.h"
#include "../include/BIT_MATH.h"

#include "../include/RCC_interface.h"
#include "../include/NVIC_interface.h"
#include "../include/DMA_interface.h"

volatile u16 LoopCounter = 0;

void main(void)
{
	volatile u32 Processor_SourceArray[1000] = {0};
	volatile u32 Processor_DestinationArray[1000];

	u32 DMA_SourceArray[1000] = {0};
	u32 DMA_DestinationArray[1000];

	/*Initialize System Clock*/
	RCC_voidInit();
	/*Enable Peripheral Clock For DMA1*/
	RCC_voidEnablePeripheralClock(RCC_AHB, RCC_AHB_DMA1EN);
	/*Enable DMA NVIC Interrupt*/
	MNVIC_voidPeripheralInterruptControl(11, MNVIC_INT_ENABLE);
	/*Initialize DMA1*/
	MDMA1_voidInit();
	/*Start The DMA Transfer Process*/
	MDMA1_voidStartTransfer(&DMA_SourceArray, &DMA_DestinationArray, 1000);
	/*Start The Process Transfer Process*/
	for(LoopCounter = 0; LoopCounter < 1000; LoopCounter++)
	{
		Processor_DestinationArray[LoopCounter] = Processor_SourceArray[LoopCounter];
		asm("NOP");
	}
	while(1);
}

void DMA1_Stream0_IRQHandler(void)
{
	asm ("NOP");
	/*Clear All Flags*/
	MDMA1_voidClearAllFlags();
}
