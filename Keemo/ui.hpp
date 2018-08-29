#pragma once
#include <Windows.h>

namespace ui
{
	// locals
	namespace Consts
	{
	}

	// externs
	


	HWND createMainWindow(HINSTANCE hinst);
	HWND createDebugWindow(HWND parent, HINSTANCE hinst);
	void showWindow(HWND wind);
	void hideWindow(HWND wind);

	LRESULT CALLBACK mainWindowProc(HWND handleforwindow, UINT msg, WPARAM wParam, LPARAM lParam);


	// callbacks
	LRESULT CALLBACK DebugProc(
	HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam
	);
}