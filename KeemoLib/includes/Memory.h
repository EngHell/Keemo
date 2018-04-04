#pragma once
#include "Cpu.h"

namespace KeemoLib
{
	namespace memory
	{

		constexpr const int RAM_SIZE = 0x2000; // 8kBi
		constexpr const int ROM_SIZE = 0x8000; // 32kBi

		uint8_t sram[RAM_SIZE];
		uint8_t rom[ROM_SIZE];
	}
}