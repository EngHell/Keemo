	#include <windows.h>
#include "ui.hpp"

LRESULT CALLBACK windowprocessforwindow1(HWND handleforwindow1,UINT message,WPARAM wParam,LPARAM lParam);
LRESULT CALLBACK windowprocessforwindow2(HWND handleforwindow2,UINT message,WPARAM wParam,LPARAM lParam);

bool window1closed=false;
bool window2closed=false;

int WINAPI WinMain(HINSTANCE hInst,HINSTANCE hPrevInst,LPSTR lpCmdLine,int nShowCmd)
{
	bool run=true;

	
	HWND handleforwindow1 = ui::createMainWindow(hInst);
	ShowWindow(handleforwindow1,nShowCmd);

	HWND handleforwindow2= ui::createDebugWindow(handleforwindow1, hInst);
	ShowWindow(handleforwindow2,nShowCmd);
	
	MSG msg;
	ZeroMemory(&msg,sizeof(MSG));
	while (run) {
		if (GetMessage(&msg,NULL,0,0)) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			run = false;
		}
	}
	MessageBox(NULL,
	L"Both Windows are closed.  Program will now close.",
	L"",
	MB_ICONINFORMATION);
	return 0;
}