################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ECUAL/Poll_Devices/Poll_Devices.c 

OBJS += \
./ECUAL/Poll_Devices/Poll_Devices.o 

C_DEPS += \
./ECUAL/Poll_Devices/Poll_Devices.d 


# Each subdirectory must supply rules for building sources it contributes
ECUAL/Poll_Devices/%.o: ../ECUAL/Poll_Devices/%.c ECUAL/Poll_Devices/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


