#include "Bit8Loads.hpp"
#include "../../includes/Cpu.hpp"
#include "../../includes/Memory.hpp"

using namespace KeemoLib;

/*
 * 8-Bit Loads
 */

/*
 * LD nn,n
 * 
 * nn
 */
void cpu::op::ld_b_n()
{
	cpu::registers.b = memory::readUInt8(++registers.pc);
}

void cpu::op::ld_c_n()
{
	registers.c = memory::readUInt8(++registers.pc);
}

void cpu::op::ld_d_n()
{
	registers.d = memory::readUInt8(++registers.pc);
}

void cpu::op::ld_e_n()
{
	registers.e = memory::readUInt8(++registers.pc);
}

void cpu::op::ld_h_n()
{
	registers.h = memory::readUInt8(++registers.pc);
}

void cpu::op::ld_l_n()
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

void cpu::op::ld_a_bc()
{
	registers.a = memory::readUInt8(registers.bc);
}

void cpu::op::ld_a_de()
{
	registers.a = memory::readUInt8(registers.de);
}

void cpu::op::ld_a_hl()
{
	registers.a = memory::readUInt8(registers.hl);
}

void cpu::op::ld_a_n()
{
	registers.a = memory::readUInt8(++registers.pc);
}

void cpu::op::ld_a_nn()
{
	registers.a = memory::readUInt8(memory::readUInt16(++registers.pc));
	//one more plus as we take the two adjacent
	registers.pc++;
}

void cpu::op::ld_a_ff_c()
{
	registers.a = memory::readUInt8(0xff00 + registers.c);
}

/*
* LD B,r2
*/
void cpu::op::ld_b_a()
{
	registers.b = registers.a;
}

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
void cpu::op::ld_c_a()
{
	registers.c = registers.a;
}

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
void cpu::op::ld_d_a()
{
	registers.d = registers.a;
}

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
void cpu::op::ld_e_a()
{
	registers.e = registers.a;
}

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
* LD H,r2
*/
void cpu::op::ld_h_a()
{
	registers.h = registers.a;
}

void cpu::op::ld_h_b()
{
	registers.h = registers.b;
}

void cpu::op::ld_h_c()
{
	registers.h = registers.c;
}

void cpu::op::ld_h_d()
{
	registers.h = registers.d;
}

void cpu::op::ld_h_e()
{
	registers.h = registers.e;
}

void cpu::op::ld_h_h()
{
	registers.h = registers.h;
}

void cpu::op::ld_h_l()
{
	registers.h = registers.l;
}

void cpu::op::ld_h_hl()
{
	registers.h = memory::readUInt8(registers.hl);
}


/*
* LD L,r2
*/
void cpu::op::ld_l_a()
{
	registers.l = registers.a;
}

void cpu::op::ld_l_b()
{
	registers.l = registers.b;
}

void cpu::op::ld_l_c()
{
	registers.l = registers.c;
}

void cpu::op::ld_l_d()
{
	registers.l = registers.d;
}

void cpu::op::ld_l_e()
{
	registers.l = registers.e;
}

void cpu::op::ld_l_h()
{
	registers.l = registers.h;
}

void cpu::op::ld_l_l()
{
	registers.l = registers.l;
}

void cpu::op::ld_l_hl()
{
	registers.l = memory::readUInt8(registers.hl);
}

/*
* LD (HL),r2
*/
void cpu::op::ld_hl_a()
{
	memory::writeUInt8(registers.hl, registers.a);
}

void cpu::op::ld_hl_b()
{
	memory::writeUInt8(registers.hl, registers.b);
}

void cpu::op::ld_hl_c()
{
	memory::writeUInt8(registers.hl, registers.c);
}

void cpu::op::ld_hl_d()
{
	memory::writeUInt8(registers.hl, registers.d);
}

void cpu::op::ld_hl_e()
{
	memory::writeUInt8(registers.hl, registers.e);
}

void cpu::op::ld_hl_h()
{
	memory::writeUInt8(registers.hl, registers.h);
}

void cpu::op::ld_hl_l()
{
	memory::writeUInt8(registers.hl, registers.l);
}

void cpu::op::ld_hl_n()
{
	memory::writeUInt8(registers.hl, memory::readUInt8(++registers.pc));
}

/*
* LD (BC),r2
*/
void cpu::op::ld_bc_a()
{
	memory::writeUInt8(registers.bc, registers.a);
}

/*
* LD (DE),r2
*/
void cpu::op::ld_de_a()
{
	memory::writeUInt8(registers.de, registers.a);
}

/*
* LD (nn),r2
*/
void cpu::op::ld_nn_a()
{
	memory::writeUInt8(memory::readUInt16(++registers.pc), registers.a);

	//this since this is a 3 byte op, so we do 2 inside and the last ++ is done in cpu::step()
	registers.pc++;
}

/*
* LD (c),r2
*/
void cpu::op::ld_ff_c_a()
{
	memory::writeUInt8(0xff00 + registers.c, registers.a);
}

/*
* LDX r1,r2
*/
void cpu::op::ldd_a_hl()
{
	registers.a = memory::readUInt8(registers.hl--);
}

void cpu::op::ldd_hl_a()
{
	memory::writeUInt8(registers.hl--, registers.a);
}

void cpu::op::ldi_a_hl()
{
	registers.a = memory::readUInt8(registers.hl++);
}

void cpu::op::ldi_hl_a()
{
	memory::writeUInt8(registers.hl++, registers.a);
}

void cpu::op::ld_ff_n_a()
{
	memory::writeUInt8(0xff00 + memory::readUInt8(++registers.pc), registers.a);
}

void cpu::op::ld_a_ff_n()
{
	registers.a = memory::readUInt8(0xff00 + memory::readUInt8(++registers.pc));
}