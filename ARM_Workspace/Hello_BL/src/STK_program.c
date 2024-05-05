/*********************************************
 * Author:				Abdullah M. Abdullah
 * Creation Data:		02 Mar, 2024
 * Version:				v3.0
 * Compiler:			GNU ARM-GCC
 * Controller:			STM32F401CCU6
 * Layer:				MCAL
 ********************************************/
/*********************************************
 * Version	  Date				  Author				  Description
 * v1.0		  02 Mar, 2024	Abdullah M. Abdullah		  Initial Creation
 * v2.0		  30 Mar, 2024	Abdullah M. Abdullah		  Add New APIs 
 *                                                        - MSTK_u32GetRemainingTime
 *                                                        - MSTK_u32GetElapsedTime
 *                                                        - MSTK_voidResetTimer
 *                                                        - MSTK_voidSetPreloadValue
 *                                                        - MSTK_voidSetSingleInterval
 *                                                        - MSTK_voidSetPeriodicInterval
 *                                                        - SysTick_Handler
 
 * v2.1		  30 Mar, 2024	Abdullah M. Abdullah		  Fix the build error
 
 * v3.0		  30 Mar, 2024	Abdullah M. Abdullah		  Add New APIs 
 *                                                        - MSTK_voidSTKEnable
 *                                                        - MSTK_voidSTKDisable
*********************************************/
#include "../include/STD_TYPES.h"
#include "../include/BIT_MATH.h"

#include "../include/STK_interface.h"
#include "../include/STK_private.h"
#include "../include/STK_config.h"

static void (*pNotificationFunction)(void) = NULLPTR;
static u8IntervalTypeFlag = SINGLE_INTERVAL;

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

u32 MSTK_u32GetRemainingTime(void)
{
    u32 Local_u32RemainingTime;
    Local_u32RemainingTime = STK -> VAL;
    return Local_u32RemainingTime;
}

u32 MSTK_u32GetElapsedTime(void)
{
    u32 Local_u32ElapsedTime;
    Local_u32ElapsedTime =  STK -> LOAD - STK -> VAL;
    return Local_u32ElapsedTime;
}

void MSTK_voidResetTimer(void)
{
    STK -> VAL = 0;
}

void MSTK_voidSTKEnable(void)
{
	SET_BIT(STK->CTRL, 0);
}

void MSTK_voidSTKDisable(void)
{
	CLR_BIT(STK->CTRL, 0);
}

void MSTK_voidSetPreloadValue(u32 Copy_u32PreloadValue)
{
	STK -> VAL = 0;
    STK -> LOAD = Copy_u32PreloadValue;
}

void MSTK_voidSetSingleInterval(u32 Copy_u32Ticks, void (*CallBackFunction) (void))
{
	STK -> VAL = 0;
	CLR_BIT(STK->CTRL, 0);
	u8IntervalTypeFlag = SINGLE_INTERVAL;
	STK -> LOAD = Copy_u32Ticks;

	SET_BIT(STK->CTRL, 1);
	SET_BIT(STK->CTRL, 0);

	pNotificationFunction = CallBackFunction;
}

void MSTK_voidSetPeriodicInterval(void (*CallBackFunction) (void))
{
    pNotificationFunction = CallBackFunction;
    u8IntervalTypeFlag = PERIODIC_INTERVAL;
}

void SysTick_Handler(void)
{
    u8 LocalTempVar = 0;
    if(u8IntervalTypeFlag == SINGLE_INTERVAL)
    {
        // Disable Timer
        STK -> LOAD = 0;
        STK -> VAL = 0;
        CLR_BIT(STK->CTRL, 0);
    }
    if(pNotificationFunction != NULLPTR)
    {
        pNotificationFunction();
    }
    // Flag Clearance
    LocalTempVar = GET_BIT(STK -> CTRL, 16);
    STK -> VAL = 0;
}
