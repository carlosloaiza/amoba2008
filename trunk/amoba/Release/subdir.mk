################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Analyzer.cpp \
../List.cpp \
../MyButton.cpp \
../Node.cpp \
../StateNet.cpp \
../StateNode.cpp \
../main.cpp \
../window.cpp 

OBJS += \
./Analyzer.o \
./List.o \
./MyButton.o \
./Node.o \
./StateNet.o \
./StateNode.o \
./main.o \
./window.o 

CPP_DEPS += \
./Analyzer.d \
./List.d \
./MyButton.d \
./Node.d \
./StateNet.d \
./StateNode.d \
./main.d \
./window.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -IC:/GTK/include/gtkmm-2.4 -IC:/GTK/lib/gtkmm-2.4/include -IC:/GTK/include/glibmm-2.4 -IC:/GTK/lib/glibmm-2.4/include -IC:/GTK/include/giomm-2.4 -IC:/GTK/lib/giomm-2.4/include -IC:/GTK/include/gdkmm-2.4 -IC:/GTK/lib/gdkmm-2.4/include -IC:/GTK/include/pangomm-1.4 -IC:/GTK/include/atkmm-1.6 -IC:/GTK/include/gtk-2.0 -IC:/GTK/include/sigc++-2.0 -IC:/GTK/lib/sigc++-2.0/include -IC:/GTK/include/glib-2.0 -IC:/GTK/lib/glib-2.0/include -IC:/GTK/lib/gtk-2.0/include -IC:/GTK/include/cairomm-1.0 -IC:/GTK/include/pango-1.0 -IC:/GTK/include/cairo -IC:/GTK/include/libpng12 -IC:/GTK/include/atk-1.0 -IC:/GTK/include/libglademm-2.4 -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


