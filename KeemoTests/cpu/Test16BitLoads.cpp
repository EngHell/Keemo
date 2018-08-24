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
				TEST_CLASS_INITIALIZE(Test_init)
				{
					srand(time(nullptr));
				}

				TEST_METHOD(Test_ld_bc_nn)
				{
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

				TEST_METHOD(Test_ld_hl_nn)
				{
					

					// Usual initialization
					const uint8_t opcode = 0x21;
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

					const uint16_t actual = cpu::registers.hl;

					// due to a Bug with visual studio we have to use IsTrue :)
					Assert::IsTrue(actual == expected);

					// same here
					Assert::IsTrue((address+3) == cpu::registers.pc);
				}

				TEST_METHOD(Test_ld_sp_nn)
				{
					

					// Usual initialization
					const uint8_t opcode = 0x31;
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

					const uint16_t actual = cpu::registers.sp;

					// due to a Bug with visual studio we have to use IsTrue :)
					Assert::IsTrue(actual == expected);

					// same here
					Assert::IsTrue((address+3) == cpu::registers.pc);
				}

				TEST_METHOD(Test_ld_sp_hl)
				{
					

					// Usual initialization
					const uint8_t opcode = 0xf9;
					const uint16_t expected = rand() % 0xffff;
					// 0 cuz this a 1 byte operand lets make sure we have room
					// for all the op code
					// the - 1 is due to the nature of modulus operator
					// since we neaver reach the max number in the range
					// -------> so length - 1
					const uint16_t oplength = 0;
					const uint16_t address = rand() % (0xffff-oplength);

					using namespace KeemoLib;

					// pc pointer setup
					cpu::registers.pc = address;
					// Opcode write to memory
					memory::writeUInt8(address, opcode);
					// Opcode arguments write to memory
					cpu::registers.hl = expected;

					// emulation step
					cpu::step();

					const uint16_t actual = cpu::registers.sp;

					// due to a Bug with visual studio we have to use IsTrue :)
					Assert::IsTrue(actual == expected);

					// same here
					Assert::IsTrue((address+1) == cpu::registers.pc);
				}

				BEGIN_TEST_METHOD_ATTRIBUTE(Test_ld_hl_sp_n_1_random)
					TEST_DESCRIPTION(L"Testing with random values so no way to test the specified flags. just the Z and N flag")
				END_TEST_METHOD_ATTRIBUTE()

				TEST_METHOD(Test_ld_hl_sp_n_1_random)
				{
					// Usual initialization
					const uint8_t opcode = 0xf8;
					
					const uint8_t n = rand() % 0xff;
					const uint16_t sp = (rand() % (0xff00 - 0xf000)) + 0xf000;

					const uint16_t expected = n + sp;

					// the - 1 is due to the nature of modulus operator
					// since we neaver reach the max number in the range
					// -------> so length - 1
					const uint16_t oplength = 1;

					// the limit here is just to not mess with the instructions
					// from the opcode
					const uint16_t address = rand() % (0xf000-oplength);

					using namespace KeemoLib;

					// pc pointer setup
					cpu::registers.pc = address;
					// Opcode write to memory
					memory::writeUInt8(address, opcode);
					// Opcode arguments write to memory
					memory::writeUInt8(address+1, n);
					cpu::registers.sp = sp;

					// emulation step
					cpu::step();

					const uint16_t actual = cpu::registers.hl;

					// due to a Bug with visual studio we have to use IsTrue :)
					Assert::IsTrue(actual == expected);

					// flag check
					const uint8_t Z = (cpu::Z & cpu::registers.f);
					Assert::AreNotEqual(uint8_t(cpu::Z), Z);

					const uint8_t N = (cpu::N & cpu::registers.f);
					Assert::AreNotEqual(uint8_t(cpu::N), N);

					// same here
					// this here as oplength - 1 from his value
					Assert::IsTrue((address+ 1 + oplength) == cpu::registers.pc);
				}

				BEGIN_TEST_METHOD_ATTRIBUTE(Test_ld_hl_sp_n_2)
					TEST_DESCRIPTION(L"Testing with value that should clear both C and H")
				END_TEST_METHOD_ATTRIBUTE()
				TEST_METHOD(Test_ld_hl_sp_n_2)
				{
					// Usual initialization
					const uint8_t opcode = 0xf8;
					
					const uint8_t n = 0x01;
					const uint16_t sp = 0x0001;

					const uint16_t expected = n + sp;

					// the - 1 is due to the nature of modulus operator
					// since we neaver reach the max number in the range
					// -------> so length - 1
					const uint16_t oplength = 1;

					// the limit here is just to not mess with the instructions
					// from the opcode
					const uint16_t address = rand() % (0xf000-oplength);

					using namespace KeemoLib;

					// pc pointer setup
					cpu::registers.pc = address;
					// Opcode write to memory
					memory::writeUInt8(address, opcode);
					// Opcode arguments write to memory
					memory::writeUInt8(address+1, n);
					cpu::registers.sp = sp;

					// emulation step
					cpu::step();

					const uint16_t actual = cpu::registers.hl;

					// due to a Bug with visual studio we have to use IsTrue :)
					Assert::IsTrue(actual == expected);

					// flag check
					const uint8_t Z = (cpu::Z & cpu::registers.f);
					Assert::AreNotEqual(uint8_t(cpu::Z), Z);

					const uint8_t N = (cpu::N & cpu::registers.f);
					Assert::AreNotEqual(uint8_t(cpu::N), N);

					const uint8_t H = (cpu::H & cpu::registers.f);
					Assert::AreNotEqual(uint8_t(cpu::H), H);

					const uint8_t C = (cpu::C & cpu::registers.f);
					Assert::AreNotEqual(uint8_t(cpu::C), C);

					// same here
					// this here as oplength - 1 from his value
					Assert::IsTrue((address+ 1 + oplength) == cpu::registers.pc);
				}

				BEGIN_TEST_METHOD_ATTRIBUTE(Test_ld_hl_sp_n_3)
					TEST_DESCRIPTION(L"Testing with value that should set C AND clear H")
				END_TEST_METHOD_ATTRIBUTE()
				TEST_METHOD(Test_ld_hl_sp_n_3)
				{
					// Usual initialization
					const uint8_t opcode = 0xf8;
					
					const uint8_t n = 0xf1;
					const uint16_t sp = 0x01f1;

					const uint16_t expected = n + sp;

					// the - 1 is due to the nature of modulus operator
					// since we neaver reach the max number in the range
					// -------> so length - 1
					const uint16_t oplength = 1;

					// the limit here is just to not mess with the instructions
					// from the opcode
					const uint16_t address = rand() % (0xf000-oplength);

					using namespace KeemoLib;

					// pc pointer setup
					cpu::registers.pc = address;
					// Opcode write to memory
					memory::writeUInt8(address, opcode);
					// Opcode arguments write to memory
					memory::writeUInt8(address+1, n);
					cpu::registers.sp = sp;

					// emulation step
					cpu::step();

					const uint16_t actual = cpu::registers.hl;

					// due to a Bug with visual studio we have to use IsTrue :)
					Assert::IsTrue(actual == expected);

					// flag check
					const uint8_t Z = (cpu::Z & cpu::registers.f);
					Assert::AreNotEqual(uint8_t(cpu::Z), Z);

					const uint8_t N = (cpu::N & cpu::registers.f);
					Assert::AreNotEqual(uint8_t(cpu::N), N);

					const uint8_t H = (cpu::H & cpu::registers.f);
					Assert::AreNotEqual(uint8_t(cpu::H), H);

					const uint8_t C = (cpu::C & cpu::registers.f);
					Assert::AreEqual(uint8_t(cpu::C), C);

					// same here
					// this here as oplength - 1 from his value
					Assert::IsTrue((address+ 1 + oplength) == cpu::registers.pc);
				}

				BEGIN_TEST_METHOD_ATTRIBUTE(Test_ld_hl_sp_n_4)
					TEST_DESCRIPTION(L"Testing with value that should set H AND clear C")
				END_TEST_METHOD_ATTRIBUTE()
				TEST_METHOD(Test_ld_hl_sp_n_4)
				{
					// Usual initialization
					const uint8_t opcode = 0xf8;
					
					const uint8_t n = 0x21;
					const uint16_t sp = 0x010f;

					const uint16_t expected = n + sp;

					// the - 1 is due to the nature of modulus operator
					// since we neaver reach the max number in the range
					// -------> so length - 1
					const uint16_t oplength = 1;

					// the limit here is just to not mess with the instructions
					// from the opcode
					const uint16_t address = rand() % (0xf000-oplength);

					using namespace KeemoLib;

					// pc pointer setup
					cpu::registers.pc = address;
					// Opcode write to memory
					memory::writeUInt8(address, opcode);
					// Opcode arguments write to memory
					memory::writeUInt8(address+1, n);
					cpu::registers.sp = sp;

					// emulation step
					cpu::step();

					const uint16_t actual = cpu::registers.hl;

					// due to a Bug with visual studio we have to use IsTrue :)
					Assert::IsTrue(actual == expected);

					// flag check
					const uint8_t Z = (cpu::Z & cpu::registers.f);
					Assert::AreNotEqual(uint8_t(cpu::Z), Z);

					const uint8_t N = (cpu::N & cpu::registers.f);
					Assert::AreNotEqual(uint8_t(cpu::N), N);

					const uint8_t H = (cpu::H & cpu::registers.f);
					Assert::AreEqual(uint8_t(cpu::H), H);

					const uint8_t C = (cpu::C & cpu::registers.f);
					Assert::AreNotEqual(uint8_t(cpu::C), C);

					// same here
					// this here as oplength - 1 from his value
					Assert::IsTrue((address+ 1 + oplength) == cpu::registers.pc);
				}

				BEGIN_TEST_METHOD_ATTRIBUTE(Test_ld_hl_sp_n_5)
					TEST_DESCRIPTION(L"Testing with value that should set H AND C")
				END_TEST_METHOD_ATTRIBUTE()
				TEST_METHOD(Test_ld_hl_sp_n_5)
				{
					// Usual initialization
					const uint8_t opcode = 0xf8;
					
					const uint8_t n = 0xf1;
					const uint16_t sp = 0x010f;

					const uint16_t expected = n + sp;

					// the - 1 is due to the nature of modulus operator
					// since we neaver reach the max number in the range
					// -------> so length - 1
					const uint16_t oplength = 1;

					// the limit here is just to not mess with the instructions
					// from the opcode
					const uint16_t address = rand() % (0xf000-oplength);

					using namespace KeemoLib;

					// pc pointer setup
					cpu::registers.pc = address;
					// Opcode write to memory
					memory::writeUInt8(address, opcode);
					// Opcode arguments write to memory
					memory::writeUInt8(address+1, n);
					cpu::registers.sp = sp;

					// emulation step
					cpu::step();

					const uint16_t actual = cpu::registers.hl;

					// due to a Bug with visual studio we have to use IsTrue :)
					Assert::IsTrue(actual == expected);

					// flag check
					const uint8_t Z = (cpu::Z & cpu::registers.f);
					Assert::AreNotEqual(uint8_t(cpu::Z), Z);

					const uint8_t N = (cpu::N & cpu::registers.f);
					Assert::AreNotEqual(uint8_t(cpu::N), N);

					const uint8_t H = (cpu::H & cpu::registers.f);
					Assert::AreEqual(uint8_t(cpu::H), H);

					const uint8_t C = (cpu::C & cpu::registers.f);
					Assert::AreEqual(uint8_t(cpu::C), C);

					// same here
					// this here as oplength - 1 from his value
					Assert::IsTrue((address+ 1 + oplength) == cpu::registers.pc);
				}

				TEST_METHOD(Test_ld_nn_sp)
				{
					// Usual initialization
					const uint8_t opcode = 0x08;
					const uint16_t expected = rand() % 0xffff;

					// the - 1 is due to the nature of modulus operator
					// since we neaver reach the max number in the range
					// -------> so length - 1
					const uint16_t oplength = 2;

					const uint16_t address = rand() % (0xffff-oplength);

					using namespace KeemoLib;

					// pc pointer setup
					cpu::registers.pc = address;
					// Opcode write to memory
					memory::writeUInt8(address, opcode);
					// Opcode arguments write to memory
					cpu::registers.sp = expected;

					// emulation step
					cpu::step();

					// we check the actual value at memory
					const uint16_t actual = memory::readUInt16(address+1);
					Assert::IsTrue(actual == expected);

					// oplenght is 1 less than it's real value so we plus 1 here
					Assert::IsTrue((address+ 1 + oplength) == cpu::registers.pc);
				}

				TEST_METHOD(Test_push_af)
				{
					// Usual initialization
					const uint8_t opcode = 0xf5;
					const uint16_t expected = rand() % 0xffff;
					const uint16_t sp = rand() % 0xffff;

					// the - 1 is due to the nature of modulus operator
					// since we neaver reach the max number in the range
					// -------> so length - 1
					const uint16_t oplength = 0;

					const uint16_t address = rand() % (0xffff-oplength);

					using namespace KeemoLib;

					// pc pointer setup
					cpu::registers.pc = address;
					// Opcode write to memory
					memory::writeUInt8(address, opcode);
					// Opcode arguments write to memory
					cpu::registers.sp = sp;

					cpu::registers.af = expected;

					// emulation step
					cpu::step();

					// we check the actual value at memory
					const uint16_t actual = memory::readUInt16(sp-2);
					Assert::IsTrue(actual == expected);

					// now we check the sp decrement
					const uint16_t actual_sp = cpu::registers.sp;
					Assert::IsTrue(actual_sp == (sp-2));

					// oplenght is 1 less than it's real value so we plus 1 here
					Assert::IsTrue((address+ 1 + oplength) == cpu::registers.pc);
				}

				TEST_METHOD(Test_push_bc)
				{
					// Usual initialization
					const uint8_t opcode = 0xc5;
					const uint16_t expected = rand() % 0xffff;
					const uint16_t sp = rand() % 0xffff;

					// the - 1 is due to the nature of modulus operator
					// since we neaver reach the max number in the range
					// -------> so length - 1
					const uint16_t oplength = 0;

					const uint16_t address = rand() % (0xffff-oplength);

					using namespace KeemoLib;

					// pc pointer setup
					cpu::registers.pc = address;
					// Opcode write to memory
					memory::writeUInt8(address, opcode);
					// Opcode arguments write to memory
					cpu::registers.sp = sp;

					cpu::registers.bc = expected;

					// emulation step
					cpu::step();

					// we check the actual value at memory
					const uint16_t actual = memory::readUInt16(sp-2);
					Assert::IsTrue(actual == expected);

					// now we check the sp decrement
					const uint16_t actual_sp = cpu::registers.sp;
					Assert::IsTrue(actual_sp == (sp-2));

					// oplenght is 1 less than it's real value so we plus 1 here
					Assert::IsTrue((address+ 1 + oplength) == cpu::registers.pc);
				}

				TEST_METHOD(Test_push_de)
				{
					// Usual initialization
					const uint8_t opcode = 0xd5;
					const uint16_t expected = rand() % 0xffff;
					const uint16_t sp = rand() % 0xffff;

					// the - 1 is due to the nature of modulus operator
					// since we neaver reach the max number in the range
					// -------> so length - 1
					const uint16_t oplength = 0;

					const uint16_t address = rand() % (0xffff-oplength);

					using namespace KeemoLib;

					// pc pointer setup
					cpu::registers.pc = address;
					// Opcode write to memory
					memory::writeUInt8(address, opcode);
					// Opcode arguments write to memory
					cpu::registers.sp = sp;

					cpu::registers.de = expected;

					// emulation step
					cpu::step();

					// we check the actual value at memory
					const uint16_t actual = memory::readUInt16(sp-2);
					Assert::IsTrue(actual == expected);

					// now we check the sp decrement
					const uint16_t actual_sp = cpu::registers.sp;
					Assert::IsTrue(actual_sp == (sp-2));

					// oplenght is 1 less than it's real value so we plus 1 here
					Assert::IsTrue((address+ 1 + oplength) == cpu::registers.pc);
				}

				TEST_METHOD(Test_push_hl)
				{
					// Usual initialization
					const uint8_t opcode = 0xe5;
					const uint16_t expected = rand() % 0xffff;
					const uint16_t sp = rand() % 0xffff;

					// the - 1 is due to the nature of modulus operator
					// since we neaver reach the max number in the range
					// -------> so length - 1
					const uint16_t oplength = 0;

					const uint16_t address = rand() % (0xffff-oplength);

					using namespace KeemoLib;

					// pc pointer setup
					cpu::registers.pc = address;
					// Opcode write to memory
					memory::writeUInt8(address, opcode);
					// Opcode arguments write to memory
					cpu::registers.sp = sp;

					cpu::registers.hl = expected;

					// emulation step
					cpu::step();

					// we check the actual value at memory
					const uint16_t actual = memory::readUInt16(sp-2);
					Assert::IsTrue(actual == expected);

					// now we check the sp decrement
					const uint16_t actual_sp = cpu::registers.sp;
					Assert::IsTrue(actual_sp == (sp-2));

					// oplenght is 1 less than it's real value so we plus 1 here
					Assert::IsTrue((address+ 1 + oplength) == cpu::registers.pc);
				}

				/*
				 * POP nn
				 */

				TEST_METHOD(Test_pop_af)
				{
					// Usual initialization
					const uint8_t opcode = 0xf1;
					const uint16_t expected = rand() % 0xffff;
					const uint16_t sp = rand() % 0xffff;

					// modifying this so it's more natural.
					const uint16_t oplength = 1;

					const uint16_t address = rand() % (0xffff-oplength);

					using namespace KeemoLib;

					// pc pointer setup
					cpu::registers.pc = address;
					// Opcode write to memory
					memory::writeUInt8(address, opcode);
					// Opcode arguments write to memory
					cpu::registers.sp = sp;

					memory::writeUInt16(sp, expected);

					// emulation step
					cpu::step();

					// we check the actual value at memory
					const uint16_t actual = cpu::registers.af;
					Assert::IsTrue(actual == expected);

					// now we check the sp increment
					const uint16_t actual_sp = cpu::registers.sp;
					Assert::IsTrue(actual_sp == (sp+2));

					// oplenght is 1 less than it's real value so we plus 1 here
					Assert::IsTrue((address+1) == cpu::registers.pc);
				}

				TEST_METHOD(Test_pop_bc)
				{
					// Usual initialization
					const uint8_t opcode = 0xc1;
					const uint16_t expected = rand() % 0xffff;
					const uint16_t sp = rand() % 0xffff;

					// modifying this so it's more natural.
					const uint16_t oplength = 1;

					const uint16_t address = rand() % (0xffff-oplength);

					using namespace KeemoLib;

					// pc pointer setup
					cpu::registers.pc = address;
					// Opcode write to memory
					memory::writeUInt8(address, opcode);
					// Opcode arguments write to memory
					cpu::registers.sp = sp;

					memory::writeUInt16(sp, expected);

					// emulation step
					cpu::step();

					// we check the actual value at memory
					const uint16_t actual = cpu::registers.bc;
					Assert::IsTrue(actual == expected);

					// now we check the sp increment
					const uint16_t actual_sp = cpu::registers.sp;
					Assert::IsTrue(actual_sp == (sp+2));

					// oplenght is 1 less than it's real value so we plus 1 here
					Assert::IsTrue((address+1) == cpu::registers.pc);
				}

				TEST_METHOD(Test_pop_de)
				{
					// Usual initialization
					const uint8_t opcode = 0xd1;
					const uint16_t expected = rand() % 0xffff;
					const uint16_t sp = rand() % 0xffff;

					// modifying this so it's more natural.
					const uint16_t oplength = 1;

					const uint16_t address = rand() % (0xffff-oplength);

					using namespace KeemoLib;

					// pc pointer setup
					cpu::registers.pc = address;
					// Opcode write to memory
					memory::writeUInt8(address, opcode);
					// Opcode arguments write to memory
					cpu::registers.sp = sp;

					memory::writeUInt16(sp, expected);

					// emulation step
					cpu::step();

					// we check the actual value at memory
					const uint16_t actual = cpu::registers.de;
					Assert::IsTrue(actual == expected);

					// now we check the sp increment
					const uint16_t actual_sp = cpu::registers.sp;
					Assert::IsTrue(actual_sp == (sp+2));

					// oplenght is 1 less than it's real value so we plus 1 here
					Assert::IsTrue((address+1) == cpu::registers.pc);
				}

				TEST_METHOD(Test_pop_hl)
				{
					// Usual initialization
					const uint8_t opcode = 0xe1;
					const uint16_t expected = rand() % 0xffff;
					const uint16_t sp = rand() % 0xffff;

					// modifying this so it's more natural.
					const uint16_t oplength = 1;

					const uint16_t address = rand() % (0xffff-oplength);

					using namespace KeemoLib;

					// pc pointer setup
					cpu::registers.pc = address;
					// Opcode write to memory
					memory::writeUInt8(address, opcode);
					// Opcode arguments write to memory
					cpu::registers.sp = sp;

					memory::writeUInt16(sp, expected);

					// emulation step
					cpu::step();

					// we check the actual value at memory
					const uint16_t actual = cpu::registers.hl;
					Assert::IsTrue(actual == expected);

					// now we check the sp increment
					const uint16_t actual_sp = cpu::registers.sp;
					Assert::IsTrue(actual_sp == (sp+2));

					// oplenght is 1 less than it's real value so we plus 1 here
					Assert::IsTrue((address+1) == cpu::registers.pc);
				}
			};
		}
	}
}