cmake_minimum_required(VERSION 3.21)
project(Mbed_Generator)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
add_definitions(-DUSE_RTOS=0)
if(WIN32)
    set(CMAKE_EXE_LINKER_FLAGS -static)
elseif(APPLE)
    set(CMAKE_OSX_ARCHITECTURES arm64 x86_64)
endif()

add_executable(Mbed_Generator main.cpp template_files/main_template.h template_files/cmake_template.h src/replace.cpp src/replace.h template_files/wait_template.h)

