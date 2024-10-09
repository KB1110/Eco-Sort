################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/Projects/FP-AI-VISION1_V3.1.0/Middlewares/Third_Party/FatFs/src/option/ccsbcs.c \
D:/Projects/FP-AI-VISION1_V3.1.0/Middlewares/Third_Party/FatFs/src/diskio.c \
D:/Projects/FP-AI-VISION1_V3.1.0/Middlewares/Third_Party/FatFs/src/ff.c \
D:/Projects/FP-AI-VISION1_V3.1.0/Middlewares/Third_Party/FatFs/src/ff_gen_drv.c \
D:/Projects/FP-AI-VISION1_V3.1.0/Middlewares/Third_Party/FatFs/src/option/syscall.c 

OBJS += \
./Middlewares/FatFs/ccsbcs.o \
./Middlewares/FatFs/diskio.o \
./Middlewares/FatFs/ff.o \
./Middlewares/FatFs/ff_gen_drv.o \
./Middlewares/FatFs/syscall.o 

C_DEPS += \
./Middlewares/FatFs/ccsbcs.d \
./Middlewares/FatFs/diskio.d \
./Middlewares/FatFs/ff.d \
./Middlewares/FatFs/ff_gen_drv.d \
./Middlewares/FatFs/syscall.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/FatFs/ccsbcs.o: D:/Projects/FP-AI-VISION1_V3.1.0/Middlewares/Third_Party/FatFs/src/option/ccsbcs.c Middlewares/FatFs/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32H747xx -DUSE_STM32H747I_DISCO -DCORE_CM7 -DDATA_IN_ExtSDRAM -DMEMORY_SCHEME=3 -DCAMERA_CAPTURE_RES=2 -DPIXEL_FMT_CONV=1 -DSTM32IPL -DARM_MATH_CM7 -D__FPU_PRESENT=1 -c -I../../../CM7/Inc -I../../../../../Common/CM7/Inc -I../../../../../../../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../../../../../../../Drivers/CMSIS/Include -I../../../../../../../../Drivers/CMSIS/DSP/Include -I../../../../../../../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../../../../../../../Drivers/BSP/STM32H747I-Discovery -I../../../../../../../../Drivers/BSP/Components/Common -I../../../../../../../../Drivers/BSP/Components/ov9655 -I../../../../../../../../Drivers/BSP/Components/otm8009a -I../../../../../../../../Utilities/Fonts -I../../../../../../../../Utilities/lcd -I../../../../../../../../Middlewares/ST/STM32_AI_Runtime/Inc -I../../../../../../../../Middlewares/ST/STM32_AI_Utilities/Inc -I../../../../../../../../Middlewares/ST/STM32_ImageProcessing_Library/Inc -I../../../../../../../../Middlewares/Third_Party/FatFs/src -Ofast -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Middlewares/FatFs/diskio.o: D:/Projects/FP-AI-VISION1_V3.1.0/Middlewares/Third_Party/FatFs/src/diskio.c Middlewares/FatFs/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32H747xx -DUSE_STM32H747I_DISCO -DCORE_CM7 -DDATA_IN_ExtSDRAM -DMEMORY_SCHEME=3 -DCAMERA_CAPTURE_RES=2 -DPIXEL_FMT_CONV=1 -DSTM32IPL -DARM_MATH_CM7 -D__FPU_PRESENT=1 -c -I../../../CM7/Inc -I../../../../../Common/CM7/Inc -I../../../../../../../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../../../../../../../Drivers/CMSIS/Include -I../../../../../../../../Drivers/CMSIS/DSP/Include -I../../../../../../../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../../../../../../../Drivers/BSP/STM32H747I-Discovery -I../../../../../../../../Drivers/BSP/Components/Common -I../../../../../../../../Drivers/BSP/Components/ov9655 -I../../../../../../../../Drivers/BSP/Components/otm8009a -I../../../../../../../../Utilities/Fonts -I../../../../../../../../Utilities/lcd -I../../../../../../../../Middlewares/ST/STM32_AI_Runtime/Inc -I../../../../../../../../Middlewares/ST/STM32_AI_Utilities/Inc -I../../../../../../../../Middlewares/ST/STM32_ImageProcessing_Library/Inc -I../../../../../../../../Middlewares/Third_Party/FatFs/src -Ofast -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Middlewares/FatFs/ff.o: D:/Projects/FP-AI-VISION1_V3.1.0/Middlewares/Third_Party/FatFs/src/ff.c Middlewares/FatFs/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32H747xx -DUSE_STM32H747I_DISCO -DCORE_CM7 -DDATA_IN_ExtSDRAM -DMEMORY_SCHEME=3 -DCAMERA_CAPTURE_RES=2 -DPIXEL_FMT_CONV=1 -DSTM32IPL -DARM_MATH_CM7 -D__FPU_PRESENT=1 -c -I../../../CM7/Inc -I../../../../../Common/CM7/Inc -I../../../../../../../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../../../../../../../Drivers/CMSIS/Include -I../../../../../../../../Drivers/CMSIS/DSP/Include -I../../../../../../../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../../../../../../../Drivers/BSP/STM32H747I-Discovery -I../../../../../../../../Drivers/BSP/Components/Common -I../../../../../../../../Drivers/BSP/Components/ov9655 -I../../../../../../../../Drivers/BSP/Components/otm8009a -I../../../../../../../../Utilities/Fonts -I../../../../../../../../Utilities/lcd -I../../../../../../../../Middlewares/ST/STM32_AI_Runtime/Inc -I../../../../../../../../Middlewares/ST/STM32_AI_Utilities/Inc -I../../../../../../../../Middlewares/ST/STM32_ImageProcessing_Library/Inc -I../../../../../../../../Middlewares/Third_Party/FatFs/src -Ofast -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Middlewares/FatFs/ff_gen_drv.o: D:/Projects/FP-AI-VISION1_V3.1.0/Middlewares/Third_Party/FatFs/src/ff_gen_drv.c Middlewares/FatFs/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32H747xx -DUSE_STM32H747I_DISCO -DCORE_CM7 -DDATA_IN_ExtSDRAM -DMEMORY_SCHEME=3 -DCAMERA_CAPTURE_RES=2 -DPIXEL_FMT_CONV=1 -DSTM32IPL -DARM_MATH_CM7 -D__FPU_PRESENT=1 -c -I../../../CM7/Inc -I../../../../../Common/CM7/Inc -I../../../../../../../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../../../../../../../Drivers/CMSIS/Include -I../../../../../../../../Drivers/CMSIS/DSP/Include -I../../../../../../../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../../../../../../../Drivers/BSP/STM32H747I-Discovery -I../../../../../../../../Drivers/BSP/Components/Common -I../../../../../../../../Drivers/BSP/Components/ov9655 -I../../../../../../../../Drivers/BSP/Components/otm8009a -I../../../../../../../../Utilities/Fonts -I../../../../../../../../Utilities/lcd -I../../../../../../../../Middlewares/ST/STM32_AI_Runtime/Inc -I../../../../../../../../Middlewares/ST/STM32_AI_Utilities/Inc -I../../../../../../../../Middlewares/ST/STM32_ImageProcessing_Library/Inc -I../../../../../../../../Middlewares/Third_Party/FatFs/src -Ofast -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Middlewares/FatFs/syscall.o: D:/Projects/FP-AI-VISION1_V3.1.0/Middlewares/Third_Party/FatFs/src/option/syscall.c Middlewares/FatFs/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32H747xx -DUSE_STM32H747I_DISCO -DCORE_CM7 -DDATA_IN_ExtSDRAM -DMEMORY_SCHEME=3 -DCAMERA_CAPTURE_RES=2 -DPIXEL_FMT_CONV=1 -DSTM32IPL -DARM_MATH_CM7 -D__FPU_PRESENT=1 -c -I../../../CM7/Inc -I../../../../../Common/CM7/Inc -I../../../../../../../../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../../../../../../../../Drivers/CMSIS/Include -I../../../../../../../../Drivers/CMSIS/DSP/Include -I../../../../../../../../Drivers/STM32H7xx_HAL_Driver/Inc -I../../../../../../../../Drivers/BSP/STM32H747I-Discovery -I../../../../../../../../Drivers/BSP/Components/Common -I../../../../../../../../Drivers/BSP/Components/ov9655 -I../../../../../../../../Drivers/BSP/Components/otm8009a -I../../../../../../../../Utilities/Fonts -I../../../../../../../../Utilities/lcd -I../../../../../../../../Middlewares/ST/STM32_AI_Runtime/Inc -I../../../../../../../../Middlewares/ST/STM32_AI_Utilities/Inc -I../../../../../../../../Middlewares/ST/STM32_ImageProcessing_Library/Inc -I../../../../../../../../Middlewares/Third_Party/FatFs/src -Ofast -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Middlewares-2f-FatFs

clean-Middlewares-2f-FatFs:
	-$(RM) ./Middlewares/FatFs/ccsbcs.cyclo ./Middlewares/FatFs/ccsbcs.d ./Middlewares/FatFs/ccsbcs.o ./Middlewares/FatFs/ccsbcs.su ./Middlewares/FatFs/diskio.cyclo ./Middlewares/FatFs/diskio.d ./Middlewares/FatFs/diskio.o ./Middlewares/FatFs/diskio.su ./Middlewares/FatFs/ff.cyclo ./Middlewares/FatFs/ff.d ./Middlewares/FatFs/ff.o ./Middlewares/FatFs/ff.su ./Middlewares/FatFs/ff_gen_drv.cyclo ./Middlewares/FatFs/ff_gen_drv.d ./Middlewares/FatFs/ff_gen_drv.o ./Middlewares/FatFs/ff_gen_drv.su ./Middlewares/FatFs/syscall.cyclo ./Middlewares/FatFs/syscall.d ./Middlewares/FatFs/syscall.o ./Middlewares/FatFs/syscall.su

.PHONY: clean-Middlewares-2f-FatFs

