#include "Tab.h"

Tab::Tab(RenderWindow* temp1Window, const char* path)
{

	this->tempWindow = temp1Window;


	tabSprites[0].x = 0;
	tabSprites[0].y = 0;
	tabSprites[0].w = TAB_SPRITES_WIDTH;
	tabSprites[0].h = TAB_SPRITES_HEIGHT;

	tabSprites[1].x = 0;
	tabSprites[1].y = 50;
	tabSprites[1].w = TAB_SPRITES_WIDTH;
	tabSprites[1].h = TAB_SPRITES_HEIGHT;

	tab = tempWindow->loadTexture(path);

}

void Tab::render(RenderWindow* tempWindow)
{
	tempWindow->render(tab, &tabSprites[frame / 40]);

	++frame;
	if (frame / 40 >= 2)
	{
		frame = 0;
	}

}