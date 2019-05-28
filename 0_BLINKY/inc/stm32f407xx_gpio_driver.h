/*************************************************************************************
 *
 *	Overview
 *	--------
 *	Macros, constants and data structures for implementing GPIO
 *
 *	Includes STM32F4XX
 *
 *
 *	Developed by
 *	------------
 *	Author	: Supreeth Anil
 *	Date	: 11-May-2019
 *
 *
 *  ==================================================================================
 *
 *  MIT License
 *
 *	Copyright (c) 2019 Supreeth Anil
 *
 *	Permission is hereby granted, free of charge, to any person obtaining a copy
 *	of this software and associated documentation files (the "Software"), to deal
 *	in the Software without restriction, including without limitation the rights
 *	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *	copies of the Software, and to permit persons to whom the Software is
 *	furnished to do so, subject to the following conditions:
 *
 *	The above copyright notice and this permission notice shall be included in all
 *	copies or substantial portions of the Software.
 *
 *	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 *	SOFTWARE.
 *
 *	==================================================================================
 *
 *
 *
 ************************************************************************************/

#ifndef __STM32F407XX_GPIO_DRIVER_H__
#define __STM32F407XX_GPIO_DRIVER_H__

#include<stdbool.h>
#include "stm32f407xx.h"
#include "stm32f407xx_rcc_driver.h"
#include "utils.h"

/* ---------------------------- GPIO Init Definition ------------------------------ */

typedef struct {

	uint8_t GPIO_Pin_Number;					/*!< Pin number ranges from 0-15 >*/
	uint8_t GPIO_Pin_Mode;						/*!< Possible values from @ref GPIO_PIN_MODES >*/
	uint8_t GPIO_Pin_Output_Type;				/*!< Possible values from @ref GPIO_OUTPUT_TYPES >*/
	uint8_t GPIO_Pin_Speed;						/*!< Possible values from @ref GPIO_PIN_OUTPUT_SPEEDS >*/
	uint8_t GPIO_Pin_PUPD_Config;				/*!< Possible values from @ref GPIO_PIN_PULL_UP_PULL_DOWN_CONFIGS >*/
	uint8_t GPIO_Pin_Alt_Func;					/*!< Possible values from  >*/

} GPIO_Pin_Config_TypeDef;


/* ---------------------------- GPIO Handle Definition ---------------------------- */

typedef struct {

	GPIO_TypeDef *pGPIOx;						/*!< Holds the base address of the GPIO port to which the pin belongs >*/
	GPIO_Pin_Config_TypeDef GPIO_Pin_Congig;	/*!< Holds the GPIO Pin configuration settings >*/

} GPIO_Handle_TypeDef;



/* Each GPIO Port in STM32 is a collection of 16 Pins */

#define PORT_LENGTH				16U


/* ------------------------------ GPIO_PIN_MODES----------------------------------- */

#define GPIO_MODE_INPUT			0U
#define GPIO_MODE_OUTPUT		1U
#define GPIO_MODE_ALT_FN		2U
#define GPIO_MODE_ANALOG		3U
#define GPIO_MODE_INT_RT		4U
#define GPIO_MODE_INT_FT		5U
#define GPIO_MODE_INT_BOTH		6U

/* ------------------------------ GPIO_OUTPUT_TYPES -------------------------------- */

#define GPIO_OP_TYPE_PP			0U
#define GPIO_OP_TYPE_OD			1U



/* ------------------------- GPIO_PIN_OUTPUT_SPEEDS -------------------------------- */

#define GPIO_SPEED_LOW			0U
#define GPIO_SPEED_MEDIUM		1U
#define GPIO_SPEED_FAST			2U
#define GPIO_SPEED_HIGH			3U



/* -------------------- GPIO_PIN_PULL_UP_PULL_DOWN_CONFIGS -------------------------- */

#define GPIO_PUPD_NONE			0U
#define GPIO_PIN_PU				1U
#define GPIO_PIN_PD				2U













/* ------------------- GPIO Pin Number Definition for Port A ----------------------- */


#define PA0		_BV(0)
#define PA1		_BV(1)
#define PA2		_BV(2)
#define PA3		_BV(3)
#define PA4		_BV(4)
#define PA5		_BV(5)
#define PA6		_BV(6)
#define PA7		_BV(7)
#define PA8		_BV(8)
#define PA9		_BV(9)
#define PA10	_BV(10)
#define PA11	_BV(11)
#define PA12	_BV(12)
#define PA13	_BV(13)
#define PA14	_BV(14)
#define PA15	_BV(15)



/* ------------------- GPIO Pin Number Definition for Port B ----------------------- */


#define PB0		_BV(0)
#define PB1		_BV(1)
#define PB2		_BV(2)
#define PB3		_BV(3)
#define PB4		_BV(4)
#define PB5		_BV(5)
#define PB6		_BV(6)
#define PB7		_BV(7)
#define PB8		_BV(8)
#define PB9		_BV(9)
#define PB10	_BV(10)
#define PB11	_BV(11)
#define PB12	_BV(12)
#define PB13	_BV(13)
#define PB14	_BV(14)
#define PB15	_BV(15)



/* ------------------- GPIO Pin Number Definition for Port C ----------------------- */


#define PC0		_BV(0)
#define PC1		_BV(1)
#define PC2		_BV(2)
#define PC3		_BV(3)
#define PC4		_BV(4)
#define PC5		_BV(5)
#define PC6		_BV(6)
#define PC7		_BV(7)
#define PC8		_BV(8)
#define PC9		_BV(9)
#define PC10	_BV(10)
#define PC11	_BV(11)
#define PC12	_BV(12)
#define PC13	_BV(13)
#define PC14	_BV(14)
#define PC15	_BV(15)



