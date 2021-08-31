#cartridge test_case
add_executable(
        cartridge_load_test
        cartridge/CartridgeLoadTests.cpp
)

target_compile_features(cartridge_load_test PRIVATE cxx_std_17)

target_link_libraries(
        cartridge_load_test
        PRIVATE
        KeemoLib
        gtest_main
)

gtest_discover_tests(cartridge_load_test)