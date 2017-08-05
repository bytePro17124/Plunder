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
	shutdownSound = Mix_LoadWAV("assets/sounds/powerdown-16-bit.wav");
	if (shutdownSound == NULL) {
		printf("Failed to load shutdown sound! SDL_mixer Error: %s\n", Mix_GetError());
		exit(-1);
	}
	lootSound = Mix_LoadWAV("assets/sounds/small-box-opening-16-bit.wav");
	if (lootSound == NULL) {
		printf("Failed to load loot sound! SDL_mixer Error: %s\n", Mix_GetError());
		exit(-1);
	}
	cancelSound = Mix_LoadWAV("assets/sounds/cancel-16-bit.wav");
	if (cancelSound == NULL) {
		printf("Failed to load cancel sound! SDL_mixer Error: %s\n", Mix_GetError());
		exit(-1);
	}
}

SDL_sound::~SDL_sound() {
	Mix_FreeChunk(startupSound);
	startupSound = NULL;
	Mix_FreeChunk(shutdownSound);
	shutdownSound = NULL;
	Mix_FreeChunk(lootSound);
	lootSound = NULL;
	Mix_FreeChunk(cancelSound);
	cancelSound = NULL;
	Mix_Quit();
}

void SDL_sound::playstartupsound() {
	Mix_PlayChannel( -1,  startupSound, 0 );
}


void SDL_sound::playshutdownsound() {
	Mix_PlayChannel( -1, shutdownSound, 0 );
}

void SDL_sound::playlootsound() {
	Mix_PlayChannel( -1, lootSound, 0 );

}

void SDL_sound::playcancelsound() {
	Mix_PlayChannel( -1, cancelSound, 0);
}
