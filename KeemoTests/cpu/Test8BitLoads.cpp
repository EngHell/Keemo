#include "stdafx.h"
#include <CppUnitTest.h>
#include "../../KeemoLib/includes/Memory.hpp"
#include "../../KeemoLib/includes/Cpu.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace KeemoTests
{
	namespace CpuTests
	{
		TEST_CLASS(Test8BitLoads)
		{
		public:
			TEST_METHOD(TestLdBN)
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

			TEST_METHOD(TestLdCN)
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

			TEST_METHOD(TestLdDN)
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
				Assert::IsTrue((address+2) == cpu::registers.pc);

			}

			TEST_METHOD(TestLdEN)
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

			TEST_METHOD(TestLdHN)
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

			TEST_METHOD(TestLdLN)
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
		};
	}
}