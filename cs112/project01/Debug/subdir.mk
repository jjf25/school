################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Playlist.cpp \
../PlaylistManager.cpp \
../PlaylistTester.cpp \
../Song.cpp \
../SongTester.cpp \
../main.cpp 

OBJS += \
./Playlist.o \
./PlaylistManager.o \
./PlaylistTester.o \
./Song.o \
./SongTester.o \
./main.o 

CPP_DEPS += \
./Playlist.d \
./PlaylistManager.d \
./PlaylistTester.d \
./Song.d \
./SongTester.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


