################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Keil tools exit code 1 is warnings only, so don't treat as an error in make
RC := test $$? -lt 2

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/driver/subdir.mk
-include src/subdir.mk
-include subdir.mk
-include objects.mk

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: aidik_4ch.omf

# Tool invocations
aidik_4ch.omf: echo_path $(OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: Keil 8051 Linker'
	LX51 "@aidik_4ch.lnp" || $(RC)
	@echo 'Finished building target: $@'

# Change from all upper case to the expected case
	@-mv "AIDIK_4CH.OMF.CRBUILD" "$@"

# Generate hex file: aidik_4ch.hex
	@Ohx51 "aidik_4ch.omf" "HEXFILE (aidik_4ch.hex)" "H386" 2>&1 >/dev/null

# Other Targets
clean:
	-$(RM) $(OBJS)$(EXECUTABLES) aidik_4ch.omf
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
# echo the path
echo_path:
	@echo PATH=$$PATH
	@echo ' '

