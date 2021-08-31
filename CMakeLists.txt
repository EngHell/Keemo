cmake_minimum_required(VERSION 3.7...3.21)

if(${CMAKE_VERSION} VERSION_LESS 3.12)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

# set the project name
project(Keemo VERSION 0.0.1
        DESCRIPTION "Keemo GameBoy emulator"
        LANGUAGES CXX)


set(CMAKE_CXX_STANDARD 17)

include(FetchContent)
include(CTest)

add_subdirectory(KeemoLib)
#add_subdirectory(KeemoSDL)
add_subdirectory(KeemoTests)