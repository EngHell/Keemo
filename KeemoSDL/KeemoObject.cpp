#include "KeemoObject.hpp"


KeemoObject::KeemoObject(KeemoObject* parent, SDL_Rect* rect)
	: parent(parent), rect(rect)
{

}

KeemoObject::~KeemoObject()
{
	parent = nullptr;
	rect = nullptr;
}

int KeemoObject::height() const
{
	return rect->h;
}

// TODO: Review this definition
SDL_Point KeemoObject::mapToThis(SDL_Point pos) const
{
	SDL_Point point{0,0};
	point.x = x() + pos.x;
	point.y = y() + pos.y;

	return point;
}

void KeemoObject::setPos(SDL_Point pos)
{
	rect->x = pos.x;
	rect->y = pos.y;
}

SDL_Point KeemoObject::mapToParent(const SDL_Point pos) const
{
	if(parent)
	{
		
		SDL_Point point{0,0};

		point.x += parent->x() + pos.x;
		point.y += parent->y() + pos.y;

		return point;
	} 
	else
	{
		return pos;
	}
}

SDL_Point KeemoObject::mapToGlobal(SDL_Point pos) const
{
	// easy to do as our window.rect is always in global coords
	SDL_Point coord = pos;

	coord.x += rect->x;
	coord.y += rect->y;

	return coord;
}


int KeemoObject::width() const
{
	return rect->w;
}

int KeemoObject::x() const
{
	int x = rect->x;
	if(parent)
		x -= parent->rect->x;

	return x;
}

int KeemoObject::y() const
{
	int y = rect->y;
	if(parent)
		y -= parent->rect->y;

	return y;
}