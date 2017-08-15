#include "scenemanager.h"
#include <iostream>


SceneManager::SceneManager() {
	fullQuit = false;
	mouseLeftX = mouseLeftY = 0;
	scene = STARTUP;
	renderer = Graphics_Engine.getRenderer();
	ScreenHeight = Graphics_Engine.getScreenHeight();
	ScreenWidth = Graphics_Engine.getScreenWidth();
	Bookman = TTF_OpenFont("assets/fonts/Bookman.ttf", 22);
	if(!Bookman) { printf("TTF_OpenFont Bookman: %s\n", TTF_GetError()); }
	//	TTF_SetFontHinting(Bookman, TTF_HINTING_LIGHT);
	Vecna = TTF_OpenFont("assets/fonts/Vecna.otf", 55);
	if(!Vecna) { printf("TTF_OpenFont Vecna: %s\n", TTF_GetError()); }
	logo1.setRenderer(renderer);
	logo1.load("assets/textures/chest-130x105.png");
	hoardlooticon.setRenderer(renderer);
	hoardlooticon.load("assets/textures/hoard_loot_icon.png");
	scrollicon.setRenderer(renderer);
	scrollicon.load("assets/textures/scroll_icon.png");
	spellbookicon.setRenderer(renderer);
	spellbookicon.load("assets/textures/spellbook_icon.png");
	toolsicon.setRenderer(renderer);
	toolsicon.load("assets/textures/other_tools.png");
	displaytext1.setRenderer(renderer);
	displaytext1.setBlendMode(SDL_BLENDMODE_BLEND);
	backarrow.setRenderer(renderer);
	backarrow.load("assets/textures/back-arrow-75x75.png");
	hoard_menu_display.resize(5);
	scroll_menu_display.resize(10);

	hoard_menu_display.resize(5);
	for (int i = 0; i < 5; i++) {
		hoard_menu_display[i].setRenderer(renderer);
		if (i == 0)	hoard_menu_display[i].load(Vecna, hoard_loot_menu_items[i], Orange);
		else hoard_menu_display[i].load(Vecna, hoard_loot_menu_items[i], Green);
	}

	scroll_menu_display.resize(10);
	for (int i = 0; i < 10; i++) {
		scroll_menu_display[i].setRenderer(renderer);
		if (i == 0)	scroll_menu_display[i].load(Vecna, scroll_level_menu_items[i], Orange);
		else scroll_menu_display[i].load(Vecna, scroll_level_menu_items[i], Green);
	}

	scroll_loot_display.setRenderer(renderer);

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
		case HOARD_LOOT:
			scene_02_hoard_loot(); break;
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
