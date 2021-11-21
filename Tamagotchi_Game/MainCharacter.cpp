#include "MainCharacter.h"

MainCharacter::MainCharacter()
{
	MainCharacterSprites[ 0 ].x = 16;
	MainCharacterSprites[ 0 ].y = 75;
	MainCharacterSprites[ 0 ].w = 70;
	MainCharacterSprites[ 0 ].h = 89;
	
	MainCharacterSprites[ 1 ].x = 170;
	MainCharacterSprites[ 1 ].y = 75;
	MainCharacterSprites[ 1 ].w = 70;
	MainCharacterSprites[ 1 ].h = 89;
}

SDL_Rect* MainCharacter::GetMainCharacterRect(int counter)
{

	return &MainCharacterSprites[counter];
}
