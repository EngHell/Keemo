#include "Bit8Math.hpp"
#include "../../includes/Cpu.hpp"
#include "MathHelpers.hpp"
#include "../../includes/Memory.hpp"

namespace KeemoLib
{
	namespace cpu
	{
		void op::add_a_n()
		{
			math::add_uint8(registers.a, memory::readUInt8(++registers.pc));
		}

		void op::add_a_a()
		{
			math::add_uint8(registers.a, registers.a);
		}

		void op::add_a_b()
		{
			math::add_uint8(registers.a, registers.b);
		}

		void op::add_a_c()
		{
			math::add_uint8(registers.a, registers.c);
		}

		void op::add_a_d()
		{
			math::add_uint8(registers.a, registers.d);
		}

		void op::add_a_e()
		{
			math::add_uint8(registers.a, registers.e);
		}

		void op::add_a_h()
		{
			math::add_uint8(registers.a, registers.h);
		}

		void op::add_a_l()
		{
			math::add_uint8(registers.a, registers.l);
		}

		void op::add_a_hl()
		{
			math::add_uint8(registers.a, memory::readUInt8(registers.hl));
		}

		void op::adc_a_n()
		{
			math::add_carry_uint8(registers.a, memory::readUInt8(++registers.pc));
		}

		void op::adc_a_a()
		{
			math::add_carry_uint8(registers.a, registers.a);
		}

		void op::adc_a_b()
		{
			math::add_carry_uint8(registers.a, registers.b);
		}

		void op::adc_a_c()
		{
			math::add_carry_uint8(registers.a, registers.c);
		}

		void op::adc_a_d()
		{
			math::add_carry_uint8(registers.a, registers.d);
		}

		void op::adc_a_e()
		{
			math::add_carry_uint8(registers.a, registers.e);
		}

		void op::adc_a_h()
		{
			math::add_carry_uint8(registers.a, registers.h);
		}

		void op::adc_a_l()
		{
			math::add_carry_uint8(registers.a, registers.l);
		}

		void op::adc_a_hl()
		{
			math::add_carry_uint8(registers.a, memory::readUInt8(registers.hl));
		}

		void op::sub_a()
		{
			math::sub_uint8(registers.a, registers.a);
		}

		void op::sub_b()
		{
			math::sub_uint8(registers.a, registers.b);
		}

		void op::sub_c()
		{
			math::sub_uint8(registers.a, registers.c);
		}

		void op::sub_d()
		{
			math::sub_uint8(registers.a, registers.d);
		}

		void op::sub_e()
		{
			math::sub_uint8(registers.a, registers.e);
		}

		void op::sub_h()
		{
			math::sub_uint8(registers.a, registers.h);
		}

		void op::sub_l()
		{
			math::sub_uint8(registers.a, registers.l);
		}

		void op::sub_hl()
		{
			math::sub_uint8(registers.a, memory::readUInt8(registers.hl));
		}

		void op::sub_n()
		{
			math::sub_uint8(registers.a, memory::readUInt8(++registers.pc));
		}

		// SBC A, n
		void op::sbc_a()
		{
			math::sub_carry_uint8(registers.a, registers.a);
		}

		void op::sbc_b()
		{
			math::sub_carry_uint8(registers.a, registers.b);
		}

		void op::sbc_c()
		{
			math::sub_carry_uint8(registers.a, registers.c);
		}

		void op::sbc_d()
		{
			math::sub_carry_uint8(registers.a, registers.d);
		}

		void op::sbc_e()
		{
			math::sub_carry_uint8(registers.a, registers.e);
		}

		void op::sbc_h()
		{
			math::sub_carry_uint8(registers.a, registers.h);
		}

		void op::sbc_l()
		{
			math::sub_carry_uint8(registers.a, registers.l);
		}

		void op::sbc_hl()
		{
			math::sub_carry_uint8(registers.a, memory::readUInt8(registers.hl));
		}

		void op::sbc_n()
		{
			math::sub_carry_uint8(registers.a, memory::readUInt8(++registers.pc));
		}


		// AND n
		void op::and_a()
		{
			math::and_uint8(registers.a, registers.a);
		}

