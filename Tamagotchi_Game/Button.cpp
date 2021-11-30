#include "Button.h"



Button::Button()
{
	hoverButton = false;
}


void Button::renderButtons(RenderWindow* gWindow) //Render 
{

}

bool Button::insideButton(SDL_Point mousePos)
{
	return true;
}

bool Button::handleEvent(SDL_Event* e, RenderWindow* gWindow)
{
		SDL_GetMouseState(&mPosition.x, &mPosition.y);
		if (insideButton(mPosition))
		{
			if (e->type == SDL_MOUSEBUTTONDOWN)
			{
				hoverButton = false;
			}
			else if (e->type == SDL_MOUSEBUTTONUP)
			{
				hoverButton = true;
				return true;
			}
			else
			{
				hoverButton = true;
			}
		}
		else
		{
			hoverButton = false;
		}

	return false;

}
