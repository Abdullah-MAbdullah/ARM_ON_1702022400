/****************************************************************************************
* Author:				Abdullah M. Abdullah
* Creation Data:		06 Apr, 2024
* Version:				v1.0
* Compiler:				GNU ARM-GCC
* Controller:			STM32F401CCU6
* Layer:				MCAL
****************************************************************************************/
/***************************************************************************************
* Version	  Date				  	Author				  			Description
* v1.0		  06 Apr, 2024			Abdullah M. Abdullah		  	Initial Creation
***************************************************************************************/
#ifndef SPI_PRIVATE_H
#define SPI_PRIVATE_H

typedef struct
{
    volatile u32 CR1;
    volatile u32 CR2;
    volatile u32 SR;
    volatile u32 DR;
}SPI_t;


#define      MSPI1      ((volatile SPI_t *)0x40013000)
#define      MSPI2      ((volatile SPI_t *)0x40003800)
#define      MSPI3      ((volatile SPI_t *)0x40003C00)
#define      MSPI4      ((volatile SPI_t *)0x40013400)

#endif