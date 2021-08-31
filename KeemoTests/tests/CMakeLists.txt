FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

include(GoogleTest)
enable_testing()

# required file coping.
file(COPY roms/tetris.gb DESTINATION roms)

# function definitions
##  Function to create a new test based off the pre-defined naming template
##  Copied from https://stackoverflow.com/questions/60251076/corrections-to-cmakelist-txt-file-for-google-testing
##
function(new_test testname interiorDirectory)
    add_executable(${testname} ${interiorDirectory}/${testname}.cpp)

    add_dependencies(${testname} KeemoLib)

    target_compile_features(${testname} PRIVATE cxx_std_17)

    target_link_libraries(${testname} PRIVATE KeemoLib gtest_main)

    gtest_discover_tests(${testname})
endfunction(new_test)

# tests.
#cartridge test_case
new_test(cartridge_load_tests cartridge)