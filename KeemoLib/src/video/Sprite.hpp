#pragma once
#include <cstdint>

class Sprite
{
public:
	uint8_t **rows;
	Sprite(uint8_t ** rows = nullptr);
	// copy constructor
	Sprite(const Sprite &sprite);
	// move constructor
	Sprite(Sprite &&other);
	//copy assignment operator
	Sprite& operator=(const Sprite& other);
	// move assignment operator
	Sprite& operator=(Sprite&& other);
	~Sprite();

private:
	void free();
	void copy_rows(uint8_t** rows);
};

