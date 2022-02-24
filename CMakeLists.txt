cmake_minimum_required(VERSION 3.21)
project(Mbed_Generator)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
if(WIN32)
    set(CMAKE_EXE_LINKER_FLAGS -static)
endif()

add_executable(Mbed_Generator main.cpp main_template.h cmake_template.h replace.cpp replace.h wait_template.h)

