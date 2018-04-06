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

		/***********************************************************************
		 * LD r1,r2
		 ***********************************************************************/

		/*
		 * LD A,r2
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
		/*
		 * LD B,r2
		 */
	case 0x40:
		op::ld_b_b();
		break;
	case 0x41:
		op::ld_b_c();
		break;
	case 0x42:
		op::ld_b_d();
		break;
	case 0x43:
		op::ld_b_e();
		break;
	case 0x44:
		op::ld_b_h();
		break;
	case 0x45:
		op::ld_b_l();
		break;
	case 0x46:
		op::ld_b_hl();
		break;
		/*
		 * LD C,r2
		 */
	case 0x48:
		op::ld_c_b();
		break;
	case 0x49:
		op::ld_c_c();
		break;
	case 0x4a:
		op::ld_c_d();
		break;
	case 0x4b:
		op::ld_c_e();
		break;
	case 0x4c:
		op::ld_c_h();
		break;
	case 0x4d:
		op::ld_c_l();
		break;
	case 0x4e:
		op::ld_c_hl();
		break;
		/**
		 * LD D,r2
		 */
	case 0x50:
		op::ld_d_b();
		break;
	case 0x51:
		op::ld_d_c();
		break;
	case 0x52:
		op::ld_d_d();
		break;
	case 0x53:
		op::ld_d_e();
		break;
	case 0x54:
		op::ld_d_h();
		break;
	case 0x55:
		op::ld_d_l();
		break;
	case 0x56:
		op::ld_d_hl();
		break;

		/**
		* LD E,r2
		*/
	case 0x58:
		op::ld_e_b();
		break;
	case 0x59:
		op::ld_e_c();
		break;
	case 0x5a:
		op::ld_e_d();
		break;
	case 0x5b:
		op::ld_e_e();
		break;
	case 0x5c:
		op::ld_e_h();
		break;
	case 0x5d:
		op::ld_e_l();
		break;
	case 0x5e:
		op::ld_e_hl();
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

/*
 * LD A,r2
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
* LD B,r2
*/
void cpu::op::ld_b_b()
{
	registers.b = registers.b;
}

void cpu::op::ld_b_c()
{
	registers.b = registers.c;
}

void cpu::op::ld_b_d()
{
	registers.b = registers.d;
}

void cpu::op::ld_b_e()
{
	registers.b = registers.e;
}

void cpu::op::ld_b_h()
{
	registers.b = registers.h;
}

void cpu::op::ld_b_l()
{
	registers.b = registers.l;
}

void cpu::op::ld_b_hl()
{
	registers.b = memory::readUInt8(registers.hl);
}

/*
* LD C,r2
*/
void cpu::op::ld_c_b()
{
	registers.c = registers.b;
}

void cpu::op::ld_c_c()
{
	registers.c = registers.c;
}

void cpu::op::ld_c_d()
{
	registers.c = registers.d;
}

void cpu::op::ld_c_e()
{
	registers.c = registers.e;
}

void cpu::op::ld_c_h()
{
	registers.c = registers.h;
}

void cpu::op::ld_c_l()
{
	registers.c = registers.l;
}

void cpu::op::ld_c_hl()
{
	registers.c = memory::readUInt8(registers.hl);
}

/*
* LD D,r2
*/
void cpu::op::ld_d_b()
{
	registers.d = registers.b;
}

void cpu::op::ld_d_c()
{
	registers.d = registers.c;
}

void cpu::op::ld_d_d()
{
	registers.d = registers.d;
}

void cpu::op::ld_d_e()
{
	registers.d = registers.e;
}

void cpu::op::ld_d_h()
{
	registers.d = registers.h;
}

void cpu::op::ld_d_l()
{
	registers.d = registers.l;
}

void cpu::op::ld_d_hl()
{
	registers.d = memory::readUInt8(registers.hl);
}

/*
* LD E,r2
*/
void cpu::op::ld_e_b()
{
	registers.e = registers.b;
}

void cpu::op::ld_e_c()
{
	registers.e = registers.c;
}

void cpu::op::ld_e_d()
{
	registers.e = registers.d;
}

void cpu::op::ld_e_e()
{
	registers.e = registers.e;
}

void cpu::op::ld_e_h()
{
	registers.e = registers.h;
}

void cpu::op::ld_e_l()
{
	registers.e = registers.l;
}

void cpu::op::ld_e_hl()
{
	registers.e = memory::readUInt8(registers.hl);
}

/*
 * NOP
 */
void cpu::op::NOP()
{
	++registers.pc;
}