#include "stdafx.h"
#include <CppUnitTest.h>
#include <ctime>
#include "../../KeemoLib/includes/Memory.hpp"
#include "../../KeemoLib/includes/Cpu.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace KeemoTests
{
	namespace CpuTests
	{
		namespace OpTests
		{
			TEST_CLASS(TestJumps)
			{
			public:
				TEST_CLASS_INITIALIZE(Test_init)
				{
					srand(time(nullptr));
				}

				TEST_METHOD(test_jp_nn)
				{
					// Usual initialization
					const uint8_t opcode = 0xc3;
					const uint16_t expected = rand() % 0xffff;

					// modifying this so it's more natural.
					const uint16_t oplength = 3;

					const uint16_t address = rand() % (0xffff-oplength);

					using namespace KeemoLib;

					// pc pointer setup
					cpu::registers.pc = address;
					// Opcode write to memory
					memory::writeUInt8(address, opcode);
					// Opcode arguments write to memory
					memory::writeUInt16(address+1, expected);

					// emulation step
					cpu::step();

					// we check the actual value at memory
					const uint16_t actual = cpu::registers.pc;
					Assert::IsTrue(actual == expected);
				}

				// jump if the Z flag is reset
				TEST_METHOD(test_jp_nz_nn_z_set)
				{
					// Usual initialization
					const uint8_t opcode = 0xc2;
					const uint16_t expected = rand() % 0xffff;

					// modifying this so it's more natural.
					const uint16_t oplength = 3;

					const uint16_t address = rand() % (0xffff-oplength);

					using namespace KeemoLib;

					// pc pointer setup
					cpu::registers.pc = address;
					// Opcode write to memory
					memory::writeUInt8(address, opcode);
					// Opcode arguments write to memory
					memory::writeUInt16(address+1, expected);
					cpu::registers.f = cpu::Flags::Z;

					// emulation step
					cpu::step();

					// we check the actual value at memory
					const uint16_t actual = cpu::registers.pc;
					Assert::IsTrue(actual == address+(oplength));
				}

				// jump if the Z flag is reset
				TEST_METHOD(test_jp_nz_nn_z_reset)
				{
					// Usual initialization
					const uint8_t opcode = 0xc2;
					const uint16_t expected = rand() % 0xffff;

					// modifying this so it's more natural.
					const uint16_t oplength = 3;

					const uint16_t address = rand() % (0xffff-oplength);

					using namespace KeemoLib;

					// pc pointer setup
					cpu::registers.pc = address;
					// Opcode write to memory
					memory::writeUInt8(address, opcode);
					// Opcode arguments write to memory
					memory::writeUInt16(address+1, expected);
					cpu::registers.f = 0;

					// emulation step
					cpu::step();

					// we check the actual value at memory
					const uint16_t actual = cpu::registers.pc;
					Assert::IsTrue(actual == expected);
				}

			};


		}
	}
}