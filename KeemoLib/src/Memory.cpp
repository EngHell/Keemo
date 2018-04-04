#include "../includes/Memory.h"

namespace KeemoLib
{
	namespace memory
	{
		uint8_t rom[ROM_SIZE];
		uint8_t vram[VRAM_SIZE];
		uint8_t sram[SRAM_SIZE];
		uint8_t iram[IRAM_SIZE];
		uint8_t oam[OAM_SIZE];
		uint8_t empty1[EMPTY1_SIZE];
		uint8_t io[IO_SIZE];
		uint8_t empty2[EMPTY2_SIZE];
		uint8_t hram[HRAM_SIZE];
	}
}

uint8_t KeemoLib::memory::readMemory(const uint16_t address)
{
	using namespace KeemoLib::memory;

	if(address < ROM_LIMIT)
	{
		return rom[address];
	}
	else if (address < VRAM_LIMIT)
	{
		return vram[address - ROM_LIMIT];
	}
	else if (address < SRAM_LIMIT)
	{
		return sram[address - VRAM_LIMIT];
	}
	else if ( address < IRAM_LIMIT)
	{
		return iram[address - SRAM_LIMIT];
	}
	else if (address < ECHO_IRAM_LIMIT)
	{
		return iram[address - IRAM_LIMIT];
	}
	else if (address < OAM_LIMIT)
	{
		return oam[address - ECHO_IRAM_LIMIT];
	}
	else if(address < EMPTY1_LIMIT)
	{
		return empty1[address - OAM_LIMIT];
	}
	else if(address < IO_LIMIT)
	{
		return io[address - EMPTY1_LIMIT];
	}
	else if(address < EMPTY2_LIMIT)
	{
		return io[address - IO_LIMIT];
	}
	else if(address < HRAM_LIMIT)
	{
		return io[address - EMPTY2_LIMIT];
	}
	
	return 0;
}