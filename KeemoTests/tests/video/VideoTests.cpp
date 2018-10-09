#include "stdafx.h"
#include <CppUnitTest.h>
#include "Video.hpp"
#include "../../../KeemoLib/src/video/Sprite.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace KeemoTests
{
	namespace VideoTests
	{
		// we will manually calculate values and limits so what we expect is what we really expect
		TEST_CLASS(SpriteTilesTests)
		{
		public:
			TEST_METHOD(TestCreateTileColorData)
			{
				const uint8_t sprite_info[] = {
				0x7C, 0x7C, 0x00, 0xC6, 0xC6, 0x00, 0x00, 0xFE, 0xC6, 0xC6, 0x00, 0xC6, 0xC6, 0x00, 0x00, 0x00
				};

				const Sprite actual{};


				KeemoLib::video::create_tile_color_data(sprite_info, actual.rows);

				const uint8_t expected[8][8]= {
					{0,3,3,3, 3,3,0,0},
					{2,2,0,0, 0,2,2,0},
					{1,1,0,0, 0,1,1,0},
					{2,2,2,2, 2,2,2,0},
					{3,3,0,0, 0,3,3,0},
					{2,2,0,0, 0,2,2,0},
					{1,1,0,0, 0,1,1,0},
					{0,0,0,0, 0,0,0,0}
				};
			
				for(auto row = 0; row < 8; row++)
				{
					for(auto col = 0; col < 8; col++)
					{
						std::wstringstream stream;
						stream << "row: " << row << "col: " << col;
						Assert::AreEqual(expected[row][col], actual.rows[row][col], stream.str().c_str());;
					}
				}
			}

		};
	}
}