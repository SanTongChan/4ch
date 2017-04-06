################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
A51_UPPER_SRCS += \
../src/SILABS_STARTUP.A51 

C_SRCS += \
../src/EFM8BB1_ADC_ExternalInput.c \
../src/EFM8BB1_FlashPrimitives.c \
../src/InitDevice.c \
../src/Interrupts.c \
../src/key.c \
../src/led.c \
../src/logic.c \
../src/wireless.c 

OBJS += \
./src/EFM8BB1_ADC_ExternalInput.OBJ \
./src/EFM8BB1_FlashPrimitives.OBJ \
./src/InitDevice.OBJ \
./src/Interrupts.OBJ \
./src/SILABS_STARTUP.OBJ \
./src/key.OBJ \
./src/led.OBJ \
./src/logic.OBJ \
./src/wireless.OBJ 


# Each subdirectory must supply rules for building sources it contributes
src/%.OBJ: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Keil 8051 Compiler'
	C51 "@$(patsubst %.OBJ,%.__i,$@)" || $(RC)
	@echo 'Finished building: $<'
	@echo ' '

src/EFM8BB1_ADC_ExternalInput.OBJ: C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/si8051/v3/Device/EFM8BB1/inc/SI_EFM8BB1_Register_Enums.h C:/Users/Administrator/SimplicityStudio/v3_workspace/aidik_4ch/inc/InitDevice.h C:/Users/Administrator/SimplicityStudio/v3_workspace/aidik_4ch/inc/logic.h C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/si8051/v3/Device/EFM8BB1/inc/SI_EFM8BB1_Defs.h C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/si8051/v3/Device/shared/si8051Base/stdbool.h C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/si8051/v3/Device/shared/si8051Base/stdint.h C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/si8051/v3/Device/shared/si8051Base/si_toolchain.h

src/EFM8BB1_FlashPrimitives.OBJ: C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/si8051/v3/Device/EFM8BB1/inc/SI_EFM8BB1_Register_Enums.h C:/Users/Administrator/SimplicityStudio/v3_workspace/aidik_4ch/inc/EFM8BB1_FlashPrimitives.h C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/si8051/v3/Device/EFM8BB1/inc/SI_EFM8BB1_Defs.h C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/si8051/v3/Device/shared/si8051Base/si_toolchain.h C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/si8051/v3/Device/shared/si8051Base/stdint.h C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/si8051/v3/Device/shared/si8051Base/stdbool.h

src/InitDevice.OBJ: C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/si8051/v3/Device/EFM8BB1/inc/SI_EFM8BB1_Register_Enums.h C:/Users/Administrator/SimplicityStudio/v3_workspace/aidik_4ch/inc/InitDevice.h C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/si8051/v3/Device/EFM8BB1/inc/SI_EFM8BB1_Defs.h C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/si8051/v3/Device/shared/si8051Base/si_toolchain.h C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/si8051/v3/Device/shared/si8051Base/stdint.h C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/si8051/v3/Device/shared/si8051Base/stdbool.h

src/Interrupts.OBJ: C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/si8051/v3/Device/EFM8BB1/inc/SI_EFM8BB1_Register_Enums.h C:/SiliconLabs/SimplicityStudio/v3/developer/toolchains/keil_8051/9.53/INC/STDIO.H C:/Users/Administrator/SimplicityStudio/v3_workspace/aidik_4ch/inc/led.h C:/Users/Administrator/SimplicityStudio/v3_workspace/aidik_4ch/src/driver/key_driver.h C:/Users/Administrator/SimplicityStudio/v3_workspace/aidik_4ch/inc/logic.h C:/Users/Administrator/SimplicityStudio/v3_workspace/aidik_4ch/inc/wireless.h C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/si8051/v3/Device/EFM8BB1/inc/SI_EFM8BB1_Defs.h C:/Users/Administrator/SimplicityStudio/v3_workspace/aidik_4ch/inc/global.h C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/si8051/v3/Device/shared/si8051Base/stdbool.h C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/si8051/v3/Device/shared/si8051Base/stdint.h C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/si8051/v3/Device/shared/si8051Base/si_toolchain.h

src/%.OBJ: ../src/%.A51
	@echo 'Building file: $<'
	@echo 'Invoking: Keil 8051 Assembler'
	AX51 "@$(patsubst %.OBJ,%.__ia,$@)" || $(RC)
	@echo 'Finished building: $<'
	@echo ' '

