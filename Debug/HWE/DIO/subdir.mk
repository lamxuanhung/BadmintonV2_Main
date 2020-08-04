################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HWE/DIO/DIO.c 

OBJS += \
./HWE/DIO/DIO.o 

C_DEPS += \
./HWE/DIO/DIO.d 


# Each subdirectory must supply rules for building sources it contributes
HWE/DIO/%.o: ../HWE/DIO/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m0 -mthumb -mfloat-abi=soft '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F030x6 -I"D:/Working/Workspace/BadmintonBoard_V2/BadmintonBoard_Main/BadmintonV2_Main/Inc" -I"D:/Working/Workspace/BadmintonBoard_V2/BadmintonBoard_Main/BadmintonV2_Main/SW4STM32/BadmintonV2_Main/Application/MCU" -I"D:/Working/Workspace/BadmintonBoard_V2/BadmintonBoard_Main/BadmintonV2_Main/Drivers/STM32F0xx_HAL_Driver/Inc" -I"D:/Working/Workspace/BadmintonBoard_V2/BadmintonBoard_Main/BadmintonV2_Main/Drivers/STM32F0xx_HAL_Driver/Inc/Legacy" -I"D:/Working/Workspace/BadmintonBoard_V2/BadmintonBoard_Main/BadmintonV2_Main/Drivers/CMSIS/Device/ST/STM32F0xx/Include" -I"D:/Working/Workspace/BadmintonBoard_V2/BadmintonBoard_Main/BadmintonV2_Main/Drivers/CMSIS/Include" -I"D:/Working/Workspace/BadmintonBoard_V2/BadmintonBoard_Main/BadmintonV2_Main/SW4STM32/BadmintonV2_Main/DeviceDriver" -I"D:/Working/Workspace/BadmintonBoard_V2/BadmintonBoard_Main/BadmintonV2_Main/SW4STM32/BadmintonV2_Main/HWE/Uart" -I"D:/Working/Workspace/BadmintonBoard_V2/BadmintonBoard_Main/BadmintonV2_Main/SW4STM32/BadmintonV2_Main/HWE/Timer/Timer1" -I"D:/Working/Workspace/BadmintonBoard_V2/BadmintonBoard_Main/BadmintonV2_Main/SW4STM32/BadmintonV2_Main/Srv/Srv_RingBuf" -I"D:/Working/Workspace/BadmintonBoard_V2/BadmintonBoard_Main/BadmintonV2_Main/SW4STM32/BadmintonV2_Main/Srv/Srv_Delay" -I"D:/Working/Workspace/BadmintonBoard_V2/BadmintonBoard_Main/BadmintonV2_Main/SW4STM32/BadmintonV2_Main/HWE/DIO" -I"D:/Working/Workspace/BadmintonBoard_V2/BadmintonBoard_Main/BadmintonV2_Main/SW4STM32/BadmintonV2_Main/HWE/TM1637" -I"D:/Working/Workspace/BadmintonBoard_V2/BadmintonBoard_Main/BadmintonV2_Main/SW4STM32/BadmintonV2_Main/DeviceDriver/Buzzer" -I"D:/Working/Workspace/BadmintonBoard_V2/BadmintonBoard_Main/BadmintonV2_Main/SW4STM32/BadmintonV2_Main/DeviceDriver/LED7" -I"D:/Working/Workspace/BadmintonBoard_V2/BadmintonBoard_Main/BadmintonV2_Main/SW4STM32/BadmintonV2_Main/DeviceDriver/LED" -I"D:/Working/Workspace/BadmintonBoard_V2/BadmintonBoard_Main/BadmintonV2_Main/SW4STM32/BadmintonV2_Main/Application/User/OS_Sched" -I"D:/Working/Workspace/BadmintonBoard_V2/BadmintonBoard_Main/BadmintonV2_Main/SW4STM32/BadmintonV2_Main/DeviceDriver/Button"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


