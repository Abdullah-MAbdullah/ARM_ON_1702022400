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
#ifndef FPEC_INTERFACE_H
#define FPEC_INTERFACE_H

void MFPEC_voidEraseAppArea(void);
void MFPEC_voidFlashSectorErase(u8 Copy_u8SectionNumber);
void MFPEC_voidFlashWrite(u32 Copy_u32LocationAddress, u16 * Copy_pu16Data, u8 Copy_u8Length);



#endif