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
	}
}
