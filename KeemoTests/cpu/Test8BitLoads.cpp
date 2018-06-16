#include "stdafx.h"
#include <CppUnitTest.h>
#include "../../KeemoLib/includes/Memory.hpp"
#include "../../KeemoLib/includes/Cpu.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace KeemoTests
{
	namespace CpuTests
	{
		namespace OpTests
		{
			TEST_CLASS(Test8BitLoads)
			{
			public:
				TEST_METHOD(Test_ld_b_n)
				{
					// OPCODE: 0x06
					// LD B, n
					using namespace KeemoLib;

					const uint8_t expected = rand() % 256;

					cpu::registers.pc = 0x100;
					memory::writeUInt8(cpu::registers.pc, 0x06);
					memory::writeUInt8(cpu::registers.pc + 1, expected);

					cpu::step();

					const uint8_t actual = cpu::registers.b;

					Assert::AreEqual(expected, actual);
					// due to a bug with Visual Studio we use Is True rather than AreEqual
					Assert::IsTrue(uint16_t(0x100 + 2) == cpu::registers.pc);

				}

				TEST_METHOD(Test_ld_c_n)
				{
					// OPCODE: 0x0e
					// LD C, n
					using namespace KeemoLib;

					const uint8_t opcode = 0x0e;
					const uint8_t expected = rand() % 256;

					cpu::registers.pc = 0x100;
					memory::writeUInt8(cpu::registers.pc, opcode);
					memory::writeUInt8(cpu::registers.pc + 1, expected);

					cpu::step();

					const uint8_t actual = cpu::registers.c;

					Assert::AreEqual(expected, actual);
					// due to a bug with Visual Studio we use Is True rather than AreEqual
					Assert::IsTrue(uint16_t(0x100 + 2) == cpu::registers.pc);

				}

				TEST_METHOD(Test_ld_d_n)
				{
					// OPCODE: 0x16
					// LD D, n
					using namespace KeemoLib;

					const uint8_t opcode = 0x16;
					const uint8_t expected = rand() % 256;
					const uint16_t address = rand() % 0xffff;

					cpu::registers.pc = address;
					memory::writeUInt8(cpu::registers.pc, opcode);
					memory::writeUInt8(cpu::registers.pc + 1, expected);

					cpu::step();

					const uint8_t actual = cpu::registers.d;

					Assert::AreEqual(expected, actual);
					// due to a bug with Visual Studio we use Is True rather than AreEqual
					Assert::IsTrue((address + 2) == cpu::registers.pc);

				}

				TEST_METHOD(Test_ld_e_n)
				{
					// OPCODE: 0x1E
					// LD D, n
					using namespace KeemoLib;

					const uint8_t opcode = 0x1e;
					const uint8_t expected = rand() % 256;
					const uint16_t address = rand() % 0xffff;

					cpu::registers.pc = address;
					memory::writeUInt8(cpu::registers.pc, opcode);
					memory::writeUInt8(cpu::registers.pc + 1, expected);

					cpu::step();

					const uint8_t actual = cpu::registers.e;

					Assert::AreEqual(expected, actual);
					// due to a bug with Visual Studio we use Is True rather than AreEqual
					Assert::IsTrue((address + 2) == cpu::registers.pc);

				}

				TEST_METHOD(Test_ld_h_n)
				{
					// OPCODE: 0x26
					// LD D, n
					using namespace KeemoLib;

					const uint8_t opcode = 0x26;
					const uint8_t expected = rand() % 256;
					const uint16_t address = rand() % 0xffff;

					cpu::registers.pc = address;
					memory::writeUInt8(cpu::registers.pc, opcode);
					memory::writeUInt8(cpu::registers.pc + 1, expected);

					cpu::step();

					const uint8_t actual = cpu::registers.h;

					Assert::AreEqual(expected, actual);
					// due to a bug with Visual Studio we use Is True rather than AreEqual
					Assert::IsTrue((address + 2) == cpu::registers.pc);

				}

				TEST_METHOD(Test_ld_l_n)
				{
					// OPCODE: 0x2e
					// LD D, n
					using namespace KeemoLib;

					const uint8_t opcode = 0x2e;
					const uint8_t expected = rand() % 256;
					const uint16_t address = rand() % 0xffff;

					cpu::registers.pc = address;
					memory::writeUInt8(cpu::registers.pc, opcode);
					memory::writeUInt8(cpu::registers.pc + 1, expected);

					cpu::step();

					const uint8_t actual = cpu::registers.l;

					Assert::AreEqual(expected, actual);
					// due to a bug with Visual Studio we use Is True rather than AreEqual
					Assert::IsTrue((address + 2) == cpu::registers.pc);

				}

				TEST_METHOD(Test_ld_a_a)
				{
					const uint8_t opcode = 0x7f;
					const uint8_t expected = rand() % 0xff;
					const uint8_t address = rand() % 0xffff;

					using namespace KeemoLib;

					cpu::registers.pc = address;
					memory::writeUInt8(address, opcode);

					// parameter register
					cpu::registers.a = expected;

					cpu::step();

					// destination register
					const uint8_t actual = cpu::registers.a;

					Assert::AreEqual(expected, actual);

					Assert::IsTrue((address + 1) == cpu::registers.pc);
				}

				TEST_METHOD(Test_ld_a_b)
				{
					const uint8_t opcode = 0x78;
					const uint8_t expected = rand() % 0xff;
					const uint8_t address = rand() % 0xffff;

					using namespace KeemoLib;

					cpu::registers.pc = address;
					memory::writeUInt8(address, opcode);

					// parameter register
					cpu::registers.b = expected;

					cpu::step();

					// destination register
					const uint8_t actual = cpu::registers.a;

					Assert::AreEqual(expected, actual);

					Assert::IsTrue((address + 1) == cpu::registers.pc);
				}

				TEST_METHOD(Test_ld_a_c)
				{
					const uint8_t opcode = 0x79;
					const uint8_t expected = rand() % 0xff;
					const uint8_t address = rand() % 0xffff;

					using namespace KeemoLib;

					cpu::registers.pc = address;
					memory::writeUInt8(address, opcode);

					// parameter register
					cpu::registers.c = expected;

					cpu::step();

					// destination register
					const uint8_t actual = cpu::registers.a;

					Assert::AreEqual(expected, actual);

					Assert::IsTrue((address + 1) == cpu::registers.pc);
				}

				TEST_METHOD(Test_ld_a_d)
				{
					const uint8_t opcode = 0x7a;
					const uint8_t expected = rand() % 0xff;
					const uint8_t address = rand() % 0xffff;

					using namespace KeemoLib;

					cpu::registers.pc = address;
					memory::writeUInt8(address, opcode);

					// parameter register
					cpu::registers.d = expected;

					cpu::step();

					// destination register
					const uint8_t actual = cpu::registers.a;

					Assert::AreEqual(expected, actual);

					Assert::IsTrue((address + 1) == cpu::registers.pc);
				}

				TEST_METHOD(Test_ld_a_e)
				{
					const uint8_t opcode = 0x7b;
					const uint8_t expected = rand() % 0xff;
					const uint8_t address = rand() % 0xffff;

					using namespace KeemoLib;

					cpu::registers.pc = address;
					memory::writeUInt8(address, opcode);

					// parameter register
					cpu::registers.e = expected;

					cpu::step();

					// destination register
					const uint8_t actual = cpu::registers.a;

					Assert::AreEqual(expected, actual);

					Assert::IsTrue((address + 1) == cpu::registers.pc);
				}

				TEST_METHOD(Test_ld_a_h)
				{
					const uint8_t opcode = 0x7c;
					const uint8_t expected = rand() % 0xff;
					const uint8_t address = rand() % 0xffff;

					using namespace KeemoLib;

					cpu::registers.pc = address;
					memory::writeUInt8(address, opcode);

					// parameter register
					cpu::registers.h = expected;

					cpu::step();

					// destination register
					const uint8_t actual = cpu::registers.a;

					Assert::AreEqual(expected, actual);

					Assert::IsTrue((address + 1) == cpu::registers.pc);
				}

				TEST_METHOD(Test_ld_a_l)
				{
					const uint8_t opcode = 0x7d;
					const uint8_t expected = rand() % 0xff;
					const uint8_t address = rand() % 0xffff;

					using namespace KeemoLib;

					cpu::registers.pc = address;
					memory::writeUInt8(address, opcode);

					// parameter register
					cpu::registers.l = expected;

					cpu::step();

					// destination register
					const uint8_t actual = cpu::registers.a;

					Assert::AreEqual(expected, actual);

					Assert::IsTrue((address + 1) == cpu::registers.pc);
				}

				TEST_METHOD(Test_ld_a_bc)
				{
					const uint8_t opcode = 0x0a;
					const uint8_t expected = rand() % 0xff;
					const uint8_t address = rand() % 0xffff;
					const uint8_t toDeference = rand() % 0xffff;

					using namespace KeemoLib;

					cpu::registers.pc = address;
					cpu::registers.bc = toDeference;

					memory::writeUInt8(address, opcode);

					// expected
					memory::writeUInt8(toDeference, expected);


					cpu::step();

					// destination register
					const uint8_t actual = cpu::registers.a;

					Assert::AreEqual(expected, actual);

					Assert::IsTrue((address + 1) == cpu::registers.pc);
				}

				TEST_METHOD(Test_ld_a_de)
				{
					const uint8_t opcode = 0x1a;
					const uint8_t expected = rand() % 0xff;
					const uint8_t address = rand() % 0xffff;
					const uint8_t toDeference = rand() % 0xffff;

					using namespace KeemoLib;

					cpu::registers.pc = address;
					cpu::registers.de = toDeference;

					memory::writeUInt8(address, opcode);

					// expected
					memory::writeUInt8(toDeference, expected);


					cpu::step();

					// destination register
					const uint8_t actual = cpu::registers.a;

					Assert::AreEqual(expected, actual);

					Assert::IsTrue((address + 1) == cpu::registers.pc);
				}


				TEST_METHOD(Test_ld_a_nn)
				{
					const uint8_t opcode = 0xfa;
					const uint8_t expected = rand() % 0xff;
					const uint8_t address = rand() % 0xffff;
					const uint8_t toDeference = rand() % 0xffff;

					using namespace KeemoLib;

					cpu::registers.pc = address;
					memory::writeUInt16(address + 1, toDeference);

					memory::writeUInt8(address, opcode);

					// expected
					memory::writeUInt8(toDeference, expected);


					cpu::step();

					// destination register
					const uint8_t actual = cpu::registers.a;

					Assert::AreEqual(expected, actual);

					Assert::IsTrue((address + 3) == cpu::registers.pc);
				}

				TEST_METHOD(Test_ld_a_hl)
				{
					const uint8_t opcode = 0x7e;
					const uint8_t expected = rand() % 0xff;
					const uint8_t address = rand() % 0xffff;
					const uint8_t hl = rand() % 0xffff;

					using namespace KeemoLib;

					cpu::registers.pc = address;
					cpu::registers.hl = hl;

					memory::writeUInt8(address, opcode);

					// expected
					memory::writeUInt8(hl, expected);


					cpu::step();

					// destination register
					const uint8_t actual = cpu::registers.a;

					Assert::AreEqual(expected, actual);

					Assert::IsTrue((address + 1) == cpu::registers.pc);
				}

				TEST_METHOD(Test_ld_a_n)
				{
					const uint8_t opcode = 0x3e;
					const uint8_t address = rand() % 0xfffe;
					const uint8_t expected = rand() % 0xff;

					using namespace KeemoLib;

					cpu::registers.pc = address;

					memory::writeUInt8(address, opcode);
					memory::writeUInt8(address + 1, expected);
					


					cpu::step();

					// destination register
					const uint8_t actual = cpu::registers.a;

					Assert::AreEqual(expected, actual);

					Assert::IsTrue((address + 2) == cpu::registers.pc);
				}

				TEST_METHOD(Test_ld_b_a)
				{
					const uint8_t opcode = 0x47;
					const uint8_t expected = rand() % 0xff;
					const uint8_t address = rand() % 0xffff;

					using namespace KeemoLib;

					cpu::registers.pc = address;
					memory::writeUInt8(address, opcode);

					// parameter register
					cpu::registers.a = expected;

					cpu::step();

					// destination register
					const uint8_t actual = cpu::registers.b;

					Assert::AreEqual(expected, actual);

					Assert::IsTrue((address + 1) == cpu::registers.pc);
				}

				TEST_METHOD(Test_ld_b_b)
				{
					const uint8_t opcode = 0x40;
					const uint8_t expected = rand() % 0xff;
					const uint8_t address = rand() % 0xffff;

					using namespace KeemoLib;

					cpu::registers.pc = address;
					memory::writeUInt8(address, opcode);

					// parameter register
					cpu::registers.b = expected;

					cpu::step();

					// destination register
					const uint8_t actual = cpu::registers.b;

					Assert::AreEqual(expected, actual);

					Assert::IsTrue((address + 1) == cpu::registers.pc);
				}

				TEST_METHOD(Test_ld_b_c)
				{
					const uint8_t opcode = 0x41;
					const uint8_t expected = rand() % 0xff;
					const uint8_t address = rand() % 0xffff;

					using namespace KeemoLib;

					cpu::registers.pc = address;
					memory::writeUInt8(address, opcode);

					// parameter register
					cpu::registers.c = expected;

					cpu::step();

					// destination register
					const uint8_t actual = cpu::registers.b;

					Assert::AreEqual(expected, actual);

					Assert::IsTrue((address + 1) == cpu::registers.pc);
				}

				TEST_METHOD(Test_ld_b_d)
				{
					const uint8_t opcode = 0x42;
					const uint8_t expected = rand() % 0xff;
					const uint8_t address = rand() % 0xffff;

					using namespace KeemoLib;

					cpu::registers.pc = address;
					memory::writeUInt8(address, opcode);

					// parameter register
					cpu::registers.d = expected;

					cpu::step();

					// destination register
					const uint8_t actual = cpu::registers.b;

					Assert::AreEqual(expected, actual);

					Assert::IsTrue((address + 1) == cpu::registers.pc);
				}

				TEST_METHOD(Test_ld_b_e)
				{
					const uint8_t opcode = 0x43;
					const uint8_t expected = rand() % 0xff;
					const uint8_t address = rand() % 0xffff;

					using namespace KeemoLib;

					cpu::registers.pc = address;
					memory::writeUInt8(address, opcode);

					// parameter register
					cpu::registers.e = expected;

					cpu::step();

					// destination register
					const uint8_t actual = cpu::registers.b;

					Assert::AreEqual(expected, actual);

					Assert::IsTrue((address + 1) == cpu::registers.pc);
				}

				TEST_METHOD(Test_ld_b_h)
				{
					const uint8_t opcode = 0x44;
					const uint8_t expected = rand() % 0xff;
					const uint8_t address = rand() % 0xffff;

					using namespace KeemoLib;

					cpu::registers.pc = address;
					memory::writeUInt8(address, opcode);

					// parameter register
					cpu::registers.h = expected;

					cpu::step();

					// destination register
					const uint8_t actual = cpu::registers.b;

					Assert::AreEqual(expected, actual);

					Assert::IsTrue((address + 1) == cpu::registers.pc);
				}

				TEST_METHOD(Test_ld_b_l)
				{
					const uint8_t opcode = 0x45;
					const uint8_t expected = rand() % 0xff;
					const uint8_t address = rand() % 0xffff;

					using namespace KeemoLib;

					cpu::registers.pc = address;
					memory::writeUInt8(address, opcode);

					// parameter register
					cpu::registers.l = expected;

					cpu::step();

					// destination register
					const uint8_t actual = cpu::registers.b;

					Assert::AreEqual(expected, actual);

					Assert::IsTrue((address + 1) == cpu::registers.pc);
				}

				TEST_METHOD(Test_ld_b_hl)
				{
					const uint8_t opcode = 0x46;
					const uint8_t expected = rand() % 0xff;
					const uint8_t address = rand() % 0xffff;
					const uint8_t hl = rand() % 0xffff;

					using namespace KeemoLib;

					cpu::registers.pc = address;
					cpu::registers.hl = hl;

					memory::writeUInt8(address, opcode);

					// expected
					memory::writeUInt8(hl, expected);


					cpu::step();

					// destination register
					const uint8_t actual = cpu::registers.b;

					Assert::AreEqual(expected, actual);

					Assert::IsTrue((address + 1) == cpu::registers.pc);
				}

				TEST_METHOD(Test_ld_c_a)
				{
					const uint8_t opcode = 0x4f;
					const uint8_t expected = rand() % 0xff;
					const uint8_t address = rand() % 0xffff;

					using namespace KeemoLib;

					cpu::registers.pc = address;
					memory::writeUInt8(address, opcode);

					// parameter register
					cpu::registers.a = expected;

					cpu::step();

					// destination register
					const uint8_t actual = cpu::registers.c;

					Assert::AreEqual(expected, actual);

					Assert::IsTrue((address + 1) == cpu::registers.pc);
				}

				TEST_METHOD(Test_ld_c_b)
				{
					const uint8_t opcode = 0x48;
					const uint8_t expected = rand() % 0xff;
					const uint8_t address = rand() % 0xffff;

					using namespace KeemoLib;

					cpu::registers.pc = address;
					memory::writeUInt8(address, opcode);

					// parameter register
					cpu::registers.b = expected;

					cpu::step();

					// destination register
					const uint8_t actual = cpu::registers.c;

					Assert::AreEqual(expected, actual);

					Assert::IsTrue((address + 1) == cpu::registers.pc);
				}

				TEST_METHOD(Test_ld_c_c)
				{
					const uint8_t opcode = 0x49;
					const uint8_t expected = rand() % 0xff;
					const uint8_t address = rand() % 0xffff;

					using namespace KeemoLib;

					cpu::registers.pc = address;
					memory::writeUInt8(address, opcode);

					// parameter register
					cpu::registers.c = expected;

					cpu::step();

					// destination register
					const uint8_t actual = cpu::registers.c;

					Assert::AreEqual(expected, actual);

					Assert::IsTrue((address + 1) == cpu::registers.pc);
				}

				TEST_METHOD(Test_ld_c_d)
				{
					const uint8_t opcode = 0x4a;
					const uint8_t expected = rand() % 0xff;
					const uint8_t address = rand() % 0xffff;

					using namespace KeemoLib;

					cpu::registers.pc = address;
					memory::writeUInt8(address, opcode);

					// parameter register
					cpu::registers.d = expected;

					cpu::step();

					// destination register
					const uint8_t actual = cpu::registers.c;

					Assert::AreEqual(expected, actual);

					Assert::IsTrue((address + 1) == cpu::registers.pc);
				}

				TEST_METHOD(Test_ld_c_e)
				{
					const uint8_t opcode = 0x4b;
					const uint8_t expected = rand() % 0xff;
					const uint8_t address = rand() % 0xffff;

					using namespace KeemoLib;

					cpu::registers.pc = address;
					memory::writeUInt8(address, opcode);

					// parameter register
					cpu::registers.e = expected;

					cpu::step();

					// destination register
					const uint8_t actual = cpu::registers.c;

					Assert::AreEqual(expected, actual);

					Assert::IsTrue((address + 1) == cpu::registers.pc);
				}

				TEST_METHOD(Test_ld_c_h)
				{
					const uint8_t opcode = 0x4c;
					const uint8_t expected = rand() % 0xff;
					const uint8_t address = rand() % 0xffff;

					using namespace KeemoLib;

					cpu::registers.pc = address;
					memory::writeUInt8(address, opcode);

					// parameter register
					cpu::registers.h = expected;

					cpu::step();

					// destination register
					const uint8_t actual = cpu::registers.c;

					Assert::AreEqual(expected, actual);

					Assert::IsTrue((address + 1) == cpu::registers.pc);
				}

				TEST_METHOD(Test_ld_c_l)
				{
					const uint8_t opcode = 0x4d;
					const uint8_t expected = rand() % 0xff;
					const uint8_t address = rand() % 0xffff;

					using namespace KeemoLib;

					cpu::registers.pc = address;
					memory::writeUInt8(address, opcode);

					// parameter register
					cpu::registers.l = expected;

					cpu::step();

					// destination register
					const uint8_t actual = cpu::registers.c;

					Assert::AreEqual(expected, actual);

					Assert::IsTrue((address + 1) == cpu::registers.pc);
				}

				TEST_METHOD(Test_ld_c_hl)
				{
					const uint8_t opcode = 0x4e;
					const uint8_t expected = rand() % 0xff;
					const uint8_t address = rand() % 0xffff;
					const uint8_t hl = rand() % 0xffff;

					using namespace KeemoLib;

					cpu::registers.pc = address;
					cpu::registers.hl = hl;

					memory::writeUInt8(address, opcode);

					// expected
					memory::writeUInt8(hl, expected);


					cpu::step();

					// destination register
					const uint8_t actual = cpu::registers.c;

					Assert::AreEqual(expected, actual);

					Assert::IsTrue((address + 1) == cpu::registers.pc);
				}

				TEST_METHOD(Test_ld_d_a)
				{
					const uint8_t opcode = 0x57;
					const uint8_t expected = rand() % 0xff;
					const uint8_t address = rand() % 0xffff;

					using namespace KeemoLib;

					cpu::registers.pc = address;
					memory::writeUInt8(address, opcode);

					// parameter register
					cpu::registers.a = expected;

					cpu::step();

					// destination register
					const uint8_t actual = cpu::registers.d;

					Assert::AreEqual(expected, actual);

					Assert::IsTrue((address + 1) == cpu::registers.pc);
				}

				TEST_METHOD(Test_ld_d_b)
				{
					const uint8_t opcode = 0x50;
					const uint8_t expected = rand() % 0xff;
					const uint8_t address = rand() % 0xffff;

					using namespace KeemoLib;

					cpu::registers.pc = address;
					memory::writeUInt8(address, opcode);

					// parameter register
					cpu::registers.b = expected;

					cpu::step();

					// destination register
					const uint8_t actual = cpu::registers.d;

					Assert::AreEqual(expected, actual);

					Assert::IsTrue((address + 1) == cpu::registers.pc);
				}

				TEST_METHOD(Test_ld_d_c)
				{
					const uint8_t opcode = 0x51;
					const uint8_t expected = rand() % 0xff;
					const uint8_t address = rand() % 0xffff;

					using namespace KeemoLib;

					cpu::registers.pc = address;
					memory::writeUInt8(address, opcode);

					// parameter register
					cpu::registers.c = expected;

					cpu::step();

					// destination register
					const uint8_t actual = cpu::registers.d;

					Assert::AreEqual(expected, actual);

					Assert::IsTrue((address + 1) == cpu::registers.pc);
				}

				TEST_METHOD(Test_ld_d_d)
				{
					const uint8_t opcode = 0x52;
					const uint8_t expected = rand() % 0xff;
					const uint8_t address = rand() % 0xffff;

					using namespace KeemoLib;

					cpu::registers.pc = address;
					memory::writeUInt8(address, opcode);

					// parameter register
					cpu::registers.d = expected;

					cpu::step();

					// destination register
					const uint8_t actual = cpu::registers.d;

					Assert::AreEqual(expected, actual);

					Assert::IsTrue((address + 1) == cpu::registers.pc);
				}

				TEST_METHOD(Test_ld_d_e)
				{
					const uint8_t opcode = 0x53;
					const uint8_t expected = rand() % 0xff;
					const uint8_t address = rand() % 0xffff;

					using namespace KeemoLib;

					cpu::registers.pc = address;
					memory::writeUInt8(address, opcode);

					// parameter register
					cpu::registers.e = expected;

					cpu::step();

					// destination register
					const uint8_t actual = cpu::registers.d;

					Assert::AreEqual(expected, actual);

					Assert::IsTrue((address + 1) == cpu::registers.pc);
				}

				TEST_METHOD(Test_ld_d_h)
				{
					const uint8_t opcode = 0x54;
					const uint8_t expected = rand() % 0xff;
					const uint8_t address = rand() % 0xffff;

					using namespace KeemoLib;

					cpu::registers.pc = address;
					memory::writeUInt8(address, opcode);

					// parameter register
					cpu::registers.h = expected;

					cpu::step();

					// destination register
					const uint8_t actual = cpu::registers.d;

					Assert::AreEqual(expected, actual);

					Assert::IsTrue((address + 1) == cpu::registers.pc);
				}

				TEST_METHOD(Test_ld_d_l)
				{
					const uint8_t opcode = 0x55;
					const uint8_t expected = rand() % 0xff;
					const uint8_t address = rand() % 0xffff;

					using namespace KeemoLib;

					cpu::registers.pc = address;
					memory::writeUInt8(address, opcode);

					// parameter register
					cpu::registers.l = expected;

					cpu::step();

					// destination register
					const uint8_t actual = cpu::registers.d;

					Assert::AreEqual(expected, actual);

					Assert::IsTrue((address + 1) == cpu::registers.pc);
				}

				TEST_METHOD(Test_ld_d_hl)
				{
					const uint8_t opcode = 0x56;
					const uint8_t expected = rand() % 0xff;
					const uint8_t address = rand() % 0xffff;
					const uint8_t hl = rand() % 0xffff;

					using namespace KeemoLib;

					cpu::registers.pc = address;
					cpu::registers.hl = hl;

					memory::writeUInt8(address, opcode);

					// expected
					memory::writeUInt8(hl, expected);


					cpu::step();

					// destination register
					const uint8_t actual = cpu::registers.d;

					Assert::AreEqual(expected, actual);

					Assert::IsTrue((address + 1) == cpu::registers.pc);
				}

				/*****************************************************************************************
				* LD E,r2
				******************************************************************************************/
				TEST_METHOD(Test_ld_e_a)
				{
					const uint8_t opcode = 0x5f;
					const uint8_t expected = rand() % 0xff;
					const uint8_t address = rand() % 0xffff;

					using namespace KeemoLib;

					cpu::registers.pc = address;
					memory::writeUInt8(address, opcode);

					// parameter register
					cpu::registers.a = expected;

					cpu::step();

					// destination register
					const uint8_t actual = cpu::registers.e;

					Assert::AreEqual(expected, actual);

					Assert::IsTrue((address + 1) == cpu::registers.pc);
				}

				TEST_METHOD(Test_ld_e_b)
				{
					const uint8_t opcode = 0x58;
					const uint8_t expected = rand() % 0xff;
					const uint8_t address = rand() % 0xffff;

					using namespace KeemoLib;

					cpu::registers.pc = address;
					memory::writeUInt8(address, opcode);

					// parameter register
					cpu::registers.b = expected;

					cpu::step();

					// destination register
					const uint8_t actual = cpu::registers.e;

					Assert::AreEqual(expected, actual);

					Assert::IsTrue((address + 1) == cpu::registers.pc);
				}

				TEST_METHOD(Test_ld_e_c)
				{
					const uint8_t opcode = 0x59;
					const uint8_t expected = rand() % 0xff;
					const uint8_t address = rand() % 0xffff;

					using namespace KeemoLib;

					cpu::registers.pc = address;
					memory::writeUInt8(address, opcode);

					// parameter register
					cpu::registers.c = expected;

					cpu::step();

					// destination register
					const uint8_t actual = cpu::registers.e;

					Assert::AreEqual(expected, actual);

					Assert::IsTrue((address + 1) == cpu::registers.pc);
				}

				TEST_METHOD(Test_ld_e_d)
				{
					const uint8_t opcode = 0x5a;
					const uint8_t expected = rand() % 0xff;
					const uint8_t address = rand() % 0xffff;

					using namespace KeemoLib;

					cpu::registers.pc = address;
					memory::writeUInt8(address, opcode);

					// parameter register
					cpu::registers.d = expected;

					cpu::step();

					// destination register
					const uint8_t actual = cpu::registers.e;

					Assert::AreEqual(expected, actual);

					Assert::IsTrue((address + 1) == cpu::registers.pc);
				}

				TEST_METHOD(Test_ld_e_e)
				{
					const uint8_t opcode = 0x5b;
					const uint8_t expected = rand() % 0xff;
					const uint8_t address = rand() % 0xffff;

					using namespace KeemoLib;

					cpu::registers.pc = address;
					memory::writeUInt8(address, opcode);

					// parameter register
					cpu::registers.e = expected;

					cpu::step();

					// destination register
					const uint8_t actual = cpu::registers.e;

					Assert::AreEqual(expected, actual);

					Assert::IsTrue((address + 1) == cpu::registers.pc);
				}

				TEST_METHOD(Test_ld_e_h)
				{
					const uint8_t opcode = 0x5c;
					const uint8_t expected = rand() % 0xff;
					const uint8_t address = rand() % 0xffff;

					using namespace KeemoLib;

					cpu::registers.pc = address;
					memory::writeUInt8(address, opcode);

					// parameter register
					cpu::registers.h = expected;

					cpu::step();

					// destination register
					const uint8_t actual = cpu::registers.e;

					Assert::AreEqual(expected, actual);

					Assert::IsTrue((address + 1) == cpu::registers.pc);
				}

				TEST_METHOD(Test_ld_e_l)
				{
					const uint8_t opcode = 0x5d;
					const uint8_t expected = rand() % 0xff;
					const uint8_t address = rand() % 0xffff;

					using namespace KeemoLib;

					cpu::registers.pc = address;
					memory::writeUInt8(address, opcode);

					// parameter register
					cpu::registers.l = expected;

					cpu::step();

					// destination register
					const uint8_t actual = cpu::registers.e;

					Assert::AreEqual(expected, actual);

					Assert::IsTrue((address + 1) == cpu::registers.pc);
				}

				TEST_METHOD(Test_ld_e_hl)
				{
					const uint8_t opcode = 0x5e;
					const uint8_t expected = rand() % 0xff;
					const uint8_t address = rand() % 0xffff;
					const uint8_t hl = rand() % 0xffff;

					using namespace KeemoLib;

					cpu::registers.pc = address;
					cpu::registers.hl = hl;

					memory::writeUInt8(address, opcode);

					// expected
					memory::writeUInt8(hl, expected);


					cpu::step();

					// destination register
					const uint8_t actual = cpu::registers.e;

					Assert::AreEqual(expected, actual);

					Assert::IsTrue((address + 1) == cpu::registers.pc);
				}

				/*****************************************************************************************
				* LD H,r2
				******************************************************************************************/
				TEST_METHOD(Test_ld_h_a)
				{
					const uint8_t opcode = 0x67;
					const uint8_t expected = rand() % 0xff;
					const uint8_t address = rand() % 0xffff;

					using namespace KeemoLib;

					cpu::registers.pc = address;
					memory::writeUInt8(address, opcode);

					// parameter register
					cpu::registers.a = expected;

					cpu::step();

					// destination register
					const uint8_t actual = cpu::registers.h;

					Assert::AreEqual(expected, actual);

					Assert::IsTrue((address + 1) == cpu::registers.pc);
				}
				
				TEST_METHOD(Test_ld_h_b)
				{
					const uint8_t opcode = 0x60;
					const uint8_t expected = rand() % 0xff;
					const uint8_t address = rand() % 0xffff;

					using namespace KeemoLib;

					cpu::registers.pc = address;
					memory::writeUInt8(address, opcode);

					// parameter register
					cpu::registers.b = expected;

					cpu::step();

					// destination register
					const uint8_t actual = cpu::registers.h;

					Assert::AreEqual(expected, actual);

					Assert::IsTrue((address + 1) == cpu::registers.pc);
				}

				TEST_METHOD(Test_ld_h_c)
				{
					const uint8_t opcode = 0x61;
					const uint8_t expected = rand() % 0xff;
					const uint8_t address = rand() % 0xffff;

					using namespace KeemoLib;

					cpu::registers.pc = address;
					memory::writeUInt8(address, opcode);

					// parameter register
					cpu::registers.c = expected;

					cpu::step();

					// destination register
					const uint8_t actual = cpu::registers.h;

					Assert::AreEqual(expected, actual);

					Assert::IsTrue((address + 1) == cpu::registers.pc);
				}

				TEST_METHOD(Test_ld_h_d)
				{
					const uint8_t opcode = 0x62;
					const uint8_t expected = rand() % 0xff;
					const uint8_t address = rand() % 0xffff;

					using namespace KeemoLib;

					cpu::registers.pc = address;
					memory::writeUInt8(address, opcode);

					// parameter register
					cpu::registers.d = expected;

					cpu::step();

					// destination register
					const uint8_t actual = cpu::registers.h;

					Assert::AreEqual(expected, actual);

					Assert::IsTrue((address + 1) == cpu::registers.pc);
				}

				TEST_METHOD(Test_ld_h_e)
				{
					const uint8_t opcode = 0x63;
					const uint8_t expected = rand() % 0xff;
					const uint8_t address = rand() % 0xffff;

					using namespace KeemoLib;

					cpu::registers.pc = address;
					memory::writeUInt8(address, opcode);

					// parameter register
					cpu::registers.e = expected;

					cpu::step();

					// destination register
					const uint8_t actual = cpu::registers.h;

					Assert::AreEqual(expected, actual);

					Assert::IsTrue((address + 1) == cpu::registers.pc);
				}

				TEST_METHOD(Test_ld_h_h)
				{
					const uint8_t opcode = 0x64;
					const uint8_t expected = rand() % 0xff;
					const uint8_t address = rand() % 0xffff;

					using namespace KeemoLib;

					cpu::registers.pc = address;
					memory::writeUInt8(address, opcode);

					// parameter register
					cpu::registers.h = expected;

					cpu::step();

					// destination register
					const uint8_t actual = cpu::registers.h;

					Assert::AreEqual(expected, actual);

					Assert::IsTrue((address + 1) == cpu::registers.pc);
				}

				TEST_METHOD(Test_ld_h_l)
				{
					const uint8_t opcode = 0x65;
					const uint8_t expected = rand() % 0xff;
					const uint8_t address = rand() % 0xffff;

					using namespace KeemoLib;

					cpu::registers.pc = address;
					memory::writeUInt8(address, opcode);

					// parameter register
					cpu::registers.l = expected;

					cpu::step();

					// destination register
					const uint8_t actual = cpu::registers.h;

					Assert::AreEqual(expected, actual);

					Assert::IsTrue((address + 1) == cpu::registers.pc);
				}

				TEST_METHOD(Test_ld_h_hl)
				{
					const uint8_t opcode = 0x66;
					const uint8_t expected = rand() % 0xff;
					const uint8_t address = rand() % 0xffff;
					const uint8_t hl = rand() % 0xffff;

					using namespace KeemoLib;

					cpu::registers.pc = address;
					cpu::registers.hl = hl;

					memory::writeUInt8(address, opcode);

					// expected
					memory::writeUInt8(hl, expected);


					cpu::step();

					// destination register
					const uint8_t actual = cpu::registers.h;

					Assert::AreEqual(expected, actual);

					Assert::IsTrue((address + 1) == cpu::registers.pc);
				}


				/*****************************************************************************************
				* LD L,r2
				******************************************************************************************/
				TEST_METHOD(Test_ld_l_a)
				{
					const uint8_t opcode = 0x6f;
					const uint8_t expected = rand() % 0xff;
					const uint8_t address = rand() % 0xffff;

					using namespace KeemoLib;

					cpu::registers.pc = address;
					memory::writeUInt8(address, opcode);

					// parameter register
					cpu::registers.a = expected;

					cpu::step();

					// destination register
					const uint8_t actual = cpu::registers.l;

					Assert::AreEqual(expected, actual);

					Assert::IsTrue((address + 1) == cpu::registers.pc);
				}
				
				TEST_METHOD(Test_ld_l_b)
				{
					const uint8_t opcode = 0x68;
					const uint8_t expected = rand() % 0xff;
					const uint8_t address = rand() % 0xffff;

					using namespace KeemoLib;

					cpu::registers.pc = address;
					memory::writeUInt8(address, opcode);

					// parameter register
					cpu::registers.b = expected;

					cpu::step();

					// destination register
					const uint8_t actual = cpu::registers.l;

					Assert::AreEqual(expected, actual);

					Assert::IsTrue((address + 1) == cpu::registers.pc);
				}

				TEST_METHOD(Test_ld_l_c)
				{
					const uint8_t opcode = 0x69;
					const uint8_t expected = rand() % 0xff;
					const uint8_t address = rand() % 0xffff;

					using namespace KeemoLib;

					cpu::registers.pc = address;
					memory::writeUInt8(address, opcode);

					// parameter register
					cpu::registers.c = expected;

					cpu::step();

					// destination register
					const uint8_t actual = cpu::registers.l;

					Assert::AreEqual(expected, actual);

					Assert::IsTrue((address + 1) == cpu::registers.pc);
				}

				TEST_METHOD(Test_ld_l_d)
				{
					const uint8_t opcode = 0x6a;
					const uint8_t expected = rand() % 0xff;
					const uint8_t address = rand() % 0xffff;

					using namespace KeemoLib;

					cpu::registers.pc = address;
					memory::writeUInt8(address, opcode);

					// parameter register
					cpu::registers.d = expected;

					cpu::step();

					// destination register
					const uint8_t actual = cpu::registers.l;

					Assert::AreEqual(expected, actual);

					Assert::IsTrue((address + 1) == cpu::registers.pc);
				}

				TEST_METHOD(Test_ld_l_e)
				{
					const uint8_t opcode = 0x6b;
					const uint8_t expected = rand() % 0xff;
					const uint8_t address = rand() % 0xffff;

					using namespace KeemoLib;

					cpu::registers.pc = address;
					memory::writeUInt8(address, opcode);

					// parameter register
					cpu::registers.e = expected;

					cpu::step();

					// destination register
					const uint8_t actual = cpu::registers.l;

					Assert::AreEqual(expected, actual);

					Assert::IsTrue((address + 1) == cpu::registers.pc);
				}

				TEST_METHOD(Test_ld_l_h)
				{
					const uint8_t opcode = 0x6c;
					const uint8_t expected = rand() % 0xff;
					const uint8_t address = rand() % 0xffff;

					using namespace KeemoLib;

					cpu::registers.pc = address;
					memory::writeUInt8(address, opcode);

					// parameter register
					cpu::registers.h = expected;

					cpu::step();

					// destination register
					const uint8_t actual = cpu::registers.l;

					Assert::AreEqual(expected, actual);

					Assert::IsTrue((address + 1) == cpu::registers.pc);
				}

				TEST_METHOD(Test_ld_l_l)
				{
					const uint8_t opcode = 0x6d;
					const uint8_t expected = rand() % 0xff;
					const uint8_t address = rand() % 0xffff;

					using namespace KeemoLib;

					cpu::registers.pc = address;
					memory::writeUInt8(address, opcode);

					// parameter register
					cpu::registers.l = expected;

					cpu::step();

					// destination register
					const uint8_t actual = cpu::registers.l;

					Assert::AreEqual(expected, actual);

					Assert::IsTrue((address + 1) == cpu::registers.pc);
				}

				TEST_METHOD(Test_ld_l_hl)
				{
					const uint8_t opcode = 0x6e;
					const uint8_t expected = rand() % 0xff;
					const uint8_t address = rand() % 0xffff;
					const uint8_t hl = rand() % 0xffff;

					using namespace KeemoLib;

					cpu::registers.pc = address;
					cpu::registers.hl = hl;

					memory::writeUInt8(address, opcode);

					// expected
					memory::writeUInt8(hl, expected);


					cpu::step();

					// destination register
					const uint8_t actual = cpu::registers.l;

					Assert::AreEqual(expected, actual);

					Assert::IsTrue((address + 1) == cpu::registers.pc);
				}

				/*****************************************************************************************
				* LD (HL),r2
				******************************************************************************************/
				TEST_METHOD(Test_ld_hl_a)
				{
					const uint8_t opcode = 0x77;
					const uint8_t expected = rand() % 0xff;
					const uint8_t address = rand() % 0xffff;

					using namespace KeemoLib;

					cpu::registers.pc = address;
					memory::writeUInt8(address, opcode);

					// parameter register
					cpu::registers.a = expected;

					cpu::step();

					// destination register
					const uint8_t actual = memory::readUInt8(cpu::registers.hl);

					Assert::AreEqual(expected, actual);

					Assert::IsTrue((address + 1) == cpu::registers.pc);
				}

				TEST_METHOD(Test_ld_hl_b)
				{
					const uint8_t opcode = 0x70;
					const uint8_t expected = rand() % 0xff;
					const uint8_t address = rand() % 0xffff;

					using namespace KeemoLib;

					cpu::registers.pc = address;
					memory::writeUInt8(address, opcode);

					// parameter register
					cpu::registers.b = expected;

					cpu::step();

					// destination register
					const uint8_t actual = memory::readUInt8(cpu::registers.hl);

					Assert::AreEqual(expected, actual);

					Assert::IsTrue((address + 1) == cpu::registers.pc);
				}

				TEST_METHOD(Test_ld_hl_c)
				{
					const uint8_t opcode = 0x71;
					const uint8_t expected = rand() % 0xff;
					const uint8_t address = rand() % 0xffff;

					using namespace KeemoLib;

					cpu::registers.pc = address;
					memory::writeUInt8(address, opcode);

					// parameter register
					cpu::registers.c = expected;

					cpu::step();

					// destination register
					const uint8_t actual = memory::readUInt8(cpu::registers.hl);

					Assert::AreEqual(expected, actual);

					Assert::IsTrue((address + 1) == cpu::registers.pc);
				}

				TEST_METHOD(Test_ld_hl_d)
				{
					const uint8_t opcode = 0x72;
					const uint8_t expected = rand() % 0xff;
					const uint8_t address = rand() % 0xffff;

					using namespace KeemoLib;

					cpu::registers.pc = address;
					memory::writeUInt8(address, opcode);

					// parameter register
					cpu::registers.d = expected;

					cpu::step();

					// destination register
					const uint8_t actual = memory::readUInt8(cpu::registers.hl);

					Assert::AreEqual(expected, actual);

					Assert::IsTrue((address + 1) == cpu::registers.pc);
				}

				TEST_METHOD(Test_ld_hl_e)
				{
					const uint8_t opcode = 0x73;
					const uint8_t expected = rand() % 0xff;
					const uint8_t address = rand() % 0xffff;

					using namespace KeemoLib;

					cpu::registers.pc = address;
					memory::writeUInt8(address, opcode);

					// parameter register
					cpu::registers.e = expected;

					cpu::step();

					// destination register
					const uint8_t actual = memory::readUInt8(cpu::registers.hl);

					Assert::AreEqual(expected, actual);

					Assert::IsTrue((address + 1) == cpu::registers.pc);
				}

				TEST_METHOD(Test_ld_hl_h)
				{
					const uint8_t opcode = 0x74;
					const uint8_t expected = rand() % 0xff;
					const uint8_t address = rand() % 0xffff;

					using namespace KeemoLib;

					cpu::registers.pc = address;
					memory::writeUInt8(address, opcode);

					// parameter register
					cpu::registers.h = expected;

					cpu::step();

					// destination register
					const uint8_t actual = memory::readUInt8(cpu::registers.hl);

					Assert::AreEqual(expected, actual);

					Assert::IsTrue((address + 1) == cpu::registers.pc);
				}

				TEST_METHOD(Test_ld_hl_l)
				{
					const uint8_t opcode = 0x75;
					const uint8_t expected = rand() % 0xff;
					const uint8_t address = rand() % 0xffff;

					using namespace KeemoLib;

					cpu::registers.pc = address;
					memory::writeUInt8(address, opcode);

					// parameter register
					cpu::registers.l = expected;

					cpu::step();

					// destination register
					const uint8_t actual = memory::readUInt8(cpu::registers.hl);

					Assert::AreEqual(expected, actual);

					Assert::IsTrue((address + 1) == cpu::registers.pc);
				}

				TEST_METHOD(Test_ld_hl_n)
				{
					const uint8_t opcode = 0x36;
					const uint8_t expected = rand() % 0xff;
					const uint8_t address = rand() % 0xffff;

					using namespace KeemoLib;

					cpu::registers.pc = address;
					memory::writeUInt8(address, opcode);

					// parameter register
					memory::writeUInt8(address+1, expected);

					cpu::step();

					// destination register
					const uint8_t actual = memory::readUInt8(cpu::registers.hl);

					Assert::AreEqual(expected, actual);

					Assert::IsTrue((address + 2) == cpu::registers.pc);
				}

				TEST_METHOD(Test_ld_bc_a)
				{
					const uint8_t opcode = 0x02;
					const uint8_t expected = rand() % 0xff;
					const uint8_t address = rand() % 0xffff;

					using namespace KeemoLib;

					cpu::registers.pc = address;
					memory::writeUInt8(address, opcode);

					// parameter register
					cpu::registers.a = expected;

					cpu::step();

					// destination register
					const uint8_t actual = memory::readUInt8(cpu::registers.bc);

					Assert::AreEqual(expected, actual);

					Assert::IsTrue((address + 1) == cpu::registers.pc);
				}
			};
		}
	}
}