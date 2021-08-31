#include <gtest/gtest.h>
#include "Cartridge.hpp"

TEST(CartridgeTests, TestCartridgeLoadStepByStepTetris) {
    using namespace KeemoLib;


    const bool success = cartridge::loadCartridgeToMemory("roms/tetris.gb");
    ASSERT_TRUE(success);


    // now we test the correct title
    std::string expectedTitle = "TETRIS";
    cartridge::readCartrideTitle();

    ASSERT_STREQ(expectedTitle.c_str(), cartridge::title.c_str());

    // now we test the correct mb type that should be 0x0 for tetris
    const bool typeSuccess = cartridge::readCartridgeType();

    ASSERT_TRUE(typeSuccess);

    ASSERT_EQ(
            static_cast<uint8_t>(cartridge::CartridgeType::Const::rom_only),
            static_cast<uint8_t>(cartridge::type)
    );
}

TEST(CartridgeTests, TestCartridgeLoadToMemoryFail){
    using namespace KeemoLib;


    const bool success = cartridge::loadCartridgeToMemory("roms/nonexistent.gb");
    ASSERT_FALSE(success);
}

TEST(CartridgeTests, TestCartridgeLoadTetris){
    using namespace KeemoLib;

    char expectedTitle[] = "TETRIS";

    const bool success = cartridge::loadCartridge("roms/tetris.gb");

    ASSERT_TRUE(success);

    ASSERT_STREQ(expectedTitle, cartridge::title.c_str());

    ASSERT_EQ(
            static_cast<uint8_t>(cartridge::CartridgeType::Const::rom_only),
            static_cast<uint8_t>(cartridge::type)
    );
}
