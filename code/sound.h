#pragma once

#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL.h>


class SDL_sound {
public:
	SDL_sound();
	~SDL_sound();
	void playstartupsound();

private:

	//The music that will be played
//	Mix_Music *themeMusic = NULL;


	//The sound effects that will be used
	Mix_Chunk *startupSound = NULL;
//	Mix_Chunk *gHigh = NULL;
//	Mix_Chunk *gMedium = NULL;
//	Mix_Chunk *gLow = NULL;

};
