#include "Sprite.hpp"

Sprite::Sprite(uint8_t ** rows)
{
	if(rows)
	{
		this->rows = rows;
	} else
	{
		this->rows = new uint8_t * [8];

		for(auto row = 0; row < 8; row++)
		{
			this->rows[row] = new uint8_t[8];
		}
	}
}

Sprite::Sprite(const Sprite& other)
	:Sprite()
{
	copy_rows(other.rows);
}

Sprite::Sprite(Sprite&& other)
	:Sprite(other.rows)
{
	other.rows = nullptr;
}

Sprite& Sprite::operator=(const Sprite& other)
{
	if(this != &other)
	{
		copy_rows(other.rows);
	}

	return *this;
}

Sprite& Sprite::operator=(Sprite&& other)
{
	if(this!=&other)
	{
		free();

		rows = other.rows;

		other.rows = nullptr;
	}

	return *this;
}

Sprite::~Sprite()
{
	free();
}

void Sprite::free()
{
	for(auto row = 0; row < 8; row++)
	{
		delete rows[row];
	}

	delete rows;
}

void Sprite::copy_rows(uint8_t** rows)
{
	for(auto row = 0; row < 8; row++)
	{
		for(auto col = 0; col < 8; col++)
		{
			this->rows[row][col] = rows[row][col];
		}
	}
}
