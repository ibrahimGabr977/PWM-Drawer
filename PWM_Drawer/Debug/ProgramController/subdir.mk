################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ProgramController/PWM_Drawer.c 

OBJS += \
./ProgramController/PWM_Drawer.o 

C_DEPS += \
./ProgramController/PWM_Drawer.d 


# Each subdirectory must supply rules for building sources it contributes
ProgramController/%.o: ../ProgramController/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"E:\AMITcourse\eclipse projects\Joseph Hanna\eclipse-workspace_1\PWM_Drawer" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


