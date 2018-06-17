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



