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

#include "BL_interface.h"
#include "BL_private.h"
#include "BL_config.h"

u16 Data[100] = {0};
u32 Address= 0x08000000;

static u8 u8AsciToHex(u8 Copy_u8Asci)
{
	u8 Result;
	if ( (Copy_u8Asci >= 48) && (Copy_u8Asci <= 57) )
	{
		Result = Copy_u8Asci - 48;
	}

	else
	{
		/*Subtract the Recevied Character (From A to F) by 55 (ASCII of character 7)*/
		Result = Copy_u8Asci - 55;
	}

	return Result;
}

void MBL_voidParseRecord(u8* Copy_u8BufData)
{
	/*Get the Record Type Digit*/
	switch (Copy_u8BufData[8])
	{
	case '0': voidParseData(Copy_u8BufData); break;
	// case '4': ParseUpperAddress(Copy_u8BufData); break;
	}
}

static void voidParseData(u8* Copy_u8BufData)
{
	volatile u8 DigitLow,DigitHigh,CC,i;
	volatile u8 DataDigit0,DataDigit1,DataDigit2,DataDigit3;
	volatile u8 DataCounter = 0;

	/* Get Character Count */
	DigitHigh = u8AsciToHex (Copy_u8BufData[1]);
	DigitLow  = u8AsciToHex (Copy_u8BufData[2]);
	CC        = (DigitHigh<<4) | DigitLow ;

	/* Get Address */
	DataDigit0 = u8AsciToHex (Copy_u8BufData[3]);
	DataDigit1 = u8AsciToHex (Copy_u8BufData[4]);
	DataDigit2 = u8AsciToHex (Copy_u8BufData[5]);
	DataDigit3 = u8AsciToHex (Copy_u8BufData[6]);

	/* Clear Low Part of Address */
	Address = Address & 0xFFFF0000;
	Address = Address | (DataDigit3) | (DataDigit2 << 4) | (DataDigit1 << 8) | (DataDigit0<<12);

	/*Get The Data Digits (Each 2 digits are 1 byte)*/
	for (i=0;i<CC/2; i++)
	{
		DataDigit0 = u8AsciToHex (Copy_u8BufData[4*i+9 ]);
		DataDigit1 = u8AsciToHex (Copy_u8BufData[4*i+10]);
		DataDigit2 = u8AsciToHex (Copy_u8BufData[4*i+11]);
		DataDigit3 = u8AsciToHex (Copy_u8BufData[4*i+12]);
		/*Rearrange the Data Digit By Shifting*/
		Data[DataCounter] = (DataDigit3 << 8) | (DataDigit2 << 12) | (DataDigit1) | (DataDigit0<<4);
		DataCounter++;
	}
	/*Write These Data To The Flash Memory*/
	MFPEC_voidFlashWrite(Address,Data,CC/2);
}
