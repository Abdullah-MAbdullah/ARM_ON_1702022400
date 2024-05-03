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
#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H

typedef enum
{
    MEXTI_EXTI0 = 0,
    MEXTI_EXTI1,
    MEXTI_EXTI2,
    MEXTI_EXTI3,
    MEXTI_EXTI4,
    MEXTI_EXTI5,
    MEXTI_EXTI6,
    MEXTI_EXTI7,
    MEXTI_EXTI8,
    MEXTI_EXTI9,
    MEXTI_EXTI10,
    MEXTI_EXTI11,
    MEXTI_EXTI12,
    MEXTI_EXTI13,
    MEXTI_EXTI14,
    MEXTI_EXTI15,
}MEXTI_INTERRUPT_LINE_t;

typedef enum
{
    MEXTI_RISING = 0,
    MEXTI_FALLING,
    MEXTI_ONCHANGE
}MEXTI_INTERRUPT_SENSE_SIGNAL_t;

void MEXTI_voidInit(void);
void MEXTI_voidEnableInterrupt(MEXTI_INTERRUPT_LINE_t Copy_tInterrupLine);
void MEXTI_voidDisableInterrupt(MEXTI_INTERRUPT_LINE_t Copy_tInterrupLine);
void MEXTI_voidChangeSenseMode(MEXTI_INTERRUPT_LINE_t Copy_tInterrupLine, MEXTI_INTERRUPT_SENSE_SIGNAL_t Copy_tSenseSignal);
void MEXTI_voidSetCallBack(MEXTI_INTERRUPT_LINE_t Copy_tInterrupLine, void (*pCallBackFunction)(void));

#endif