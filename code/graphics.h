#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

class SDL_graphics {
public:
	
	static SDL_Renderer *renderer;

	SDL_graphics(void);
	~SDL_graphics(void);
	bool init(void);
	void clear(void);
	void render(void) { SDL_RenderPresent(renderer); }

	/* Accessors */
	SDL_Window *getWindow(void) { return mainWindow; }
	int getScreenWidth(void) { return SCREEN_WIDTH; }
	int getScreenHeight(void) { return SCREEN_HEIGHT; }
	
private:
	SDL_Window *mainWindow = NULL;
	int SCREEN_WIDTH;
	int SCREEN_HEIGHT;
};
