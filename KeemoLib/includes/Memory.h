#pragma once
#include <cstdint>
#include <climits>

namespace KeemoLib
{
	namespace memory
	{

		constexpr const int ROM_SIZE = 0x8000; // 32kBi
		constexpr const int VRAM_SIZE = 0x2000; // 8kBi
		constexpr const int SRAM_SIZE = 0x2000; // 8kBi
		constexpr const int IRAM_SIZE = 0x2000; // 8kBi
		constexpr const int ECHO_IRAM_SIZE = 0x1e00; //
		constexpr const int OAM_SIZE = 0xa0; // 160
		constexpr const int EMPTY1_SIZE = 0x60; // 96
		constexpr const int IO_SIZE = 0x4c; // 76
		constexpr const int EMPTY2_SIZE = 0x34; // 52
		constexpr const int HRAM_SIZE = 0x7f; // 127

		constexpr const int ROM_LIMIT = ROM_SIZE;
		constexpr const int VRAM_LIMIT = ROM_LIMIT + VRAM_SIZE;
		constexpr const int SRAM_LIMIT = VRAM_LIMIT + SRAM_SIZE;
		constexpr const int IRAM_LIMIT = SRAM_LIMIT + IRAM_SIZE;
		constexpr const int ECHO_IRAM_LIMIT = IRAM_LIMIT + ECHO_IRAM_SIZE;
		constexpr const int OAM_LIMIT = ECHO_IRAM_LIMIT + OAM_SIZE;
		constexpr const int EMPTY1_LIMIT = OAM_LIMIT + EMPTY1_SIZE;
		constexpr const int IO_LIMIT = EMPTY1_LIMIT + IO_SIZE;
		constexpr const int EMPTY2_LIMIT = IO_LIMIT + EMPTY2_SIZE;
		constexpr const int HRAM_LIMIT = EMPTY2_LIMIT + HRAM_SIZE;

		extern uint8_t rom[ROM_SIZE];
		extern uint8_t vram[VRAM_SIZE];
		extern uint8_t sram[SRAM_SIZE];
		extern uint8_t iram[IRAM_SIZE];
		extern uint8_t oam[OAM_SIZE];
		extern uint8_t empty1[EMPTY1_SIZE];
		extern uint8_t io[IO_SIZE];
		extern uint8_t empty2[EMPTY2_SIZE];
		extern uint8_t hram[HRAM_SIZE];

		uint8_t readUInt8(const uint16_t address);
		void writeUInt8(const uint16_t address, const uint8_t value);
	}
}
