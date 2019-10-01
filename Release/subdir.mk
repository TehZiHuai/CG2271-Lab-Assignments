################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Lab2_3.cpp \
../cg2271lab2part2.cpp \
../lab1_part2.cpp \
../lab1_part2_q4.cpp \
../lab2.cpp \
../lab3_test.cpp \
../prioq.cpp \
../sample_3.cpp \
../sample_lab2.cpp 

OBJS += \
./Lab2_3.o \
./cg2271lab2part2.o \
./lab1_part2.o \
./lab1_part2_q4.o \
./lab2.o \
./lab3_test.o \
./prioq.o \
./sample_3.o \
./sample_lab2.o 

CPP_DEPS += \
./Lab2_3.d \
./cg2271lab2part2.d \
./lab1_part2.d \
./lab1_part2_q4.d \
./lab2.d \
./lab3_test.d \
./prioq.d \
./sample_3.d \
./sample_lab2.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: AVR C++ Compiler'
	avr-g++ -I"C:\Users\Teh Zi Huai\Documents\arduino-nightly\hardware\arduino\avr\cores\arduino" -I"C:\Users\Teh Zi Huai\Documents\1_School\CG2271\Lab assignments\Lab3\freeRTOS\Source\include" -I"C:\Users\Teh Zi Huai\Documents\arduino-nightly\hardware\arduino\avr\variants\standard" -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -funsigned-char -funsigned-bitfields -fno-exceptions -mmcu=atmega328p -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


