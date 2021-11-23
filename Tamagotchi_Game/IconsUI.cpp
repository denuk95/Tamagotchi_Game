#include "IconsUI.h"

Icons::Icons(RenderWindow* gWindow)
{
	for (int i = 0; i < AMOUNT_OF_ICONS; i++)
	{
		iconsList[i] = NULL;
	}

	iconsList[0] = gWindow->loadTexture("assets/Icons_top_1.png");
	iconsList[1] = gWindow->loadTexture("assets/Icons_top_2.png");
	iconsList[2] = gWindow->loadTexture("assets/Icons_top_3.png");
	iconsList[3] = gWindow->loadTexture("assets/Icons_top_4.png");
	iconsList[4] = gWindow->loadTexture("assets/Icons_top_5.png");
	iconsList[5] = gWindow->loadTexture("assets/Icons_top_1.png");
	iconsList[6] = gWindow->loadTexture("assets/Icons_top_2.png");
	iconsList[7] = gWindow->loadTexture("assets/Icons_top_3.png");
	iconsList[8] = gWindow->loadTexture("assets/Icons_top_4.png");
	iconsList[9] = gWindow->loadTexture("assets/Icons_top_5.png");


}


void Icons::renderIcons(RenderWindow* gWindow, bool temp)
{
	int startPosX=535;
	int startPosY=308;
	int startPosY2=541;


	changeIconsAlpha(temp);


	for (int i = 0, j=5; i <= 4 || j <= 9; i++, j++)
	{
		
		gWindow->render(iconsList[i], startPosX, startPosY, 50, 50);
		gWindow->render(iconsList[j], startPosX, startPosY2, 50, 50);
		startPosX += 120;

	}


}

void Icons::changeIconsAlpha(bool alpha)
{
	for (int i = 0; i <= 9; i++)
	{
		SDL_SetTextureBlendMode(iconsList[i], SDL_BLENDMODE_BLEND);
		SDL_SetTextureAlphaMod(iconsList[i], 50);
	}

	if (counter > 9)
	{
		counter=0;
	}

	SDL_SetTextureAlphaMod(iconsList[counter], 250);


	if (alpha)
	{
		counter++;
	}



}
