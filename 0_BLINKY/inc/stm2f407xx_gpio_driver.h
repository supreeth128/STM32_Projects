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

#ifndef __GPIO_DRIVER_H__
#define __GPIO_DRIVER_H__

#include<stdbool.h>
#include "stm32f407xx.h"
#include "utils.h"

/* ---------------------------- GPIO Init Definition ------------------------------ */

typedef struct {

	uint8_t GPIO_Pin_Number;					/*!< Pin number ranges from 0-15 >*/
	uint8_t GPIO_Pin_Mode;						/*!< Possible values from @GPIO_PIN_MODES >*/
	uint8_t GPIO_Pin_Output_Type;				/*!< Possible values from @GPIO_OUTPUT_TYPES >*/
	uint8_t GPIO_Pin_Speed;						/*!< Possible values from @GPIO_PIN_OUTPUT_SPEEDS >*/
	uint8_t GPIO_Pin_PUPD_Config;				/*!< Possible values from @GPIO_PIN_PULL_UP_PULL_DOWN_CONFIGS >*/
	uint8_t GPIO_Pin_Alt_Func;					/*!< Possible values from  >*/

} GPIO_Pin_Config_TypeDef;


/* ---------------------------- GPIO Handle Definition ---------------------------- */

typedef struct {

	GPIO_TypeDef *pGPIOx;						/*!< Holds the base address of the GPIO port to which the pin belongs >*/
	GPIO_Pin_Config_TypeDef *GPIO_Pin_Congig;	/*!< Holds the GPIO Pin configuration settings >*/

} GPIO_Handle_TypeDef;




/* ------------------------------ @GPIO_PIN_MODES----------------------------------- */

#define GPIO_MODE_INPUT			0
#define GPIO_MODE_OUTPUT		1
#define GPIO_MODE_ALT_FN		2
#define GPIO_MODE_ANALOG		3



/* ------------------------------ @GPIO_OUTPUT_TYPES -------------------------------- */

#define GPIO_OP_TYPE_PP			0
#define GPIO_OP_TYPE_OD			1



/* ------------------------- @GPIO_PIN_OUTPUT_SPEEDS -------------------------------- */

#define GPIO_SPEED_LOW			0
#define GPIO_SPEED_MEDIUM		1
#define GPIO_SPEED_FAST			2
#define GPIO_SPEED_HIGH			3



/* -------------------- @GPIO_PIN_PULL_UP_PULL_DOWN_CONFIGS -------------------------- */

#define GPIO_PUPD_NONE			0
#define GPIO_PIN_PU				1
#define GPIO_PIN_PD				2













/* ------------------- GPIO Pin Number Definition for Port A ----------------------- */


#define PA0		0
#define PA1		1
#define PA2		2
#define PA3		3
#define PA4		4
#define PA5		5
#define PA6		6
#define PA7		7
#define PA8		8
#define PA9		9
#define PA10	10
#define PA11	11
#define PA12	12
#define PA13	13
#define PA14	14
#define PA15	15



/* ------------------- GPIO Pin Number Definition for Port B ----------------------- */


#define PB0		0
#define PB1		1
#define PB2		2
#define PB3		3
#define PB4		4
#define PB5		5
#define PB6		6
#define PB7		7
#define PB8		8
#define PB9		9
#define PB10	10
#define PB11	11
#define PB12	12
#define PB13	13
#define PB14	14
#define PB15	15



/* ------------------- GPIO Pin Number Definition for Port C ----------------------- */


#define PC0		0
#define PC1		1
#define PC2		2
#define PC3		3
#define PC4		4
#define PC5		5
#define PC6		6
#define PC7		7
#define PC8		8
#define PC9		9
#define PC10	10
#define PC11	11
#define PC12	12
#define PC13	13
#define PC14	14
#define PC15	15



/* ------------------- GPIO Pin Number Definition for Port D ----------------------- */


#define PD0		0
#define PD1		1
#define PD2		2
#define PD3		3
#define PD4		4
#define PD5		5
#define PD6		6
#define PD7		7
#define PD8		8
#define PD9		9
#define PD10	10
#define PD11	11
#define PD12	12
#define PD13	13
#define PD14	14
#define PD15	15



/* ------------------- GPIO Pin Number Definition for Port E ----------------------- */


#define PE0		0
#define PE1		1
#define PE2		2
#define PE3		3
#define PE4		4
#define PE5		5
#define PE6		6
#define PE7		7
#define PE8		8
#define PE9		9
#define PE10	10
#define PE11	11
#define PE12	12
#define PE13	13
#define PE14	14
#define PE15	15



/* ------------------- GPIO Pin Number Definition for Port F ----------------------- */


#define PF0		0
#define PF1		1
#define PF2		2
#define PF3		3
#define PF4		4
#define PF5		5
#define PF6		6
#define PF7		7
#define PF8		8
#define PF9		9
#define PF10	10
#define PF11	11
#define PF12	12
#define PF13	13
#define PF14	14
#define PF15	15




/* ------------------- GPIO Pin Number Definition for Port G ----------------------- */


#define PG0		0
#define PG1		1
#define PG2		2
#define PG3		3
#define PG4		4
#define PG5		5
#define PG6		6
#define PG7		7
#define PG8		8
#define PG9		9
#define PG10	10
#define PG11	11
#define PG12	12
#define PG13	13
#define PG14	14
#define PG15	15




/* ------------------- GPIO Pin Number Definition for Port H ----------------------- */


#define PH0		0
#define PH1		1
#define PH2		2
#define PH3		3
#define PH4		4
#define PH5		5
#define PH6		6
#define PH7		7
#define PH8		8
#define PH9		9
#define PH10	10
#define PH11	11
#define PH12	12
#define PH13	13
#define PH14	14
#define PH15	15




/* ------------------- GPIO Pin Number Definition for Port I ----------------------- */


#define PI0		0
#define PI1		1
#define PI2		2
#define PI3		3
#define PI4		4
#define PI5		5
#define PI6		6
#define PI7		7
#define PI8		8
#define PI9		9
#define PI10	10
#define PI11	11
#define PI12	12
#define PI13	13
#define PI14	14
#define PI15	15









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




#endif				/* __GPIO_DRIVER_H__ */













