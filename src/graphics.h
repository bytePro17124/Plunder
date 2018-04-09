#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

class SDL_graphics {
public:

	static SDL_Renderer *renderer;

	SDL_graphics();

	~SDL_graphics();

	bool init();

	void clear();

	void render() { SDL_RenderPresent(renderer); }

	/* Accessors */
	SDL_Window *getWindow() { return mainWindow; }

	int getScreenWidth() { return SCREEN_WIDTH; }

	int getScreenHeight() { return SCREEN_HEIGHT; }

private:
	SDL_Window *mainWindow = NULL;
	int SCREEN_WIDTH;
	int SCREEN_HEIGHT;
};
