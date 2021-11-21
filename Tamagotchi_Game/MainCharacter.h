#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <string>

#include "RenderWindow.h"

const int WALKING_ANIMATION_FRAMES=2;

class MainCharacter
{
	public:
	MainCharacter();
	SDL_Rect* GetMainCharacterRect(int counter);

	private:
	SDL_Rect MainCharacterSprites[WALKING_ANIMATION_FRAMES];

};