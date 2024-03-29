/*********************************************
 * Author:				Abdullah M. Abdullah
 * Creation Data:		22 Mar, 2024
 * Version:				v1.0
 * Compiler:			GNU ARM-GCC
 * Controller:			STM32F401CCU6
 * Layer:				HAL
 ********************************************/
/*********************************************
 * Version	  Date				  Author				  Description
 * v1.0		  22 Mar, 2024	Abdullah M. Abdullah		  Initial Creation
*********************************************/
#include "../include/STD_TYPES.h"
#include "../include/BIT_MATH.h"

#include "../include/GPIO_interface.h"
#include "../include/STK_interface.h"


#include "../include/LEDMAT_interface.h"
#include "../include/LEDMAT_private.h"
#include "../include/LEDMAT_config.h"



void HLEDMAT_voidInit(void)
{
    /*Set Columns Pins To Be Output*/
    MGPIO_voidSetPinMode(HLEDMAT_COL0_PORT_PIN, GPIO_OUTPUT);
    MGPIO_voidSetPinMode(HLEDMAT_COL1_PORT_PIN, GPIO_OUTPUT);
    MGPIO_voidSetPinMode(HLEDMAT_COL2_PORT_PIN, GPIO_OUTPUT);
    MGPIO_voidSetPinMode(HLEDMAT_COL3_PORT_PIN, GPIO_OUTPUT);
    MGPIO_voidSetPinMode(HLEDMAT_COL4_PORT_PIN, GPIO_OUTPUT);
    MGPIO_voidSetPinMode(HLEDMAT_COL5_PORT_PIN, GPIO_OUTPUT);
    MGPIO_voidSetPinMode(HLEDMAT_COL6_PORT_PIN, GPIO_OUTPUT);
    MGPIO_voidSetPinMode(HLEDMAT_COL7_PORT_PIN, GPIO_OUTPUT);

    /*Set Columns Pins To Be Output PP*/
    MGPIO_voidSetPinOutputType(HLEDMAT_COL0_PORT_PIN, GPIO_OUTPUT_PP);
    MGPIO_voidSetPinOutputType(HLEDMAT_COL1_PORT_PIN, GPIO_OUTPUT_PP);
    MGPIO_voidSetPinOutputType(HLEDMAT_COL2_PORT_PIN, GPIO_OUTPUT_PP);
    MGPIO_voidSetPinOutputType(HLEDMAT_COL3_PORT_PIN, GPIO_OUTPUT_PP);
    MGPIO_voidSetPinOutputType(HLEDMAT_COL4_PORT_PIN, GPIO_OUTPUT_PP);
    MGPIO_voidSetPinOutputType(HLEDMAT_COL5_PORT_PIN, GPIO_OUTPUT_PP);
    MGPIO_voidSetPinOutputType(HLEDMAT_COL6_PORT_PIN, GPIO_OUTPUT_PP);
    MGPIO_voidSetPinOutputType(HLEDMAT_COL7_PORT_PIN, GPIO_OUTPUT_PP);

    /*Set Columns Pin To Be Output Low Speed*/
    MGPIO_voidSetPinOutputSpeed(HLEDMAT_COL0_PORT_PIN, GPIO_LOW_SPEED);
    MGPIO_voidSetPinOutputSpeed(HLEDMAT_COL1_PORT_PIN, GPIO_LOW_SPEED);
    MGPIO_voidSetPinOutputSpeed(HLEDMAT_COL2_PORT_PIN, GPIO_LOW_SPEED);
    MGPIO_voidSetPinOutputSpeed(HLEDMAT_COL3_PORT_PIN, GPIO_LOW_SPEED);
    MGPIO_voidSetPinOutputSpeed(HLEDMAT_COL4_PORT_PIN, GPIO_LOW_SPEED);
    MGPIO_voidSetPinOutputSpeed(HLEDMAT_COL5_PORT_PIN, GPIO_LOW_SPEED);
    MGPIO_voidSetPinOutputSpeed(HLEDMAT_COL6_PORT_PIN, GPIO_LOW_SPEED);
    MGPIO_voidSetPinOutputSpeed(HLEDMAT_COL7_PORT_PIN, GPIO_LOW_SPEED);


    /*Set Rows Pins To Be Output*/
    MGPIO_voidSetPinMode(HLEDMAT_ROW0_PORT_PIN, GPIO_OUTPUT);
    MGPIO_voidSetPinMode(HLEDMAT_ROW1_PORT_PIN, GPIO_OUTPUT);
    MGPIO_voidSetPinMode(HLEDMAT_ROW2_PORT_PIN, GPIO_OUTPUT);
    MGPIO_voidSetPinMode(HLEDMAT_ROW3_PORT_PIN, GPIO_OUTPUT);
    MGPIO_voidSetPinMode(HLEDMAT_ROW4_PORT_PIN, GPIO_OUTPUT);
    MGPIO_voidSetPinMode(HLEDMAT_ROW5_PORT_PIN, GPIO_OUTPUT);
    MGPIO_voidSetPinMode(HLEDMAT_ROW6_PORT_PIN, GPIO_OUTPUT);
    MGPIO_voidSetPinMode(HLEDMAT_ROW7_PORT_PIN, GPIO_OUTPUT);
    
    /*Set Rows Pins To Be Output PP*/
    MGPIO_voidSetPinOutputType(HLEDMAT_ROW0_PORT_PIN, GPIO_OUTPUT_PP);
    MGPIO_voidSetPinOutputType(HLEDMAT_ROW1_PORT_PIN, GPIO_OUTPUT_PP);
    MGPIO_voidSetPinOutputType(HLEDMAT_ROW2_PORT_PIN, GPIO_OUTPUT_PP);
    MGPIO_voidSetPinOutputType(HLEDMAT_ROW3_PORT_PIN, GPIO_OUTPUT_PP);
    MGPIO_voidSetPinOutputType(HLEDMAT_ROW4_PORT_PIN, GPIO_OUTPUT_PP);
    MGPIO_voidSetPinOutputType(HLEDMAT_ROW5_PORT_PIN, GPIO_OUTPUT_PP);
    MGPIO_voidSetPinOutputType(HLEDMAT_ROW6_PORT_PIN, GPIO_OUTPUT_PP);
    MGPIO_voidSetPinOutputType(HLEDMAT_ROW7_PORT_PIN, GPIO_OUTPUT_PP);

    /*Set Rows Pin To Be Output Low Speed*/
    MGPIO_voidSetPinOutputSpeed(HLEDMAT_ROW0_PORT_PIN, GPIO_LOW_SPEED);
    MGPIO_voidSetPinOutputSpeed(HLEDMAT_ROW1_PORT_PIN, GPIO_LOW_SPEED);
    MGPIO_voidSetPinOutputSpeed(HLEDMAT_ROW2_PORT_PIN, GPIO_LOW_SPEED);
    MGPIO_voidSetPinOutputSpeed(HLEDMAT_ROW3_PORT_PIN, GPIO_LOW_SPEED);
    MGPIO_voidSetPinOutputSpeed(HLEDMAT_ROW4_PORT_PIN, GPIO_LOW_SPEED);
    MGPIO_voidSetPinOutputSpeed(HLEDMAT_ROW5_PORT_PIN, GPIO_LOW_SPEED);
    MGPIO_voidSetPinOutputSpeed(HLEDMAT_ROW6_PORT_PIN, GPIO_LOW_SPEED);
    MGPIO_voidSetPinOutputSpeed(HLEDMAT_ROW7_PORT_PIN, GPIO_LOW_SPEED);
}

