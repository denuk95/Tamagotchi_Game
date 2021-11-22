#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <stdio.h>
#include <string>

#include "RenderWindow.h"
#include "Buttons.h"
#include "MainCharacter.h"
#include "IconsUI.h"

using namespace std;

const int MONITOR_WIDTH = 1600;
const int MONITOR_HEIGHT = 900;

const int TOTAL_BUTTONS = 1;

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
		SDL_Texture* foregroundTx = window.loadTexture("assets/tama7.png");


		bool bGameRunning = false;
		SDL_Event gEvent;

		Buttons gButtons(&window);
		Icons gIcons(&window);
		MainCharacter gMainCharacter(&window);

		int frame = 0;

		unsigned int currentTime, lastTime=0;

		bool bTick= true;


		while (!bGameRunning)
		{
			int mouse_x, mouse_y;
			SDL_GetMouseState(&mouse_x, &mouse_y);
			int count = 0;
			bool bTemp=false;

			while (SDL_PollEvent(&gEvent) != 0)
			{
				if (gEvent.type == SDL_QUIT)
				{
					bGameRunning = true;
				}

				if (gEvent.type == SDL_KEYDOWN)
				{
					if (gEvent.key.keysym.sym == SDLK_ESCAPE)
					{
						bGameRunning =true;
					}

				}

				if (gEvent.type == SDL_KEYDOWN)
				{
					if (gEvent.key.keysym.sym == SDLK_UP)
					{
						bTemp = true;
					}

				}

				
				bTemp = gButtons.handleEvent(&gEvent, &window);

			}

			window.clearRender();

			window.render(backgroundTx);
			gMainCharacter.RenderMainCharacter(&window, bTick);

			window.render(foregroundTx);

			gIcons.renderIcons(&window, bTemp);

			gButtons.renderButtons(&window);

			currentTime = SDL_GetTicks();

			if (currentTime > lastTime + 30) {
				lastTime = currentTime;
				bTick = true;
			}
			else
			{
				bTick = false;
			}

			window.display();

		}

		window.cleanUp();

		IMG_Quit();
		SDL_Quit();
	}
	



	return 0;
}