#include "Cartridge.hpp"
#include "Memory.hpp"
#include <fstream>
#include <sys/stat.h>
#include "Cpu.hpp"

namespace KeemoLib
{
	namespace cartridge
	{
		CartridgeType::Const type;
		uint16_t size;
		std::string title;
	}
}

bool KeemoLib::cartridge::loadCartridge(std::string path)
{
	bool success = false;

	if(loadCartridgeToMemory(path))
	{
		if(readCartridgeType())
		{
			readCartrideTitle();
			readRamSize();

			success = true;
		}
	}

	return success;
}

bool KeemoLib::cartridge::loadCartridgeToMemory(std::string path)
{
	bool success = false;

	std::streampos stream_size;
	std::ifstream file(path, std::ios::in | std::ios::binary);

	if (file.is_open())
	{
		struct stat stat_buf;
		int rc = stat(path.c_str(), &stat_buf);

		if(!rc)
		{
			size = stat_buf.st_size;

			if(size<= Consts::MAX_CARTRIDGE_SIZE)
			{

				file.seekg(0, std::ios::beg);
			
				file.read(reinterpret_cast<char*>(memory::rom), size);

				success = true;
			}

			

		}
		
		file.close();

	}

	return success;
	
}

void KeemoLib::cartridge::readCartrideTitle()
{
	const size_t TITLE_LIMIT = 17;

	char buff[TITLE_LIMIT];

	for(uint16_t i = Consts::ROM_TITLE_START_OFFSET; i <= Consts::ROM_TITLE_END_OFFSET; i++)
	{
		buff[i- Consts::ROM_TITLE_START_OFFSET] = memory::rom[i];
	}

	// just in case :p
	buff[TITLE_LIMIT-1]= '\0';

	title = std::string{buff, TITLE_LIMIT};
}

bool KeemoLib::cartridge::readCartridgeType()
{
	bool supported  = false;
	uint8_t SUPPORTED_MB[0xff] = {0};

	SUPPORTED_MB[Consts::ROM_ONLY] = 1;
	auto romType = memory::rom[Consts::ROM_TYPE_OFFSET];

	if(SUPPORTED_MB[romType])
	{
		supported = true;
		type = static_cast<CartridgeType::Const>(romType);	
	}

	return supported;
}

void KeemoLib::cartridge::readRamSize()
{
	KeemoLib::cpu::ram_size = KeemoLib::memory::rom[Consts::RAM_SIZE_OFFSET];
}
