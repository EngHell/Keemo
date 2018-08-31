#include "../includes/Core.hpp"
#include "../includes/Cartridge.hpp"
#include "../includes/Cpu.hpp"


bool KeemoLib::Core::bootUp(std::string path)
{
	bool sucess = false;

	if(cartridge::loadCartridge(path))
	{
		cpu::registers.a = 0x01;
		cpu::registers.f = 0xb0;
		cpu::registers.bc = 0x13;
		cpu::registers.de = 0xd8;
		cpu::registers.hl = 0x14d;

		cpu::registers.sp = 0xffff;
		cpu::registers.pc = 0x100;

		// TODO: add the initialization for timers, screen, etc etc when they re ready

		sucess = true;
	}

	return sucess;
}
