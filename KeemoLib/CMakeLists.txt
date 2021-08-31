set(HEADER_LIST
        "includes/Cartridge.hpp"
        "includes/Core.hpp"
        "includes/Cpu.hpp"
        "includes/KeemoDefines.h"
        "includes/Memory.hpp"
        "includes/Video.hpp"
        "src/op/"
        )

set(OP_SOURCES
        "src/op/Bit8Loads.cpp"
        "src/op/Bit8Math.cpp"
        "src/op/Bit16Loads.cpp"
        "src/op/ControlFlow.cpp"
        "src/op/MathHelpers.hpp"
        "src/op/Op.hpp"
        )

add_library(KeemoLib STATIC ${OP_SOURCES} src/Cartridge.cpp src/Core.cpp src/Cpu.cpp src/Memory.cpp src/Video.cpp ${HEADER_LIST})
target_include_directories(KeemoLib PUBLIC includes)
target_compile_features(KeemoLib PUBLIC cxx_std_17)