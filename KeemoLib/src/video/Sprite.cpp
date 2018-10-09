#include "Sprite.hpp"

Sprite::Sprite()
{
	rows = new uint8_t * [8];

	for(auto row = 0; row < 8; row++)
	{
		rows[row] = new uint8_t[8];
	}
}

Sprite::~Sprite()
{
	for(auto row = 0; row < 8; row++)
	{
		delete rows[row];
	}

	delete rows;
}
