#include "Tab.h"

Tab::Tab(RenderWindow* temp1Window, const char* path)
{
	this->tempWindow = temp1Window;


	mainCharacterSprites[0].x = 53;
	mainCharacterSprites[0].y = 11;
	mainCharacterSprites[0].w = 88;
	mainCharacterSprites[0].h = 32;

	mainCharacterSprites[1].x = 53;
	mainCharacterSprites[1].y = 61;
	mainCharacterSprites[1].w = 88;
	mainCharacterSprites[1].h = 32;

	tab = tempWindow->loadTexture(path);

}

void Tab::render(RenderWindow* tempWindow)
{
	tempWindow->render(tab, &mainCharacterSprites[frame / 40], 600, 450);


	++frame;

	if (frame / 40 >= 2)
	{
		frame = 0;
	}




}