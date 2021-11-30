#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <string>
#include <cmath>

#include "RenderWindow.h"
#include "Button.h"

using namespace std;

class CircledButton : public Button
{
	public:
		CircledButton(){};
		CircledButton(RenderWindow* gWindow, int posX, int posY, float tempRadius);
		void renderButtons();


	protected:

		bool insideButton(SDL_Point mousePos) override;

	private:

		const float CIRCLE_RADIUS = 37;

		RenderWindow* windowTemporary = nullptr;

		SDL_Texture* buttonPressed = nullptr;

		int centerX = 0, centerY = 0;
		float radius = 0.f;

};
