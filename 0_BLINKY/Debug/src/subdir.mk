################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/main.c \
../src/stm32f407xx_gpio_driver.c 

OBJS += \
./src/main.o \
./src/stm32f407xx_gpio_driver.o 

C_DEPS += \
./src/main.d \
./src/stm32f407xx_gpio_driver.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -fno-move-loop-invariants -Wall -Wextra  -g3 -DDEBUG -DSTM32F407xx -I"/home/super/Desktop/STM32_Projects/0_BLINKY/inc" -I"/home/super/Desktop/STM32_Projects/0_BLINKY/sys/cmsis/inc" -I"/home/super/Desktop/STM32_Projects/0_BLINKY/sys/inc" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


