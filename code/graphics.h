#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

class SDL_graphics {
public:
	SDL_graphics(void);
	~SDL_graphics(void);

	bool init(void);
	void clear(void);
	void render(void) { SDL_RenderPresent(mainRenderer); }

	/* Accessors */
	SDL_Window *getWindow(void) { return mainWindow; }
	SDL_Renderer *getRenderer(void) { return mainRenderer; }
	int getScreenWidth(void) { return SCREEN_WIDTH; }
	int getScreenHeight(void) { return SCREEN_HEIGHT; }

private:
	SDL_Window *mainWindow = NULL;
	SDL_Renderer *mainRenderer = NULL;

	int SCREEN_WIDTH;
	int SCREEN_HEIGHT;
};
