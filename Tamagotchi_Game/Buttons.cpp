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

bool Buttons::handleEvent(SDL_Event* e, RenderWindow *gWindow)
{
	if (e->type == SDL_MOUSEMOTION || e->type == SDL_MOUSEBUTTONDOWN || e->type == SDL_MOUSEBUTTONUP)
	{
		SDL_GetMouseState(&mPosition.x, &mPosition.y);

		//Left button
		if (mPosition.x > 622 && mPosition.x < 622 + 75 && mPosition.y > 654 && mPosition.y < 654 + 75)
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
		else if (mPosition.x > 764 && mPosition.x < 764 + 75 && mPosition.y > 729 && mPosition.y < 729 + 75)
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
		else if (mPosition.x > 904 && mPosition.x < 904 + 75 && mPosition.y > 654 && mPosition.y < 654 + 75)
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
