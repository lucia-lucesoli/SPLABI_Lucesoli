################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/LinkedList.c \
../src/controller.c \
../src/input.c \
../src/libro.c \
../src/main.c 

OBJS += \
./src/LinkedList.o \
./src/controller.o \
./src/input.o \
./src/libro.o \
./src/main.o 

C_DEPS += \
./src/LinkedList.d \
./src/controller.d \
./src/input.d \
./src/libro.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


