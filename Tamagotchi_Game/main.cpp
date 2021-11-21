#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <stdio.h>
#include <string>

#include "RenderWindow.h"
#include "Buttons.h"
#include "MainCharacter.h"

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
		SDL_Texture* tamaSkin = window.loadTexture("assets/mob2.png");

		bool gameRunning = false;
		SDL_Event gEvent;

		Buttons gButtons(&window);
		MainCharacter gMainCharacter;


		unsigned int lastTime = 0, currentTime;
		int frame = 0;
		int positionX=480;
		bool directionMovements=true;
		while (!gameRunning)
		{
			int mouse_x, mouse_y;
			SDL_GetMouseState(&mouse_x, &mouse_y);
			int count = 0;

			while (SDL_PollEvent(&gEvent) != 0)
			{
				if (gEvent.type == SDL_QUIT)
				{
					gameRunning = true;
				}

				if (gEvent.type == SDL_KEYDOWN)
				{
					if (gEvent.key.keysym.sym == SDLK_ESCAPE)
					{
						gameRunning =true;
					}

				}


				gButtons.handleEvent(&gEvent, &window);

			}

			window.clearRender();

			window.render(backgroundTx);



			window.render(tamaSkin, gMainCharacter.GetMainCharacterRect(frame/40), positionX);

			window.render(foregroundTx);


			gButtons.renderButtons(&window);



			++frame;

			if (frame / 40 >= 2)
			{
				frame = 0;
			}

			if (positionX >= 980)
			{
				directionMovements=false;
			}
			else if(positionX <= 480)
			{
				directionMovements = true;
			}

			currentTime = SDL_GetTicks();
			if (currentTime > lastTime + 60) {
				printf("Report:%i", currentTime);
				lastTime = currentTime;
				if (directionMovements)
				{
					positionX += 5;
				}
				else
				{
					positionX -= 5;
				}
			}



			window.display();

		}

		window.cleanUp();

		IMG_Quit();
		SDL_Quit();
	}
	



	return 0;
}