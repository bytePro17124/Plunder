#pragma once

#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL.h>

class SDL_sound {
public:
	SDL_sound();
	~SDL_sound();
	void playstartupsound();
	void playshutdownsound();
	void playlootsound();
	void playcancelsound();
	void playmenusound();
private:
	//The music that will be played
	//	Mix_Music *themeMusic = NULL;
	//The sound effects that will be used
	Mix_Chunk *startupSound = NULL;
	Mix_Chunk *shutdownSound = NULL;
	Mix_Chunk *lootSound = NULL;
	Mix_Chunk *cancelSound = NULL;
	Mix_Chunk *menuSound = NULL;
};
