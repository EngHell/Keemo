// Resources.cpp

// Header required to help detect window version
#include <sdkddkver.h>

// Macro used to reduce namespace pollution
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif

// Reference for various Win32 API functions and
// structure declarations.
#include <Windows.h>

// Header needed for unicode adjustment support
#include <tchar.h>
#include <iostream>
#include <strsafe.h>

#include "resource.h"
#include "ui.hpp"

constexpr const size_t MAX_LOADSTRING = 100;

TCHAR className[MAX_LOADSTRING];
TCHAR title[MAX_LOADSTRING];

HCURSOR cursor;
HICON icon, iconSmall;
HMENU menu;

HINSTANCE hinst;
HWND debug;

//
//
// WndProc - Window procedure
//
//
LRESULT CALLBACK WndProc(
	HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam
)
{
	switch (uMsg)
	{
	case WM_CREATE:
		debug = ui::createDebugWindow(hWnd, hinst);
	if (debug)
	{
		//ui::showWindow(debug);
		//UpdateWindow(debug);
		
		ShowWindow(debug, SW_SHOW);
		UpdateWindow(debug);
	}
	else
	{
		LPVOID lpMsgBuf;
		LPVOID lpDisplayBuf;
		DWORD dw = GetLastError();

		FormatMessage(
			FORMAT_MESSAGE_ALLOCATE_BUFFER |
			FORMAT_MESSAGE_FROM_SYSTEM |
			FORMAT_MESSAGE_IGNORE_INSERTS,
			NULL,
			dw,
			MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
			(LPTSTR)&lpMsgBuf,
			0, NULL);

		// Display the error message and exit the process

		lpDisplayBuf = (LPVOID)LocalAlloc(
			LMEM_ZEROINIT,
			(lstrlen((LPCTSTR)lpMsgBuf) + lstrlen((LPCTSTR)"hi") + 40) * sizeof(TCHAR)
		);
		StringCchPrintf((LPTSTR)lpDisplayBuf,
		                LocalSize(lpDisplayBuf) / sizeof(TCHAR),
		                TEXT("%s failed with error %d: %s"),
		                "hi", dw, lpMsgBuf
		);
		MessageBox(NULL, (LPCTSTR)lpDisplayBuf, TEXT("Error"), MB_OK);

		LocalFree(lpMsgBuf);
		LocalFree(lpDisplayBuf);
	}
		break;

	case WM_DESTROY:
		::PostQuitMessage(0);
		break;

		/*		
		case WM_SYSCOMMAND:
			_RPTF0(_CRT_WARN, "SYSCOMMAND");
			return DefWindowProc(hWnd, uMsg, wParam, lParam);
			break;
			*/


	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case ID_FILE_OPEN:
			break;

		case ID_FILE_QUIT:
			DestroyWindow(hWnd);
			break;

		case ID_DEBUG_SHOWDEBUGWINDOW:
			break;
		}
		break;


	default:
		return ::DefWindowProc(hWnd, uMsg, wParam, lParam);
	}

	return 0;
}

//
//
// WinMain - Win32 application entry point.
//
//
int APIENTRY _tWinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPTSTR lpCmdLine,
	int nShowCmd)
{
	hinst = hInstance;

	LoadString(hInstance, IDS_MYAPP_CLASS, className, sizeof(TCHAR) * MAX_LOADSTRING);
	LoadString(hInstance, IDS_MYAPP_TITLE, title, sizeof(TCHAR) * MAX_LOADSTRING);

	cursor = LoadCursor(hInstance, MAKEINTRESOURCE(IDC_MYAPP_POINTER));

	icon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MYAPP_ICON));
	iconSmall = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MYAPP_ICON_SMALL));


	// Setup window class attributes.
	WNDCLASSEX wcex;
	ZeroMemory(&wcex, sizeof(wcex));

	wcex.cbSize = sizeof(wcex); // WNDCLASSEX size in bytes
	wcex.style = CS_HREDRAW | CS_VREDRAW; // Window class styles
	wcex.lpszClassName = className; // Window class name
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1); // Window background brush color.
	wcex.hCursor = cursor; // Window cursor
	wcex.hIcon = icon;
	wcex.hIconSm = iconSmall;
	wcex.lpfnWndProc = WndProc; // Window procedure associated to this window class.
	wcex.hInstance = hInstance; // The application instance.
	wcex.lpszMenuName = MAKEINTRESOURCE(IDM_MYAPP_MENU_MAIN);

	// Register window and ensure registration success.
	if (!RegisterClassEx(&wcex))
		return 1;

	// Setup window initialization attributes.
	CREATESTRUCT cs;
	ZeroMemory(&cs, sizeof(cs));

	cs.x = 0; // Window X position
	cs.y = 0; // Window Y position
	cs.cx = 640; // Window width
	cs.cy = 480; // Window height
	cs.hInstance = hInstance; // Window instance.
	cs.lpszClass = wcex.lpszClassName; // Window class name
	cs.lpszName = TEXT("My First Window"); // Window title
	cs.style = WS_OVERLAPPEDWINDOW; // Window style

	// Create the window.
	HWND hWnd = ::CreateWindowEx(
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

	// Validate window.
	if (!hWnd)
		return 1;

	// Display the window.
	::ShowWindow(hWnd, SW_SHOWDEFAULT);
	::UpdateWindow(hWnd);


	// Main message loop.
	MSG msg;
	while (::GetMessage(&msg, hWnd, 0, 0) > 0)
		::DispatchMessage(&msg);

	// Unregister window class, freeing the memory that was
	// previously allocated for this window.
	::UnregisterClass(wcex.lpszClassName, hInstance);

	return (int)msg.wParam;
}