void HLED_voidDisplay(u8 * Copy_pu8Data)
{
    while(1)
    {
        /*Disable All Columns*/
        voidDisableAllColumns();
        /*Set Rows Value*/
        voidSetRowsValue(Copy_pu8Data[0]);
        /*Activate Column 0*/
        MGPIO_voidSetPinValue(HLEDMAT_COL0_PORT_PIN, GPIO_PIN_LOW);
        /*Delay for 2.5msec*/
        MSTK_voidSetBusyWait(2500);


        /*Disable All Columns*/
        voidDisableAllColumns();
        /*Set Rows Value*/
        voidSetRowsValue(Copy_pu8Data[1]);
        /*Activate Column 1*/
        MGPIO_voidSetPinValue(HLEDMAT_COL1_PORT_PIN, GPIO_PIN_LOW);
        /*Delay for 2.5msec*/
        MSTK_voidSetBusyWait(2500);

        /*Disable All Columns*/
        voidDisableAllColumns();
        /*Set Rows Value*/
        voidSetRowsValue(Copy_pu8Data[2]);
        /*Activate Column 2*/
        MGPIO_voidSetPinValue(HLEDMAT_COL2_PORT_PIN, GPIO_PIN_LOW);
        /*Delay for 2.5msec*/
        MSTK_voidSetBusyWait(2500);

        /*Disable All Columns*/
        voidDisableAllColumns();
        /*Set Rows Value*/
        voidSetRowsValue(Copy_pu8Data[3]);
        /*Activate Column 3*/
        MGPIO_voidSetPinValue(HLEDMAT_COL3_PORT_PIN, GPIO_PIN_LOW);
        /*Delay for 2.5msec*/
        MSTK_voidSetBusyWait(2500);
    
        /*Disable All Columns*/
        voidDisableAllColumns();
        /*Set Rows Value*/
        voidSetRowsValue(Copy_pu8Data[4]);
        /*Activate Column 4*/
        MGPIO_voidSetPinValue(HLEDMAT_COL4_PORT_PIN, GPIO_PIN_LOW);
        /*Delay for 2.5msec*/
        MSTK_voidSetBusyWait(2500);

        /*Disable All Columns*/
        voidDisableAllColumns();
        /*Set Rows Value*/
        voidSetRowsValue(Copy_pu8Data[5]);
        /*Activate Column 5*/
        MGPIO_voidSetPinValue(HLEDMAT_COL5_PORT_PIN, GPIO_PIN_LOW);
        /*Delay for 2.5msec*/
        MSTK_voidSetBusyWait(2500);

        /*Disable All Columns*/
        voidDisableAllColumns();
        /*Set Rows Value*/
        voidSetRowsValue(Copy_pu8Data[6]);
        /*Activate Column 6*/
        MGPIO_voidSetPinValue(HLEDMAT_COL6_PORT_PIN, GPIO_PIN_LOW);
        /*Delay for 2.5msec*/
        MSTK_voidSetBusyWait(2500);


        /*Disable All Columns*/
        voidDisableAllColumns();
        /*Set Rows Value*/
        voidSetRowsValue(Copy_pu8Data[7]);
        /*Activate Column 7*/
        MGPIO_voidSetPinValue(HLEDMAT_COL7_PORT_PIN, GPIO_PIN_LOW);
        /*Delay for 2.5msec*/
        MSTK_voidSetBusyWait(2500);
    }
}

