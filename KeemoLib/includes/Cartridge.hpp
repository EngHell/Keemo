#pragma once
#include <cstdint>
#include <string>

namespace KeemoLib
{
	namespace cartridge
	{
		namespace Consts
		{
			constexpr const uint16_t MAX_CARTRIDGE_SIZE = 0x8000;
			constexpr const uint16_t ROM_TITLE_START_OFFSET = 0x134;
			constexpr const uint16_t ROM_TITLE_END_OFFSET = 0x142;
			constexpr const uint16_t ROM_TYPE_OFFSET = 0x147;


			constexpr const uint8_t ROM_ONLY = 0x0;
			constexpr const uint8_t ROM_MBC1 = 0x1;
			constexpr const uint8_t ROM_MBC1_RAM = 0x2;
			constexpr const uint8_t ROM_MBC1_RAM_BAT = 0x3;
			constexpr const uint8_t ROM_MBC2 = 0x5;
			constexpr const uint8_t ROM_MBC2_BATTERY = 0x06;
			constexpr const uint8_t ROM_RAM = 0x08;
			constexpr const uint8_t ROM_RAM_BATTERY = 0x09;
			constexpr const uint8_t ROM_MMM01 = 0xb;
			constexpr const uint8_t ROM_MMM01_SRAM = 0xc;
			constexpr const uint8_t ROM_MMM01_SRAM_BATT = 0xd;
			constexpr const uint8_t ROM_MBC3_TIMER_BATT = 0xf;
			constexpr const uint8_t ROM_MBC3_TIMER_RAM_BATT = 0x10;
			constexpr const uint8_t ROM_MBC = 0x11;
			constexpr const uint8_t ROM_MBC3_RAM = 0x12;
			constexpr const uint8_t ROM_MBC3_RAM_BAT = 0x13;
			constexpr const uint8_t ROM_MBC5 = 0x19;
			constexpr const uint8_t ROM_MBC5_RAM = 0x1a;
			constexpr const uint8_t ROM_MBC5_RAM_BAT = 0x1b;
			constexpr const uint8_t ROM_MBC5_RUMBLE = 0x1c;
			constexpr const uint8_t ROM_MBC5_RUMBLE_SRAM = 0x1d;
			constexpr const uint8_t ROM_MBC5_RUMBLE_SRAM_BAT = 0x1e;
			constexpr const uint8_t POCKET_CAMERA = 0x1f;
			constexpr const uint8_t BANDAI_TAMA5 = 0xfd;
			constexpr const uint8_t HUDSON_HUC_3 = 0xfe;
			constexpr const uint8_t HUDSON_HUC_1 = 0xff;
		}

		/*
		 * Enums
		 */
		struct CartridgeType
		{
			enum Const
			{
				rom_only = Consts::ROM_ONLY,
				rom_mbc1 = Consts::ROM_MBC1,
				rom_mbc1_ram = Consts::ROM_MBC1_RAM,
				rom_mbc1_ram_bat = Consts::ROM_MBC1_RAM_BAT,
				rom_mbc2 = Consts::ROM_MBC2,
				rom_mbc2_battery = Consts::ROM_MBC2_BATTERY,
				rom_ram = Consts::ROM_RAM,
				rom_ram_battery = Consts::ROM_RAM_BATTERY,
				rom_mmm01 = Consts::ROM_MMM01,
				rom_mmm01_sram = Consts::ROM_MMM01_SRAM,
				rom_mmm01_sram_batt = Consts::ROM_MMM01_SRAM_BATT,
				rom_mbc3_timer_batt = Consts::ROM_MBC3_TIMER_BATT,
				rom_mbc3_timer_ram_batt = Consts::ROM_MBC3_TIMER_RAM_BATT,
				rom_mbc = Consts::ROM_MBC,
				rom_mbc3_ram = Consts::ROM_MBC3_RAM,
				rom_mbc3_ram_bat = Consts::ROM_MBC3_RAM_BAT,
				rom_mbc5 = Consts::ROM_MBC5,
				rom_mbc5_ram = Consts::ROM_MBC5_RAM,
				rom_mbc5_ram_bat = Consts::ROM_MBC5_RAM_BAT,
				rom_mbc5_rumble = Consts::ROM_MBC5_RUMBLE,
				rom_mbc5_rumble_sram = Consts::ROM_MBC5_RUMBLE_SRAM,
				rom_mbc5_rumble_sram_bat = Consts::ROM_MBC5_RUMBLE_SRAM_BAT,
				pocket_camera = Consts::POCKET_CAMERA,
				bandai_tama5 = Consts::BANDAI_TAMA5,
				hudson_huc_3 = Consts::HUDSON_HUC_3,
				hudson_huc_1 = Consts::HUDSON_HUC_1
			};
		};


		//properties
		extern CartridgeType::Const type;
		extern uint16_t size;
		extern std::string title;

		/*
		 * Loads rom and processes all
		 */
		bool loadCartridge(std::string path);

		/*
		 * Loads rom file to memory::rom
		 */
		bool loadCartridgeToMemory(std::string path);

		/*
		 * Read's rom title
		 */
		void readCartrideTitle();
		bool readCartridgeType();
	}
}
