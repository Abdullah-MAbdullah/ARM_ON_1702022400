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
#ifndef TFT_PRIVATE_H
#define TFT_PRIVATE_H

#define SLPOUT_CMD              0x11
#define COLMOD_CMD              0x3A
#define TFT_COLOR_MODE          0x05
#define DISPON_CMD              0x29
#define X_ADD_CMD               0x2A
#define Y_ADD_CMD               0x2B
#define RAM_WR_CMD              0x2C

static void voidSendCommand(u8 Copy_u8Command);



#endif