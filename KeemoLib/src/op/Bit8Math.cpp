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
	}
}
