﻿#include "Bit16Loads.hpp"
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
