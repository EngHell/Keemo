#include "stdafx.h"
#include <CppUnitTest.h>
#include "Cpu.hpp"
#include "Memory.hpp"
#include <ctime>
#include "../../../KeemoLib/src/op/MathHelpers.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace KeemoTests
{
	namespace CpuTests
	{
		namespace OpTests
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
				const uint8_t opcode = 0x87;
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
				const uint8_t opcode = 0x87;
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
				const uint8_t opcode = 0x87;
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
				Assert::IsTrue(cpu::CHECK_FLAG(cpu::Flags::H));

				// finally we check our expeted
				const uint8_t actual = cpu::registers.a;
				Assert::AreEqual(expected, actual);

				// we check pc steps
				Assert::IsTrue(cpu::registers.pc == (address + oplength));
			}
			TEST_METHOD(Test_add_a_a_with_0_result)
			{
				// Usual initialization
				const uint8_t opcode = 0x87;
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
				const uint8_t opcode = 0x80;
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
				const uint8_t opcode = 0x81;
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
				const uint8_t opcode = 0x82;
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
				const uint8_t opcode = 0x83;
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
				const uint8_t opcode = 0x84;
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
				const uint8_t opcode = 0x85;
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
				const uint8_t opcode = 0x86;
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
				const uint8_t opcode = 0xc6;
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

			// the ADC instruction just calls the same add_uint8 function that
			// ADD uses but first plus the carry to the value, so you know, 
			// making tests for it doesn't look to appealing in the case of the bit carrys and flags
			// as those are already tested above, may it be a bad practice?
			// probably but lets put the man power in a more interesting area
			// than retesting whats already tested
			TEST_METHOD(Test_adc_a_a)
			{
				// Usual initialization
				const uint8_t opcode = 0x8f;
				const uint8_t x = rand() % 128;
				const uint8_t y = x; //rand() % x;
				const uint8_t carry = rand() % 2;

				const uint8_t expected = x + y + carry;

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
				//cpu::registers.b = y;
				if(carry)
					cpu::SET_FLAGS(cpu::Flags::C);
				else
					cpu::CLEAR_FLAGS(cpu::Flags::C);

				// emulation step
				cpu::step();

				// finally we check our expeted
				const uint8_t actual = cpu::registers.a;
				Assert::AreEqual(expected, actual);

				// we check pc steps
				Assert::IsTrue(cpu::registers.pc == (address + oplength));
			}

			TEST_METHOD(Test_adc_a_b)
			{
				// Usual initialization
				const uint8_t opcode = 0x88;
				const uint8_t x = rand() % 0xff;
				const uint8_t y = rand() % x;
				const uint8_t carry = rand() % 2;

				const uint8_t expected = x + y + carry;

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
				if(carry)
					cpu::SET_FLAGS(cpu::Flags::C);
				else
					cpu::CLEAR_FLAGS(cpu::Flags::C);

				// emulation step
				cpu::step();

				// finally we check our expeted
				const uint8_t actual = cpu::registers.a;
				Assert::AreEqual(expected, actual);

				// we check pc steps
				Assert::IsTrue(cpu::registers.pc == (address + oplength));
			}
			TEST_METHOD(Test_adc_a_c)
			{
				// Usual initialization
				const uint8_t opcode = 0x89;
				const uint8_t x = rand() % 0xff;
				const uint8_t y = rand() % x;
				const uint8_t carry = rand() % 2;

				const uint8_t expected = x + y + carry;

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
				if(carry)
					cpu::SET_FLAGS(cpu::Flags::C);
				else
					cpu::CLEAR_FLAGS(cpu::Flags::C);

				// emulation step
				cpu::step();

				// finally we check our expeted
				const uint8_t actual = cpu::registers.a;
				Assert::AreEqual(expected, actual);

				// we check pc steps
				Assert::IsTrue(cpu::registers.pc == (address + oplength));
			}
			TEST_METHOD(Test_adc_a_d)
			{
				// Usual initialization
				const uint8_t opcode = 0x8a;
				const uint8_t x = rand() % 0xff;
				const uint8_t y = rand() % x;
				const uint8_t carry = rand() % 2;

				const uint8_t expected = x + y + carry;

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
				if(carry)
					cpu::SET_FLAGS(cpu::Flags::C);
				else
					cpu::CLEAR_FLAGS(cpu::Flags::C);

				// emulation step
				cpu::step();

				// finally we check our expeted
				const uint8_t actual = cpu::registers.a;
				Assert::AreEqual(expected, actual);

				// we check pc steps
				Assert::IsTrue(cpu::registers.pc == (address + oplength));
			}
			TEST_METHOD(Test_adc_a_e)
			{
				// Usual initialization
				const uint8_t opcode = 0x8b;
				const uint8_t x = rand() % 0xff;
				const uint8_t y = rand() % x;
				const uint8_t carry = rand() % 2;

				const uint8_t expected = x + y + carry;

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
				if(carry)
					cpu::SET_FLAGS(cpu::Flags::C);
				else
					cpu::CLEAR_FLAGS(cpu::Flags::C);

				// emulation step
				cpu::step();

				// finally we check our expeted
				const uint8_t actual = cpu::registers.a;
				Assert::AreEqual(expected, actual);

				// we check pc steps
				Assert::IsTrue(cpu::registers.pc == (address + oplength));
			}
			TEST_METHOD(Test_adc_a_h)
			{
				// Usual initialization
				const uint8_t opcode = 0x8c;
				const uint8_t x = rand() % 0xff;
				const uint8_t y = rand() % x;
				const uint8_t carry = rand() % 2;

				const uint8_t expected = x + y + carry;

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
				if(carry)
					cpu::SET_FLAGS(cpu::Flags::C);
				else
					cpu::CLEAR_FLAGS(cpu::Flags::C);

				// emulation step
				cpu::step();

				// finally we check our expeted
				const uint8_t actual = cpu::registers.a;
				Assert::AreEqual(expected, actual);

				// we check pc steps
				Assert::IsTrue(cpu::registers.pc == (address + oplength));
			}
			TEST_METHOD(Test_adc_a_l)
			{
				// Usual initialization
				const uint8_t opcode = 0x8d;
				const uint8_t x = rand() % 0xff;
				const uint8_t y = rand() % x;
				const uint8_t carry = rand() % 2;

				const uint8_t expected = x + y + carry;

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
				if(carry)
					cpu::SET_FLAGS(cpu::Flags::C);
				else
					cpu::CLEAR_FLAGS(cpu::Flags::C);

				// emulation step
				cpu::step();

				// finally we check our expeted
				const uint8_t actual = cpu::registers.a;
				Assert::AreEqual(expected, actual);

				// we check pc steps
				Assert::IsTrue(cpu::registers.pc == (address + oplength));
			}
			TEST_METHOD(Test_adc_a_hl)
			{
				// Usual initialization
				const uint8_t opcode = 0x8e;
				const uint8_t x = rand() % 0xff;
				const uint8_t y = rand() % x;
				const uint8_t carry = rand() % 2;

				const uint8_t expected = x + y + carry;

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

				// Opcode arguments write to memory
				cpu::registers.hl = hl;
				cpu::registers.a = x;
				//cpu::registers.b = y;
				memory::writeUInt8(hl, y);

				if(carry)
					cpu::SET_FLAGS(cpu::Flags::C);
				else
					cpu::CLEAR_FLAGS(cpu::Flags::C);

				// emulation step
				cpu::step();

				// finally we check our expeted
				const uint8_t actual = cpu::registers.a;
				Assert::AreEqual(expected, actual);

				// we check pc steps
				Assert::IsTrue(cpu::registers.pc == (address + oplength));
			}
			TEST_METHOD(Test_adc_a_n)
			{
				// Usual initialization
				const uint8_t opcode = 0xce;
				const uint8_t x = rand() % 0xff;
				const uint8_t y = rand() % x;
				const uint8_t carry = rand() % 2;

				const uint8_t expected = x + y + carry;

				// modifying this so it's more natural.
				const uint16_t oplength = 2;
				// we get a random address for our opcode
				const uint16_t address = rand() % (0xffff - oplength);

				using namespace KeemoLib;

				// pc pointer setup
				cpu::registers.pc = address;
				// Opcode write to memory
				memory::writeUInt8(address, opcode);

				// Opcode arguments write to memory
				cpu::registers.a = x;
				memory::writeUInt8(address+1, y);
				if(carry)
					cpu::SET_FLAGS(cpu::Flags::C);
				else
					cpu::CLEAR_FLAGS(cpu::Flags::C);

				// emulation step
				cpu::step();

				// finally we check our expeted
				const uint8_t actual = cpu::registers.a;
				Assert::AreEqual(expected, actual);

				// we check pc steps
				Assert::IsTrue(cpu::registers.pc == (address + oplength));
			}

			// NOW im going to test our math helper function from top to bot instead of doing it at the
			// the first instruction i write using it.
			TEST_METHOD(Test_sub_uint8_with_borrow)
			{
				uint8_t a = 10;
				const uint8_t b = 20;

				const uint8_t expected = a - b;

				using namespace KeemoLib;

				cpu::math::sub_uint8(a, b);

				Assert::AreEqual(expected, a);

				Assert::IsTrue(CHECK_FLAG(cpu::C));
				Assert::IsFalse(CHECK_FLAG(cpu::H));
				Assert::IsFalse(CHECK_FLAG(cpu::Z));
				Assert::IsTrue(CHECK_FLAG(cpu::N));
			}

			TEST_METHOD(Test_sub_uint8_with_half_borrow)
			{
				uint8_t a = 1<<4;
				const uint8_t b = 1;

				const uint8_t expected = a - b;

				using namespace KeemoLib;

				cpu::math::sub_uint8(a, b);

				Assert::AreEqual(expected, a);

				Assert::IsFalse(CHECK_FLAG(cpu::C));
				Assert::IsTrue(CHECK_FLAG(cpu::H));
				Assert::IsFalse(CHECK_FLAG(cpu::Z));
				Assert::IsTrue(CHECK_FLAG(cpu::N));
			}

			TEST_METHOD(Test_sub_uint8_result_0)
			{
				uint8_t a = rand() % 0xff;
				const uint8_t b = a;

				const uint8_t expected = a - b;

				using namespace KeemoLib;

				cpu::math::sub_uint8(a, b);

				Assert::AreEqual(expected, a);

				Assert::IsFalse(CHECK_FLAG(cpu::C));
				Assert::IsFalse(CHECK_FLAG(cpu::H));
				Assert::IsTrue(CHECK_FLAG(cpu::Z));
				Assert::IsTrue(CHECK_FLAG(cpu::N));


			}

			TEST_METHOD(Test_sub_uint8_test_correct_result_random)
			{
				uint8_t a, b, expected;

				for(auto i = 0; i < 100; i ++)
				{
					a = rand() % 0xff;
					b =  rand() % 0xff;

					expected = a - b;

					using namespace KeemoLib;

					cpu::math::sub_uint8(a, b);

					Assert::AreEqual(expected, a);
				}
			}

			TEST_METHOD(Test_sub_a)
			{
				// Usual initialization
				const uint8_t opcode = 0x97;
				const uint8_t x = rand() % 0xff;
				const uint8_t y = x;//rand() % x;

				const uint8_t expected = x - y;

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
				//cpu::registers.b = y;

				// emulation step
				cpu::step();

				// finally we check our expeted
				const uint8_t actual = cpu::registers.a;
				Assert::AreEqual(expected, actual);

				// we check pc steps
				Assert::IsTrue(cpu::registers.pc == (address + oplength));
			}

			TEST_METHOD(Test_sub_b)
			{
				// Usual initialization
				const uint8_t opcode = 0x90;
				const uint8_t x = rand() % 0xff;
				const uint8_t y = rand() % x;

				const uint8_t expected = x - y;

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

			TEST_METHOD(Test_sub_c)
			{
				// Usual initialization
				const uint8_t opcode = 0x91;
				const uint8_t x = rand() % 0xff;
				const uint8_t y = rand() % x;

				const uint8_t expected = x - y;

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
			
			TEST_METHOD(Test_sub_e)
			{
				// Usual initialization
				const uint8_t opcode = 0x93;
				const uint8_t x = rand() % 0xff;
				const uint8_t y = rand() % x;

				const uint8_t expected = x - y;

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

			TEST_METHOD(Test_sub_h)
			{
				// Usual initialization
				const uint8_t opcode = 0x94;
				const uint8_t x = rand() % 0xff;
				const uint8_t y = rand() % x;

				const uint8_t expected = x - y;

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

			TEST_METHOD(Test_sub_l)
			{
				// Usual initialization
				const uint8_t opcode = 0x95;
				const uint8_t x = rand() % 0xff;
				const uint8_t y = rand() % x;

				const uint8_t expected = x - y;

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

			TEST_METHOD(Test_sub_hl)
			{
				// Usual initialization
				const uint8_t opcode = 0x96;
				const uint8_t x = rand() % 0xff;
				const uint8_t y = rand() % x;

				const uint8_t expected = x - y;

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
				// Opcode arguments write to memory
				cpu::registers.a = x;
				cpu::registers.hl = hl;
				memory::writeUInt8(hl, y);

				// emulation step
				cpu::step();

				// finally we check our expeted
				const uint8_t actual = cpu::registers.a;
				Assert::AreEqual(expected, actual);

				// we check pc steps
				Assert::IsTrue(cpu::registers.pc == (address + oplength));
			}

			TEST_METHOD(Test_sub_n)
			{
				// Usual initialization
				const uint8_t opcode = 0xd6;
				const uint8_t x = rand() % 0xff;
				const uint8_t y = rand() % x;

				const uint8_t expected = x - y;

				// modifying this so it's more natural.
				const uint16_t oplength = 2;
				// we get a random address for our opcode
				const uint16_t address = rand() % (0xffff - oplength);

				using namespace KeemoLib;

				// pc pointer setup
				cpu::registers.pc = address;
				// Opcode write to memory
				memory::writeUInt8(address, opcode);
				// Opcode arguments write to memory
				cpu::registers.a = x;
				memory::writeUInt8(address+1, y);

				// emulation step
				cpu::step();

				// finally we check our expeted
				const uint8_t actual = cpu::registers.a;
				Assert::AreEqual(expected, actual);

				// we check pc steps
				Assert::IsTrue(cpu::registers.pc == (address + oplength));
			}

			// SBC just calls the same sub_uint8 with so it doesnt makes sense to test the flags
			TEST_METHOD(Test_sbc_a)
			{
				// Usual initialization
				const uint8_t opcode = 0x9f;
				const uint8_t x = rand() % 128;
				const uint8_t y = x; //rand() % x;
				const uint8_t carry = rand() % 2;

				const uint8_t expected = x - (y + carry);

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
				//cpu::registers.b = y;
				if(carry)
					cpu::SET_FLAGS(cpu::Flags::C);
				else
					cpu::CLEAR_FLAGS(cpu::Flags::C);

				// emulation step
				cpu::step();

				// finally we check our expeted
				const uint8_t actual = cpu::registers.a;
				Assert::AreEqual(expected, actual);

				// we check pc steps
				Assert::IsTrue(cpu::registers.pc == (address + oplength));
			}

			TEST_METHOD(Test_sbc_b)
			{
				// Usual initialization
				const uint8_t opcode = 0x98;
				const uint8_t x = rand() % 0xff;
				const uint8_t y = rand() % x;
				const uint8_t carry = rand() % 2;

				const uint8_t expected = x -( y + carry);

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
				if(carry)
					cpu::SET_FLAGS(cpu::Flags::C);
				else
					cpu::CLEAR_FLAGS(cpu::Flags::C);

				// emulation step
				cpu::step();

				// finally we check our expeted
				const uint8_t actual = cpu::registers.a;
				Assert::AreEqual(expected, actual);

				// we check pc steps
				Assert::IsTrue(cpu::registers.pc == (address + oplength));
			}
			TEST_METHOD(Test_sbc_c)
			{
				// Usual initialization
				const uint8_t opcode = 0x99;
				const uint8_t x = rand() % 0xff;
				const uint8_t y = rand() % x;
				const uint8_t carry = rand() % 2;

				const uint8_t expected = x - (y + carry);

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
				if(carry)
					cpu::SET_FLAGS(cpu::Flags::C);
				else
					cpu::CLEAR_FLAGS(cpu::Flags::C);

				// emulation step
				cpu::step();

				// finally we check our expeted
				const uint8_t actual = cpu::registers.a;
				Assert::AreEqual(expected, actual);

				// we check pc steps
				Assert::IsTrue(cpu::registers.pc == (address + oplength));
			}
			TEST_METHOD(Test_sbc_d)
			{
				// Usual initialization
				const uint8_t opcode = 0x9a;
				const uint8_t x = rand() % 0xff;
				const uint8_t y = rand() % x;
				const uint8_t carry = rand() % 2;

				const uint8_t expected = x - (y + carry);

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
				if(carry)
					cpu::SET_FLAGS(cpu::Flags::C);
				else
					cpu::CLEAR_FLAGS(cpu::Flags::C);

				// emulation step
				cpu::step();

				// finally we check our expeted
				const uint8_t actual = cpu::registers.a;
				Assert::AreEqual(expected, actual);

				// we check pc steps
				Assert::IsTrue(cpu::registers.pc == (address + oplength));
			}
			TEST_METHOD(Test_sbc_e)
			{
				// Usual initialization
				const uint8_t opcode = 0x9b;
				const uint8_t x = rand() % 0xff;
				const uint8_t y = rand() % x;
				const uint8_t carry = rand() % 2;

				const uint8_t expected = x - (y + carry);

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
				if(carry)
					cpu::SET_FLAGS(cpu::Flags::C);
				else
					cpu::CLEAR_FLAGS(cpu::Flags::C);

				// emulation step
				cpu::step();

				// finally we check our expeted
				const uint8_t actual = cpu::registers.a;
				Assert::AreEqual(expected, actual);

				// we check pc steps
				Assert::IsTrue(cpu::registers.pc == (address + oplength));
			}
			TEST_METHOD(Test_sbc_h)
			{
				// Usual initialization
				const uint8_t opcode = 0x9c;
				const uint8_t x = rand() % 0xff;
				const uint8_t y = rand() % x;
				const uint8_t carry = rand() % 2;

				const uint8_t expected = x - (y + carry);

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
				if(carry)
					cpu::SET_FLAGS(cpu::Flags::C);
				else
					cpu::CLEAR_FLAGS(cpu::Flags::C);

				// emulation step
				cpu::step();

				// finally we check our expeted
				const uint8_t actual = cpu::registers.a;
				Assert::AreEqual(expected, actual);

				// we check pc steps
				Assert::IsTrue(cpu::registers.pc == (address + oplength));
			}
			TEST_METHOD(Test_sbc_l)
			{
				// Usual initialization
				const uint8_t opcode = 0x9d;
				const uint8_t x = rand() % 0xff;
				const uint8_t y = rand() % x;
				const uint8_t carry = rand() % 2;

				const uint8_t expected = x - (y + carry);

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
				if(carry)
					cpu::SET_FLAGS(cpu::Flags::C);
				else
					cpu::CLEAR_FLAGS(cpu::Flags::C);

				// emulation step
				cpu::step();

				// finally we check our expeted
				const uint8_t actual = cpu::registers.a;
				Assert::AreEqual(expected, actual);

				// we check pc steps
				Assert::IsTrue(cpu::registers.pc == (address + oplength));
			}
			TEST_METHOD(Test_sbc_hl)
			{
				// Usual initialization
				const uint8_t opcode = 0x9e;
				const uint8_t x = rand() % 0xff;
				const uint8_t y = rand() % x;
				const uint8_t carry = rand() % 2;

				const uint8_t expected = x - (y + carry);

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

				// Opcode arguments write to memory
				cpu::registers.hl = hl;
				cpu::registers.a = x;
				//cpu::registers.b = y;
				memory::writeUInt8(hl, y);

				if(carry)
					cpu::SET_FLAGS(cpu::Flags::C);
				else
					cpu::CLEAR_FLAGS(cpu::Flags::C);

				// emulation step
				cpu::step();

				// finally we check our expeted
				const uint8_t actual = cpu::registers.a;
				Assert::AreEqual(expected, actual);

				// we check pc steps
				Assert::IsTrue(cpu::registers.pc == (address + oplength));
			}

			// first we will test our and_uint8(...)
			TEST_METHOD(Test_and_uint8_with_0_result)
			{
				uint8_t a = rand() % 0xff;
				const uint8_t b = 0;

				const uint8_t expected = a & b;

				using namespace KeemoLib;

				cpu::math::and_uint8(a, b);

				const auto actual = a;

				Assert::AreEqual(expected, actual);
				Assert::IsTrue(CHECK_FLAG(cpu::Z));
				Assert::IsTrue(CHECK_FLAG(cpu::H));
				Assert::IsFalse(CHECK_FLAG(cpu::N));
				Assert::IsFalse(CHECK_FLAG(cpu::C));
			}
			TEST_METHOD(Test_and_uint8_with_non_0_result)
			{
				uint8_t a = (rand() % 0xfe) + 1;
				const uint8_t b = (rand() % 0xfe) + 1;

				const uint8_t expected = a & b;

				using namespace KeemoLib;

				cpu::math::and_uint8(a, b);

				const auto actual = a;

				Assert::AreEqual(expected, actual);
				Assert::IsFalse(CHECK_FLAG(cpu::Z));
				Assert::IsTrue(CHECK_FLAG(cpu::H));
				Assert::IsFalse(CHECK_FLAG(cpu::N));
				Assert::IsFalse(CHECK_FLAG(cpu::C));
			}

			TEST_METHOD(Test_and_a)
			{
				// Usual initialization
				const uint8_t opcode = 0xa7;
				const uint8_t x = rand() % 0xff;
				const uint8_t y = x; //rand() % x;

				const uint8_t expected = x & y;

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
				//cpu::registers.b = y;

				// emulation step
				cpu::step();

				// finally we check our expeted
				const uint8_t actual = cpu::registers.a;
				Assert::AreEqual(expected, actual);

				// we check pc steps
				Assert::IsTrue(cpu::registers.pc == (address + oplength));
			}
			TEST_METHOD(Test_and_b)
			{
				// Usual initialization
				const uint8_t opcode = 0xa0;
				const uint8_t x = rand() % 0xff;
				const uint8_t y = rand() % 0xff;

				const uint8_t expected = x & y;

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
			TEST_METHOD(Test_and_c)
			{
				// Usual initialization
				const uint8_t opcode = 0xa1;
				const uint8_t x = rand() % 0xff;
				const uint8_t y = rand() % 0xff;

				const uint8_t expected = x & y;

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
			TEST_METHOD(Test_and_d)
			{
				// Usual initialization
				const uint8_t opcode = 0xa2;
				const uint8_t x = rand() % 0xff;
				const uint8_t y = rand() % 0xff;

				const uint8_t expected = x & y;

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
			TEST_METHOD(Test_and_e)
			{
				// Usual initialization
				const uint8_t opcode = 0xa3;
				const uint8_t x = rand() % 0xff;
				const uint8_t y = rand() % 0xff;

				const uint8_t expected = x & y;

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
			TEST_METHOD(Test_and_h)
			{
				// Usual initialization
				const uint8_t opcode = 0xa4;
				const uint8_t x = rand() % 0xff;
				const uint8_t y = rand() % 0xff;

				const uint8_t expected = x & y;

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
			TEST_METHOD(Test_and_l)
			{
				// Usual initialization
				const uint8_t opcode = 0xa5;
				const uint8_t x = rand() % 0xff;
				const uint8_t y = rand() % 0xff;

				const uint8_t expected = x & y;

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
			TEST_METHOD(Test_and_hl)
			{
				// Usual initialization
				const uint8_t opcode = 0xa6;
				const uint8_t x = rand() % 0xff;
				const uint8_t y = rand() % 0xff;

				const uint8_t expected = x & y;

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
				// Opcode arguments write to memory
				cpu::registers.a = x;
				cpu::registers.hl = hl;
				memory::writeUInt8(hl, y);

				// emulation step
				cpu::step();

				// finally we check our expeted
				const uint8_t actual = cpu::registers.a;
				Assert::AreEqual(expected, actual);

				// we check pc steps
				Assert::IsTrue(cpu::registers.pc == (address + oplength));
			}
			TEST_METHOD(Test_and_n)
			{
				// Usual initialization
				const uint8_t opcode = 0xe6;
				const uint8_t x = rand() % 0xff;
				const uint8_t y = rand() % 0xff;

				const uint8_t expected = x & y;

				// modifying this so it's more natural.
				const uint16_t oplength = 2;
				// we get a random address for our opcode
				const uint16_t address = rand() % (0xffff - oplength);

				using namespace KeemoLib;

				// pc pointer setup
				cpu::registers.pc = address;
				// Opcode write to memory
				memory::writeUInt8(address, opcode);
				// Opcode arguments write to memory
				cpu::registers.a = x;
				memory::writeUInt8(address+1, y);

				// emulation step
				cpu::step();

				// finally we check our expeted
				const uint8_t actual = cpu::registers.a;
				Assert::AreEqual(expected, actual);

				// we check pc steps
				Assert::IsTrue(cpu::registers.pc == (address + oplength));
			}

			TEST_METHOD(Test_or_uint8_with_0_result)
			{
				uint8_t a = 0;
				uint8_t b = 0;

				const uint8_t expected = a | b;

				using namespace KeemoLib;

				cpu::math::or_uint8(a, b);

				Assert::AreEqual(expected, a);
				Assert::IsTrue(CHECK_FLAG(cpu::Z));
				Assert::IsFalse(CHECK_FLAG(cpu::N));
				Assert::IsFalse(CHECK_FLAG(cpu::H));
				Assert::IsFalse(CHECK_FLAG(cpu::C));
			}


			TEST_METHOD(Test_or_uint8_with_non_0_result)
			{
				uint8_t a = rand() % 0xff;
				uint8_t b = (rand() % 0xfe) + 1;

				const uint8_t expected = a | b;

				using namespace KeemoLib;

				cpu::math::or_uint8(a, b);

				Assert::AreEqual(expected, a);
				Assert::IsFalse(CHECK_FLAG(cpu::Z));
				Assert::IsFalse(CHECK_FLAG(cpu::N));
				Assert::IsFalse(CHECK_FLAG(cpu::H));
				Assert::IsFalse(CHECK_FLAG(cpu::C));
			}

			TEST_METHOD(Test_or_a)
			{
				// Usual initialization
				const uint8_t opcode = 0xb7;
				const uint8_t x = rand() % 0xff;
				const uint8_t y = x; //rand() % x;

				const uint8_t expected = x | y;

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
				//cpu::registers.b = y;

				// emulation step
				cpu::step();

				// finally we check our expeted
				const uint8_t actual = cpu::registers.a;
				Assert::AreEqual(expected, actual);

				// we check pc steps
				Assert::IsTrue(cpu::registers.pc == (address + oplength));
			}
			TEST_METHOD(Test_or_b)
			{
				// Usual initialization
				const uint8_t opcode = 0xb0;
				const uint8_t x = rand() % 0xff;
				const uint8_t y = rand() % 0xff;

				const uint8_t expected = x | y;

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
			TEST_METHOD(Test_or_c)
			{
				// Usual initialization
				const uint8_t opcode = 0xb1;
				const uint8_t x = rand() % 0xff;
				const uint8_t y = rand() % 0xff;

				const uint8_t expected = x | y;

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
			TEST_METHOD(Test_or_d)
			{
				// Usual initialization
				const uint8_t opcode = 0xb2;
				const uint8_t x = rand() % 0xff;
				const uint8_t y = rand() % 0xff;

				const uint8_t expected = x | y;

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
			TEST_METHOD(Test_or_e)
			{
				// Usual initialization
				const uint8_t opcode = 0xb3;
				const uint8_t x = rand() % 0xff;
				const uint8_t y = rand() % 0xff;

				const uint8_t expected = x | y;

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
			TEST_METHOD(Test_or_h)
			{
				// Usual initialization
				const uint8_t opcode = 0xb4;
				const uint8_t x = rand() % 0xff;
				const uint8_t y = rand() % 0xff;

				const uint8_t expected = x | y;

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
			TEST_METHOD(Test_or_l)
			{
				// Usual initialization
				const uint8_t opcode = 0xb5;
				const uint8_t x = rand() % 0xff;
				const uint8_t y = rand() % 0xff;

				const uint8_t expected = x | y;

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
			TEST_METHOD(Test_or_hl)
			{
				// Usual initialization
				const uint8_t opcode = 0xb6;
				const uint8_t x = rand() % 0xff;
				const uint8_t y = rand() % 0xff;

				const uint8_t expected = x | y;

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
				// Opcode arguments write to memory
				cpu::registers.a = x;
				cpu::registers.hl = hl;
				memory::writeUInt8(hl, y);

				// emulation step
				cpu::step();

				// finally we check our expeted
				const uint8_t actual = cpu::registers.a;
				Assert::AreEqual(expected, actual);

				// we check pc steps
				Assert::IsTrue(cpu::registers.pc == (address + oplength));
			}
			TEST_METHOD(Test_or_n)
			{
				// Usual initialization
				const uint8_t opcode = 0xf6;
				const uint8_t x = rand() % 0xff;
				const uint8_t y = rand() % 0xff;

				const uint8_t expected = x | y;

				// modifying this so it's more natural.
				const uint16_t oplength = 2;
				// we get a random address for our opcode
				const uint16_t address = rand() % (0xffff - oplength);

				using namespace KeemoLib;

				// pc pointer setup
				cpu::registers.pc = address;
				// Opcode write to memory
				memory::writeUInt8(address, opcode);
				// Opcode arguments write to memory
				cpu::registers.a = x;
				memory::writeUInt8(address+1, y);

				// emulation step
				cpu::step();

				// finally we check our expeted
				const uint8_t actual = cpu::registers.a;
				Assert::AreEqual(expected, actual);

				// we check pc steps
				Assert::IsTrue(cpu::registers.pc == (address + oplength));
			}

			TEST_METHOD(Test_xor_uint8_with_0_result)
			{
				const uint8_t a = rand() % 0xff;
				const uint8_t b = a;

				const uint8_t expected = a ^ b;

				using namespace KeemoLib;

				cpu::registers.a =  a;

				cpu::math::xor_uint8(b);

				const uint8_t actual = cpu::registers.a;

				Assert::AreEqual(expected, actual);

				Assert::IsTrue(CHECK_FLAG(cpu::Z));
				Assert::IsFalse(CHECK_FLAG(cpu::N));
				Assert::IsFalse(CHECK_FLAG(cpu::H));
				Assert::IsFalse(CHECK_FLAG(cpu::C));
			}
			TEST_METHOD(Test_xor_uint8_with_non_0_result)
			{
				const uint8_t a = rand() % 0xff;
				uint8_t b = rand() % 0xff;

				while(a == b)
				{
					b = rand() % 0xff;
				}

				const uint8_t expected = a ^ b;

				using namespace KeemoLib;

				cpu::registers.a = a;

				cpu::math::xor_uint8(b);

				const uint8_t actual = cpu::registers.a;

				Assert::AreEqual(expected, actual);

				Assert::IsFalse(CHECK_FLAG(cpu::Z));
				Assert::IsFalse(CHECK_FLAG(cpu::N));
				Assert::IsFalse(CHECK_FLAG(cpu::H));
				Assert::IsFalse(CHECK_FLAG(cpu::C));
			}

			TEST_METHOD(Test_xor_a)
			{
				// Usual initialization
				const uint8_t opcode = 0xaf;
				const uint8_t x = rand() % 0xff;
				const uint8_t y = x; //rand() % x;

				const uint8_t expected = x ^ y;

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
				//cpu::registers.b = y;

				// emulation step
				cpu::step();

				// finally we check our expeted
				const uint8_t actual = cpu::registers.a;
				Assert::AreEqual(expected, actual);

				// we check pc steps
				Assert::IsTrue(cpu::registers.pc == (address + oplength));
			}
			TEST_METHOD(Test_xor_b)
			{
				// Usual initialization
				const uint8_t opcode = 0xa8;
				const uint8_t x = rand() % 0xff;
				const uint8_t y = rand() % 0xff;

				const uint8_t expected = x ^ y;

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
			TEST_METHOD(Test_xor_c)
			{
				// Usual initialization
				const uint8_t opcode = 0xa9;
				const uint8_t x = rand() % 0xff;
				const uint8_t y = rand() % 0xff;

				const uint8_t expected = x ^ y;

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
			TEST_METHOD(Test_xor_d)
			{
				// Usual initialization
				const uint8_t opcode = 0xaa;
				const uint8_t x = rand() % 0xff;
				const uint8_t y = rand() % 0xff;

				const uint8_t expected = x ^ y;

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
			TEST_METHOD(Test_xor_e)
			{
				// Usual initialization
				const uint8_t opcode = 0xab;
				const uint8_t x = rand() % 0xff;
				const uint8_t y = rand() % 0xff;

				const uint8_t expected = x ^ y;

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
			TEST_METHOD(Test_xor_h)
			{
				// Usual initialization
				const uint8_t opcode = 0xac;
				const uint8_t x = rand() % 0xff;
				const uint8_t y = rand() % 0xff;

				const uint8_t expected = x ^ y;

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
			TEST_METHOD(Test_xor_l)
			{
				// Usual initialization
				const uint8_t opcode = 0xad;
				const uint8_t x = rand() % 0xff;
				const uint8_t y = rand() % 0xff;

				const uint8_t expected = x ^ y;

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
			TEST_METHOD(Test_xor_hl)
			{
				// Usual initialization
				const uint8_t opcode = 0xae;
				const uint8_t x = rand() % 0xff;
				const uint8_t y = rand() % 0xff;

				const uint8_t expected = x ^ y;

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
				// Opcode arguments write to memory
				cpu::registers.a = x;
				cpu::registers.hl = hl;
				memory::writeUInt8(hl, y);

				// emulation step
				cpu::step();

				// finally we check our expeted
				const uint8_t actual = cpu::registers.a;
				Assert::AreEqual(expected, actual);

				// we check pc steps
				Assert::IsTrue(cpu::registers.pc == (address + oplength));
			}
			TEST_METHOD(Test_xor_n)
			{
				// Usual initialization
				const uint8_t opcode = 0xee;
				const uint8_t x = rand() % 0xff;
				const uint8_t y = rand() % 0xff;

				const uint8_t expected = x ^ y;

				// modifying this so it's more natural.
				const uint16_t oplength = 2;
				// we get a random address for our opcode
				const uint16_t address = rand() % (0xffff - oplength);

				using namespace KeemoLib;

				// pc pointer setup
				cpu::registers.pc = address;
				// Opcode write to memory
				memory::writeUInt8(address, opcode);
				// Opcode arguments write to memory
				cpu::registers.a = x;
				memory::writeUInt8(address+1, y);

				// emulation step
				cpu::step();

				// finally we check our expeted
				const uint8_t actual = cpu::registers.a;
				Assert::AreEqual(expected, actual);

				// we check pc steps
				Assert::IsTrue(cpu::registers.pc == (address + oplength));
			}

			// why no tests for cp?
			// well since i made it before sub_uint8
			// then i refactore sub_uint8 to use cp
			// it should be already tested inside
			// i yet somehow got a bit lazy and don't want to make tests for cp
			// why? because what would i tests? the flags? since i make the numbers random i
			// will end with a lot of ifs and elses for the assertions and mmmm
			// i just got lazy :D

			TEST_METHOD(Test_inc_uint8_with_carry_bit_4)
			{
				uint8_t a = 0xaf;
				const uint8_t expected = a + 1;

				using namespace KeemoLib;

				cpu::math::inc_uint8(a);

				Assert::AreEqual(expected, a);

				Assert::IsTrue(CHECK_FLAG(cpu::H));
				Assert::IsFalse(CHECK_FLAG(cpu::Z));
				Assert::IsFalse(CHECK_FLAG(cpu::N));
			}
			TEST_METHOD(Test_inc_uint8_without_carry_bit_4)
			{
				uint8_t a = 0x12;
				const uint8_t expected = a + 1;

				using namespace KeemoLib;

				cpu::math::inc_uint8(a);

				Assert::AreEqual(expected, a);

				Assert::IsFalse(CHECK_FLAG(cpu::H));
				Assert::IsFalse(CHECK_FLAG(cpu::Z));
				Assert::IsFalse(CHECK_FLAG(cpu::N));
			}
			TEST_METHOD(Test_inc_uint8_with_0_result)
			{
				uint8_t a = 0xff;
				const uint8_t expected = a + 1;

				using namespace KeemoLib;

				cpu::math::inc_uint8(a);

				Assert::AreEqual(expected, a);

				//Assert::IsTrue(CHECK_FLAG(cpu::H));
				Assert::IsTrue(CHECK_FLAG(cpu::Z));
				Assert::IsFalse(CHECK_FLAG(cpu::N));
			}
			TEST_METHOD(Test_inc_uint8_with_non_0_result)
			{
				uint8_t a = (rand() % 0xfe) + 1;
				const uint8_t expected = a + 1;

				using namespace KeemoLib;

				cpu::math::inc_uint8(a);

				Assert::AreEqual(expected, a);

				//Assert::IsTrue(CHECK_FLAG(cpu::H));
				Assert::IsFalse(CHECK_FLAG(cpu::Z));
				Assert::IsFalse(CHECK_FLAG(cpu::N));
			}

			TEST_METHOD(Test_inc_a)
			{
				// Usual initialization
				const uint8_t opcode = 0x3c;
				const uint8_t x = rand() % 0xff;

				const uint8_t expected = x + 1;

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

				// emulation step
				cpu::step();

				// finally we check our expeted
				const uint8_t actual = cpu::registers.a;
				Assert::AreEqual(expected, actual);

				// we check pc steps
				Assert::IsTrue(cpu::registers.pc == (address + oplength));
			}
			TEST_METHOD(Test_inc_b)
			{
				// Usual initialization
				const uint8_t opcode = 0x04;
				const uint8_t x = rand() % 0xff;

				const uint8_t expected = x + 1;

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
				cpu::registers.b = x;

				// emulation step
				cpu::step();

				// finally we check our expeted
				const uint8_t actual = cpu::registers.b;
				Assert::AreEqual(expected, actual);

				// we check pc steps
				Assert::IsTrue(cpu::registers.pc == (address + oplength));
			}
			TEST_METHOD(Test_inc_c)
			{
				// Usual initialization
				const uint8_t opcode = 0x0c;
				const uint8_t x = rand() % 0xff;

				const uint8_t expected = x + 1;

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
				cpu::registers.c = x;

				// emulation step
				cpu::step();

				// finally we check our expeted
				const uint8_t actual = cpu::registers.c;
				Assert::AreEqual(expected, actual);

				// we check pc steps
				Assert::IsTrue(cpu::registers.pc == (address + oplength));
			}
			TEST_METHOD(Test_inc_d)
			{
				// Usual initialization
				const uint8_t opcode = 0x14;
				const uint8_t x = rand() % 0xff;

				const uint8_t expected = x + 1;

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
				cpu::registers.d = x;

				// emulation step
				cpu::step();

				// finally we check our expeted
				const uint8_t actual = cpu::registers.d;
				Assert::AreEqual(expected, actual);

				// we check pc steps
				Assert::IsTrue(cpu::registers.pc == (address + oplength));
			}
			TEST_METHOD(Test_inc_e)
			{
				// Usual initialization
				const uint8_t opcode = 0x1c;
				const uint8_t x = rand() % 0xff;

				const uint8_t expected = x + 1;

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
				cpu::registers.e = x;

				// emulation step
				cpu::step();

				// finally we check our expeted
				const uint8_t actual = cpu::registers.e;
				Assert::AreEqual(expected, actual);

				// we check pc steps
				Assert::IsTrue(cpu::registers.pc == (address + oplength));
			}
			TEST_METHOD(Test_inc_h)
			{
				// Usual initialization
				const uint8_t opcode = 0x24;
				const uint8_t x = rand() % 0xff;

				const uint8_t expected = x + 1;

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
				cpu::registers.h = x;

				// emulation step
				cpu::step();

				// finally we check our expeted
				const uint8_t actual = cpu::registers.h;
				Assert::AreEqual(expected, actual);

				// we check pc steps
				Assert::IsTrue(cpu::registers.pc == (address + oplength));
			}
			TEST_METHOD(Test_inc_l)
			{
				// Usual initialization
				const uint8_t opcode = 0x2c;
				const uint8_t x = rand() % 0xff;

				const uint8_t expected = x + 1;

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
				cpu::registers.l = x;

				// emulation step
				cpu::step();

				// finally we check our expeted
				const uint8_t actual = cpu::registers.l;
				Assert::AreEqual(expected, actual);

				// we check pc steps
				Assert::IsTrue(cpu::registers.pc == (address + oplength));
			}
			TEST_METHOD(Test_inc_hl)
			{
				// Usual initialization
				const uint8_t opcode = 0x34;
				const uint8_t x = rand() % 0xff;

				const uint8_t expected = x + 1;

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
				// Opcode arguments write to memory
				cpu::registers.hl = hl;
				memory::writeUInt8(hl, x);

				// emulation step
				cpu::step();

				// finally we check our expeted
				const uint8_t actual = memory::readUInt8(cpu::registers.hl);
				Assert::AreEqual(expected, actual);

				// we check pc steps
				Assert::IsTrue(cpu::registers.pc == (address + oplength));
			}
		};
		}
	}
}
