################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/main.c \
../src/stm2f407xx_gpio_driver.c 

OBJS += \
./src/main.o \
./src/stm2f407xx_gpio_driver.o 

C_DEPS += \
./src/main.d \
./src/stm2f407xx_gpio_driver.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -Wall -Wextra  -g -DNDEBUG -DSTM32F407xx -I"/home/super/Desktop/STM32_Projects/0_OUTPUT/inc" -I"/home/super/Desktop/STM32_Projects/0_OUTPUT/sys/cmsis/inc" -I"/home/super/Desktop/STM32_Projects/0_OUTPUT/sys/inc" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


