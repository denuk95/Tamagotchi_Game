#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <stdio.h>
#include <string>

#include "RenderWindow.h"
#include "CircledButton.h"
#include "MainCharacter.h"
#include "IconsUI.h"
#include "Tabs/Tab.h"
#include "Tabs/Food.h"
#include "Tabs/Toilet.h"
#include "StatTracking.h"

using namespace std;

const int MONITOR_WIDTH = 1600;
const int MONITOR_HEIGHT = 900;
const int CIRCLE_RADIUS = 37;


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

bool isDead(StatTracking &tracking)
{
	if (tracking.getHealth() < 0)
	{
		return true;
	}
	return false;
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

		CircledButton circleLeft (&window ,658, 690, CIRCLE_RADIUS);
		CircledButton circleCenter (&window, 799, 765, CIRCLE_RADIUS);
		CircledButton circleRight (&window, 940, 690, CIRCLE_RADIUS);

		CircledButton* buttons[3];
		buttons[0] = &circleLeft;
		buttons[1] = &circleCenter;
		buttons[2] = &circleRight;

		Tab* arrayTabs[5];


		Food food(&window);
		Toilet toilet(&window);

		//Tab information(&window);
		
		//Tab attention(&window);
		//Tab medicine(&window);

		arrayTabs[0] = &food;
		arrayTabs[1] = &toilet;
		//arrayTabs[2] = &information;
		//arrayTabs[3] = &attention;
		//arrayTabs[4] = &medicine;



		Icons gIcons(&window);
		MainCharacter gMainCharacter(&window);

		int frame = 0;

		unsigned int currentTime, lastTime=0;

		bool bTick= true;
		bool displayMC = true;
		bool iconDisplay = false;
		int temporary = 0;
		bool canBeSwitched = true;
		StatTracking tracking;


		while (!bGameRunning)
		{
			int mouse_x, mouse_y;
			SDL_GetMouseState(&mouse_x, &mouse_y);
			int count = 0;
			bool bTemp = false;
			bool bPressed = false;




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

					if (gEvent.key.keysym.sym == SDLK_UP)
					{
						tracking.record();
					}
					if (gEvent.key.keysym.sym == SDLK_DOWN)
					{
						tracking.read();
					}

				}


					for (int i = 0; i < 3; i++)
					{
						buttons[i]->handleEvent(&gEvent, &window);

						if (i == 0 && canBeSwitched)
						{
							bTemp = buttons[i]->handleEvent(&gEvent, &window);
							if (bTemp)
							{
								cout << gIcons.getCurrentIcon() << endl;
							}

						}
						if (i == 2 && canBeSwitched)
						{

							bPressed = buttons[i]->handleEvent(&gEvent, &window);
							if (bPressed)
							{
								cout << gIcons.getCurrentIcon() << endl;
								iconDisplay = true;

								temporary = currentTime + 5000;
								arrayTabs[gIcons.getCurrentIcon()]->action(tracking);
							}
						}



					}


			}

			window.clearRender();

			window.render(backgroundTx);

			for (int i = 0; i < 3; i++)
			{
				buttons[i]->renderButtons();
			}



			if (isDead(tracking))
			{
				displayMC = false;
				canBeSwitched = false;
				arrayTabs[gIcons.getCurrentIcon()]->render(&window);
			}


			if (iconDisplay)
			{
				displayMC = false;
				arrayTabs[gIcons.getCurrentIcon()]->render(&window);
				canBeSwitched = false;
				if (temporary < currentTime)
				{

					displayMC = true;
					canBeSwitched = true;
					iconDisplay = false;
				}
			}

			if (displayMC)
			{
				gMainCharacter.RenderMainCharacter(&window, bTick);
			}

			window.render(foregroundTx);

			gIcons.renderIcons(&window, bTemp);




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

		tracking.record();

		window.cleanUp();

		IMG_Quit();
		SDL_Quit();
	}
	



	return 0;
}