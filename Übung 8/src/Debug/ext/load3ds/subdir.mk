################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../ext/load3ds/C3DSLightReader.cpp \
../ext/load3ds/C3DSMaterialReader.cpp \
../ext/load3ds/C3DSMeshNormalCalculator.cpp \
../ext/load3ds/C3DSMeshReader.cpp \
../ext/load3ds/C3DSReaderBase.cpp 

OBJS += \
./ext/load3ds/C3DSLightReader.o \
./ext/load3ds/C3DSMaterialReader.o \
./ext/load3ds/C3DSMeshNormalCalculator.o \
./ext/load3ds/C3DSMeshReader.o \
./ext/load3ds/C3DSReaderBase.o 

CPP_DEPS += \
./ext/load3ds/C3DSLightReader.d \
./ext/load3ds/C3DSMaterialReader.d \
./ext/load3ds/C3DSMeshNormalCalculator.d \
./ext/load3ds/C3DSMeshReader.d \
./ext/load3ds/C3DSReaderBase.d 


# Each subdirectory must supply rules for building sources it contributes
ext/load3ds/%.o: ../ext/load3ds/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


