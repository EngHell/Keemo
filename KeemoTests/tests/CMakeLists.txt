cmake_minimum_required(VERSION 3.7...3.21)

if(${CMAKE_VERSION} VERSION_LESS 3.12)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

# set the project name
project(KeemoTestsFolder
        DESCRIPTION "The tests source files folder, used for add_subdirectory()"
        LANGUAGES CXX)


set(CMAKE_CXX_STANDARD 17)


add_executable(
        hello_test
        hello_test.cxx
)
target_link_libraries(
        hello_test
        gtest_main
)

gtest_discover_tests(hello_test)