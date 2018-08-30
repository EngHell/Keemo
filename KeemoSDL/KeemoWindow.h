#pragma once
#include "KeemoObject.hpp"

class KeemoWindow :
	public KeemoObject
{
public:
	//members
	kiss_window window;

	KeemoWindow(KeemoObject* parent, int x, int y, int w, int h);
	virtual ~KeemoWindow();

	//methods

	void hide() override;
	void setBackgroundColor(SDL_Color color) override;
	void show() override;
};

