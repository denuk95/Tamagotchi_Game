#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <string>

#include "RenderWindow.h"

using namespace std;

int MONITOR_WIDTH = 1600;
int MONITOR_HEIGHT = 900;

bool init()
{
	bool success = true;
	
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		printf("SDL2 couldn't initialize! SDL Error: %s\n", SDL_GetError());
		success=false;	
	}	
	
	if (!IMG_Init(IMG_INIT_PNG))
	{
		printf("IMG couldn't initialize! SDL Error: %s\n", IMG_GetError());
		success=false;	
	}

	return success;
}


int main(int argc, char* args[])
{
	if (!init())
	{
		cout<<"Failed init!";
	}
	else
	{
		RenderWindow window("Tamagotchi", MONITOR_WIDTH, MONITOR_HEIGHT);
		SDL_Texture* backgroundTx = window.loadTexture("assets/tama6.png");
		SDL_Texture* frontTx = window.loadTexture("assets/tama7.png");

		bool gameRunning = false;
		SDL_Event gEvent;

		
		while (!gameRunning)
		{
			while (SDL_PollEvent(&gEvent) != 0)
			{
				if (gEvent.type == SDL_KEYDOWN)
				{
					if (gEvent.key.keysym.sym == SDLK_ESCAPE)
					{
						gameRunning =true;
					}
				}

			}
			window.clearRender();
			
			window.render(backgroundTx);
			window.render(frontTx);
			window.display();
		}

		window.cleanUp();

		IMG_Quit();
		SDL_Quit();
	}
	



	return 0;
}