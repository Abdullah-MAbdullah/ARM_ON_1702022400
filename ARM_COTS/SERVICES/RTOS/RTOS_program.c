/****************************************************************************************
* Author:				Abdullah M. Abdullah
* Creation Data:		18 May, 2024
* Version:				v1.0
* Compiler:				GNU ARM-GCC
* Controller:			STM32F401CCU6
* Layer:				SERVICE
****************************************************************************************/
/***************************************************************************************
* Version	  Date				  	Author				  			Description
* v1.0		  18 May, 2024			Abdullah M. Abdullah		  	Initial Creation
***************************************************************************************/
#include "../include/STD_TYPES.h"
#include "../include/BIT_MATH.h"

#include "../include/STK_interface.h"

#include "../include/RTOS_interface.h"
#include "../include/RTOS_private.h"
#include "../include/RTOS_config.h"

RTOS_t SystemTasks[NUM_OF_TASKS];

void SRTOS_voidInit(void)
{
    // Initialize STK
    STK_voidInit();
    // Set the callback for the STK
    MSTK_voidSetPeriodicInterval(1000000, &voidScheduler);
}

void SRTOS_voidCreateTask(u8 Copy_u8Priority, u32 Copy_u32Periodicity, void (*TaskFunction)(void))
{
    SystemTasks[Copy_u8Priority].Copy_u8Priority = Copy_u8Priority;
    SystemTasks[Copy_u8Priority].Periodicity = Copy_u32Periodicity;
    SystemTasks[Copy_u8Priority].TaskFunctionCallback = TaskFunction;
    SystemTasks[Copy_u8Priority].TaskState = TASK_READY;
}

void SRTOS_voidDeleteTask(u8 Copy_u8Priority)
{
    SystemTasks[Copy_u8Priority].TaskState = TASK_DELETED;
}

static void voidScheduler(void)
{
    /*Algorithm = Priodity Based*/
    static u32 Local_u32TickCounter = 0;
    Local_u32TickCounter++;
    u8 Local_u8LoopCounter = 0;
    for(Local_u8LoopCounter = 0; Local_u8LoopCounter < NUM_OF_TASKS; Local_u8LoopCounter++)
    {
        if(SystemTasks[Local_u8LoopCounter].TaskState == TASK_READY)
        {
            if(SystemTasks[Local_u8LoopCounter].TaskFunctionCallback != NULLPTR)
            {
                if(Local_u32TickCounter % SystemTasks[Local_u8LoopCounter].Periodicity == 0)
                {
                    SystemTasks[Local_u8LoopCounter].TaskState = TASK_RUNNING;
                    // Invoke the Task Function
                    SystemTasks[Local_u8LoopCounter].TaskFunctionCallback();
                    SystemTasks[Local_u8LoopCounter].TaskState = TASK_READY;
                }
            }
        }
    }
}
