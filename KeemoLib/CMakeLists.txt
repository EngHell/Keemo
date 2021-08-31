set(HEADER_LIST
        "includes/Cartridge.hpp"
        "includes/Core.hpp"
        "includes/Cpu.hpp"
        "includes/KeemoDefines.h"
        "includes/Memory.hpp"
        "includes/Video.hpp")

add_library(KeemoLib STATIC src/Cartridge.cpp src/Core.cpp src/Cpu.cpp src/Memory.cpp src/Video.cpp ${HEADER_LIST})
target_include_directories(KeemoLib PUBLIC includes)
target_compile_features(KeemoLib PUBLIC cxx_std_17)