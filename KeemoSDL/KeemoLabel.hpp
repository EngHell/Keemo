#pragma once
#include "KeemoObject.hpp"
#include <string>

class KeemoLabel : public KeemoObject
{
public:
	//members
	std::string text;
	kiss_label label;

	KeemoLabel(KeemoObject* parent, std::string text, int x, int y);
	~KeemoLabel();

	void hide() override;
	void setBackgroundColor(SDL_Color color) override;
	void show() override;
};

