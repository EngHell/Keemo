#include "stdafx.h"
#include <CppUnitTest.h>
#include "../KeemoLib/includes/Memory.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace KeemoTests
{
	namespace MemoryTests
	{
		// we will manually calculate values and limits so what we expect is what we really expect
		TEST_CLASS(ReadMemoryTests)
		{
		public:
			TEST_METHOD(TestReadRomMemorySpace)
			{
				
				const uint16_t size = 0x8000;
				const uint16_t limit = 0 + size;

				for(uint16_t i = 0; i < limit; ++i )
				{
					KeemoLib::memory::rom[i] = uint8_t(i);
				}

				for(uint16_t i = 0; i < limit; ++i)
				{
					const uint8_t val = KeemoLib::memory::readMemory(i);
					Assert::AreEqual(uint8_t(i), val);
				}
			}
		};
	}
}