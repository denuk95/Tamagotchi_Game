#include "Buttons.h"

Buttons::Buttons(RenderWindow* gWindow)
{
	mPosition.x = 0;
	mPosition.y = 0;
	mCurrentSprite= ButtonsSprite::BUTTON_NULL_STATE;
	for (int i = 0; i < AMOUNT_OF_BUTTONS; i++)
	{
		buttonPressed[i]=NULL;
	}
	buttonPressed[0] = gWindow->loadTexture("assets/Button2.png");
	buttonPressed[1] = gWindow->loadTexture("assets/Button3.png");
	buttonPressed[2] = gWindow->loadTexture("assets/Button4.png");
}


void Buttons::renderButtons(RenderWindow* gWindow)
{	
	if(mCurrentSprite!= ButtonsSprite::BUTTON_NULL_STATE)
	{
		gWindow->render(buttonPressed[static_cast<int>(mCurrentSprite)]);
	}

}
bool Buttons::insideButton(SDL_Point mousePos, SDL_Point buttonCenter)
{
	float distance;
	const float BUTTON_RADIUS = 37;

	distance = sqrt(pow(buttonCenter.x - mousePos.x, 2) +pow(buttonCenter.y - mousePos.y, 2));

	if (distance < BUTTON_RADIUS)
	{
		return true;
	}

	return false;
}

bool Buttons::handleEvent(SDL_Event* e, RenderWindow *gWindow)
{
	if (e->type == SDL_MOUSEMOTION || e->type == SDL_MOUSEBUTTONDOWN || e->type == SDL_MOUSEBUTTONUP)
	{
		SDL_GetMouseState(&mPosition.x, &mPosition.y);

		//Left button
		SDL_Point leftCenter = { 659, 691};
		SDL_Point centerButton = { 801, 766 };
		SDL_Point rightCenter = { 941, 691 };


		//659x 691y center left button radius 37,5 diameter 75
		// if(insideButton(mPosition, leftCenter)
		if (insideButton(mPosition, leftCenter))
		{
			if (e->type == SDL_MOUSEBUTTONDOWN)
			{
				mCurrentSprite = ButtonsSprite::BUTTON_NULL_STATE;
			}
			else if (e->type == SDL_MOUSEBUTTONUP)
			{
				mCurrentSprite = ButtonsSprite::BUTTON_SPRITE_LEFT;
				return true;
			}
			else
			{	
				mCurrentSprite = ButtonsSprite::BUTTON_SPRITE_LEFT;
			}
		}



		//Center button
		else if (insideButton(mPosition, centerButton))
		{
			if (e->type == SDL_MOUSEBUTTONDOWN)
			{
				mCurrentSprite = ButtonsSprite::BUTTON_NULL_STATE;
			}
			else if (e->type == SDL_MOUSEBUTTONUP)
			{
				mCurrentSprite = ButtonsSprite::BUTTON_SPRITE_CENTER;
			}
			else
			{
				mCurrentSprite = ButtonsSprite::BUTTON_SPRITE_CENTER;
			}
		}
		//Right button
		else if (insideButton(mPosition, rightCenter))
		{
			if (e->type == SDL_MOUSEBUTTONDOWN)
			{
				mCurrentSprite = ButtonsSprite::BUTTON_NULL_STATE;
			}
			else if (e->type == SDL_MOUSEBUTTONUP)
			{
				mCurrentSprite = ButtonsSprite::BUTTON_SPRITE_RIGHT;
			}
			else
			{
				mCurrentSprite = ButtonsSprite::BUTTON_SPRITE_RIGHT;
			}
		}
		else
		{
			mCurrentSprite = ButtonsSprite::BUTTON_NULL_STATE;
		}




	}
	return false;

}
