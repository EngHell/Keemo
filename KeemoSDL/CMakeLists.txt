# add the executable
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

add_executable(main main.cpp)
target_link_libraries(main ${SDL2_LIBRARIES})