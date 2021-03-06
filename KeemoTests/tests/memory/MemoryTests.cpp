#include "stdafx.h"
#include <CppUnitTest.h>
#include "Memory.hpp"

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
				const uint16_t start = 0;
				const uint16_t size = 0x8000;
				const uint16_t limit = start + size;

				for(uint16_t i = 0; i < size; ++i )
				{
					KeemoLib::memory::rom[i] = 1;
				}

				for(uint16_t i = start; i < limit; ++i)
				{
					const uint8_t actual = KeemoLib::memory::readUInt8(i);
					
					Assert::AreEqual(uint8_t(1), actual);
				}
			}

			TEST_METHOD(TestReadVramMemorySpace)
			{
				const uint16_t start = 0x8000;
				const uint16_t size = 0x2000;
				const uint16_t limit = start + size;

				for(uint16_t i = 0; i < size; ++i)
				{
					KeemoLib::memory::vram[i] = 2;
				}

				for(uint16_t i = start; i < limit; ++i)
				{
					const uint8_t actual = KeemoLib::memory::readUInt8(i);
					
					Assert::AreEqual(uint8_t(2), actual);
				}
			}

			TEST_METHOD(TestReadSRamMemorySpace)
			{
				const uint16_t start = 0xa000;
				const uint16_t size = 0x2000;
				const uint16_t limit = start + size;

				for (uint16_t i = 0; i < size; ++i)
				{
					KeemoLib::memory::sram[i] = 3;
				}

				for (uint16_t i = start; i < limit; ++i)
				{
					const uint8_t actual = KeemoLib::memory::readUInt8(i);
					
					Assert::AreEqual(uint8_t(3), actual);
				}
			}

			TEST_METHOD(TestReadIRamMemorySpace)
			{
				const uint16_t start = 0xc000;
				const uint16_t size = 0x2000;
				const uint16_t limit = start + size;

				for (uint16_t i = 0; i < size; ++i)
				{
					KeemoLib::memory::iram[i] = 4;
				}

				for (uint16_t i = start; i < limit; ++i)
				{
					const uint8_t actual = KeemoLib::memory::readUInt8(i);
					
					Assert::AreEqual(uint8_t(4), actual);
				}
			}

			TEST_METHOD(TestReadEchoMemorySpace)
			{
				const uint16_t start = 0xe000;
				const uint16_t size = 0x1e00;
				const uint16_t limit = start + size;

				for (uint16_t i = 0; i < size; ++i)
				{
					KeemoLib::memory::iram[i] = 5;
				}

				for (uint16_t i = start; i < limit; ++i)
				{
					const uint8_t actual = KeemoLib::memory::readUInt8(i);
					
					Assert::AreEqual(uint8_t(5), actual);
				}
			}

			TEST_METHOD(TestReadOamMemorySpace)
			{
				const uint16_t start = 0xfe00;
				const uint16_t size = 0xa0;
				const uint16_t limit = start + size;

				for (uint16_t i = 0; i < size; ++i)
				{
					KeemoLib::memory::oam[i] = 6;
				}

				for (uint16_t i = start; i < limit; ++i)
				{
					const uint8_t actual = KeemoLib::memory::readUInt8(i);
					
					Assert::AreEqual(uint8_t(6), actual);
				}
			}

			TEST_METHOD(TestReadEmpty1MemorySpace)
			{
				const uint16_t start = 0xfea0;
				const uint16_t size = 0x60;
				const uint16_t limit = start + size;

				for (uint16_t i = 0; i < size; ++i)
				{
					KeemoLib::memory::empty1[i] = 7;
				}

				for (uint16_t i = start; i < limit; ++i)
				{
					const uint8_t actual = KeemoLib::memory::readUInt8(i);
					
					Assert::AreEqual(uint8_t(7), actual);
				}
			}

			TEST_METHOD(TestReadIOMemorySpace)
			{
				const uint16_t start = 0xff00;
				const uint16_t size = 0x4c;
				const uint16_t limit = start + size;

				for (uint16_t i = 0; i < size; ++i)
				{
					KeemoLib::memory::io[i] = 8;
				}

				for (uint16_t i = start; i < limit; ++i)
				{
					const uint8_t actual = KeemoLib::memory::readUInt8(i);
					
					std::wstringstream lineBuild;
					lineBuild << "i:" << i;
					std::wstring str = lineBuild.str();
					const wchar_t * c = str.c_str();
					Assert::AreEqual(uint8_t(8), actual, c);
				}
			}

			TEST_METHOD(TestReadEmpty2MemorySpace)
			{
				const uint16_t start = 0xff4c;
				const uint16_t size = 0x34;
				const uint16_t limit = start + size;

				for (uint16_t i = 0; i < size; ++i)
				{
					KeemoLib::memory::empty2[i] = 9;
				}

				for (uint16_t i = start; i < limit; ++i)
				{
					const uint8_t actual = KeemoLib::memory::readUInt8(i);
					
					Assert::AreEqual(uint8_t(9), actual);
				}
			}

			TEST_METHOD(TestReadHRamMemorySpace)
			{
				const uint16_t start = 0xff80;
				const uint16_t size = 0x7f;
				const uint16_t limit = start + size;

				for (uint16_t i = 0; i < size; ++i)
				{
					KeemoLib::memory::hram[i] = 10;
				}

				for (uint16_t i = start; i < limit; ++i)
				{
					const uint8_t actual = KeemoLib::memory::readUInt8(i);
					
					Assert::AreEqual(uint8_t(10), actual);
				}
			}

			TEST_METHOD(TestWriteMemory)
			{
				/*
				 * We can test this directly in an unique for loop since we have
				 * strong tests against the reads
				 * so we know our reads mapping is right, then based on this
				 * we can just test a continuos write to all the memory address
				 */
				const uint16_t start = 0;
				const uint16_t limit = 0xffff;

				for(uint16_t i = start; i < limit; ++i)
				{
					KeemoLib::memory::writeUInt8(i, uint8_t(i));
				}

				for (uint16_t i = start; i < limit; ++i)
				{
					const uint8_t actual = KeemoLib::memory::readUInt8(i);
					const uint8_t expected = uint8_t(i);

					Assert::AreEqual(expected, actual);
				}
			}

			TEST_METHOD(Test16BitRead)
			{
				const uint16_t address = rand() % 0xffff;
				const uint16_t expected = 0xff0f;

				using namespace KeemoLib;

				memory::writeUInt8(address, 0xff);
				memory::writeUInt8(address + 1, 0x0f);

				const uint16_t actual = memory::readUInt16(address);

				// sort arround bugs and some output as there isnt any output from this assert
				Assert::IsTrue(actual == expected, L"actual is diferent from expected");
			}

			TEST_METHOD(Test16BitWrite)
			{
				const uint16_t address = rand() % 0xffff;
				const uint16_t expected = rand() % 0xffff;
				const uint8_t expected_first_byte = expected >> 8;
				const uint8_t expected_second_byte = expected & 0xff;

				using namespace KeemoLib;

				memory::writeUInt16(address, expected);
				//memory::writeUInt8(address + 1, second_byte);

				const uint8_t actual_first_byte = memory::readUInt8(address);
				const uint8_t actual_second_byte = memory::readUInt8(address + 1);

				Assert::AreEqual(expected_first_byte, actual_first_byte);
				Assert::AreEqual(expected_second_byte, actual_second_byte);
			}
		};
	}
}