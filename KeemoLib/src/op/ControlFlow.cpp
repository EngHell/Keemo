#include "ControlFlow.hpp"
#include "../../includes/Cpu.hpp"
#include "../../includes/Memory.hpp"

using namespace KeemoLib;

void cpu::op::jp_nn()
{
	registers.pc = memory::readUInt16(++registers.pc);
	raise_pc = false;
}

void KeemoLib::cpu::op::jp_nz_nn()
{
	if(!CHECK_FLAG(Flags::Z))
	{
		raise_pc = false;
		registers.pc = memory::readUInt16(++registers.pc);
	} else
	{
		registers.pc += 2;
	}
}
