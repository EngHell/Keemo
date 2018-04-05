#include "../includes/Cpu.hpp"
#include "../includes/Memory.hpp"

namespace KeemoLib
{
	namespace cpu
	{
		uint8_t opcode;
		Registers registers;
	}
}

using namespace KeemoLib;


void cpu::step()
{
	opcode = KeemoLib::memory::readUInt8(registers.pc);

	switch (opcode)
	{

		/**
		 * 8 bit loads.
		 */

		/**
		 * LD nn,n
		 */
	case 0x06:
		op::LD_B_n();
		break;
	case 0x0e:
		op::LD_C_n();
		break;
	case 0x16:
		op::LD_D_n();
		break;
	case 0x1e:
		op::LD_E_n();
		break;
	case 0x26:
		op::LD_H_n();
		break;
	case 0x2e:
		op::LD_L_n();
		break;

		/*
		 * LD r1,r2
		 */
	case 0x7f:
		op::ld_a_a();
		break;
	case 0x78:
		op::ld_a_b();
		break;
	case 0x79:
		op::ld_a_c();
		break;
	case 0x7a:
		op::ld_a_d();
		break;
	case 0x7b:
		op::ld_a_e();
		break;
	case 0x7c:
		op::ld_a_h();
		break;
	case 0x7d:
		op::ld_a_l();
		break;
	case 0x7e:
		op::ld_a_hl();
		break;
	default:
		op::NOP();
		break;
	}

	// I'm going to assume that each function increments the register
	// only when they relly on continuous bits to the pc
	// this means, i just need to increace one more time here, and
	// avoid a shitton of ++registers.pc at the end of each opcode function
	++registers.pc;
}

/*
 * 8-Bit Loads
 */

/*
 * LD nn,n
 * 
 * nn
 */
void cpu::op::LD_B_n()
{
	registers.b = memory::readUInt8(++registers.pc);
}

void cpu::op::LD_C_n()
{
	registers.c = memory::readUInt8(++registers.pc);
}

void cpu::op::LD_D_n()
{
	registers.d = memory::readUInt8(++registers.pc);
}

void cpu::op::LD_E_n()
{
	registers.e = memory::readUInt8(++registers.pc);
}

void cpu::op::LD_H_n()
{
	registers.h = memory::readUInt8(++registers.pc);
}

void cpu::op::LD_L_n()
{
	registers.l = memory::readUInt8(++registers.pc);
}


/*
 * LD r1,r2
 * 
 * r1 = r2
 */
void cpu::op::ld_a_a()
{
	registers.a = registers.a;
}

void cpu::op::ld_a_b()
{
	registers.a = registers.b;
}

void cpu::op::ld_a_c()
{
	registers.a = registers.c;
}

void cpu::op::ld_a_d()
{
	registers.a = registers.d;
}

void cpu::op::ld_a_e()
{
	registers.a = registers.e;
}

void cpu::op::ld_a_h()
{
	registers.a = registers.h;
}

void cpu::op::ld_a_l()
{
	registers.a = registers.l;
}

void cpu::op::ld_a_hl()
{
	registers.a = memory::readUInt8(registers.hl);
}

/*
 * NOP
 */
void cpu::op::NOP()
{
	++registers.pc;
}