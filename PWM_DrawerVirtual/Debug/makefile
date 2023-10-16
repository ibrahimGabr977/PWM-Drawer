################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include WaveDrawer/subdir.mk
-include ProgramController/subdir.mk
-include PWM/subdir.mk
-include LCD/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
PWM_DrawerVirtual.lss \

FLASH_IMAGE += \
PWM_DrawerVirtual.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: PWM_DrawerVirtual.elf secondary-outputs

# Tool invocations
PWM_DrawerVirtual.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,PWM_DrawerVirtual.map -mmcu=atmega32 -o "PWM_DrawerVirtual.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

PWM_DrawerVirtual.lss: PWM_DrawerVirtual.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S PWM_DrawerVirtual.elf  >"PWM_DrawerVirtual.lss"
	@echo 'Finished building: $@'
	@echo ' '

PWM_DrawerVirtual.hex: PWM_DrawerVirtual.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex PWM_DrawerVirtual.elf  "PWM_DrawerVirtual.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: PWM_DrawerVirtual.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 PWM_DrawerVirtual.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) PWM_DrawerVirtual.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents

-include ../makefile.targets