		void op::and_b()
		{
			math::and_uint8(registers.a, registers.b);
		}

		void op::and_c()
		{
			math::and_uint8(registers.a, registers.c);
		}

		void op::and_d()
		{
			math::and_uint8(registers.a, registers.d);
		}

		void op::and_e()
		{
			math::and_uint8(registers.a, registers.e);
		}

		void op::and_h()
		{
			math::and_uint8(registers.a, registers.h);
		}

		void op::and_l()
		{
			math::and_uint8(registers.a, registers.l);
		}

		void op::and_hl()
		{
			math::and_uint8(registers.a, memory::readUInt8(registers.hl));
		}

		void op::and_n()
		{
			math::and_uint8(registers.a, memory::readUInt8(++registers.pc));
		}

		void op::or_a()
		{
			math::or_uint8(registers.a , registers.a);
		}

		void op::or_b()
		{
			math::or_uint8(registers.a , registers.b);
		}

		void op::or_c()
		{
			math::or_uint8(registers.a , registers.c);
		}

		void op::or_d()
		{
			math::or_uint8(registers.a , registers.d);
		}

		void op::or_e()
		{
			math::or_uint8(registers.a , registers.e);
		}

		void op::or_h()
		{
			math::or_uint8(registers.a , registers.h);
		}

		void op::or_l()
		{
			math::or_uint8(registers.a , registers.l);
		}

		void op::or_hl()
		{
			math::or_uint8(registers.a , memory::readUInt8(registers.hl));
		}

		void op::or_n()
		{
			math::or_uint8(registers.a , memory::readUInt8(++registers.pc));
		}

		void op::xor_a()
		{
			math::xor_uint8(registers.a);
		}

		void op::xor_b()
		{
			math::xor_uint8(registers.b);
		}

		void op::xor_c()
		{
			math::xor_uint8(registers.c);
		}

		void op::xor_d()
		{
			math::xor_uint8(registers.d);
		}

		void op::xor_e()
		{
			math::xor_uint8(registers.e);
		}

		void op::xor_h()
		{
			math::xor_uint8(registers.h);
		}

		void op::xor_l()
		{
			math::xor_uint8(registers.l);
		}

		void op::xor_hl()
		{
			math::xor_uint8(memory::readUInt8(registers.hl));
		}

		void op::xor_n()
		{
			math::xor_uint8(memory::readUInt8(++registers.pc));
		}

		void op::cp_a()
		{
			math::cp_uint8(registers.a, registers.a);
		}

		void op::cp_b()
		{
			math::cp_uint8(registers.a, registers.b);
		}

		void op::cp_c()
		{
			math::cp_uint8(registers.a, registers.c);
		}

		void op::cp_d()
		{
			math::cp_uint8(registers.a, registers.d);
		}

		void op::cp_e()
		{
			math::cp_uint8(registers.a, registers.e);
		}

		void op::cp_h()
		{
			math::cp_uint8(registers.a, registers.h);
		}

		void op::cp_l()
		{
			math::cp_uint8(registers.a, registers.l);
		}

		void op::cp_hl()
		{
			math::cp_uint8(registers.a, memory::readUInt8(registers.hl));
		}

		void op::cp_n()
		{
			math::cp_uint8(registers.a, memory::readUInt8(++registers.pc));
		}

		void op::inc_a()
		{
			math::inc_uint8(registers.a);
		}

		void op::inc_b()
		{
			math::inc_uint8(registers.b);
		}

		void op::inc_c()
		{
			math::inc_uint8(registers.c);
		}

		void op::inc_d()
		{
			math::inc_uint8(registers.d);
		}

		void op::inc_e()
		{
			math::inc_uint8(registers.e);
		}

		void op::inc_h()
		{
			math::inc_uint8(registers.h);
		}

		void op::inc_l()
		{
			math::inc_uint8(registers.l);
		}

		void op::inc_hl()
		{
			auto a = memory::readUInt8(registers.hl);
			math::inc_uint8(a);
			memory::writeUInt8(registers.hl, a);
		}
	}
}
