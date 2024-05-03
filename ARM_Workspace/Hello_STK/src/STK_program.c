/*********************************************
 * Author:				Abdullah M. Abdullah
 * Creation Data:		02 Mar, 2024
 * Version:				v1.0
 * Compiler:			GNU ARM-GCC
 * Controller:			STM32F401CCU6
 * Layer:				MCAL
 ********************************************/
/*********************************************
 * Version	  Date				  Author				  Description
 * v1.0		  02 Mar, 2024	Abdullah M. Abdullah		  Initial Creation
*********************************************/
#include "../include/STD_TYPES.h"
#include "../include/BIT_MATH.h"

#include "../include/STK_interface.h"
#include "../include/STK_private.h"
#include "../include/STK_config.h"

void MSTK_voidInit(void)
{
    // Choose the Clock Source For Systick
    #if STK_CLK_SRC == STK_AHB
        SET_BIT(STK->CTRL, 2);
    #elif STK_CLK_SRC == STK_AHB_DIV_8
        CLR_BIT(STK->CTRL, 2);
    #else
        #error "STK_CLK_SRC Configuration Error"
    #endif

    // Control The Systick Interrupt
    #if STK_INT_CTRL == STK_DISABLE
        CLR_BIT(STK->CTRL, 1);
    #elif STK_INT_CTRL == STK_ENABLE
        SET_BIT(STK->CTRL, 1);
    #else
        #error "STK_INT_CTRL Configuration Error"
    #endif

    // Control The Systick Enable/Disable
    #if STK_CTRL == STK_DISABLE
        CLR_BIT(STK->CTRL, 0);
    #elif STK_CTRL == STK_ENABLE
        SET_BIT(STK->CTRL, 0);
    #else
        #error "STK_CTRL Configuration Error"
    #endif
}

void MSTK_voidSetBusyWait(u32 Copy_u32Ticks)
{
    // Load The Ticks Value into the LOAD Register
    STK -> LOAD = Copy_u32Ticks;
    // Polling (Busy Wait) on the flag
    while(GET_BIT(STK->CTRL, 16) == 0);
    // Flag Clearance
    STK -> VAL = 0;
}
