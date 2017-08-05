#include "scenemanager.h"


SceneManager::SceneManager() {
	fullQuit = false;
	mouseLeftX = mouseLeftY = 0;
	scene = STARTUP;
	renderer = Graphics_Engine.getRenderer();
	ScreenHeight = Graphics_Engine.getScreenHeight();
	ScreenWidth = Graphics_Engine.getScreenWidth();
	Bookman = TTF_OpenFont("assets/fonts/Bookman.ttf", 30);
	if(!Bookman) { printf("TTF_OpenFont Bookman: %s\n", TTF_GetError()); }
	TTF_SetFontHinting(Bookman, TTF_HINTING_LIGHT);
	Vecna = TTF_OpenFont("assets/fonts/Vecna.otf", 45);
	if(!Vecna) { printf("TTF_OpenFont Vecna: %s\n", TTF_GetError()); }
	logo1.setRenderer(renderer);
	logo1.load("assets/textures/test-logo.png");
	hordelooticon.setRenderer(renderer);
	hordelooticon.load("assets/textures/horde_loot_icon.png");
	displaytext1.setRenderer(renderer);
	displaytext1.setBlendMode(SDL_BLENDMODE_BLEND);
}


SceneManager::~SceneManager() {
	TTF_CloseFont(Vecna);
	Vecna = NULL;
	TTF_CloseFont(Bookman);
	Bookman = NULL;
}


void SceneManager::scene_selector() {
	while (!fullQuit) {
		switch (scene) {
		case STARTUP:
			scene_00_startup(); break;
		case MAIN_MENU:
			scene_01_main_menu(); break;
		case HORDE_LOOT:
			scene_02_horde_loot();
			break;
		case EXIT:
			scene_99_exit();
			fullQuit = true;
			break;
		}
	}
}


