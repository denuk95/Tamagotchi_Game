#include "RenderWindow.h"

RenderWindow::RenderWindow(const char* p_title, int p_w, int p_h)
:gWindow(NULL), gRenderer(NULL)
{
	gWindow = SDL_CreateWindow(p_title,SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, p_w, p_h, SDL_WINDOW_SHOWN);

	if (gWindow == NULL)
	{
		printf("Window couldn't be created! SDL Error: %s\n", SDL_GetError());
	}

	gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);

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
	SDL_Texture* gTexture = NULL;
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

void RenderWindow::display()
{
	SDL_RenderPresent(gRenderer);
}

void RenderWindow::cleanUp()
{
	SDL_DestroyWindow(gWindow);
	SDL_DestroyRenderer(gRenderer);
}
