################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../math/Matrix.cpp \
../math/Quaternion.cpp \
../math/Vertex.cpp 

OBJS += \
./math/Matrix.o \
./math/Quaternion.o \
./math/Vertex.o 

CPP_DEPS += \
./math/Matrix.d \
./math/Quaternion.d \
./math/Vertex.d 


# Each subdirectory must supply rules for building sources it contributes
math/%.o: ../math/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


