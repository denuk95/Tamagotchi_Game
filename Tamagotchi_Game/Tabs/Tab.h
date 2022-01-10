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
		SDL_Rect tabSprites[2];
		const int TAB_SPRITES_WIDTH = 100;
		const int TAB_SPRITES_HEIGHT = 50;
		int frame = 0;
};