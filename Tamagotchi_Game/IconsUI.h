#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <string>

#include "RenderWindow.h"

using namespace std;


const int AMOUNT_OF_ICONS = 5;

enum class UpperIcons
{
	FIRST_ICON = 0,
	SECOND_ICON = 1,
	THIRD_ICON = 2,
	FOURTH_ICON = 3,
	FIFTH_ICON = 4,
	SIXTH_ICON = 5,
	SEVENTH_ICON = 6,
	EIGHTH_ICON = 7,
	NINTH_ICON = 8,
	TENTH_ICON = 9
};




class Icons
{	
	public:
	Icons(RenderWindow* gWindow);
	void renderIcons(RenderWindow* gWindow, bool temp, bool alphaControl);
	void changeIconsAlpha(bool alpha);
	int getCurrentIcon();


	private:
	UpperIcons icon;
	SDL_Texture* iconsList[10];
	int counter = 0;
	bool everythingTransparent = false;
};
