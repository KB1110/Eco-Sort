################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/Projects/FP-AI-VISION1_V3.1.0/Projects/STM32H747I-DISCO/Applications/PersonDetection/MobileNetv2_Model/Common/Src/system_stm32h7xx.c 

OBJS += \
./Common/system_stm32h7xx.o 

C_DEPS += \
./Common/system_stm32h7xx.d 


# Each subdirectory must supply rules for building sources it contributes
Common/system_stm32h7xx.o: D:/Projects/FP-AI-VISION1_V3.1.0/Projects/STM32H747I-DISCO/Applications/PersonDetection/MobileNetv2_Model/Common/Src/system_stm32h7xx.c Common/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32H747xx -DUSE_STM32H747I_DISCO -DCORE_CM7 -DDATA_IN_ExtSDRAM -DMEMORY_SCHEME=3 -DCAMERA_CAPTURE_RES=2 -DPIXEL_FMT_CONV=1 -DSTM32IPL -DARM_MATH_CM7 -D__FPU_PRESENT=1 -c -I../../../CM7/Inc -I../../../../../Common/CM7/Inc -I../../../../../../../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../../../../../../../Drivers/CMSIS/Include -I../../../../../../../../Drivers/CMSIS/DSP/Include -I../../../../../../../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../../../../../../../Drivers/BSP/STM32H747I-Discovery -I../../../../../../../../Drivers/BSP/Components/Common -I../../../../../../../../Drivers/BSP/Components/ov9655 -I../../../../../../../../Drivers/BSP/Components/otm8009a -I../../../../../../../../Utilities/Fonts -I../../../../../../../../Utilities/lcd -I../../../../../../../../Middlewares/ST/STM32_AI_Runtime/Inc -I../../../../../../../../Middlewares/ST/STM32_AI_Utilities/Inc -I../../../../../../../../Middlewares/ST/STM32_ImageProcessing_Library/Inc -I../../../../../../../../Middlewares/Third_Party/FatFs/src -Ofast -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Common

clean-Common:
	-$(RM) ./Common/system_stm32h7xx.cyclo ./Common/system_stm32h7xx.d ./Common/system_stm32h7xx.o ./Common/system_stm32h7xx.su

.PHONY: clean-Common

