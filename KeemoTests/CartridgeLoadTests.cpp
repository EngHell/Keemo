#include "stdafx.h"
#include <CppUnitTest.h>
#include "../KeemoLib/includes/Cartridge.hpp"
#include "../KeemoLib/includes/Memory.hpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

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
				using namespace KeemoLib;


				const int errBuffSize = 250;
				char* errbuff = new char[errBuffSize];


				const bool success = cartridge::loadCartridgeToMemory("roms/tetris.gb");
				Assert::IsTrue(success);


				// now we test the correct title
				std::string expectedTitle = "TETRIS";
				cartridge::readCartrideTitle();

				Assert::AreEqual(expectedTitle.c_str(), cartridge::title.c_str());

				// now we test the correct mb type that should be 0x0 for tetris
				const bool typeSuccess = cartridge::readCartridgeType();

				Assert::IsTrue(typeSuccess);

				Assert::AreEqual(
					static_cast<uint8_t>(cartridge::CartridgeType::Const::rom_only),
					static_cast<uint8_t>(cartridge::type)
				);

			}
		};
	}
}