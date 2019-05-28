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


#include <stm32f407xx_gpio_driver.h>




/*************************************************************************************
 *
 *	@brief	- Enable clock for the specified GPIO Port
 *
 *	@param	- pGPIOx        Base Address of the Port. E.g:- GPIOA, GPIOB etc.
 *
 *	@return	- None
 *
 *	@note	- Ports F, G and I are not available in devices with 100-pin packages
 *
 ************************************************************************************/

void GPIO_Clock_Enable(GPIO_TypeDef *pGPIOx)
{
	if (pGPIOx == GPIOA) {
		RCC_GPIOA_CLK_ENABLE();
	} else if (pGPIOx == GPIOB) {
		RCC_GPIOB_CLK_ENABLE();
	} else if (pGPIOx == GPIOC) {
		RCC_GPIOC_CLK_ENABLE();
	} else if (pGPIOx == GPIOD) {
		RCC_GPIOD_CLK_ENABLE();
	} else if (pGPIOx == GPIOE) {
		RCC_GPIOE_CLK_ENABLE();
	} else if (pGPIOx == GPIOF) {
		RCC_GPIOF_CLK_ENABLE();
	} else if (pGPIOx == GPIOG) {
		RCC_GPIOG_CLK_ENABLE();
	} else if (pGPIOx == GPIOH) {
		RCC_GPIOH_CLK_ENABLE();
	} else if (pGPIOx == GPIOI) {
		RCC_GPIOI_CLK_ENABLE();
	}
}



/*************************************************************************************
 *
 *	@brief	- Disable clock for the specified GPIO Port
 *
 *	@param	- pGPIOx        Base Address of the Port. E.g:- GPIOA, GPIOB etc.
 *
 *	@return	- None
 *
 *	@note	- Ports F, G and I are not available in devices with 100-pin packages
 *
 ************************************************************************************/

void GPIO_Clock_Disable(GPIO_TypeDef *pGPIOx)
{
	if (pGPIOx == GPIOA) {
		RCC_GPIOA_CLK_DISABLE();
	} else if (pGPIOx == GPIOB) {
		RCC_GPIOB_CLK_DISABLE();
	} else if (pGPIOx == GPIOC) {
		RCC_GPIOC_CLK_DISABLE();
	} else if (pGPIOx == GPIOD) {
		RCC_GPIOD_CLK_DISABLE();
	} else if (pGPIOx == GPIOE) {
		RCC_GPIOE_CLK_DISABLE();
	} else if (pGPIOx == GPIOF) {
		RCC_GPIOF_CLK_DISABLE();
	} else if (pGPIOx == GPIOG) {
		RCC_GPIOG_CLK_DISABLE();
	} else if (pGPIOx == GPIOH) {
		RCC_GPIOH_CLK_DISABLE();
	} else if (pGPIOx == GPIOI) {
		RCC_GPIOI_CLK_DISABLE();
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
	/* Enable Clock for the peripheral */
	GPIO_Clock_Enable(pGPIOHandle->pGPIOx);

	/* The loop will ensure that you can use OR masks while calling GPIO_Init */
	/* For instance you can OR mask PA0 | PA1 in pin number */
	for (uint32_t pin_no = 0U; pin_no < PORT_LENGTH; pin_no++) {

		if (pGPIOHandle->GPIO_Pin_Congig.GPIO_Pin_Number & (1U << pin_no)) {

			/* Mode settings for the GPIO Pin */

			if (pGPIOHandle->GPIO_Pin_Congig.GPIO_Pin_Mode <= GPIO_MODE_ANALOG) {

				/* User has not selected interrupt modes */

				pGPIOHandle->pGPIOx->MODER &= ~(3U << (pin_no * 2U));
				pGPIOHandle->pGPIOx->MODER |= (pGPIOHandle->GPIO_Pin_Congig.GPIO_Pin_Mode << (pin_no * 2U));

			} else {

				/* User has selected one of the interrupt modes */

				/* Enable Clock for System configuration controller */
				RCC_SYSCFG_CLK_ENABLE();

				/* Configuring Port and GPIO Pin for EXTI module */
				SYSCFG->EXTICR[pin_no >> 2U] &= ~(0xFU << ((pin_no * 4) % 16U));
				SYSCFG->EXTICR[pin_no >> 2U] |= (GET_PORT_CODE(pGPIOHandle->pGPIOx) << ((pin_no * 4) % 16U));

				/* Rising/Falling trigger selection for the GPIO Pin */
				if (pGPIOHandle->GPIO_Pin_Congig.GPIO_Pin_Mode == GPIO_MODE_INT_RT) {

					EXTI->RTSR |=  (1U << pin_no);
					EXTI->FTSR &= ~(1U << pin_no);

				} else if (pGPIOHandle->GPIO_Pin_Congig.GPIO_Pin_Mode == GPIO_MODE_INT_FT) {

					EXTI->FTSR |=  (1U << pin_no);
					EXTI->RTSR &= ~(1U << pin_no);

				} else {

					EXTI->RTSR |=  (1U << pin_no);
					EXTI->FTSR |=  (1U << pin_no);

				}

				/* Enable interrupts for GPIO Pin */
				EXTI->IMR |= (1U << pin_no);
			}

			if ((pGPIOHandle->GPIO_Pin_Congig.GPIO_Pin_Mode == GPIO_MODE_OUTPUT) ||
				(pGPIOHandle->GPIO_Pin_Congig.GPIO_Pin_Mode == GPIO_MODE_ALT_FN)) {

				/* Output type settings for GPIO Pin */
				pGPIOHandle->pGPIOx->OTYPER &= ~(1U << pin_no);
				pGPIOHandle->pGPIOx->OTYPER |= (pGPIOHandle->GPIO_Pin_Congig.GPIO_Pin_Output_Type << pin_no);

				/* Speed settings for the GPIO Pin */
				pGPIOHandle->pGPIOx->OSPEEDR &= ~(3U << (pin_no * 2U));
				pGPIOHandle->pGPIOx->OSPEEDR |= (pGPIOHandle->GPIO_Pin_Congig.GPIO_Pin_Speed << (pin_no * 2U));

			}

			/* Configure Pull Up/Pull Down register settings for GPIO Pin */
			pGPIOHandle->pGPIOx->PUPDR &= ~(3U << (pin_no * 2U));
			pGPIOHandle->pGPIOx->PUPDR |= (pGPIOHandle->GPIO_Pin_Congig.GPIO_Pin_PUPD_Config << (pin_no * 2U));

			/* Configure the alternate function for GPIO Pin */
			if (pGPIOHandle->GPIO_Pin_Congig.GPIO_Pin_Mode == GPIO_MODE_ALT_FN) {

				pGPIOHandle->pGPIOx->AFR[pin_no >> 3U] &= ~(0xFU << ((pin_no * 4U) % 32U));
				pGPIOHandle->pGPIOx->AFR[pin_no >> 3U] |=  (pGPIOHandle->GPIO_Pin_Congig.GPIO_Pin_Alt_Func <<
														 ((pin_no * 4U) % 32U));

			}
		}
	}

}

