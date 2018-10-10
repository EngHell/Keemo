#include "KeemoUi.hpp"
#include "imgui/imgui.h"
#include "Cpu.hpp"
#include "Memory.hpp"
#include <string>
#include <iostream>
#include <Windows.h>
#include <shobjidl.h>
#include <shtypes.h>
#include <shlwapi.h>
#include "Core.hpp"


void ui::showDebugger(bool* show, bool* play, bool* step_by_step_mode)
{
	using namespace ImGui;
	ImGui::Begin(debuggerId, show, ImGuiWindowFlags_None);

	// debug controls
	if(ImGui::Button("Play"))
	{
		*play = true;
	}
	ImGui::SameLine();
	if(Button("Pause"))
	{
		*play = false;
	}
	ImGui::SameLine();
	if(ImGui::Button("Restart"))
	{
		*play = false;
		// this button yet does not do anything, cuz im a bit lazy to make it do something yet xd
	}
	SameLine();
	if(Button("Next Step"))
	{
		*play = true;
	}

	Checkbox("Step By Step, debugging", step_by_step_mode);

	static const size_t buffMax = 8;
	static char registerBuff[buffMax];
	static bool showInHex = true;
	static uint16_t evaluate1 = 0;
	static uint16_t evaluate2 = 0;
	static uint8_t result1 = 0;
	static uint16_t result2 = 0;
	static const size_t err_buff_size = 100;
	static char err_buff[err_buff_size];
	static uint8_t opcode;


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
	if (ui::InputUint8("Result1", &result1, registerBuff, buffMax, &showInHex))
	{
		KeemoLib::memory::writeUInt8(evaluate1, result1);
	}
	NextColumn();

	ui::InputUint16("Get uint16", &evaluate2, registerBuff, buffMax, &showInHex);
	NextColumn();
	result2 = KeemoLib::memory::readUInt16(evaluate2);
	if (ui::InputUint16("Result2", &result2, registerBuff, buffMax, &showInHex))
	{
		KeemoLib::memory::writeUInt16(evaluate2, result2);
	}
	Columns(1);
	Separator();

	// so to get the current opcode instead of waiting for cpu::step() when the pc raises and the opcode of the last 
	// operation is left
	opcode = KeemoLib::memory::readUInt8(KeemoLib::cpu::registers.pc);
	// will add a hot opcode edition if needed but otherwise nope
	InputUint8("OPCode", &opcode, registerBuff, buffMax, &showInHex);

	if (Button("Open file"))
	{
		if(KeemoLib::Core::bootUp(std::string{file_name}))
		{
			
		} else
		{
			strerror_s(err_buff, err_buff_size, errno);
			std::cerr << "Error: " << err_buff;
		}
	}

	ImGui::End();
}

bool ui::InputUint8(const char* label, uint8_t* uint, char* buff, size_t buffSize, bool* hex)
{
	static const char* format;

	format = "%u";

	if (hex)
	{
		if (*hex)
		{
			format = "0x%x";
		}
	}


	snprintf(buff, buffSize, format, *uint);

	if (ImGui::InputText(label, buff, buffSize))
	{
		unsigned long r = strtoul(buff, nullptr, 0);
		if (r > UINT8_MAX)
		{
			r = UINT8_MAX;
		}
		else if (r < 0)
		{
			r = 0;
		}
		*uint = r;
		return true;
	}

	return false;
}

bool ui::InputUint16(const char* label, uint16_t* uint, char* buff, size_t buff_size, bool* hex)
{
	static const char* format;

	format = "%u";

	if (hex)
	{
		if (*hex)
		{
			format = "0x%x";
		}
	}

	snprintf(buff, buff_size, format, *uint);

	if (ImGui::InputText(label, buff, buff_size))
	{
		unsigned long r = strtoul(buff, nullptr, 0);
		if (r > UINT16_MAX)
		{
			r = UINT16_MAX;
		}
		else if (r < 0)
		{
			r = 0;
		}
		*uint = r;
		return true;
	}

	return false;
}

bool ui::openFileWithWindowsApi(char* result, int buff_size)
{
	bool success = false;

	OPENFILENAME ofn;
	ZeroMemory(&result, buff_size);
	ZeroMemory(&ofn, sizeof(ofn));
	ofn.lStructSize = sizeof(ofn);
	ofn.hwndOwner = NULL; // If you have a window to center over, put its HANDLE here
	ofn.hInstance = nullptr;
	ofn.lpstrFilter = "Text Files\0*.txt\0Any File\0*.*\0";
	ofn.lpstrFile = result;
	//ofn.lpstrFile[0] = '\0';
	ofn.nMaxFile = MAX_PATH;
	ofn.lpstrTitle = "Select a File, yo!";
	ofn.Flags = OFN_DONTADDTORECENT | OFN_FILEMUSTEXIST;

	if (GetOpenFileName(&ofn))
	{
		std::cout << "You chose the file \"" << result << "\"\n";
		success = true;
	}
	else
	{
		// All this stuff below is to tell you exactly how you messed up above. 
		// Once you've got that fixed, you can often (not always!) reduce it to a 'user cancelled' assumption.
		switch (CommDlgExtendedError())
		{
		case CDERR_DIALOGFAILURE: std::cout << "CDERR_DIALOGFAILURE\n";
			break;
		case CDERR_FINDRESFAILURE: std::cout << "CDERR_FINDRESFAILURE\n";
			break;
		case CDERR_INITIALIZATION: std::cout << "CDERR_INITIALIZATION\n";
			break;
		case CDERR_LOADRESFAILURE: std::cout << "CDERR_LOADRESFAILURE\n";
			break;
		case CDERR_LOADSTRFAILURE: std::cout << "CDERR_LOADSTRFAILURE\n";
			break;
		case CDERR_LOCKRESFAILURE: std::cout << "CDERR_LOCKRESFAILURE\n";
			break;
		case CDERR_MEMALLOCFAILURE: std::cout << "CDERR_MEMALLOCFAILURE\n";
			break;
		case CDERR_MEMLOCKFAILURE: std::cout << "CDERR_MEMLOCKFAILURE\n";
			break;
		case CDERR_NOHINSTANCE: std::cout << "CDERR_NOHINSTANCE\n";
			break;
		case CDERR_NOHOOK: std::cout << "CDERR_NOHOOK\n";
			break;
		case CDERR_NOTEMPLATE: std::cout << "CDERR_NOTEMPLATE\n";
			break;
		case CDERR_STRUCTSIZE: std::cout << "CDERR_STRUCTSIZE\n";
			break;
		case FNERR_BUFFERTOOSMALL: std::cout << "FNERR_BUFFERTOOSMALL\n";
			break;
		case FNERR_INVALIDFILENAME: std::cout << "FNERR_INVALIDFILENAME\n";
			break;
		case FNERR_SUBCLASSFAILURE: std::cout << "FNERR_SUBCLASSFAILURE\n";
			break;
		default: std::cout << "You cancelled.\n";
		}
	}

	return success;
}
