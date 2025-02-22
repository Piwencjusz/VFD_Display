################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DP_VFD/dp_vfd.c 

OBJS += \
./DP_VFD/dp_vfd.o 

C_DEPS += \
./DP_VFD/dp_vfd.d 


# Each subdirectory must supply rules for building sources it contributes
DP_VFD/%.o: ../DP_VFD/%.c DP_VFD/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


