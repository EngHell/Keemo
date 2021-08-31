cmake_minimum_required(VERSION 3.7...3.21)

if(${CMAKE_VERSION} VERSION_LESS 3.12)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

# set the project name
project(KeemoLib VERSION 0.0.1
        DESCRIPTION "Keemo GameBoy emulator library"
        LANGUAGES CXX)


set(CMAKE_CXX_STANDARD 17)

add_library(KeemoLib STATIC src/Cartridge.cpp src/Core.cpp src/Cpu.cpp src/Memory.cpp src/Video.cpp)
target_include_directories(KeemoLib PUBLIC includes)