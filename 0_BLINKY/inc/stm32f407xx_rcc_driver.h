/*************************************************************************************
 *
 *	Overview
 *	--------
 *	Macros, constants and data structures for managing and configuring RCC block
 *  It also contain clock handling macros for various peripherals
 *
 *	Includes STM32F4XX
 *
 *
 *	Developed by
 *	------------
 *	Author	: Supreeth Anil
 *	Date	: 21-May-2019
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

#ifndef __STM32F407XX_RCC_DRIVER_H__
#define __STM32F407XX_RCC_DRIVER_H__


#include "stm32f407xx.h"
#include "utils.h"

/*************************************************************************************
 *
 *	@brief	- Enable/Disable Clock for the AHB1 Peripherals which include GPIO Ports
 *
 *	@note	- Ports F, G and I are not available in devices with 100-pin packages
 *
 ************************************************************************************/

#define	RCC_GPIOA_CLK_ENABLE()	do { \
                                    volatile uint32_t temp; \
                                    RCC->AHB1ENR |= (1U << RCC_AHB1ENR_GPIOAEN_Pos); \
                                    /* Dummy delay for clock stabilization */ \
                                    temp = RCC->AHB1ENR & (1U << RCC_AHB1ENR_GPIOAEN_Pos); \
                                    UNUSED(temp); \
                                } while (0U)

#define	RCC_GPIOB_CLK_ENABLE()	do { \
                                    volatile uint32_t temp; \
                                    RCC->AHB1ENR |= (1U << RCC_AHB1ENR_GPIOBEN_Pos); \
                                    /* Dummy delay for clock stabilization */ \
                                    temp = RCC->AHB1ENR & (1U << RCC_AHB1ENR_GPIOBEN_Pos); \
                                    UNUSED(temp); \
                                } while (0U)

#define	RCC_GPIOC_CLK_ENABLE()	do { \
                                    volatile uint32_t temp; \
                                    RCC->AHB1ENR |= (1U << RCC_AHB1ENR_GPIOCEN_Pos); \
                                    /* Dummy delay for clock stabilization */ \
                                    temp = RCC->AHB1ENR & (1U << RCC_AHB1ENR_GPIOCEN_Pos); \
                                    UNUSED(temp); \
                                } while (0U)

#define	RCC_GPIOD_CLK_ENABLE()	do { \
                                    volatile uint32_t temp; \
                                    RCC->AHB1ENR |= (1U << RCC_AHB1ENR_GPIODEN_Pos); \
                                    /* Dummy delay for clock stabilization */ \
                                    temp = RCC->AHB1ENR & (1U << RCC_AHB1ENR_GPIODEN_Pos); \
                                    UNUSED(temp); \
                                } while (0U)

#define	RCC_GPIOE_CLK_ENABLE()	do { \
                                    volatile uint32_t temp; \
                                    RCC->AHB1ENR |= (1U << RCC_AHB1ENR_GPIOEEN_Pos); \
                                    /* Dummy delay for clock stabilization */ \
                                    temp = RCC->AHB1ENR & (1U << RCC_AHB1ENR_GPIOEEN_Pos); \
                                    UNUSED(temp); \
                                } while (0U)

#define	RCC_GPIOF_CLK_ENABLE()	do { \
                                    volatile uint32_t temp; \
                                    RCC->AHB1ENR |= (1U << RCC_AHB1ENR_GPIOFEN_Pos); \
                                    /* Dummy delay for clock stabilization */ \
                                    temp = RCC->AHB1ENR & (1U << RCC_AHB1ENR_GPIOFEN_Pos); \
                                    UNUSED(temp); \
                                } while (0U)

#define	RCC_GPIOG_CLK_ENABLE()	do { \
                                    volatile uint32_t temp; \
                                    RCC->AHB1ENR |= (1U << RCC_AHB1ENR_GPIOGEN_Pos); \
                                    /* Dummy delay for clock stabilization */ \
                                    temp = RCC->AHB1ENR & (1U << RCC_AHB1ENR_GPIOGEN_Pos); \
                                    UNUSED(temp); \
                                } while (0U)

#define	RCC_GPIOH_CLK_ENABLE()	do { \
                                    volatile uint32_t temp; \
                                    RCC->AHB1ENR |= (1U << RCC_AHB1ENR_GPIOHEN_Pos); \
                                    /* Dummy delay for clock stabilization */ \
                                    temp = RCC->AHB1ENR & (1U << RCC_AHB1ENR_GPIOHEN_Pos); \
                                    UNUSED(temp); \
                                } while (0U)

#define	RCC_GPIOI_CLK_ENABLE()	do { \
                                    volatile uint32_t temp; \
                                    RCC->AHB1ENR |= (1U << RCC_AHB1ENR_GPIOIEN_Pos); \
                                    /* Dummy delay for clock stabilization */ \
                                    temp = RCC->AHB1ENR & (1U << RCC_AHB1ENR_GPIOIEN_Pos); \
                                    UNUSED(temp); \
                                } while (0U)



#define	RCC_GPIOA_CLK_DISABLE()	(RCC->AHB1ENR &= ~(1U << RCC_AHB1ENR_GPIOAEN_Pos))
#define	RCC_GPIOB_CLK_DISABLE()	(RCC->AHB1ENR &= ~(1U << RCC_AHB1ENR_GPIOBEN_Pos))
#define	RCC_GPIOC_CLK_DISABLE()	(RCC->AHB1ENR &= ~(1U << RCC_AHB1ENR_GPIOCEN_Pos))
#define	RCC_GPIOD_CLK_DISABLE()	(RCC->AHB1ENR &= ~(1U << RCC_AHB1ENR_GPIODEN_Pos))
#define	RCC_GPIOE_CLK_DISABLE()	(RCC->AHB1ENR &= ~(1U << RCC_AHB1ENR_GPIOEEN_Pos))
#define	RCC_GPIOF_CLK_DISABLE()	(RCC->AHB1ENR &= ~(1U << RCC_AHB1ENR_GPIOFEN_Pos))
#define	RCC_GPIOG_CLK_DISABLE()	(RCC->AHB1ENR &= ~(1U << RCC_AHB1ENR_GPIOGEN_Pos))
#define	RCC_GPIOH_CLK_DISABLE()	(RCC->AHB1ENR &= ~(1U << RCC_AHB1ENR_GPIOHEN_Pos))
#define	RCC_GPIOI_CLK_DISABLE()	(RCC->AHB1ENR &= ~(1U << RCC_AHB1ENR_GPIOIEN_Pos))




/*************************************************************************************
 *
 *	@brief	- Enable/Disable Clock for the APB2 Peripherals
 *
 ************************************************************************************/

#define	RCC_SYSCFG_CLK_ENABLE()	do { \
                                    volatile uint32_t temp; \
                                    RCC->APB2ENR |= (1U << RCC_APB2ENR_SYSCFGEN_Pos); \
                                    /* Dummy delay for clock stabilization */ \
                                    temp = RCC->APB2ENR & (1U << RCC_APB2ENR_SYSCFGEN_Pos); \
                                    UNUSED(temp); \
                                } while (0U)




#define	RCC_SYSCFG_CLK_DISABLE()	(RCC->APB2ENR &= ~(1U << RCC_APB2ENR_SYSCFGEN_Pos))


#endif				/* __STM32F407XX_RCC_DRIVER_H__ */




