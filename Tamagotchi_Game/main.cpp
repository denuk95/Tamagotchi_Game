#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <string>


using namespace std;

const int MONITOR_WIDTH = 1600;
const int MONITOR_HEIGHT = 900;


SDL_Window* gWindow = NULL;
SDL_Texture* gTexture = NULL;
SDL_Renderer* gRenderer = NULL;
SDL_Surface* gSurface = NULL;

bool init()
{
	bool success = true;
	
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		printf("SDL2 couldn't initialize! SDL Error: %s\n", SDL_GetError());
		success=false;	
	}
	else
	{
		gWindow = SDL_CreateWindow("Tamagotchi", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, MONITOR_WIDTH, MONITOR_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			printf("Window couldn't be created! SDL Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
			if (gRenderer == NULL)
			{
				printf("Renderer couldn't be created! SDL Error: %s\n", SDL_GetError());
				success = false;
			}
			else {
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
			}
		}
	}




	return success;
}

bool loadFromFile()
{
	gSurface = IMG_Load("assets/tama4.png");
	if (gSurface == NULL)
	{
		printf("Image couldn't be load %s\n", SDL_GetError());
		return false;
	}
	else
	{
		
		gTexture = SDL_CreateTextureFromSurface(gRenderer, gSurface);
		if (gTexture == NULL)
		{
			printf("Unable to create texture %s\n", SDL_GetError());
		}

		SDL_FreeSurface(gSurface);
	}
	 return true;
}


int main(int argc, char* args[])
{
	if (!init())
	{
		cout<<"Failed init!";
	}
	else
	{
		if (!loadFromFile())
		{
			printf("Unable to load IMG %s\n", SDL_GetError());
		}
		else
		{
			SDL_Event gEvent;
			bool quit=false;
			while (!quit)
			{
				while (SDL_PollEvent(&gEvent) != 0)
				{
					if (gEvent.type == SDL_KEYDOWN)
					{
						if (gEvent.key.keysym.sym == SDLK_ESCAPE)
						{
							quit=true;
						}
					}

				}
				SDL_RenderCopy(gRenderer, gTexture, NULL, NULL);
				SDL_RenderPresent(gRenderer);
			}


		}

	}


	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	SDL_DestroyTexture(gTexture);
	gWindow = NULL;
	gRenderer = NULL;
	gTexture=NULL;


	IMG_Quit();
	SDL_Quit();


	return 0;
}