static void voidDisableAllColumns(void)
{
    MGPIO_voidSetPinValue(HLEDMAT_COL0_PORT_PIN, GPIO_PIN_HIGH);
    MGPIO_voidSetPinValue(HLEDMAT_COL1_PORT_PIN, GPIO_PIN_HIGH);
    MGPIO_voidSetPinValue(HLEDMAT_COL2_PORT_PIN, GPIO_PIN_HIGH);
    MGPIO_voidSetPinValue(HLEDMAT_COL3_PORT_PIN, GPIO_PIN_HIGH);
    MGPIO_voidSetPinValue(HLEDMAT_COL4_PORT_PIN, GPIO_PIN_HIGH);
    MGPIO_voidSetPinValue(HLEDMAT_COL5_PORT_PIN, GPIO_PIN_HIGH);
    MGPIO_voidSetPinValue(HLEDMAT_COL6_PORT_PIN, GPIO_PIN_HIGH);
    MGPIO_voidSetPinValue(HLEDMAT_COL7_PORT_PIN, GPIO_PIN_HIGH);
}

static void voidSetRowsValue(u8 Copy_u8Value)
{
    u8 Local_u8Bit;
    /*Set Rows Value*/
    Local_u8Bit = GET_BIT(Copy_u8Value, 0);
    MGPIO_voidSetPinValue(HLEDMAT_ROW0_PORT_PIN, Local_u8Bit);
    Local_u8Bit = GET_BIT(Copy_u8Value, 1);
    MGPIO_voidSetPinValue(HLEDMAT_ROW1_PORT_PIN, Local_u8Bit);
    Local_u8Bit = GET_BIT(Copy_u8Value, 2);
    MGPIO_voidSetPinValue(HLEDMAT_ROW2_PORT_PIN, Local_u8Bit);
    Local_u8Bit = GET_BIT(Copy_u8Value, 3);
    MGPIO_voidSetPinValue(HLEDMAT_ROW3_PORT_PIN, Local_u8Bit);
    Local_u8Bit = GET_BIT(Copy_u8Value, 4);
    MGPIO_voidSetPinValue(HLEDMAT_ROW4_PORT_PIN, Local_u8Bit);
    Local_u8Bit = GET_BIT(Copy_u8Value, 5);
    MGPIO_voidSetPinValue(HLEDMAT_ROW5_PORT_PIN, Local_u8Bit);
    Local_u8Bit = GET_BIT(Copy_u8Value, 6);
    MGPIO_voidSetPinValue(HLEDMAT_ROW6_PORT_PIN, Local_u8Bit);
    Local_u8Bit = GET_BIT(Copy_u8Value, 7);
    MGPIO_voidSetPinValue(HLEDMAT_ROW7_PORT_PIN, Local_u8Bit);
}