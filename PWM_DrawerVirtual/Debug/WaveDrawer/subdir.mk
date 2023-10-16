################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../WaveDrawer/WaveDrawer.c 

OBJS += \
./WaveDrawer/WaveDrawer.o 

C_DEPS += \
./WaveDrawer/WaveDrawer.d 


# Each subdirectory must supply rules for building sources it contributes
WaveDrawer/%.o: ../WaveDrawer/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"E:\AMITcourse\eclipse projects\Joseph Hanna\eclipse-workspace_1\PWM_DrawerVirtual" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


