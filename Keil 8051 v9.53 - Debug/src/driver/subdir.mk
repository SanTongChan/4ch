################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/driver/key_driver.c 

OBJS += \
./src/driver/key_driver.OBJ 


# Each subdirectory must supply rules for building sources it contributes
src/driver/%.OBJ: ../src/driver/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Keil 8051 Compiler'
	C51 "@$(patsubst %.OBJ,%.__i,$@)" || $(RC)
	@echo 'Finished building: $<'
	@echo ' '

src/driver/key_driver.OBJ: C:/Users/Administrator/SimplicityStudio/v3_workspace/aidik_4ch/src/driver/key_driver.h C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/si8051/v3/Device/EFM8BB1/inc/SI_EFM8BB1_Register_Enums.h C:/Users/Administrator/SimplicityStudio/v3_workspace/aidik_4ch/inc/led.h C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/si8051/v3/Device/shared/si8051Base/stdbool.h C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/si8051/v3/Device/EFM8BB1/inc/SI_EFM8BB1_Defs.h C:/Users/Administrator/SimplicityStudio/v3_workspace/aidik_4ch/inc/global.h C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/si8051/v3/Device/shared/si8051Base/si_toolchain.h C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/si8051/v3/Device/shared/si8051Base/stdint.h


