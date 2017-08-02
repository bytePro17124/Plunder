#include "graphics.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

bool SDL_graphics::init()
{
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) {
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		return false;
	} else {
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
			printf("Warning: Linear texture filtering not enabled!");
		}
		mainWindow = SDL_CreateWindow("Plunder Loot",
									  SDL_WINDOWPOS_UNDEFINED,
									  SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
									  SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (mainWindow == NULL) {
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
			return false;
		} else {
			mainRenderer = SDL_CreateRenderer(mainWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
			if (mainRenderer == NULL) {
				printf("SDL Failed to Create Renderer! ERROR: %s. \n", SDL_GetError());
				return false;
			} else {
				SDL_SetRenderDrawColor(mainRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags)) {
					printf("SDL_image could not initialize! SDL2_image Error %s\n", IMG_GetError());
					return false;
				}
				if (TTF_Init() == -1) {
					printf("SDL_ttf could not initialize! SDL2_ttf Error: %s\n", TTF_GetError());
					return false;
				}
				if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 ) {
					printf( "SDL_mixer could not initialize! SDL2_mixer Error: %s\n", Mix_GetError() );
					return false;
				}
			}
		}
	}
	return true;
}

void SDL_graphics::clear(void) {
	SDL_SetRenderDrawColor(mainRenderer, 0x00, 0x00, 0x00, 0xFF);  //black opague
	SDL_RenderClear(mainRenderer);
}

SDL_graphics::~SDL_graphics(void) {
	SDL_DestroyRenderer(mainRenderer);
	mainRenderer = NULL;
	SDL_DestroyWindow(mainWindow);
	mainWindow = NULL;
	Mix_Quit();
	IMG_Quit();
	TTF_Quit();
	SDL_Quit();
}

SDL_graphics::SDL_graphics() {

	SCREEN_WIDTH = 1280;
	SCREEN_HEIGHT = 720;

	printf("Screen Size Defaulted to %dx%d\n", SCREEN_WIDTH, SCREEN_HEIGHT);

	init();
}
