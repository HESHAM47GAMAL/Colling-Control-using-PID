################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../SERVICE/Polling/Poll.c 

OBJS += \
./SERVICE/Polling/Poll.o 

C_DEPS += \
./SERVICE/Polling/Poll.d 


# Each subdirectory must supply rules for building sources it contributes
SERVICE/Polling/%.o: ../SERVICE/Polling/%.c SERVICE/Polling/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


