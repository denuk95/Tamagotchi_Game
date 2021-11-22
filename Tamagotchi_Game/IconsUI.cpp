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

	switch (counter)
	{
	case 0:
		SDL_SetTextureAlphaMod(iconsList[0], 250);
		break;
	case 1:
		SDL_SetTextureAlphaMod(iconsList[1], 250);
		break;
	case 2:
		SDL_SetTextureAlphaMod(iconsList[2], 250);
		break;
	case 3:
		SDL_SetTextureAlphaMod(iconsList[3], 250);
		break;
	case 4:
		SDL_SetTextureAlphaMod(iconsList[4], 250);
		break;
	case 5:
		SDL_SetTextureAlphaMod(iconsList[5], 250);
		break;
	case 6:
		SDL_SetTextureAlphaMod(iconsList[6], 250);
		break;
	case 7:
		SDL_SetTextureAlphaMod(iconsList[7], 250);
		break;
	case 8:
		SDL_SetTextureAlphaMod(iconsList[8], 250);
		break;
	case 9:
		SDL_SetTextureAlphaMod(iconsList[9], 250);
		break;
	default:
		counter=0;
		break;
	}

	if (alpha)
	{
		counter++;
	}



}
