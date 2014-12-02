################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../rendering/Skybox.cpp \
../rendering/Texture.cpp \
../rendering/TexturedMesh.cpp \
../rendering/Transformable.cpp \
../rendering/TriangleMesh.cpp 

OBJS += \
./rendering/Skybox.o \
./rendering/Texture.o \
./rendering/TexturedMesh.o \
./rendering/Transformable.o \
./rendering/TriangleMesh.o 

CPP_DEPS += \
./rendering/Skybox.d \
./rendering/Texture.d \
./rendering/TexturedMesh.d \
./rendering/Transformable.d \
./rendering/TriangleMesh.d 


# Each subdirectory must supply rules for building sources it contributes
rendering/%.o: ../rendering/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


