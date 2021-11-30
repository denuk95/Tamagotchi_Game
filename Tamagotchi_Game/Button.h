#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <string>
#include <cmath>

#include "RenderWindow.h"

using namespace std;

//Наслідування

class Button
{
public:
	Button();
	bool handleEvent(SDL_Event* e, RenderWindow* gWindow);
protected:

	void virtual renderButtons(RenderWindow* gWindow);
	virtual bool insideButton(SDL_Point mousePos);
	bool hoverButton;


private:
	SDL_Point mPosition{0,0};

};
