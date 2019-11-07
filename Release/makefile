################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
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
project-smart-line-sensor.lss \

FLASH_IMAGE += \
project-smart-line-sensor.hex \

EEPROM_IMAGE += \
project-smart-line-sensor.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: project-smart-line-sensor.elf secondary-outputs

# Tool invocations
project-smart-line-sensor.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,project-smart-line-sensor.map -mmcu=atmega2560 -o "project-smart-line-sensor.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

project-smart-line-sensor.lss: project-smart-line-sensor.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S project-smart-line-sensor.elf  >"project-smart-line-sensor.lss"
	@echo 'Finished building: $@'
	@echo ' '

project-smart-line-sensor.hex: project-smart-line-sensor.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex project-smart-line-sensor.elf  "project-smart-line-sensor.hex"
	@echo 'Finished building: $@'
	@echo ' '

project-smart-line-sensor.eep: project-smart-line-sensor.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex project-smart-line-sensor.elf  "project-smart-line-sensor.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: project-smart-line-sensor.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=berkeley -t project-smart-line-sensor.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) project-smart-line-sensor.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
