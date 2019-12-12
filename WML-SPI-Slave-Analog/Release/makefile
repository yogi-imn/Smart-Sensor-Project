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
WML-SPI-Slave-Analog.lss \

FLASH_IMAGE += \
WML-SPI-Slave-Analog.hex \

EEPROM_IMAGE += \
WML-SPI-Slave-Analog.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: WML-SPI-Slave-Analog.elf secondary-outputs

# Tool invocations
WML-SPI-Slave-Analog.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,WML-SPI-Slave-Analog.map -mmcu=atmega2560 -o "WML-SPI-Slave-Analog.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

WML-SPI-Slave-Analog.lss: WML-SPI-Slave-Analog.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S WML-SPI-Slave-Analog.elf  >"WML-SPI-Slave-Analog.lss"
	@echo 'Finished building: $@'
	@echo ' '

WML-SPI-Slave-Analog.hex: WML-SPI-Slave-Analog.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex WML-SPI-Slave-Analog.elf  "WML-SPI-Slave-Analog.hex"
	@echo 'Finished building: $@'
	@echo ' '

WML-SPI-Slave-Analog.eep: WML-SPI-Slave-Analog.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex WML-SPI-Slave-Analog.elf  "WML-SPI-Slave-Analog.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: WML-SPI-Slave-Analog.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=berkeley -t WML-SPI-Slave-Analog.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) WML-SPI-Slave-Analog.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
