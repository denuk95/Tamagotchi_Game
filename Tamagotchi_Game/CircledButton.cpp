#include "CircledButton.h"

CircledButton::CircledButton(RenderWindow* gWindow, int posX, int posY, float valueRadius)
: windowTemporary{ gWindow }, centerX{ posX }, centerY{ posY }, radius { valueRadius }
{
	buttonPressed = windowTemporary->loadTexture("assets/ButtonColor.png");
}


void CircledButton::renderButtons()
{	
	if(hoverButton)
	{
		windowTemporary->render(buttonPressed, centerX - radius, centerY - radius, 77, 77);
	}

}
bool CircledButton::insideButton(SDL_Point mousePos)
{
	double distance;

	distance = sqrt(pow(centerX - mousePos.x, 2) +pow(centerY - mousePos.y, 2));

	if (distance < radius)
	{
		return true;
	}

	return false;
}

void CircledButton::reset()
{
	
}