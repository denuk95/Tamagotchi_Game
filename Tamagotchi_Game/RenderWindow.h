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
	void renderCentr(SDL_Texture* p_tex, SDL_Rect* picture);
	void display();
	void cleanUp();


	private:
	int mainCharacterPosX = 0;
	SDL_Window* gWindow;
	SDL_Renderer* gRenderer;
	SDL_Texture* gTexture = nullptr;
	SDL_Point screenCentrPoint;
	SDL_Point screenLeftPoint;
	float scale = 1.8;
	float scalePicture = 1.5;
	const int TAMA_SCREEN_POS_LEFT_UP_X = 800;
	const int TAMA_SCREEN_POS_LEFT_UP_Y = 449;
	const int TAMA_SCREEN_WIDTH = 604;
	const int TAMA_SCREEN_HEIGHT = 292;

};
