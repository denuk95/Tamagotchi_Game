#include "RenderWindow.h"

RenderWindow::RenderWindow(const char* p_title, int p_w, int p_h)
:gWindow(NULL), gRenderer(NULL)
{
	gWindow = SDL_CreateWindow(p_title,SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, p_w, p_h, SDL_WINDOW_SHOWN);

	if (gWindow == NULL)
	{
		printf("Window couldn't be created! SDL Error: %s\n", SDL_GetError());
	}

	gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	if (gRenderer == NULL)
	{
		printf("Renderer couldn't be created! SDL Error: %s\n", SDL_GetError());
	}
	else {
		SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
	}
}

SDL_Texture* RenderWindow::loadTexture(const char* p_filePath)
{

	gTexture = IMG_LoadTexture(gRenderer, p_filePath);

	if (gTexture == NULL)
	{
		printf("Unable to create texture %s\n", SDL_GetError());
	}

	return gTexture;
}

void RenderWindow::clearRender()
{
	SDL_RenderClear(gRenderer);
}

void RenderWindow::render(SDL_Texture* p_tex)
{
	SDL_RenderCopy(gRenderer, p_tex, NULL, NULL);
}
void RenderWindow::render(SDL_Texture* p_tex, SDL_Rect* MainCharacterCopy, int posX)
{
	int posMainCharacterX=posX;
	cout<<posMainCharacterX<<endl;
	int posMainCharacterY=367;
	float scale=1.9;
	SDL_Rect MainCharacterOnScreen = { posMainCharacterX, posMainCharacterY, scale*MainCharacterCopy->w, scale*MainCharacterCopy->h};

	SDL_RenderCopy(gRenderer, p_tex, MainCharacterCopy,  &MainCharacterOnScreen);
}



void RenderWindow::display()
{
	SDL_RenderPresent(gRenderer);
}

void RenderWindow::cleanUp()
{
	SDL_DestroyWindow(gWindow);
	SDL_DestroyRenderer(gRenderer);
}

RenderWindow:: ~RenderWindow()
{
	cleanUp();
}
