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

	screenLeftPoint.x = 498;
	screenLeftPoint.y = 303;
	screenCentrPoint.x = screenLeftPoint.x + TAMA_SCREEN_WIDTH / 2;
	screenCentrPoint.y = screenLeftPoint.y + TAMA_SCREEN_HEIGHT / 2;
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

void RenderWindow::render(SDL_Texture* p_tex, SDL_Rect* rectCopy, int posX, int posY)
{
	float scaleActual = scale;
	if (posX == -1 && posY == -1)
	{
		scaleActual = scalePicture;
		posX = screenCentrPoint.x - scalePicture * rectCopy->w / 2;
		posY = screenCentrPoint.y - scalePicture * rectCopy->h / 2;
	}
	SDL_Rect rectOnScreen = { posX, posY, scaleActual * rectCopy->w, scaleActual * rectCopy->h};

	SDL_RenderCopy(gRenderer, p_tex, rectCopy,  &rectOnScreen);
}

void RenderWindow::renderIcon(SDL_Texture* p_tex, int iconPosX, int iconPosY, int iconWidth, int iconHeight)
{

	SDL_Rect iconOnScreen = { iconPosX , iconPosY , iconWidth , iconHeight };

	SDL_RenderCopy(gRenderer, p_tex, NULL , &iconOnScreen);
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
