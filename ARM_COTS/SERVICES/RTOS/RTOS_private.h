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
#ifndef RTOS_PRIVATE_H
#define RTOS_PRIVATE_H


typedef enum
{
    TASK_DELETED,
    TASK_READY,
    TASK_RUNNING,
    TASK_SUSPENDED
}Task_State_t;

typedef struct
{
    u8 Priority;
    u32 Periodicity;
    Task_State_t TaskState;
    void (*TaskFunctionCallback)(void);
}RTOS_t;

static void voidScheduler(void);

#endif