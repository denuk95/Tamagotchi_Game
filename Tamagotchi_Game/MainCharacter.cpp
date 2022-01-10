#include "MainCharacter.h"

MainCharacter::MainCharacter(RenderWindow* gWindow)
{
	mainCharacterSprites[ 0 ].x = 16;
	mainCharacterSprites[ 0 ].y = 75;
	mainCharacterSprites[ 0 ].w = 70;
	mainCharacterSprites[ 0 ].h = 89;
	
	mainCharacterSprites[ 1 ].x = 170;
	mainCharacterSprites[ 1 ].y = 75;
	mainCharacterSprites[ 1 ].w = 70;
	mainCharacterSprites[ 1 ].h = 89;

	mainCharacterTx = gWindow->loadTexture("assets/mob2.png");

}

int MainCharacter::GetMainCharacterX(bool currentTime)
{
	
	if (mainCharacterPosX >= 980)
	{
		moveRight = false;
	}
	else if (mainCharacterPosX <= 480)
	{
		moveRight = true;
	}

	
	if (currentTime) {
		if (moveRight)
		{
			mainCharacterPosX += 3;
			//cout<< mainCharacterPosX<<endl;

		}
		else
		{
			mainCharacterPosX -= 3;
			//cout << mainCharacterPosX << endl;
		}
	}
	return mainCharacterPosX;


}
int MainCharacter::GetMainCharacterY()
{
	return mainCharacterPosY;
}

void MainCharacter::RenderMainCharacter(RenderWindow* gWindow, bool ticks)
{
	gWindow->render(mainCharacterTx, &mainCharacterSprites[frame / 40], GetMainCharacterX(ticks), mainCharacterPosY);

	
	++frame;

	if (frame / 40 >= 2)
	{
		frame = 0;
	}

}