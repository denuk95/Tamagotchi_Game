#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <string>


class RenderWindow
{
	public:
	RenderWindow(const char* p_title, int p_w, int p_h);
	SDL_Texture* loadTexture(const char* p_filePath);
	void clearRender();
	void render(SDL_Texture* p_tex);
	void display();
	void cleanUp();



	private:
	SDL_Window* gWindow;
	SDL_Renderer* gRenderer;
};
