#include "KeemoUi.hpp"
#include "imgui/imgui.h"
#include "Cpu.hpp"
#include <string>
#include "Memory.hpp"


void ui::showDebugger(bool* show)
{
	using namespace  ImGui;
	ImGui::Begin(debuggerId, show, ImGuiWindowFlags_None);

	// debug controls
	ImGui::Button("Play");
	ImGui::SameLine();
	ImGui::Button("Pause");
	ImGui::SameLine();
	ImGui::Button("Restart");

	static const size_t buffMax = 8;
	static char registerBuff[buffMax];
	static bool showInHex = true;
	static uint16_t evaluate1 = 0;
	static uint16_t evaluate2 = 0;
	static uint8_t result1 = 0;
	static uint16_t result2 = 0;


	// register display
	Separator();
	Text("Registers");
	Separator();

	ImGui::Checkbox("Format Hex", &showInHex);
	Separator();

	Columns(3, "RegistersCol1");
	ui::InputUint8("A", &KeemoLib::cpu::registers.a, registerBuff, buffMax, &showInHex);
	ui::InputUint8("B", &KeemoLib::cpu::registers.b, registerBuff, buffMax, &showInHex);
	ui::InputUint8("D", &KeemoLib::cpu::registers.d, registerBuff, buffMax, &showInHex);
	ui::InputUint8("H", &KeemoLib::cpu::registers.h, registerBuff, buffMax, &showInHex);
	NextColumn();

	ui::InputUint8("F", &KeemoLib::cpu::registers.f, registerBuff, buffMax, &showInHex);
	ui::InputUint8("C", &KeemoLib::cpu::registers.c, registerBuff, buffMax, &showInHex);
	ui::InputUint8("E", &KeemoLib::cpu::registers.e, registerBuff, buffMax, &showInHex);
	ui::InputUint8("L", &KeemoLib::cpu::registers.l, registerBuff, buffMax, &showInHex);
	NextColumn();

	ui::InputUint16("AF", &KeemoLib::cpu::registers.af, registerBuff, buffMax, &showInHex);
	ui::InputUint16("BC", &KeemoLib::cpu::registers.bc, registerBuff, buffMax, &showInHex);
	ui::InputUint16("DE", &KeemoLib::cpu::registers.de, registerBuff, buffMax, &showInHex);
	ui::InputUint16("HL", &KeemoLib::cpu::registers.hl, registerBuff, buffMax, &showInHex);

	Columns(1);
	Separator();

	Columns(2, "RegistersCol2");
	ui::InputUint16("PC", &KeemoLib::cpu::registers.pc, registerBuff, buffMax, &showInHex);
	NextColumn();

	ui::InputUint16("SP", &KeemoLib::cpu::registers.sp, registerBuff, buffMax, &showInHex);

	Columns(1);
	Separator();

	Columns(2, "EvaluateCol1");
	ui::InputUint16("Get uint8", &evaluate1, registerBuff, buffMax, &showInHex);
	NextColumn();
	result1 = KeemoLib::memory::readUInt8(evaluate1);
	if(ui::InputUint8("Result1",&result1, registerBuff, buffMax, &showInHex))
	{
		KeemoLib::memory::writeUInt8(evaluate1, result1);
	}
	NextColumn();

	ui::InputUint16("Get uint16", &evaluate2, registerBuff, buffMax, &showInHex);
	NextColumn();
	result2 = KeemoLib::memory::readUInt16(evaluate2);
	if(ui::InputUint16("Result2",&result2, registerBuff, buffMax, &showInHex))
	{
		KeemoLib::memory::writeUInt16(evaluate2, result2);
	}
	Columns(1);
	Separator();

	InputUint8("OPCode",&KeemoLib::cpu::opcode, registerBuff, buffMax, &showInHex);	

	ImGui::End();
}

bool ui::InputUint8(const char* label, uint8_t* uint, char* buff, size_t buffSize, bool* hex)
{
	static const char * format;

	format ="%u";

	if(hex)
	{
		if(*hex)
		{
			format = "0x%x";
		}
	}

	
	snprintf(buff, buffSize, format, *uint);

	if(ImGui::InputText(label, buff, buffSize))
	{
		unsigned long r = strtoul(buff, nullptr, 0);
		if(r > UINT8_MAX)
		{
			r = UINT8_MAX;
		}
		else if (r < 0)
		{
			r = 0 ;
		}
		*uint = uint8_t{r};
		return true;
	}

	return false;
}

bool ui::InputUint16(const char* label, uint16_t* uint, char*buff, size_t buff_size, bool* hex)
{
	static const char * format;

	format ="%u";

	if(hex)
	{
		if(*hex)
		{
			format = "0x%x";
		}
	}

	snprintf(buff, buff_size, format, *uint);

	if(ImGui::InputText(label, buff, buff_size))
	{
		unsigned long r = strtoul(buff, nullptr, 0);
		if(r > UINT16_MAX)
		{
			r = UINT16_MAX;
		}
		else if (r < 0 )
		{
			r = 0;
		}
		*uint = uint16_t{r};
		return true;
	}

	return false;
}
