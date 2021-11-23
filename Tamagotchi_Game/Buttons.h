#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <string>
#include <cmath>

#include "RenderWindow.h"

using namespace std;


enum class ButtonsSprite
{
	BUTTON_SPRITE_LEFT = 0,
	BUTTON_SPRITE_CENTER = 1,
	BUTTON_SPRITE_RIGHT = 2,
	BUTTON_NULL_STATE=3
};

const int AMOUNT_OF_BUTTONS = 3;


class Buttons
{
	public:
	Buttons(RenderWindow* gWindow);
	bool handleEvent(SDL_Event* e, RenderWindow* gWindow);
	void renderButtons (RenderWindow* gWindow);

	protected:
	bool insideButton(SDL_Point mousePos, SDL_Point buttonCenter);

	private:

	SDL_Point mPosition;

	SDL_Texture* buttonPressed[AMOUNT_OF_BUTTONS];

	ButtonsSprite mCurrentSprite;

};
