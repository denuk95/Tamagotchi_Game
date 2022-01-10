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

bool Button::handleEvent(SDL_Event* e, RenderWindow* gWindow, bool bResetButton)
{
		SDL_GetMouseState(&mPosition.x, &mPosition.y);
		if (insideButton(mPosition))
		{
			if (e->type == SDL_MOUSEBUTTONDOWN)
			{
				hoverButton = true;
				cout<<"Button down"<<endl;
				timer2 = time(NULL);
			}
			else if (e->type == SDL_MOUSEBUTTONUP)
			{
				hoverButton = false;
				cout << "Button up" << endl;
				
				if (bResetButton)
				{
					timer = time(NULL);
					if (timer > timer2 + 5)
					{
						cout << "YEAH" << endl;
						return true;
					}
					else
					{
						return false;
					}
				}

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
