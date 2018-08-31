#pragma once
#include <cstdint>

namespace ui
{
	const char debuggerId[] = "Debugger##Debugger";
	void showDebugger(bool * show);
	bool InputUint8(const char * label, uint8_t * uint, char * buff, size_t buffSize, bool* hex = nullptr);
	bool InputUint16(const char * label, uint16_t * uint, char * buff, size_t buff_size, bool* hex = nullptr);
}
	


