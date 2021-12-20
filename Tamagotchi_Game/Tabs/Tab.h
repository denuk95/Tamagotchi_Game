#pragma once

#include "../RenderWindow.h"
#include "../StatTracking.h"




class Tab
{
	public:
		Tab(){};
		Tab(RenderWindow* temp1Window, const char* path);
		void render(RenderWindow* tempWindow);
		virtual void action(StatTracking &stat) {};

	protected:
		RenderWindow* tempWindow = nullptr;

	private:
		SDL_Texture* tab = nullptr;
		SDL_Rect mainCharacterSprites[2];

		int frame = 0;
};