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
			TEST_CLASS(Test16BitsLoads)
			{
			public:
				TEST_METHOD(Test_ld_bc_nn)
				{
					srand(time(nullptr));

					// Usual initialization
					const uint8_t opcode = 0x01;
					const uint16_t expected = rand() % 0xffff;
					// -3 cuz this a 3 byte operand lets make sure we have room
					// for all the op code
					const uint16_t address = rand() % (0xffff-3);

					using namespace KeemoLib;

					// pc pointer setup
					cpu::registers.pc = address;
					// Opcode write to memory
					memory::writeUInt8(address, opcode);
					// Opcode arguments write to memory
					memory::writeUInt16(address+1, expected);

					// emulation step
					cpu::step();

					const uint16_t actual = cpu::registers.bc;

					// due to a Bug with visual studio we have to use IsTrue :)
					Assert::IsTrue(actual == expected);

					// same here
					Assert::IsTrue((address+3) == cpu::registers.pc);
				}

				TEST_METHOD(Test_ld_de_nn)
				{
					srand(time(nullptr));

					// Usual initialization
					const uint8_t opcode = 0x11;
					const uint16_t expected = rand() % 0xffff;
					// 3 cuz this a 3 byte operand lets make sure we have room
					// for all the op code
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

					const uint16_t actual = cpu::registers.de;

					// due to a Bug with visual studio we have to use IsTrue :)
					Assert::IsTrue(actual == expected);

					// same here
					Assert::IsTrue((address+3) == cpu::registers.pc);
				}
			};
		}
	}
}