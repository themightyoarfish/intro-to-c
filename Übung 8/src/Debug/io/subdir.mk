################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../io/PLYTraits.cpp \
../io/Read3DS.cpp \
../io/ReadJPG.cpp \
../io/ReadPLY.cpp \
../io/ReadPPM.cpp \
../io/ReadTGA.cpp \
../io/ReadTIFF.cpp \
../io/TextureFactory.cpp \
../io/TriangleMeshFactory.cpp 

OBJS += \
./io/PLYTraits.o \
./io/Read3DS.o \
./io/ReadJPG.o \
./io/ReadPLY.o \
./io/ReadPPM.o \
./io/ReadTGA.o \
./io/ReadTIFF.o \
./io/TextureFactory.o \
./io/TriangleMeshFactory.o 

CPP_DEPS += \
./io/PLYTraits.d \
./io/Read3DS.d \
./io/ReadJPG.d \
./io/ReadPLY.d \
./io/ReadPPM.d \
./io/ReadTGA.d \
./io/ReadTIFF.d \
./io/TextureFactory.d \
./io/TriangleMeshFactory.d 


# Each subdirectory must supply rules for building sources it contributes
io/%.o: ../io/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