src/key.OBJ: C:/Users/Administrator/SimplicityStudio/v3_workspace/aidik_4ch/inc/key.h C:/Users/Administrator/SimplicityStudio/v3_workspace/aidik_4ch/src/driver/key_driver.h C:/Users/Administrator/SimplicityStudio/v3_workspace/aidik_4ch/inc/logic.h C:/Users/Administrator/SimplicityStudio/v3_workspace/aidik_4ch/inc/led.h C:/Users/Administrator/SimplicityStudio/v3_workspace/aidik_4ch/inc/wireless.h C:/Users/Administrator/SimplicityStudio/v3_workspace/aidik_4ch/inc/global.h C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/si8051/v3/Device/shared/si8051Base/stdbool.h C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/si8051/v3/Device/shared/si8051Base/stdint.h C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/si8051/v3/Device/EFM8BB1/inc/SI_EFM8BB1_Register_Enums.h C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/si8051/v3/Device/EFM8BB1/inc/SI_EFM8BB1_Defs.h C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/si8051/v3/Device/shared/si8051Base/si_toolchain.h

src/led.OBJ: C:/Users/Administrator/SimplicityStudio/v3_workspace/aidik_4ch/inc/led.h C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/si8051/v3/Device/EFM8BB1/inc/SI_EFM8BB1_Register_Enums.h C:/SiliconLabs/SimplicityStudio/v3/developer/toolchains/keil_8051/9.53/INC/STDIO.H C:/Users/Administrator/SimplicityStudio/v3_workspace/aidik_4ch/inc/logic.h C:/Users/Administrator/SimplicityStudio/v3_workspace/aidik_4ch/inc/global.h C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/si8051/v3/Device/EFM8BB1/inc/SI_EFM8BB1_Defs.h C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/si8051/v3/Device/shared/si8051Base/stdbool.h C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/si8051/v3/Device/shared/si8051Base/stdint.h C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/si8051/v3/Device/shared/si8051Base/si_toolchain.h

src/logic.OBJ: C:/Users/Administrator/SimplicityStudio/v3_workspace/aidik_4ch/inc/logic.h C:/Users/Administrator/SimplicityStudio/v3_workspace/aidik_4ch/inc/key.h C:/Users/Administrator/SimplicityStudio/v3_workspace/aidik_4ch/inc/led.h C:/SiliconLabs/SimplicityStudio/v3/developer/toolchains/keil_8051/9.53/INC/STDIO.H C:/Users/Administrator/SimplicityStudio/v3_workspace/aidik_4ch/inc/wireless.h C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/si8051/v3/Device/shared/si8051Base/stdbool.h C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/si8051/v3/Device/shared/si8051Base/stdint.h C:/Users/Administrator/SimplicityStudio/v3_workspace/aidik_4ch/inc/global.h C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/si8051/v3/Device/EFM8BB1/inc/SI_EFM8BB1_Register_Enums.h C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/si8051/v3/Device/EFM8BB1/inc/SI_EFM8BB1_Defs.h C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/si8051/v3/Device/shared/si8051Base/si_toolchain.h

src/wireless.OBJ: C:/Users/Administrator/SimplicityStudio/v3_workspace/aidik_4ch/inc/wireless.h C:/Users/Administrator/SimplicityStudio/v3_workspace/aidik_4ch/inc/led.h C:/Users/Administrator/SimplicityStudio/v3_workspace/aidik_4ch/inc/logic.h C:/Users/Administrator/SimplicityStudio/v3_workspace/aidik_4ch/inc/EFM8BB1_FlashPrimitives.h C:/Users/Administrator/SimplicityStudio/v3_workspace/aidik_4ch/inc/global.h C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/si8051/v3/Device/shared/si8051Base/stdbool.h C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/si8051/v3/Device/shared/si8051Base/stdint.h C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/si8051/v3/Device/EFM8BB1/inc/SI_EFM8BB1_Register_Enums.h C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/si8051/v3/Device/EFM8BB1/inc/SI_EFM8BB1_Defs.h C:/SiliconLabs/SimplicityStudio/v3/developer/sdks/si8051/v3/Device/shared/si8051Base/si_toolchain.h


