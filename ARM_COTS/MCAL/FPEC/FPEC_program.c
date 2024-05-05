/*****************************************************************************************
* Author:				Abdullah M. Abdullah
* Creation Data:		11 Jun, 2023
* Version:				v1.0
* Compiler:				GNU ARM-GCC
* Controller:			STM32F401CCU6 (32-bit Architecture)
* Processor:			Cortex M4 (32-bit Architecture)
* Layer:				MCAL Layer
*****************************************************************************************/
/*****************************************************************************************
 * Version	  Date				  Author				  Description
 * v1.0		  11 Jun, 2023	Abdullah M. Abdullah		  Initial Creation
*****************************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "FPEC_interface.h"
#include "FPEC_private.h"
#include "FPEC_config.h"



void MFPEC_voidEraseAppArea(void)
{
	u8 Local_u8LoopCounter;
    /*Erase The Flash Memory Sector 1 to 5 (These are the application Sectors)*/
	for (Local_u8LoopCounter=1;Local_u8LoopCounter<6;Local_u8LoopCounter++)
	{
		MFPEC_voidFlashSectorErase(Local_u8LoopCounter);
	}
}

void MFPEC_voidFlashSectorErase(u8 Copy_u8SectionNumber)
{
    /*Polling while the FPEC is busy*/
    while(GET_BIT(FPEC->SR, 16) == 1 );
    /*Check if the FPEC Is Locked*/
    if(GET_BIT(FPEC->CR, 31) == 1)
    {
        FPEC -> KEYR = KEY1;
        FPEC -> KEYR = KEY2;
    }
    /* Set Sector Erase Operation */
    SET_BIT(FPEC->CR, 1);
    /*Select The Sector To Be Erased*/
    FPEC->CR &=0xFFFFFF87;
    FPEC->CR |=Copy_u8SectionNumber<<3;
    /*Set Start Bit*/
    SET_BIT(FPEC -> CR, 16);
    /*Polling while the FPEC is busy*/
    while(GET_BIT(FPEC->SR, 16) == 1 );
    /*Clear EOP Flag*/
    SET_BIT(FPEC->SR, 0);
    /* Clear Sector Erase Operation */
    CLR_BIT(FPEC->CR, 1);
}


void MFPEC_voidFlashWrite(u32 Copy_u32LocationAddress, u16 * Copy_pu16Data, u8 Copy_u8Length)
{
    u8 Local_u8LoopCounter = 0;
    /*Polling while the FPEC is busy*/
    while(GET_BIT(FPEC->SR, 16) == 1 );
    /*Check if the FPEC Is Locked*/
    if(GET_BIT(FPEC->CR, 31) == 1)
    {
        FPEC -> KEYR = KEY1;
        FPEC -> KEYR = KEY2;
    }
    /*Choose the size of data to be wrote on the flash memory, we choosed half word (2-bytes)*/
    FPEC -> CR &= 0xFFFFFCFF ;
    FPEC -> CR |= (1<<8) ;
    for(Local_u8LoopCounter = 0; Local_u8LoopCounter < Copy_u8Length; Local_u8LoopCounter++)
    {
        /*SET Program Operation*/
        SET_BIT(FPEC->CR ,0);
        /*Write The Data To The Flash Memory*/
        *(volatile u16 *)Copy_u32LocationAddress = Copy_pu16Data[Local_u8LoopCounter];
        Copy_u32LocationAddress += 2 ;
        /*Polling while the FPEC is busy*/
        while(GET_BIT(FPEC->SR, 16) == 1 );
        /*Clear EOP Flag*/
        SET_BIT(FPEC->SR, 0);
        /* Clear Program Operation */
        CLR_BIT(FPEC->CR, 0);
    }
} 
