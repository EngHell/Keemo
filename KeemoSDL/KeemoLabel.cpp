#include "KeemoLabel.hpp"
#include <string>


KeemoLabel::KeemoLabel(KeemoObject * parent, std::string text, int x, int y)
	:KeemoObject(parent, &label.rect), text(text), label(kiss_label())
{
	kiss_label_new(&label, nullptr, text.c_str(), x, y);
	label.visible = 1;
}

KeemoLabel::~KeemoLabel()
{
}

void KeemoLabel::hide()
{
	label.visible = 0;
}

void KeemoLabel::show()
{
	label.visible = 0;
}
