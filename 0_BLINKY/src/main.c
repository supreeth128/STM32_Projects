/*************************************************************************************
 *
 *	Overview
 *	--------
 *	Application layer for testing GPIO drivers
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



#include<stdint.h>
#include<stdbool.h>
#include <stm32f407xx_gpio_driver.h>
#include <stm32f407xx_rcc_driver.h>
#include "stm32f407xx.h"

void Init_LED(void);

int main(void)
{
	Init_LED();
	while (true) {
		GPIOD->ODR |= 0xFFFF;
		for (uint32_t i = 0; i < 100000; i++);
		GPIOD->ODR &= ~0xFFFF;
		for (uint32_t i = 0; i < 100000; i++);
	}

	RCC_GPIOA_CLK_ENABLE();

}

void Init_LED(void)
{
	RCC->AHB1ENR |= (1U << 3);
	GPIOD->MODER = (GPIOD->MODER & ~ 0xC000) | (1U << (15 * 2));

}



