#include "ControlFlow.hpp"
#include "../../includes/Cpu.hpp"
#include "../../includes/Memory.hpp"

using namespace KeemoLib;

void cpu::op::jp_nn()
{
	registers.pc = memory::readUInt16(++registers.pc);
	raise_pc = false;
}