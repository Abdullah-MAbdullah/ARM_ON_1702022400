/*********************************************
 * Author:				Abdullah M. Abdullah
 * Creation Data:		16 Mar, 2024
 * Version:				v1.0
 * Compiler:			GNU ARM-GCC
 * Controller:			STM32F401CCU6
 * Layer:				MCAL
 ********************************************/
/*********************************************
 * Version	  Date				  Author				  Description
 * v1.0		  16 Mar, 2024	Abdullah M. Abdullah		  Initial Creation
*********************************************/
#include "../include/STD_TYPES.h"
#include "../include/BIT_MATH.h"

#include "../include/NVIC_interface.h"
#include "../include/NVIC_private.h"
#include "../include/NVIC_config.h"

void MNVIC_voidInit(void)
{
    #define SCB_AIRCR       *((volatile u32 *)0xE000ED00+0x0C)
    /*Set The Group And Sub Priorities Distribution*/
    SCB_AIRCR |= (AIRCR_PRIVKEY << 16) | (MNVIC_GRP_SUB_DISTRIBUTION << 8);
}

void MNVIC_voidPeripheralInterruptControl(u8 Copy_u8PeripheralID, u8 Copy_u8InterruptState)
{
    u8 Local_u8RegisterIndex = 0;
    Local_u8RegisterIndex = Copy_u8PeripheralID / 32;
    switch(Copy_u8InterruptState)
    {
        case MNVIC_INT_ENABLE:
            NVIC -> ISER[Local_u8RegisterIndex] = (1 << (Copy_u8PeripheralID % 32));
        break;

        case MNVIC_INT_DISABLE:
            NVIC -> ICER[Local_u8RegisterIndex] = (1 << (Copy_u8PeripheralID % 32));
        break;
        
        default:
            // Error
        break;
    }
}

/**
void MNVIC_voidPeripheralInterruptControl(u8 Copy_u8PeripheralID,  NVIC_INT_CTRL_t Copy_tInterruptState)
{
    u8 Local_u8RegisterIndex = 0;
    Local_u8RegisterIndex = Copy_u8PeripheralID / 32;
    switch(Copy_tInterruptState)
    {
        case MNVIC_INT_ENABLE:
            NVIC -> ISER[Local_u8RegisterIndex] = (1 << (Copy_u8PeripheralID % 32));
        break;

        case MNVIC_INT_DISABLE:
            NVIC -> ICER[Local_u8RegisterIndex] = (1 << (Copy_u8PeripheralID % 32));
        break;
        
        default:
            // Error
        break;
    }
}
**/


void MNVIC_voidSetPendingFlag(u8 Copy_u8PeripheralID)
{
    if(Copy_u8PeripheralID <= 239)
    {
        u8 Local_u8RegisterIndex = 0;
        Local_u8RegisterIndex = Copy_u8PeripheralID / 32;
        NVIC -> ISPR[Local_u8RegisterIndex] = (1 << ((Copy_u8PeripheralID % 32)));
    }
}

/*Task*/ 
void MNVIC_voidClearPendingFlag()
{

}

/*Task*/ 
u8 MNVIC_u8GetActiveFlag(u8 Copy_u8PeripheralID)
{

}

void MNVIC_voidSetPeripheralPriority(u8 Copy_u8PeripheralID, u8 Copy_u8Priority)
{
	NVIC -> IP[Copy_u8PeripheralID] = (Copy_u8Priority << 4);
}
