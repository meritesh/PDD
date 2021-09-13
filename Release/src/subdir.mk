################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Main.c \
../src/PDD.c \
../src/adc.c \
../src/encoder.c \
../src/file.c \
../src/gpiotest.c \
../src/newgpio.c \
../src/pwm_o.c \
../src/pwmandanalog.c 

OBJS += \
./src/Main.o \
./src/PDD.o \
./src/adc.o \
./src/encoder.o \
./src/file.o \
./src/gpiotest.o \
./src/newgpio.o \
./src/pwm_o.o \
./src/pwmandanalog.o 

C_DEPS += \
./src/Main.d \
./src/PDD.d \
./src/adc.d \
./src/encoder.d \
./src/file.d \
./src/gpiotest.d \
./src/newgpio.d \
./src/pwm_o.d \
./src/pwmandanalog.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


