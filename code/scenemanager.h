#pragma once

#include "graphics.h"

class SceneManager {
public:
	SceneManager() {
		fullQuit = false;
		mouseLeftX = mouseLeftY = 0;
		scene = MAIN_MENU;
		renderer = Graphics_Engine.getRenderer();
		ScreenHeight = Graphics_Engine.getScreenHeight();
		ScreenWidth = Graphics_Engine.getScreenWidth();
		Bookman = TTF_OpenFont("assets/fonts/Bookman.ttf", 30);
		if(!Bookman) { printf("TTF_OpenFont Bookman: %s\n", TTF_GetError()); }
		TTF_SetFontHinting(Bookman, TTF_HINTING_LIGHT);
		Vecna = TTF_OpenFont("assets/fonts/Vecna.otf", 45);
		if(!Vecna) { printf("TTF_OpenFont Vecna: %s\n", TTF_GetError()); }
	}
	
	~SceneManager() {
		TTF_CloseFont(Vecna);
		Vecna = NULL;
		TTF_CloseFont(Bookman);
		Bookman = NULL;
	}

	void scene_selector();

private:

	bool fullQuit;  // application management
	
	// SCENE MANAGEMENT
	SDL_graphics Graphics_Engine;
	SDL_Renderer *renderer;
	int ScreenWidth, ScreenHeight;  // scene sizes
	
	enum SCENE { EXIT, MAIN_MENU, HORDE_LOOT };  //core scenes
	SCENE scene; 
	
	void scene_00_exit();  // do exit scene
	void scene_01_main_menu();  // display main menu
	void scene_02_horde_loot(); 
	
	SDL_Event e;  // key press management
	int mouseLeftX, mouseLeftY;  // mouse movement and clicks management
	void process_mouse_and_keyboard();
	
	//preloaded scene variables below
	SDL_Color Black = {0,0,0,0};
	SDL_Color Orange = {255,115,35,0};
	SDL_Color White = {240,248,240,0};  //offwhite cause it looks better
	SDL_Color Red = {255,0,0,0};
	SDL_Color Blue = {0,0,255,0};
	SDL_Color Teal = {0,191,255,0};
	SDL_Color Green = {0,255,127,0};
	
	TTF_Font *Leadcoat, *Bookman, *Vivian, *Vecna, *Verdana;

	
};
