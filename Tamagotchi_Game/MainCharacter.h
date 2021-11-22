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
	MainCharacter(RenderWindow* gWindow);
	//SDL_Rect* GetMainCharacterRect(int counter);
	int GetMainCharacterX(bool currentTime);
	int GetMainCharacterY();
	void RenderMainCharacter(RenderWindow* gWindow, bool ticks);

	private:
	SDL_Texture* mainCharacterTx;
	SDL_Rect mainCharacterSprites[WALKING_ANIMATION_FRAMES];
	int mainCharacterPosX = 480;
	int mainCharacterPosY = 380;
	unsigned int lastTime=0;
	bool directionMovements = true;
	int frame=0;

};