################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ECUAL/TC72_temperature/tc72_temperature.c 

OBJS += \
./ECUAL/TC72_temperature/tc72_temperature.o 

C_DEPS += \
./ECUAL/TC72_temperature/tc72_temperature.d 


# Each subdirectory must supply rules for building sources it contributes
ECUAL/TC72_temperature/%.o: ../ECUAL/TC72_temperature/%.c ECUAL/TC72_temperature/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


