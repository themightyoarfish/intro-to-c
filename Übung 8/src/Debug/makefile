################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include view/subdir.mk
-include rendering/subdir.mk
-include math/subdir.mk
-include io/subdir.mk
-include ext/load3ds/subdir.mk
-include build/ext/load3ds/CMakeFiles/c3dsreader.dir/subdir.mk
-include build/CMakeFiles/viewer.dir/view/subdir.mk
-include build/CMakeFiles/viewer.dir/rendering/subdir.mk
-include build/CMakeFiles/viewer.dir/math/subdir.mk
-include build/CMakeFiles/viewer.dir/io/subdir.mk
-include build/CMakeFiles/viewer.dir/subdir.mk
-include build/CMakeFiles/2.8.12.2/CompilerIdCXX/subdir.mk
-include build/CMakeFiles/2.8.12.2/CompilerIdC/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(TCC_DEPS)),)
-include $(TCC_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: blatt8

# Tool invocations
blatt8: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: GCC C++ Linker'
	g++  -o "blatt8" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(C++_DEPS)$(C_DEPS)$(TCC_DEPS)$(CC_DEPS)$(CPP_DEPS)$(EXECUTABLES)$(CXX_DEPS)$(C_UPPER_DEPS) blatt8
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
