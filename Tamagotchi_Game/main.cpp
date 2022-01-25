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
		bool bGameRunning = false;
		
		RenderWindow window("Tamagotchi", MONITOR_WIDTH, MONITOR_HEIGHT);
		SDL_Texture* backgroundTx = window.loadTexture("assets/tama6.png");
		SDL_Texture* foregroundTx = window.loadTexture("assets/tama7.png");
		SDL_Texture* screenMessagesTx = window.loadTexture("assets/screenMessages.png");
		

		SDL_Rect gameOver{0,0,100,50};

		MainCharacter gMainCharacter(&window);
		SDL_Event gEvent;
		Icons gIcons(&window);




		//Buttons
		CircledButton circleLeft (&window ,658, 690, CIRCLE_RADIUS);
		CircledButton circleCenter (&window, 799, 765, CIRCLE_RADIUS);
		CircledButton circleRight (&window, 940, 690, CIRCLE_RADIUS);

		CircledButton* buttons[3];
		buttons[0] = &circleLeft;
		buttons[1] = &circleCenter;
		buttons[2] = &circleRight;


		//Tabs
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

		StatTracking tracking;



		int frame = 0;
		unsigned int temporary = 0;
		unsigned int resetTimer = 0;
		unsigned int currentTime, lastTime=0;

		bool bTick= true;
		bool bDisplayMC = true;
		bool bActionDisplay = false;
		bool bButtonIsActive = true;
		bool bNewGame = true;
		bool bSelection = true;


		while (!bGameRunning)
		{
			int mouse_x, mouse_y;
			SDL_GetMouseState(&mouse_x, &mouse_y);
			int count = 0;
			bool bTemp = false;
			bool bPressed = false;
			bool bReset = false;




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

						if (i == 0 && bButtonIsActive)
						{
							bTemp = buttons[i]->handleEvent(&gEvent, &window, false);
						}

						if (i == 1 && (bButtonIsActive || isDead(tracking)))
						{
							bReset = buttons[i]->handleEvent(&gEvent, &window, true);
						}


						if (i == 2 && bButtonIsActive)
						{
							bPressed = buttons[i]->handleEvent(&gEvent, &window, false);

							if (bPressed)
							{
								bActionDisplay = true;
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


			if (bReset)
			{
				cout<<"RESET"<<endl;
				tracking.reset();
				bButtonIsActive = true;
				bDisplayMC = true;
				bSelection = true;
			}

			if (isDead(tracking))
			{
				bDisplayMC = false;
				bButtonIsActive = false;
				bSelection = false;
				window.render(screenMessagesTx, &gameOver);
			}


			if (bActionDisplay)
			{
				bDisplayMC = false;
				arrayTabs[gIcons.getCurrentIcon()]->render(&window);
				bButtonIsActive = false;
				if (temporary < currentTime)
				{

					bDisplayMC = true;
					bButtonIsActive = true;
					bActionDisplay = false;
				}
			}

			if (bDisplayMC)
			{
				gMainCharacter.RenderMainCharacter(&window, bTick);
			}

			window.render(foregroundTx);

			gIcons.renderIcons(&window, bTemp, bSelection);




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