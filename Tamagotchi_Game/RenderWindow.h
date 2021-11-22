#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <string>

using namespace std;


class RenderWindow
{
	public:
	RenderWindow(const char* p_title, int p_w, int p_h);
	~RenderWindow();
	SDL_Texture* loadTexture(const char* p_filePath);
	void clearRender();
	void render(SDL_Texture* p_tex);
	void render(SDL_Texture* p_tex, SDL_Rect* MainCharacterCopy, int posMainCharacterX, int posMainCharacterY);
	void render(SDL_Texture* p_tex, int iconPosX, int iconPosY, int iconWidth, int iconHeight);
	void display();
	void cleanUp();




	private:
	int mainCharacterPosX = 0;
	SDL_Window* gWindow;
	SDL_Renderer* gRenderer;
	SDL_Texture* gTexture;
};
