/*********************************************
 * Author:				Abdullah M. Abdullah
 * Creation Data:		29 Mar, 2024
 * Version:				v1.0
 * Compiler:			GNU ARM-GCC
 * Controller:			STM32F401CCU6
 * Layer:				MCAL
 ********************************************/
/*********************************************
 * Version	  Date				  Author				  Description
 * v1.0		  29 Mar, 2024	Abdullah M. Abdullah		  Initial Creation
*********************************************/
#include "../include/STD_TYPES.h"
#include "../include/BIT_MATH.h"

#include "../include/EXTI_interface.h"
#include "../include/EXTI_private.h"
#include "../include/EXTI_config.h"

// static void (*EXTI0_pNotificationFunction)(void) = NULLPTR;
// static void (*EXTI1_pNotificationFunction)(void) = NULLPTR;

// Array Of Pointers to Function
static void (*EXTI_pNotificationFunction[16])(void) = {NULLPTR};


// Task
void MEXTI_voidInit(void)
{

}

void MEXTI_voidEnableInterrupt(MEXTI_INTERRUPT_LINE_t Copy_tInterrupLine)
{
    SET_BIT(EXTI->IMR, Copy_tInterrupLine);
}

void MEXTI_voidDisableInterrupt(MEXTI_INTERRUPT_LINE_t Copy_tInterrupLine)
{
    CLR_BIT(EXTI->IMR, Copy_tInterrupLine);
}

void MEXTI_voidChangeSenseMode(MEXTI_INTERRUPT_LINE_t Copy_tInterrupLine, MEXTI_INTERRUPT_SENSE_SIGNAL_t Copy_tSenseSignal)
{
    switch(Copy_tSenseSignal)
    {
        case MEXTI_RISING:
            CLR_BIT(EXTI->FTSR, Copy_tInterrupLine);
            SET_BIT(EXTI->RTSR, Copy_tInterrupLine);
        break;

        case MEXTI_FALLING:
            CLR_BIT(EXTI->RTSR, Copy_tInterrupLine);
            SET_BIT(EXTI->FTSR, Copy_tInterrupLine);
        break;

        case MEXTI_ONCHANGE:
            SET_BIT(EXTI->RTSR, Copy_tInterrupLine);
            SET_BIT(EXTI->FTSR, Copy_tInterrupLine);
        break;

        default:
        break;
    }
}

void MEXTI_voidSetCallBack(MEXTI_INTERRUPT_LINE_t Copy_tInterrupLine, void (*pCallBackFunction)(void))
{
    switch(Copy_tInterrupLine)
    {
        case MEXTI_EXTI0:
            // EXTI0_pNotificationFunction = pCallBackFunction;
            EXTI_pNotificationFunction[Copy_tInterrupLine] = pCallBackFunction;
        break;
        case MEXTI_EXTI1:
            // EXTI1_pNotificationFunction = pCallBackFunction;
            EXTI_pNotificationFunction[Copy_tInterrupLine] = pCallBackFunction;

        break;
    }
}

// ISR For EXTI0
void EXTI0_IRQHandler(void)
{
    // if(EXTI0_pNotificationFunction != NULLPTR)
    if(EXTI_pNotificationFunction[0] != NULLPTR)
    {
        // EXTI0_pNotificationFunction();
        EXTI_pNotificationFunction[0]();
    }
    else
    {
        // Do Nothing
    }
    // Flag Clearance
    SET_BIT(EXTI->PR, 0);
}

// ISR For EXTI1
void EXTI1_IRQHandler(void)
{
    if(EXTI_pNotificationFunction[1] != NULLPTR)
    {
    	EXTI_pNotificationFunction[1]();
    }
    else
    {
        // Do Nothing
    }
    // Flag Clearance
    SET_BIT(EXTI->PR, 1);
}


