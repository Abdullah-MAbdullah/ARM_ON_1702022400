/****************************************************************************************
* Author:				Abdullah M. Abdullah
* Creation Data:		19 Apr, 2024
* Version:				v1.0
* Compiler:				GNU ARM-GCC
* Controller:			STM32F401CCU6
* Layer:				HAL
****************************************************************************************/
/***************************************************************************************
* Version	  Date				  	Author				  			Description
* v1.0		  19 Apr, 2024			Abdullah M. Abdullah		  	Initial Creation
***************************************************************************************/
#ifndef TFT_INTERFACE_H
#define TFT_INTERFACE_H

void HTFT_voidInit(void);
void HTFT_voidSendData(u8 Copy_u8Data);
void HTFT_voidSetWindow(u8 Copy_u8X0, u8 Copy_u8X1, u8 Copy_u8Y0, u8 Copy_u8Y1);
void HTFT_voidDisplayImage(u16 * Copy_pu8Image);



#endif