#pragma once
#include <cstdint>
#include <stddef.h>
//#include <windows.h>

namespace ui
{
	static const char debuggerId[] = "Debugger##Debugger";
	static const char * file_name = "tetris.gb";

	void showDebugger(bool* show, bool* play, bool* step_by_step_mode);
	bool InputUint8(const char* label, uint8_t* uint, char* buff,   size_t buffSize, bool* hex = nullptr);
	bool InputUint16(const char* label, uint16_t* uint, char* buff, size_t buff_size, bool* hex = nullptr);

	bool openFileWithWindowsApi(char* result, int buff_size);
}
