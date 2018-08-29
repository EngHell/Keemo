#include "ui.hpp"
#include "resource.h"
#include <crtdbg.h>

namespace ui
{
}

HWND ui::createMainWindow(HINSTANCE hinst)
{
	//create window 1

	WNDCLASSEX windowclassforwindow1;
	ZeroMemory(&windowclassforwindow1,sizeof(WNDCLASSEX));
	windowclassforwindow1.cbClsExtra = NULL;
	windowclassforwindow1.cbSize = sizeof(WNDCLASSEX);
	windowclassforwindow1.cbWndExtra = NULL;
	windowclassforwindow1.hbrBackground = (HBRUSH)COLOR_WINDOW;
	windowclassforwindow1.hCursor = LoadCursor(NULL,IDC_ARROW);
	windowclassforwindow1.hIcon = NULL;
	windowclassforwindow1.hIconSm = NULL;
	windowclassforwindow1.hInstance = hinst;
	windowclassforwindow1.lpfnWndProc = (WNDPROC)mainWindowProc;
	windowclassforwindow1.lpszClassName = L"windowclass 1";
	windowclassforwindow1.lpszMenuName = NULL;
	windowclassforwindow1.style = CS_HREDRAW | CS_VREDRAW;

	if (!RegisterClassEx(&windowclassforwindow1))
	{
		int nResult = GetLastError();
		MessageBox(NULL,
				   L"Window class creation failed",
				   L"Window Class Failed",
				   MB_ICONERROR);

		return nullptr;
	}

	HWND handle = CreateWindowEx(NULL,
								 windowclassforwindow1.lpszClassName,
								 L"Parent Window",
								 WS_OVERLAPPEDWINDOW,
								 200,
								 150,
								 640,
								 480,
								 NULL,
								 NULL,
								 hinst,
								 NULL /* No Window Creation data */
	);

	if (!handle)
	{
		int nResult = GetLastError();

		MessageBox(NULL,
				   L"Window creation failed",
				   L"Window Creation Failed",
				   MB_ICONERROR);

		return nullptr;
	}

	return handle;
}

HWND ui::createDebugWindow(HWND parent, HINSTANCE hinst)
{
	// create window 2

	WNDCLASSEX windowclassforwindow2;
	ZeroMemory(&windowclassforwindow2,sizeof(WNDCLASSEX));
	windowclassforwindow2.cbClsExtra=NULL;
	windowclassforwindow2.cbSize=sizeof(WNDCLASSEX);
	windowclassforwindow2.cbWndExtra=NULL;
	windowclassforwindow2.hbrBackground=(HBRUSH)COLOR_WINDOW;
	windowclassforwindow2.hCursor=LoadCursor(NULL,IDC_ARROW);
	windowclassforwindow2.hIcon=NULL;
	windowclassforwindow2.hIconSm=NULL;
	windowclassforwindow2.hInstance=hinst;
	windowclassforwindow2.lpfnWndProc= ui::DebugProc;
	windowclassforwindow2.lpszClassName=L"window class2";
	windowclassforwindow2.lpszMenuName=NULL;
	windowclassforwindow2.style=CS_HREDRAW|CS_VREDRAW;

	if(!RegisterClassEx(&windowclassforwindow2))
	{
		int nResult=GetLastError();
		MessageBox(nullptr,
			L"Window class creation failed for window 2",
			L"Window Class Failed",
			MB_ICONERROR);

		return nullptr;
	}

	HWND handle=CreateWindowEx(NULL,
		windowclassforwindow2.lpszClassName,
			L"Child Window",
			WS_POPUPWINDOW | WS_CAPTION,
			200,
			150,
			640,
			480,
			parent,
			NULL,
			hinst,
			NULL);

	if(!handle)
	{
		int nResult=GetLastError();

		MessageBox(NULL,
			L"Window creation failed",
			L"Window Creation Failed",
			MB_ICONERROR);

		return nullptr;
	}

	return handle;
}

void ui::showWindow(HWND wind)
{
	ShowWindow(wind, SW_SHOW);
}

void ui::hideWindow(HWND wind)
{
	ShowWindow(wind, SW_HIDE);
}

LRESULT CALLBACK ui::mainWindowProc(HWND handleforwindow,UINT msg,WPARAM wParam,LPARAM lParam)
{
	switch(msg)
	{
		case WM_DESTROY: {
			MessageBox(NULL,
			L"Window 1 closed",
			L"Message",
			MB_ICONINFORMATION);

			PostQuitMessage(0);
		}
		break;
	}

	return DefWindowProc(handleforwindow,msg,wParam,lParam);
}

LRESULT CALLBACK ui::DebugProc(HWND handle, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_DESTROY: {
			MessageBox(NULL,
					   L"Window 2 closed",
					   L"Message",
					   MB_ICONINFORMATION);

			//window2closed=true;
			//
		}
		break;
	}

	return DefWindowProc(handle, msg, wParam, lParam);
}
