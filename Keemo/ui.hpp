#pragma once
#include <Windows.h>

namespace ui
{
	// locals
	namespace Consts
	{
	}

	// externs
	



	HWND createDebugWindow(HWND parent, HINSTANCE hinst);
	void showWindow(HWND wind);
	void hideWindow(HWND wind);


	// callbacks
	LRESULT CALLBACK DebugProc(
	HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam
	);
}