#include "scenemanager.h"
#include <iostream>


SceneManager::SceneManager() {
	fullQuit = false;
	mouseLeftX = mouseLeftY = 0;
	scene = STARTUP;
	renderer = Graphics_Engine.getRenderer();
	ScreenHeight = Graphics_Engine.getScreenHeight();
	ScreenWidth = Graphics_Engine.getScreenWidth();
	Bookman = TTF_OpenFont("assets/fonts/Bookman.ttf", 31);
	if(!Bookman) { printf("TTF_OpenFont Bookman: %s\n", TTF_GetError()); }
	TTF_SetFontHinting(Bookman, TTF_HINTING_LIGHT);
	Vecna = TTF_OpenFont("assets/fonts/Vecna.otf", 55);
	if(!Vecna) { printf("TTF_OpenFont Vecna: %s\n", TTF_GetError()); }
	logo1.setRenderer(renderer);
	logo1.load("assets/textures/chest-130x105.png");
	hordelooticon.setRenderer(renderer);
	hordelooticon.load("assets/textures/horde_loot_icon.png");
	scrollicon.setRenderer(renderer);
	scrollicon.load("assets/textures/scroll_icon.png");
	spellbookicon.setRenderer(renderer);
	spellbookicon.load("assets/textures/spellbook_icon.png");
	displaytext1.setRenderer(renderer);
	displaytext1.setBlendMode(SDL_BLENDMODE_BLEND);
	backarrow.setRenderer(renderer);
	backarrow.load("assets/textures/back-arrow-75x75.png");
	horde_menu_display.resize(5);
	for (int i = 0; i < 5; i++) {
		horde_menu_display[i].setRenderer(renderer);
		if (i == 0)	horde_menu_display[i].load(Vecna, horde_loot_menu_items[i], Orange);
		else horde_menu_display[i].load(Bookman, horde_loot_menu_items[i], White);
//		horde_menu_display[i].setBlendMode(SDL_BLENDMODE_BLEND);
	}
	loot_found_header.setRenderer(renderer);
	loot_found_header.load(Vecna, "Treasure Pile: ", Orange);
	save_loot_button.setRenderer(renderer);
	save_loot_button.load("assets/textures/save.png");
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
			scene_02_horde_loot(); break;
		case SPELLBOOK_CREATE:
			scene_03_spellbook(); break;
		case SCROLL_ROLLER:
			scene_04_scroll(); break;
		case EXIT:
			scene_99_exit();
			fullQuit = true;
			break;
		}
	}
}
