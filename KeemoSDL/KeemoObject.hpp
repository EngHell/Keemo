#pragma once

extern "C" {
#include "kiss_sdl/kiss_sdl.h"
}
class KeemoObject
{
public:
	//members
	KeemoObject* parent = nullptr;
	SDL_Rect* rect;

	// init, dest
	/**
	 * \brief Creates a window at coord x, y, width x and height h
	 * \param parent 
	 * \param x relative to the parent
	 * \param y relative to the parent
	 * \param w 
	 * \param h 
	 */
	KeemoObject(KeemoObject * parent, SDL_Rect* rect);
	virtual ~KeemoObject();


	/*
	 * methods
	 */

	/**
	 * \brief Holds the height of the window
	 * \return int with the height
	 */
	int height() const;
	/**
	 * \brief hides the window.
	 */
	virtual void hide() = 0;
	/**
	 * \brief maps from a global coordinate to the coordinate in parent coords
	 * \return SDL_Point with the mapped coordinats
	 */
	SDL_Point mapFromGlobal(SDL_Point pos) const;
	/**
	 * \brief Used to map a global coordinate to the coordinates of this object, 
	 * \return SDL_Point with the mapped coordinates
	 */
	SDL_Point mapToThis(SDL_Point pos) const;
	/**
	 * \brief Maps a pos to the parent coords, or to global if parent is null
	 * \param pos the position to map
	 */
	SDL_Point mapToParent(SDL_Point pos) const;
	/**
	 * \brief Maps a pos relative the parent coords, to global
	 * \param pos the position to map
	 * \return the mapped coord
	 */
	SDL_Point mapToGlobal(SDL_Point pos) const;
	/**
	 * \brief Sets the background color of the window
	 * \param color SDL_Color to be used
	 */
	virtual void setBackgroundColor(SDL_Color color) = 0;
	/**
	 * \brief Sets the pos of the window, coordinates must be in parent's coordinates or globalcoordinates if no parent has been provided.
	 * \param x coordinate x
	 * \param y coordinate y
	 */
	void setPos(const SDL_Point pos);
	/**
	 * \brief Shows the window
	 */
	virtual void show() = 0;
	/**
	 * \brief Holds the width of the window
	 * \return int with the width
	 */
	int width() const;
	/**
	 * \brief Gets position x relative to it's parent
	 * \return x coordinate
	 */
	int x() const;
	/**
	 * \brief Gets position y relative to it's parent
	 * \return y coordinate
	 */
	int y() const;
};

