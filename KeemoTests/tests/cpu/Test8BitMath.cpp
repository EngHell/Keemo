#include "stdafx.h"
#include <CppUnitTest.h>
#include "Cpu.hpp"
#include "Memory.hpp"
#include <ctime>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace KeemoTests
{
	namespace CpuTests
	{
		// well dont rant of me for not doing explicit test for each add operation
		// as they all use the same add(uint8_t& destination, uint8_t value) function.
		// when you re only 1 you chose to be lazy in the parts that are already tested.
		TEST_CLASS(Bit8MathTests)
		{
		public:
			TEST_CLASS_INITIALIZE(Test_init)
			{
				srand(time(nullptr));
			}

			TEST_METHOD(Test_add_a_a_with_bit_7_carry)
			{
				// Usual initialization
				const uint8_t opcode = 0x8f;
				const uint8_t a = 128;

				const uint8_t expected = a + a;

				// modifying this so it's more natural.
				const uint16_t oplength = 1;
				// we get a random address for our opcode
				const uint16_t address = rand() % (0xffff - oplength);

				using namespace KeemoLib;

				// pc pointer setup
				cpu::registers.pc = address;
				// Opcode write to memory
				memory::writeUInt8(address, opcode);
				// Opcode arguments write to memory
				cpu::registers.a = a;

				// emulation step
				cpu::step();

				// we check for C set
				Assert::IsTrue(cpu::CHECK_FLAG(cpu::Flags::C));

				// we check Z is reset because the result is not 0
				// even when the addition gets 0 in the register
				// there was a carry so Z is unset or reset however you
				// want to call it.
				Assert::IsFalse(cpu::CHECK_FLAG(cpu::Flags::Z));

				// with this number there was no carry from bit 3 so
				Assert::IsFalse(cpu::CHECK_FLAG(cpu::Flags::H));

				// finally we check our expeted
				const uint8_t actual = cpu::registers.a;
				Assert::AreEqual(expected, actual);

				// we check pc steps
				Assert::IsTrue(cpu::registers.pc == (address + oplength));
			}
			TEST_METHOD(Test_add_a_a_with_bit_3_carry)
			{
				// Usual initialization
				const uint8_t opcode = 0x8f;
				const uint8_t a = 15;

				const uint8_t expected = a + a;

				// modifying this so it's more natural.
				const uint16_t oplength = 1;
				// we get a random address for our opcode
				const uint16_t address = rand() % (0xffff - oplength);

				using namespace KeemoLib;

				// pc pointer setup
				cpu::registers.pc = address;
				// Opcode write to memory
				memory::writeUInt8(address, opcode);
				// Opcode arguments write to memory
				cpu::registers.a = a;

				// emulation step
				cpu::step();

				// we check for C reset
				Assert::IsFalse(cpu::CHECK_FLAG(cpu::Flags::C));

				// we check Z is reset because the result is not 0
				Assert::IsFalse(cpu::CHECK_FLAG(cpu::Flags::Z));

				// we had a carry from bit 3 so this should be true
				Assert::IsTrue(cpu::CHECK_FLAG(cpu::Flags::H));

				// finally we check our expeted
				const uint8_t actual = cpu::registers.a;
				Assert::AreEqual(expected, actual);

				// we check pc steps
				Assert::IsTrue(cpu::registers.pc == (address + oplength));
			}
			TEST_METHOD(Test_add_a_a_with_bit_7_and_3_carry)
			{
				// Usual initialization
				const uint8_t opcode = 0x8f;
				const uint8_t a = 136;

				const uint8_t expected = a + a;

				// modifying this so it's more natural.
				const uint16_t oplength = 1;
				// we get a random address for our opcode
				const uint16_t address = rand() % (0xffff - oplength);

				using namespace KeemoLib;

				// pc pointer setup
				cpu::registers.pc = address;
				// Opcode write to memory
				memory::writeUInt8(address, opcode);
				// Opcode arguments write to memory
				cpu::registers.a = a;

				// emulation step
				cpu::step();

				// we check for C set
				Assert::IsTrue(cpu::CHECK_FLAG(cpu::Flags::C));

				// we check Z is reset because the result is not 0
				Assert::IsFalse(cpu::CHECK_FLAG(cpu::Flags::Z));

				// there was a carry from bit 3 as well bith 7
				Assert::IsTrue(
cpu::CHECK_FLAG(cpu::Flags::H));

				// finally we check our expeted
				const uint8_t actual = cpu::registers.a;
				Assert::AreEqual(expected, actual);

				// we check pc steps
				Assert::IsTrue(cpu::registers.pc == (address + oplength));
			}
			TEST_METHOD(Test_add_a_a_with_0_result)
			{
				// Usual initialization
				const uint8_t opcode = 0x8f;
				const uint8_t a = 0;

				const uint8_t expected = a + a;

				// modifying this so it's more natural.
				const uint16_t oplength = 1;
				// we get a random address for our opcode
				const uint16_t address = rand() % (0xffff - oplength);

				using namespace KeemoLib;

				// pc pointer setup
				cpu::registers.pc = address;
				// Opcode write to memory
				memory::writeUInt8(address, opcode);
				// Opcode arguments write to memory
				cpu::registers.a = a;

				// emulation step
				cpu::step();

				// we check for C unsert
				Assert::IsFalse(cpu::CHECK_FLAG(cpu::Flags::C));

				// we check Z is set
				Assert::IsTrue(cpu::CHECK_FLAG(cpu::Flags::Z));

				// with this number there was no carry from bit 3 so
				Assert::IsFalse(cpu::CHECK_FLAG(cpu::Flags::H));

				// finally we check our expeted
				const uint8_t actual = cpu::registers.a;
				Assert::AreEqual(expected, actual);

				// we check pc steps
				Assert::IsTrue(cpu::registers.pc == (address + oplength));
			}
			// as explained at the start imma just do this kind of test for the whole subset of add instructions
			TEST_METHOD(Test_add_a_b)
			{
				// Usual initialization
				const uint8_t opcode = 0x88;
				const uint8_t x = rand() % 0xff;
				const uint8_t y = rand() % x;

				const uint8_t expected = x + y;

				// modifying this so it's more natural.
				const uint16_t oplength = 1;
				// we get a random address for our opcode
				const uint16_t address = rand() % (0xffff - oplength);

				using namespace KeemoLib;

				// pc pointer setup
				cpu::registers.pc = address;
				// Opcode write to memory
				memory::writeUInt8(address, opcode);
				// Opcode arguments write to memory
				cpu::registers.a = x;
				cpu::registers.b = y;

				// emulation step
				cpu::step();

				// finally we check our expeted
				const uint8_t actual = cpu::registers.a;
				Assert::AreEqual(expected, actual);

				// we check pc steps
				Assert::IsTrue(cpu::registers.pc == (address + oplength));
			}
			TEST_METHOD(Test_add_a_c)
			{
				// Usual initialization
				const uint8_t opcode = 0x89;
				const uint8_t x = rand() % 0xff;
				const uint8_t y = rand() % x;

				const uint8_t expected = x + y;

				// modifying this so it's more natural.
				const uint16_t oplength = 1;
				// we get a random address for our opcode
				const uint16_t address = rand() % (0xffff - oplength);

				using namespace KeemoLib;

				// pc pointer setup
				cpu::registers.pc = address;
				// Opcode write to memory
				memory::writeUInt8(address, opcode);
				// Opcode arguments write to memory
				cpu::registers.a = x;
				cpu::registers.c = y;

				// emulation step
				cpu::step();

				// finally we check our expeted
				const uint8_t actual = cpu::registers.a;
				Assert::AreEqual(expected, actual);

				// we check pc steps
				Assert::IsTrue(cpu::registers.pc == (address + oplength));
			}

			TEST_METHOD(Test_add_a_d)
			{
				// Usual initialization
				const uint8_t opcode = 0x8a;
				const uint8_t x = rand() % 0xff;
				const uint8_t y = rand() % x;

				const uint8_t expected = x + y;

				// modifying this so it's more natural.
				const uint16_t oplength = 1;
				// we get a random address for our opcode
				const uint16_t address = rand() % (0xffff - oplength);

				using namespace KeemoLib;

				// pc pointer setup
				cpu::registers.pc = address;
				// Opcode write to memory
				memory::writeUInt8(address, opcode);
				// Opcode arguments write to memory
				cpu::registers.a = x;
				cpu::registers.d = y;

				// emulation step
				cpu::step();

				// finally we check our expeted
				const uint8_t actual = cpu::registers.a;
				Assert::AreEqual(expected, actual);

				// we check pc steps
				Assert::IsTrue(cpu::registers.pc == (address + oplength));
			}

			TEST_METHOD(Test_add_a_e)
			{
				// Usual initialization
				const uint8_t opcode = 0x8b;
				const uint8_t x = rand() % 0xff;
				const uint8_t y = rand() % x;

				const uint8_t expected = x + y;

				// modifying this so it's more natural.
				const uint16_t oplength = 1;
				// we get a random address for our opcode
				const uint16_t address = rand() % (0xffff - oplength);

				using namespace KeemoLib;

				// pc pointer setup
				cpu::registers.pc = address;
				// Opcode write to memory
				memory::writeUInt8(address, opcode);
				// Opcode arguments write to memory
				cpu::registers.a = x;
				cpu::registers.e = y;

				// emulation step
				cpu::step();

				// finally we check our expeted
				const uint8_t actual = cpu::registers.a;
				Assert::AreEqual(expected, actual);

				// we check pc steps
				Assert::IsTrue(cpu::registers.pc == (address + oplength));
			}

			TEST_METHOD(Test_add_a_h)
			{
				// Usual initialization
				const uint8_t opcode = 0x8c;
				const uint8_t x = rand() % 0xff;
				const uint8_t y = rand() % x;

				const uint8_t expected = x + y;

				// modifying this so it's more natural.
				const uint16_t oplength = 1;
				// we get a random address for our opcode
				const uint16_t address = rand() % (0xffff - oplength);

				using namespace KeemoLib;

				// pc pointer setup
				cpu::registers.pc = address;
				// Opcode write to memory
				memory::writeUInt8(address, opcode);
				// Opcode arguments write to memory
				cpu::registers.a = x;
				cpu::registers.h = y;

				// emulation step
				cpu::step();

				// finally we check our expeted
				const uint8_t actual = cpu::registers.a;
				Assert::AreEqual(expected, actual);

				// we check pc steps
				Assert::IsTrue(cpu::registers.pc == (address + oplength));
			}

			TEST_METHOD(Test_add_a_l)
			{
				// Usual initialization
				const uint8_t opcode = 0x8d;
				const uint8_t x = rand() % 0xff;
				const uint8_t y = rand() % x;

				const uint8_t expected = x + y;

				// modifying this so it's more natural.
				const uint16_t oplength = 1;
				// we get a random address for our opcode
				const uint16_t address = rand() % (0xffff - oplength);

				using namespace KeemoLib;

				// pc pointer setup
				cpu::registers.pc = address;
				// Opcode write to memory
				memory::writeUInt8(address, opcode);
				// Opcode arguments write to memory
				cpu::registers.a = x;
				cpu::registers.l = y;

				// emulation step
				cpu::step();

				// finally we check our expeted
				const uint8_t actual = cpu::registers.a;
				Assert::AreEqual(expected, actual);

				// we check pc steps
				Assert::IsTrue(cpu::registers.pc == (address + oplength));
			}

			TEST_METHOD(Test_add_a_hl)
			{
				// Usual initialization
				const uint8_t opcode = 0x8e;
				const uint8_t x = rand() % 0xff;
				const uint8_t y = rand() % x;

				const uint8_t expected = x + y;

				// modifying this so it's more natural.
				const uint16_t oplength = 1;
				// we get a random address for our opcode
				const uint16_t address = rand() % (0xffff - oplength);

				uint16_t hl = rand() % 0xffff;
				while(hl <= address && (hl >=  (address-oplength)))
				{
					hl = rand() % 0xffff;
				}

				using namespace KeemoLib;

				// pc pointer setup
				cpu::registers.pc = address;
				// Opcode write to memory
				memory::writeUInt8(address, opcode);
				memory::writeUInt8(hl, y);
				// Opcode arguments write to memory
				cpu::registers.a = x;
				cpu::registers.hl = hl;

				// emulation step
				cpu::step();

				// finally we check our expeted
				const uint8_t actual = cpu::registers.a;
				Assert::AreEqual(expected, actual);

				// we check pc steps
				Assert::IsTrue(cpu::registers.pc == (address + oplength));
			}

			TEST_METHOD(Test_add_a_n)
			{
				// Usual initialization
				const uint8_t opcode = 0xce;
				const uint8_t x = rand() % 0xff;
				const uint8_t y = rand() % x;

				const uint8_t expected = x + y;

				// modifying this so it's more natural.
				const uint16_t oplength = 2;
				// we get a random address for our opcode
				const uint16_t address = rand() % (0xffff - oplength);

				using namespace KeemoLib;

				// pc pointer setup
				cpu::registers.pc = address;
				// Opcode write to memory
				memory::writeUInt8(address, opcode);
				memory::writeUInt8(address+1,y);
				// Opcode arguments write to memory
				cpu::registers.a = x;

				// emulation step
				cpu::step();

				// finally we check our expeted
				const uint8_t actual = cpu::registers.a;
				Assert::AreEqual(expected, actual);

				// we check pc steps
				Assert::IsTrue(cpu::registers.pc == (address + oplength));
			}
		};
	}
}
