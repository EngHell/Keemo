#include "Cartridge.hpp"
#include <gtest/gtest.h>

TEST(CartridgeTests, TestCartridgeLoadStepByStepTetris) {
    using namespace KeemoLib;


    const bool success = cartridge::loadCartridgeToMemory("roms/tetris.gb");
    ASSERT_TRUE(success);


    // now we test the correct title
    std::string expectedTitle = "TETRIS";
    cartridge::readCartrideTitle();

    ASSERT_EQ(expectedTitle.c_str(), cartridge::title.c_str());

    // now we test the correct mb type that should be 0x0 for tetris
    const bool typeSuccess = cartridge::readCartridgeType();

    ASSERT_TRUE(typeSuccess);

    ASSERT_EQ(
            static_cast<uint8_t>(cartridge::CartridgeType::Const::rom_only),
            static_cast<uint8_t>(cartridge::type)
    );
}

/*
namespace KeemoTests
{
	namespace CartridgeTests
	{
		// we will manually calculate values and limits so what we expect is what we really expect
		TEST_CLASS(CartridgeLoadTests)
		{
		public:
			TEST_METHOD(TestCartridgeLoadStepByStepTetris)
			{


			}

			TEST_METHOD(TestCartridgeLoadToMemoryFail)
			{
				using namespace KeemoLib;


				const bool success = cartridge::loadCartridgeToMemory("roms/nonexistent.gb");
				Assert::IsFalse(success);

			}


			TEST_METHOD(TestCartridgeLoadTetris)
			{
				using namespace KeemoLib;

				char expectedTitle[] = "TETRIS";

				const bool success = cartridge::loadCartridge("roms/tetris.gb");

				Assert::IsTrue(success);

				Assert::AreEqual(expectedTitle, cartridge::title.c_str());

				Assert::AreEqual(
					static_cast<uint8_t>(cartridge::CartridgeType::Const::rom_only),
					static_cast<uint8_t>(cartridge::type)
				);

			}

		};
	}
}

 **/
