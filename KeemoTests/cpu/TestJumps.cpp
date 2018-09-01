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
				TEST_METHOD_INITIALIZE(methodName)   
				{  
					// to avoid bugs from last tests and not set it at the start of each test
				    KeemoLib::cpu::raise_pc = true;
				}

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

					const uint16_t address = rand() % (0xffff - oplength);

					using namespace KeemoLib;

					// pc pointer setup
					cpu::registers.pc = address;
					// Opcode write to memory
					memory::writeUInt8(address, opcode);
					// Opcode arguments write to memory
					memory::writeUInt16(address + 1, expected);

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

					const uint16_t address = rand() % (0xffff - oplength);

					using namespace KeemoLib;

					// pc pointer setup
					cpu::registers.pc = address;
					// Opcode write to memory
					memory::writeUInt8(address, opcode);
					// Opcode arguments write to memory
					memory::writeUInt16(address + 1, expected);
					cpu::registers.f = cpu::Flags::Z;

					// emulation step
					cpu::step();

					// we check the actual value at memory
					const uint16_t actual = cpu::registers.pc;
					Assert::IsTrue(actual == address + (oplength));
				}

				// jump if the Z flag is reset
				TEST_METHOD(test_jp_nz_nn_z_reset)
				{
					// Usual initialization
					const uint8_t opcode = 0xc2;
					const uint16_t expected = rand() % 0xffff;

					// modifying this so it's more natural.
					const uint16_t oplength = 3;

					const uint16_t address = rand() % (0xffff - oplength);

					using namespace KeemoLib;

					// pc pointer setup
					cpu::registers.pc = address;
					// Opcode write to memory
					memory::writeUInt8(address, opcode);
					// Opcode arguments write to memory
					memory::writeUInt16(address + 1, expected);
					cpu::registers.f = 0;

					// emulation step
					cpu::step();

					// we check the actual value at memory
					const uint16_t actual = cpu::registers.pc;
					Assert::IsTrue(actual == expected);
				}


				// jumps is z is set
				TEST_METHOD(test_jp_z_nn_set)
				{
					// Usual initialization
					const uint8_t opcode = 0xca;
					const uint16_t expected = rand() % 0xffff;

					// modifying this so it's more natural.
					const uint16_t oplength = 3;

					const uint16_t address = rand() % (0xffff - oplength);

					using namespace KeemoLib;

					// pc pointer setup
					cpu::registers.pc = address;
					// Opcode write to memory
					memory::writeUInt8(address, opcode);
					// Opcode arguments write to memory
					memory::writeUInt16(address + 1, expected);
					cpu::registers.f = cpu::Flags::Z;

					// emulation step
					cpu::step();

					// we check the actual value at memory
					const uint16_t actual = cpu::registers.pc;
					Assert::IsTrue(actual == expected);
				}

				// jumps is z is set
				TEST_METHOD(test_jp_z_nn_reset)
				{
					// Usual initialization
					const uint8_t opcode = 0xca;
					const uint16_t expected = rand() % 0xffff;

					// modifying this so it's more natural.
					const uint16_t oplength = 3;

					const uint16_t address = rand() % (0xffff - oplength);

					using namespace KeemoLib;

					// pc pointer setup
					cpu::registers.pc = address;
					// Opcode write to memory
					memory::writeUInt8(address, opcode);
					// Opcode arguments write to memory
					memory::writeUInt16(address + 1, expected);
					cpu::registers.f = 0;

					// emulation step
					cpu::step();

					// we check the actual value at memory
					const uint16_t actual = cpu::registers.pc;
					Assert::IsTrue(actual == (address+oplength));
				}


				// jump if the C flag is reset
				TEST_METHOD(test_jp_nc_nn_c_set)
				{
					// Usual initialization
					const uint8_t opcode = 0xd2;
					const uint16_t expected = rand() % 0xffff;

					// modifying this so it's more natural.
					const uint16_t oplength = 3;

					const uint16_t address = rand() % (0xffff - oplength);

					using namespace KeemoLib;

					// pc pointer setup
					cpu::registers.pc = address;
					// Opcode write to memory
					memory::writeUInt8(address, opcode);
					// Opcode arguments write to memory
					memory::writeUInt16(address + 1, expected);
					cpu::registers.f = cpu::Flags::C;

					// emulation step
					cpu::step();

					// we check the actual value at memory
					const uint16_t actual = cpu::registers.pc;
					Assert::IsTrue(actual == address + (oplength));
				}

				// jump if the c flag is reset
				TEST_METHOD(test_jp_nc_nn_c_reset)
				{
					// Usual initialization
					const uint8_t opcode = 0xd2;
					const uint16_t expected = rand() % 0xffff;

					// modifying this so it's more natural.
					const uint16_t oplength = 3;

					const uint16_t address = rand() % (0xffff - oplength);

					using namespace KeemoLib;

					// pc pointer setup
					cpu::registers.pc = address;
					// Opcode write to memory
					memory::writeUInt8(address, opcode);
					// Opcode arguments write to memory
					memory::writeUInt16(address + 1, expected);
					cpu::registers.f = 0;

					// emulation step
					cpu::step();

					// we check the actual value at memory
					const uint16_t actual = cpu::registers.pc;
					Assert::IsTrue(actual == expected);
				}

				// jumps is c is set
				TEST_METHOD(test_jp_c_nn_set)
				{
					// Usual initialization
					const uint8_t opcode = 0xda;
					const uint16_t expected = rand() % 0xffff;

					// modifying this so it's more natural.
					const uint16_t oplength = 3;

					const uint16_t address = rand() % (0xffff - oplength);

					using namespace KeemoLib;

					// pc pointer setup
					cpu::registers.pc = address;
					// Opcode write to memory
					memory::writeUInt8(address, opcode);
					// Opcode arguments write to memory
					memory::writeUInt16(address + 1, expected);
					cpu::registers.f = cpu::Flags::C;

					// emulation step
					cpu::step();

					// we check the actual value at memory
					const uint16_t actual = cpu::registers.pc;
					Assert::IsTrue(actual == expected);
				}

				// jumps is z is set
				TEST_METHOD(test_jp_c_nn_reset)
				{
					// Usual initialization
					const uint8_t opcode = 0xda;
					const uint16_t expected = rand() % 0xffff;

					// modifying this so it's more natural.
					const uint16_t oplength = 3;

					const uint16_t address = rand() % (0xffff - oplength);

					using namespace KeemoLib;

					// pc pointer setup
					cpu::registers.pc = address;
					// Opcode write to memory
					memory::writeUInt8(address, opcode);
					// Opcode arguments write to memory
					memory::writeUInt16(address + 1, expected);
					cpu::registers.f = 0;

					// emulation step
					cpu::step();

					// we check the actual value at memory
					const uint16_t actual = cpu::registers.pc;
					Assert::IsTrue(actual == (address+oplength));
				}

				TEST_METHOD(test_jp_hl)
				{
					// Usual initialization
					const uint8_t opcode = 0xe9;
					const uint16_t expected = rand() % 0xffff;
					const uint16_t toDeffer = rand() % 0xffff;

					// modifying this so it's more natural.
					const uint16_t oplength = 1;

					const uint16_t address = rand() % (0xffff - oplength);

					using namespace KeemoLib;

					// pc pointer setup
					cpu::registers.pc = address;
					// Opcode write to memory
					memory::writeUInt8(address, opcode);
					// Opcode arguments write to memory
					memory::writeUInt16(toDeffer, expected);
					cpu::registers.hl = toDeffer;

					// emulation step
					cpu::step();

					// we check the actual value at memory
					const uint16_t actual = cpu::registers.pc;
					Assert::IsTrue(actual == expected);
				}

				TEST_METHOD(test_jr_n)
				{
					// Usual initialization
					const uint8_t opcode = 0x18;
					const uint16_t n = rand() % 0xff;

					// modifying this so it's more natural.
					const uint16_t oplength = 2;

					const uint16_t address = rand() % (0xffff - 0xff - oplength);

					using namespace KeemoLib;

					// pc pointer setup
					cpu::registers.pc = address;
					// Opcode write to memory
					memory::writeUInt8(address, opcode);
					// Opcode arguments write to memory
					memory::writeUInt8(address+1, n);

					// emulation step
					cpu::step();

					// we check the actual value at memory
					const uint16_t actual = cpu::registers.pc;
					Assert::IsTrue(actual == (address+n));
				}

				// jump if the Z flag is reset
				TEST_METHOD(test_jr_nz_n_z_set)
				{
					// Usual initialization
					const uint64_t address_limit = 0xff;
					const uint8_t opcode = 0x20;
					const uint8_t n = rand() % address_limit;

					// modifying this so it's more natural.
					const uint16_t oplength = 2;

					const uint16_t address = rand() % (0xffff - oplength - address_limit);

					using namespace KeemoLib;

					// pc pointer setup
					cpu::registers.pc = address;
					// Opcode write to memory
					memory::writeUInt8(address, opcode);
					// Opcode arguments write to memory
					memory::writeUInt8(address + 1, n);
					cpu::registers.f = cpu::Flags::Z;

					// emulation step
					cpu::step();

					// we check the actual value at memory
					const uint16_t actual = cpu::registers.pc;
					Assert::IsTrue(actual == address + (oplength));
				}

				// jump if the Z flag is reset
				TEST_METHOD(test_jr_nz_n_z_reset)
				{
					// Usual initialization
					const uint64_t address_limit = 0xff;
					const uint8_t opcode = 0x20;
					const uint8_t n = rand() % address_limit;

					// modifying this so it's more natural.
					const uint16_t oplength = 2;

					const uint16_t address = rand() % (0xffff - oplength - address_limit);

					using namespace KeemoLib;

					// pc pointer setup
					cpu::registers.pc = address;
					// Opcode write to memory
					memory::writeUInt8(address, opcode);
					// Opcode arguments write to memory
					memory::writeUInt8(address + 1, n);
					cpu::registers.f = 0;

					// emulation step
					cpu::step();

					// we check the actual value at memory
					const uint16_t actual = cpu::registers.pc;
					Assert::IsTrue(actual == (address+n));
				}


				// jumps is z is set
				TEST_METHOD(test_jr_z_n_set)
				{
					// Usual initialization
					const uint64_t address_limit = 0xff;
					const uint8_t opcode = 0x28;
					const uint8_t n = rand() % address_limit;

					// modifying this so it's more natural.
					const uint16_t oplength = 2;

					const uint16_t address = rand() % (0xffff - oplength - address_limit);

					using namespace KeemoLib;

					// pc pointer setup
					cpu::registers.pc = address;
					// Opcode write to memory
					memory::writeUInt8(address, opcode);
					// Opcode arguments write to memory
					memory::writeUInt8(address + 1, n);
					cpu::registers.f = cpu::Flags::Z;

					// emulation step
					cpu::step();

					// we check the actual value at memory
					const uint16_t actual = cpu::registers.pc;
					Assert::IsTrue(actual == (address+n));
				}

				// jumps is z is set
				TEST_METHOD(test_jr_z_n_reset)
				{
					// Usual initialization
					const uint64_t address_limit = 0xff;
					const uint8_t opcode = 0x28;
					const uint8_t n = rand() % address_limit;

					// modifying this so it's more natural.
					const uint16_t oplength = 2;

					const uint16_t address = rand() % (0xffff - oplength - address_limit);

					using namespace KeemoLib;

					// pc pointer setup
					cpu::registers.pc = address;
					// Opcode write to memory
					memory::writeUInt8(address, opcode);
					// Opcode arguments write to memory
					memory::writeUInt8(address + 1, n);
					cpu::registers.f = 0;

					// emulation step
					cpu::step();

					// we check the actual value at memory
					const uint16_t actual = cpu::registers.pc;
					Assert::IsTrue(actual == (address+oplength));
				}


				// jump if the Z flag is reset
				TEST_METHOD(test_jr_nc_n_c_set)
				{
					// Usual initialization
					const uint64_t address_limit = 0xff;
					const uint8_t opcode = 0x30;
					const uint8_t n = rand() % address_limit;

					// modifying this so it's more natural.
					const uint16_t oplength = 2;

					const uint16_t address = rand() % (0xffff - oplength - address_limit);

					using namespace KeemoLib;

					// pc pointer setup
					cpu::registers.pc = address;
					// Opcode write to memory
					memory::writeUInt8(address, opcode);
					// Opcode arguments write to memory
					memory::writeUInt8(address + 1, n);
					cpu::registers.f = cpu::Flags::C;

					// emulation step
					cpu::step();

					// we check the actual value at memory
					const uint16_t actual = cpu::registers.pc;
					Assert::IsTrue(actual == address + (oplength));
				}

				// jump if the Z flag is reset
				TEST_METHOD(test_jr_nc_n_c_reset)
				{
					// Usual initialization
					const uint64_t address_limit = 0xff;
					const uint8_t opcode = 0x30;
					const uint8_t n = rand() % address_limit;

					// modifying this so it's more natural.
					const uint16_t oplength = 2;

					const uint16_t address = rand() % (0xffff - oplength - address_limit);

					using namespace KeemoLib;

					// pc pointer setup
					cpu::registers.pc = address;
					// Opcode write to memory
					memory::writeUInt8(address, opcode);
					// Opcode arguments write to memory
					memory::writeUInt8(address + 1, n);
					cpu::registers.f = 0;

					// emulation step
					cpu::step();

					// we check the actual value at memory
					const uint16_t actual = cpu::registers.pc;
					Assert::IsTrue(actual == (address+n));
				}

			};

		}
	}
}
