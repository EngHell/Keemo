#include "ui.hpp"
#include "resource.h"
#include <crtdbg.h>

namespace ui
{
	
}

HWND ui::createDebugWindow(HWND parent, HINSTANCE hinst)
{
	WNDCLASSEX wcex;
	ZeroMemory(&wcex, sizeof(wcex));

	wcex.cbSize = sizeof(wcex); // WNDCLASSEX size in bytes
	wcex.style = CS_HREDRAW | CS_VREDRAW; // Window class styles
	wcex.lpszClassName = (LPCTSTR)"HiClass"; // Window class name
	wcex.hbrBackground = CreateSolidBrush(RGB(255, 0, 0)); // Window background brush color.
	wcex.hCursor = LoadCursor(hinst, MAKEINTRESOURCE(IDC_MYAPP_POINTER)); // Window cursor
	wcex.lpfnWndProc = DebugProc; // Window procedure associated to this window class.
	wcex.hInstance = hinst; // The application instance.

	if(!RegisterClassEx(&wcex)) 
		return nullptr;

	CREATESTRUCT cs;
	ZeroMemory(&cs, sizeof(cs));

		cs.x = 100; // Window X position
		cs.y = 100; // Window Y position
		cs.cx = 140; // Window width
		cs.cy = 280; // Window height
		cs.hInstance = hinst; // Window instance.
		cs.lpszClass = wcex.lpszClassName; // Window class name
		cs.lpszName = TEXT("My second Window"); // Window title
	cs.hwndParent = parent;
	cs.hMenu = (HMENU) 10005;
		cs.style = WS_CHILD | WS_SIZEBOX; // Window style

	return CreateWindowEx(
		cs.dwExStyle,
		cs.lpszClass,
		cs.lpszName,
		cs.style,
		cs.x,
		cs.y,
		cs.cx,
		cs.cy,
		cs.hwndParent,
		cs.hMenu,
		cs.hInstance,
		cs.lpCreateParams);
}

void ui::showWindow(HWND wind)
{
	ShowWindow(wind, SW_SHOW);
}

void ui::hideWindow(HWND wind)
{
	ShowWindow(wind, SW_HIDE);
}

LRESULT ui::DebugProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;

	switch (uMsg)
	{
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		// TODO: Add any drawing code here...
		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, uMsg, wParam, lParam);
	}
	return 0;
}
