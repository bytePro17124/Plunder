#include "sound.h"

SDL_sound::SDL_sound() {
	//Initialize SDL
	if( SDL_Init(SDL_INIT_AUDIO) < 0 ) {
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
	}

	if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 ) {
		printf( "SDL_mixer could not initialize! SDL2_mixer Error: %s\n", Mix_GetError() );
		exit(-1);
	}

	startupSound = Mix_LoadWAV("assets/sounds/digital-life-16-bit.wav");
	if (startupSound == NULL) {
		printf("Failed to load startup sound! SDL_mixer Error: %s\n", Mix_GetError());
		exit(-1);
	}


}


SDL_sound::~SDL_sound() {
	Mix_FreeChunk(startupSound);
	startupSound = NULL;
	Mix_Quit();
}


void SDL_sound::playstartupsound() {
	Mix_PlayChannel( -1,  startupSound, 0 );
}
