#include "Bit16Loads.hpp"
#include "../../includes/Cpu.hpp"
#include "../../includes/Memory.hpp"

using namespace KeemoLib;

/*
 * LD n,nn
 */
void cpu::op::ld_bc_nn()
{
	registers.bc = memory::readUInt16(++registers.pc);

	// extra hop cuz 3 bytes op
	++registers.pc;
}

void cpu::op::ld_de_nn()
{
	registers.de = memory::readUInt16(++registers.pc);
	++registers.pc;
}

void cpu::op::ld_hl_nn()
{
	registers.hl = memory::readUInt16(++registers.pc);
	++registers.pc;
}

void cpu::op::ld_sp_nn()
{
	registers.sp = memory::readUInt16(++registers.pc);
	++registers.pc;
}

void cpu::op::ld_sp_hl()
{
	registers.sp = registers.hl;
}

void cpu::op::ld_hl_sp_n()
{
	const uint16_t n = memory::readUInt8(++registers.pc);
	const uint16_t result = registers.sp + n;

	registers.hl = result;

	CLEAR_FLAGS( Z | N | H | C);

	if(((registers.sp & 0xff) + (n & 0xff)) > 0xff)
		SET_FLAGS(C);

	if(((registers.sp & 0x0f) + (n & 0x0f)) > 0x0f)
		SET_FLAGS(H);
}