/* ------------------- GPIO Pin Number Definition for Port D ----------------------- */


#define PD0		_BV(0)
#define PD1		_BV(1)
#define PD2		_BV(2)
#define PD3		_BV(3)
#define PD4		_BV(4)
#define PD5		_BV(5)
#define PD6		_BV(6)
#define PD7		_BV(7)
#define PD8		_BV(8)
#define PD9		_BV(9)
#define PD10	_BV(10)
#define PD11	_BV(11)
#define PD12	_BV(12)
#define PD13	_BV(13)
#define PD14	_BV(14)
#define PD15	_BV(15)



/* ------------------- GPIO Pin Number Definition for Port E ----------------------- */


#define PE0		_BV(0)
#define PE1		_BV(1)
#define PE2		_BV(2)
#define PE3		_BV(3)
#define PE4		_BV(4)
#define PE5		_BV(5)
#define PE6		_BV(6)
#define PE7		_BV(7)
#define PE8		_BV(8)
#define PE9		_BV(9)
#define PE10	_BV(10)
#define PE11	_BV(11)
#define PE12	_BV(12)
#define PE13	_BV(13)
#define PE14	_BV(14)
#define PE15	_BV(15)



/* ------------------- GPIO Pin Number Definition for Port F ----------------------- */


#define PF0		_BV(0)
#define PF1		_BV(1)
#define PF2		_BV(2)
#define PF3		_BV(3)
#define PF4		_BV(4)
#define PF5		_BV(5)
#define PF6		_BV(6)
#define PF7		_BV(7)
#define PF8		_BV(8)
#define PF9		_BV(9)
#define PF10	_BV(10)
#define PF11	_BV(11)
#define PF12	_BV(12)
#define PF13	_BV(13)
#define PF14	_BV(14)
#define PF15	_BV(15)




/* ------------------- GPIO Pin Number Definition for Port G ----------------------- */


#define PG0		_BV(0)
#define PG1		_BV(1)
#define PG2		_BV(2)
#define PG3		_BV(3)
#define PG4		_BV(4)
#define PG5		_BV(5)
#define PG6		_BV(6)
#define PG7		_BV(7)
#define PG8		_BV(8)
#define PG9		_BV(9)
#define PG10	_BV(10)
#define PG11	_BV(11)
#define PG12	_BV(12)
#define PG13	_BV(13)
#define PG14	_BV(14)
#define PG15	_BV(15)




/* ------------------- GPIO Pin Number Definition for Port H ----------------------- */


#define PH0		_BV(0)
#define PH1		_BV(1)
#define PH2		_BV(2)
#define PH3		_BV(3)
#define PH4		_BV(4)
#define PH5		_BV(5)
#define PH6		_BV(6)
#define PH7		_BV(7)
#define PH8		_BV(8)
#define PH9		_BV(9)
#define PH10	_BV(10)
#define PH11	_BV(11)
#define PH12	_BV(12)
#define PH13	_BV(13)
#define PH14	_BV(14)
#define PH15	_BV(15)




/* ------------------- GPIO Pin Number Definition for Port I ----------------------- */


#define PI0		_BV(0)
#define PI1		_BV(1)
#define PI2		_BV(2)
#define PI3		_BV(3)
#define PI4		_BV(4)
#define PI5		_BV(5)
#define PI6		_BV(6)
#define PI7		_BV(7)
#define PI8		_BV(8)
#define PI9		_BV(9)
#define PI10	_BV(10)
#define PI11	_BV(11)
#define PI12	_BV(12)
#define PI13	_BV(13)
#define PI14	_BV(14)
#define PI15	_BV(15)








#define GET_PORT_CODE(port)	(((port) == (GPIOA)) ? 0U : \
							 ((port) == (GPIOB)) ? 1U : \
							 ((port) == (GPIOC)) ? 2U : \
							 ((port) == (GPIOD)) ? 3U : \
							 ((port) == (GPIOE)) ? 4U : \
							 ((port) == (GPIOF)) ? 5U : \
							 ((port) == (GPIOG)) ? 6U : \
							 ((port) == (GPIOH)) ? 7U : 8U)




/*************************************************************************************
 *
 * 						APIs supported by GPIO drivers
 * 		For more information about the APIs check the function definition
 *
 ************************************************************************************/


/* GPIO Clock Handle API */

void GPIO_Clock_Enable(GPIO_TypeDef *pGPIOx);
void GPIO_Clock_Disable(GPIO_TypeDef *pGPIOx);

/* GPIO Initializing API and API for resetting GPIO Port Settings */

void GPIO_Init(GPIO_Handle_TypeDef *pGPIOHandle);
void GPIO_De_Init(GPIO_TypeDef *pGPIOx);


/* GPIO Data Read and Write APIs */

bool GPIO_Pin_Read(GPIO_TypeDef *pGPIOx, uint8_t pin);
uint16_t GPIO_Port_Read(GPIO_TypeDef *pGPIOx);
void GPIO_Pin_Write(GPIO_TypeDef *pGPIOx, uint8_t pin, bool value);
void GPIO_Port_Write(GPIO_TypeDef *pGPIOx, uint16_t value);
void GPIO_Pin_Toggle(GPIO_TypeDef *pGPIOx, uint8_t pin);


/* GPIO IRQ Handling APIs */

void GPIO_IRQ_Init(void);
void GPIO_IRQ_Handler(void);




#endif				/* __STM32F407XX_GPIO_DRIVER_H__ */













