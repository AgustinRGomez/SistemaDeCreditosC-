################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Clientes.c \
../Credito.c \
../lista.c \
../lista_de_credito.c \
../main.c 

OBJS += \
./Clientes.o \
./Credito.o \
./lista.o \
./lista_de_credito.o \
./main.o 

C_DEPS += \
./Clientes.d \
./Credito.d \
./lista.d \
./lista_de_credito.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


