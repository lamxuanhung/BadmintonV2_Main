################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/Working/Workspace/BadmintonBoard_V2/BadmintonBoard_Main/BadmintonV2_Main/Src/main.c \
D:/Working/Workspace/BadmintonBoard_V2/BadmintonBoard_Main/BadmintonV2_Main/Src/stm32f0xx_hal_msp.c \
D:/Working/Workspace/BadmintonBoard_V2/BadmintonBoard_Main/BadmintonV2_Main/Src/stm32f0xx_it.c 

OBJS += \
./Application/User/main.o \
./Application/User/stm32f0xx_hal_msp.o \
./Application/User/stm32f0xx_it.o 

C_DEPS += \
./Application/User/main.d \
./Application/User/stm32f0xx_hal_msp.d \
./Application/User/stm32f0xx_it.d 


# Each subdirectory must supply rules for building sources it contributes
Application/User/main.o: D:/Working/Workspace/BadmintonBoard_V2/BadmintonBoard_Main/BadmintonV2_Main/Src/main.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m0 -mthumb -mfloat-abi=soft '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F030x6 -I"D:/Working/Workspace/BadmintonBoard_V2/BadmintonBoard_Main/BadmintonV2_Main/Inc" -I"D:/Working/Workspace/BadmintonBoard_V2/BadmintonBoard_Main/BadmintonV2_Main/Drivers/STM32F0xx_HAL_Driver/Inc" -I"D:/Working/Workspace/BadmintonBoard_V2/BadmintonBoard_Main/BadmintonV2_Main/Drivers/STM32F0xx_HAL_Driver/Inc/Legacy" -I"D:/Working/Workspace/BadmintonBoard_V2/BadmintonBoard_Main/BadmintonV2_Main/Drivers/CMSIS/Device/ST/STM32F0xx/Include" -I"D:/Working/Workspace/BadmintonBoard_V2/BadmintonBoard_Main/BadmintonV2_Main/Drivers/CMSIS/Include" -I"D:/Working/Workspace/BadmintonBoard_V2/BadmintonBoard_Main/BadmintonV2_Main/SW4STM32/BadmintonV2_Main/Srv/Srv_RingBuf" -I"D:/Working/Workspace/BadmintonBoard_V2/BadmintonBoard_Main/BadmintonV2_Main/SW4STM32/BadmintonV2_Main/HWE/Uart" -I"D:/Working/Workspace/BadmintonBoard_V2/BadmintonBoard_Main/BadmintonV2_Main/SW4STM32/BadmintonV2_Main/HWE/Timer" -I"D:/Working/Workspace/BadmintonBoard_V2/BadmintonBoard_Main/BadmintonV2_Main/SW4STM32/BadmintonV2_Main/DeviceDriver"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Application/User/stm32f0xx_hal_msp.o: D:/Working/Workspace/BadmintonBoard_V2/BadmintonBoard_Main/BadmintonV2_Main/Src/stm32f0xx_hal_msp.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m0 -mthumb -mfloat-abi=soft '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F030x6 -I"D:/Working/Workspace/BadmintonBoard_V2/BadmintonBoard_Main/BadmintonV2_Main/Inc" -I"D:/Working/Workspace/BadmintonBoard_V2/BadmintonBoard_Main/BadmintonV2_Main/Drivers/STM32F0xx_HAL_Driver/Inc" -I"D:/Working/Workspace/BadmintonBoard_V2/BadmintonBoard_Main/BadmintonV2_Main/Drivers/STM32F0xx_HAL_Driver/Inc/Legacy" -I"D:/Working/Workspace/BadmintonBoard_V2/BadmintonBoard_Main/BadmintonV2_Main/Drivers/CMSIS/Device/ST/STM32F0xx/Include" -I"D:/Working/Workspace/BadmintonBoard_V2/BadmintonBoard_Main/BadmintonV2_Main/Drivers/CMSIS/Include" -I"D:/Working/Workspace/BadmintonBoard_V2/BadmintonBoard_Main/BadmintonV2_Main/SW4STM32/BadmintonV2_Main/Srv/Srv_RingBuf" -I"D:/Working/Workspace/BadmintonBoard_V2/BadmintonBoard_Main/BadmintonV2_Main/SW4STM32/BadmintonV2_Main/HWE/Uart" -I"D:/Working/Workspace/BadmintonBoard_V2/BadmintonBoard_Main/BadmintonV2_Main/SW4STM32/BadmintonV2_Main/HWE/Timer" -I"D:/Working/Workspace/BadmintonBoard_V2/BadmintonBoard_Main/BadmintonV2_Main/SW4STM32/BadmintonV2_Main/DeviceDriver"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Application/User/stm32f0xx_it.o: D:/Working/Workspace/BadmintonBoard_V2/BadmintonBoard_Main/BadmintonV2_Main/Src/stm32f0xx_it.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m0 -mthumb -mfloat-abi=soft '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F030x6 -I"D:/Working/Workspace/BadmintonBoard_V2/BadmintonBoard_Main/BadmintonV2_Main/Inc" -I"D:/Working/Workspace/BadmintonBoard_V2/BadmintonBoard_Main/BadmintonV2_Main/Drivers/STM32F0xx_HAL_Driver/Inc" -I"D:/Working/Workspace/BadmintonBoard_V2/BadmintonBoard_Main/BadmintonV2_Main/Drivers/STM32F0xx_HAL_Driver/Inc/Legacy" -I"D:/Working/Workspace/BadmintonBoard_V2/BadmintonBoard_Main/BadmintonV2_Main/Drivers/CMSIS/Device/ST/STM32F0xx/Include" -I"D:/Working/Workspace/BadmintonBoard_V2/BadmintonBoard_Main/BadmintonV2_Main/Drivers/CMSIS/Include" -I"D:/Working/Workspace/BadmintonBoard_V2/BadmintonBoard_Main/BadmintonV2_Main/SW4STM32/BadmintonV2_Main/Srv/Srv_RingBuf" -I"D:/Working/Workspace/BadmintonBoard_V2/BadmintonBoard_Main/BadmintonV2_Main/SW4STM32/BadmintonV2_Main/HWE/Uart" -I"D:/Working/Workspace/BadmintonBoard_V2/BadmintonBoard_Main/BadmintonV2_Main/SW4STM32/BadmintonV2_Main/HWE/Timer" -I"D:/Working/Workspace/BadmintonBoard_V2/BadmintonBoard_Main/BadmintonV2_Main/SW4STM32/BadmintonV2_Main/DeviceDriver"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


