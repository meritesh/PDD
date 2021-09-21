################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/ADS123X.c \
../src/Main.c \
../src/PDD.c \
../src/Stepper.c \
../src/adc.c \
../src/encoder.c \
../src/encoderfunctions.c \
../src/file.c \
../src/gpiotest.c \
../src/loadcellfunctions.c \
../src/loadcelltest.c \
../src/manbackup1.c \
../src/newgpio.c \
../src/pwm_o.c \
../src/pwmandadcfunctions.c \
../src/pwmandanalog.c \
../src/stepperfunctions.c \
../src/steppertest.c 

OBJS += \
./src/ADS123X.o \
./src/Main.o \
./src/PDD.o \
./src/Stepper.o \
./src/adc.o \
./src/encoder.o \
./src/encoderfunctions.o \
./src/file.o \
./src/gpiotest.o \
./src/loadcellfunctions.o \
./src/loadcelltest.o \
./src/manbackup1.o \
./src/newgpio.o \
./src/pwm_o.o \
./src/pwmandadcfunctions.o \
./src/pwmandanalog.o \
./src/stepperfunctions.o \
./src/steppertest.o 

C_DEPS += \
./src/ADS123X.d \
./src/Main.d \
./src/PDD.d \
./src/Stepper.d \
./src/adc.d \
./src/encoder.d \
./src/encoderfunctions.d \
./src/file.d \
./src/gpiotest.d \
./src/loadcellfunctions.d \
./src/loadcelltest.d \
./src/manbackup1.d \
./src/newgpio.d \
./src/pwm_o.d \
./src/pwmandadcfunctions.d \
./src/pwmandanalog.d \
./src/stepperfunctions.d \
./src/steppertest.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	arm-angstrom-linux-gnueabi-gcc  -march=armv7-a -mthumb -mfpu=neon -mfloat-abi=hard --sysroot=/usr/local/oecore-x86_64/sysroots/armv7at2hf-neon-angstrom-linux-gnueabi -O0 -g3 -Wall -O2 -pipe -g -feliminate-unused-debug-types  -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


