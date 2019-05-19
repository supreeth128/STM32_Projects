################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../sys/src/system_stm32f4xx.c 

S_UPPER_SRCS += \
../sys/src/startup_stm32f407xx.S 

OBJS += \
./sys/src/startup_stm32f407xx.o \
./sys/src/system_stm32f4xx.o 

S_UPPER_DEPS += \
./sys/src/startup_stm32f407xx.d 

C_DEPS += \
./sys/src/system_stm32f4xx.d 


# Each subdirectory must supply rules for building sources it contributes
sys/src/%.o: ../sys/src/%.S
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM Cross Assembler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -fno-move-loop-invariants -Wall -Wextra  -g3 -x assembler-with-cpp -DSTM32F407xx -DDEBUG -I"/home/super/Desktop/STM32_Projects/0_OUTPUT/inc" -I"/home/super/Desktop/STM32_Projects/0_OUTPUT/sys/cmsis/inc" -I"/home/super/Desktop/STM32_Projects/0_OUTPUT/sys/inc" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

sys/src/%.o: ../sys/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -fno-move-loop-invariants -Wall -Wextra  -g3 -DDEBUG -DSTM32F407xx -I"/home/super/Desktop/STM32_Projects/0_OUTPUT/inc" -I"/home/super/Desktop/STM32_Projects/0_OUTPUT/sys/cmsis/inc" -I"/home/super/Desktop/STM32_Projects/0_OUTPUT/sys/inc" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


