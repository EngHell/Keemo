#include "../includes/Memory.hpp"

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

uint8_t KeemoLib::memory::readUInt8(const uint16_t address)
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
		return empty2[address - IO_LIMIT];
	}
	else if(address < HRAM_LIMIT)
	{
		return hram[address - EMPTY2_LIMIT];
	}
	
	return 0;
}

void KeemoLib::memory::writeUInt8(const uint16_t address, const uint8_t value)
{
	using namespace KeemoLib::memory;

	if (address < ROM_LIMIT)
	{
		 rom[address] = value;
	}
	else if (address < VRAM_LIMIT)
	{
		 vram[address - ROM_LIMIT] = value;
	}
	else if (address < SRAM_LIMIT)
	{
		 sram[address - VRAM_LIMIT] = value;
	}
	else if (address < IRAM_LIMIT)
	{
		 iram[address - SRAM_LIMIT] = value;
	}
	else if (address < ECHO_IRAM_LIMIT)
	{
		 iram[address - IRAM_LIMIT] = value;
	}
	else if (address < OAM_LIMIT)
	{
		 oam[address - ECHO_IRAM_LIMIT] = value;
	}
	else if (address < EMPTY1_LIMIT)
	{
		 empty1[address - OAM_LIMIT] = value;
	}
	else if (address < IO_LIMIT)
	{
		 io[address - EMPTY1_LIMIT] = value;
	}
	else if (address < EMPTY2_LIMIT)
	{
		 empty2[address - IO_LIMIT] = value;
	}
	else if (address < HRAM_LIMIT)
	{
		 hram[address - EMPTY2_LIMIT] = value;
	}
}
