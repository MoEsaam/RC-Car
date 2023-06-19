################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Buzzer.c \
../DcMotor.c \
../GPIO.c \
../ICU.c \
../MotorDriver.c \
../Ultrasonic_sensor\ _HC-SR04.c \
../adc.c \
../app.c \
../bluetooth.c \
../servo.c \
../timer.c \
../uart.c 

OBJS += \
./Buzzer.o \
./DcMotor.o \
./GPIO.o \
./ICU.o \
./MotorDriver.o \
./Ultrasonic_sensor\ _HC-SR04.o \
./adc.o \
./app.o \
./bluetooth.o \
./servo.o \
./timer.o \
./uart.o 

C_DEPS += \
./Buzzer.d \
./DcMotor.d \
./GPIO.d \
./ICU.d \
./MotorDriver.d \
./Ultrasonic_sensor\ _HC-SR04.d \
./adc.d \
./app.d \
./bluetooth.d \
./servo.d \
./timer.d \
./uart.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Ultrasonic_sensor\ _HC-SR04.o: ../Ultrasonic_sensor\ _HC-SR04.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"Ultrasonic_sensor _HC-SR04.d" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


