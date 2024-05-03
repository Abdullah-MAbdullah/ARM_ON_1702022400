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
#include "../include/STD_TYPES.h"
#include "../include/BIT_MATH.h"

#include "../include/GPIO_interface.h"
#include "../include/STK_interface.h"
#include "../include/SPI_interface.h"

#include "../include/TFT_interface.h"
#include "../include/TFT_private.h"
#include "../include/TFT_config.h"

void HTFT_voidInit(void)
{
    // Set A0 Of TFT To be Output Pin
    MGPIO_voidSetPinMode(HTFT_A0_PORT_PIN, GPIO_OUTPUT);
    // Set RST Of TFT To be Output Pin
    MGPIO_voidSetPinMode(HTFT_RST_PORT_PIN, GPIO_OUTPUT);

    // Initialization Sequence
    // Rest Pulses
    MGPIO_voidSetPinValue(HTFT_RST_PORT_PIN, GPIO_PIN_HIGH);
    MSTK_voidSetBusyWait(100);
    MGPIO_voidSetPinValue(HTFT_RST_PORT_PIN, GPIO_PIN_LOW);
    MSTK_voidSetBusyWait(1);
    MGPIO_voidSetPinValue(HTFT_RST_PORT_PIN, GPIO_PIN_HIGH);
    MSTK_voidSetBusyWait(100);
    MGPIO_voidSetPinValue(HTFT_RST_PORT_PIN, GPIO_PIN_LOW);
    MSTK_voidSetBusyWait(100);
    MGPIO_voidSetPinValue(HTFT_RST_PORT_PIN, GPIO_PIN_HIGH);
    MSTK_voidSetBusyWait(120000);

    voidSendCommand(SLPOUT_CMD);
    MSTK_voidSetBusyWait(150000);
    voidSendCommand(COLMOD_CMD);
    HTFT_voidSendData(TFT_COLOR_MODE);
    voidSendCommand(DISPON_CMD);
}

static void voidSendCommand(u8 Copy_u8Command)
{
    u8 Local_u8Dummy;
    // Set A0 Pin To Be Low For Command
    MGPIO_voidSetPinValue(HTFT_A0_PORT_PIN, GPIO_PIN_LOW);
    Local_u8Dummy = MSPI1_u8TrancieveSynchronous(Copy_u8Command);
}

void HTFT_voidSendData(u8 Copy_u8Data)
{
    u8 Local_u8Dummy;
    // Set A0 Pin To Be Low For Data
    MGPIO_voidSetPinValue(HTFT_A0_PORT_PIN, GPIO_PIN_HIGH);
    Local_u8Dummy = MSPI1_u8TrancieveSynchronous(Copy_u8Data);
}


void HTFT_voidSetWindow(u8 Copy_u8X0, u8 Copy_u8X1, u8 Copy_u8Y0, u8 Copy_u8Y1)
{
    // Send Set X Addresses Command
    voidSendCommand(X_ADD_CMD);
    HTFT_voidSendData(0);
    HTFT_voidSendData(Copy_u8X0);
    HTFT_voidSendData(0);
    HTFT_voidSendData(Copy_u8X1);
    // Send Set Y Addresses Command
    voidSendCommand(Y_ADD_CMD);
    HTFT_voidSendData(0);
    HTFT_voidSendData(Copy_u8Y0);
    HTFT_voidSendData(0);
    HTFT_voidSendData(Copy_u8Y1);
}

void HTFT_voidDisplayImage(u16 * Copy_pu16Image)
{
    u16 Local_u16LoopCounter = 0;
    u8 Local_u8Data;
    HTFT_voidSetWindow(0, 127, 0, 159);
    // Send Write RAM Command
    voidSendCommand(RAM_WR_CMD);
    for(Local_u16LoopCounter = 0; Local_u16LoopCounter <= 20480; Local_u16LoopCounter++)
    {
        // Send MSB First
        Local_u8Data = (u8)(Copy_pu16Image[Local_u16LoopCounter] >> 8);
        HTFT_voidSendData(Local_u8Data);
        // Send LSB Then
        Local_u8Data = (u8)Copy_pu16Image[Local_u16LoopCounter];
        HTFT_voidSendData(Local_u8Data);
    }
}
