/*************************************************************************************
 *
 *	Overview
 *	--------
 *	Driver layer provides subroutines for initializing and accessing GPIO
 *
 *	Runs on STM32F4XX
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


#include "stm2f407xx_gpio_driver.h"



/*************************************************************************************
 *
 *	@brief	- Enable Clock for the specified GPIO Port
 *
 *	@param	- pGPIOx Base Address of the GPIO Port to which the pin belongs
 *
 *	@return	- None
 *
 *	@note	- Ports F, G and I are not available in devices with 100-pin packages
 *
 ************************************************************************************/

void GPIO_Clock_Enable(GPIO_TypeDef *pGPIOx)
{
	if (pGPIOx == GPIOA) {
		RCC->AHB1ENR |= _BV(0);
	} else if (pGPIOx == GPIOB) {
		RCC->AHB1ENR |= _BV(1);
	} else if (pGPIOx == GPIOC) {
		RCC->AHB1ENR |= _BV(2);
	} else if (pGPIOx == GPIOD) {
		RCC->AHB1ENR |= _BV(3);
	} else if (pGPIOx == GPIOE) {
		RCC->AHB1ENR |= _BV(4);
	} else if (pGPIOx == GPIOF) {
		RCC->AHB1ENR |= _BV(5);
	} else if (pGPIOx == GPIOG) {
		RCC->AHB1ENR |= _BV(6);
	} else if (pGPIOx == GPIOH) {
		RCC->AHB1ENR |= _BV(7);
	} else if (pGPIOx == GPIOI) {
		RCC->AHB1ENR |= _BV(8);
	}
}



/*************************************************************************************
 *
 *	@brief	- Disable Clock for the specified GPIO Port
 *
 *	@param	- pGPIOx Base Address of the GPIO Port to which the pin belongs
 *
 *	@return	- None
 *
 *	@note	- Ports F, G and I are not available in devices with 100-pin packages
 *
 ************************************************************************************/
void GPIO_Clock_Disable(GPIO_TypeDef *pGPIOx)
{
	if (pGPIOx == GPIOA) {
		RCC->AHB1ENR &= ~_BV(0);
	} else if (pGPIOx == GPIOB) {
		RCC->AHB1ENR &= ~_BV(1);
	} else if (pGPIOx == GPIOC) {
		RCC->AHB1ENR &= ~_BV(2);
	} else if (pGPIOx == GPIOD) {
		RCC->AHB1ENR &= ~_BV(3);
	} else if (pGPIOx == GPIOE) {
		RCC->AHB1ENR &= ~_BV(4);
	} else if (pGPIOx == GPIOF) {
		RCC->AHB1ENR &= ~_BV(5);
	} else if (pGPIOx == GPIOG) {
		RCC->AHB1ENR &= ~_BV(6);
	} else if (pGPIOx == GPIOH) {
		RCC->AHB1ENR &= ~_BV(7);
	} else if (pGPIOx == GPIOI) {
		RCC->AHB1ENR &= ~_BV(8);
	}
}



/*************************************************************************************
 *
 *	@brief	- Initialize GPIO port with the given configuration settings
 *
 *	@param	- pGPIOHandle 	Data structure containing Base address of the Port, and
 *						  	other configuration parameters such as pin no, mode, output
 *						  	type, speed, PUPD register settings and alternate functions
 *
 *	@return	- None
 *
 *	@note	- Ports F, G and I are not available in devices with 100-pin packages
 *
 ************************************************************************************/
void GPIO_Init(GPIO_Handle_TypeDef *pGPIOHandle)
{
	(void)pGPIOHandle;
}

