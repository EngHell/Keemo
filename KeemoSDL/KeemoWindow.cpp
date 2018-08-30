#include "KeemoWindow.h"



 KeemoWindow::KeemoWindow(KeemoObject* parent, int x, int y, int w, int h)
	: KeemoObject(parent, &window.rect), window(kiss_window{})
{
	SDL_Point p{x, y};
	p = mapToGlobal(p);

	kiss_window_new(&window, nullptr, 0, p.x, p.y, w, h);
}


KeemoWindow::~KeemoWindow()
= default;


void KeemoWindow::hide()
 {
	window.visible = 0;
 }
 void KeemoWindow::setBackgroundColor(SDL_Color color)
 {
	window.bg = color;
 }

 void KeemoWindow::show()
 {
	window.visible = 1;
 }
