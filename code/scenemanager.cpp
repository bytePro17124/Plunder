#include "scenemanager.h"
#include <string>
#include <stdexcept>
#include <iostream>


SceneManager::SceneManager() {
	fullQuit = false;
	mouseLeftX = mouseLeftY = 0;
	scene = STARTUP;
	renderer = Graphics_Engine.getRenderer();
	ScreenHeight = Graphics_Engine.getScreenHeight();
	ScreenWidth = Graphics_Engine.getScreenWidth();
	Bookman = TTF_OpenFont("assets/fonts/Bookman.ttf", 23);
	if(!Bookman) { printf("TTF_OpenFont Bookman: %s\n", TTF_GetError()); }
	//	TTF_SetFontHinting(Bookman, TTF_HINTING_LIGHT);
	Vecna = TTF_OpenFont("assets/fonts/Vecna.otf", 55);
	if(!Vecna) { printf("TTF_OpenFont Vecna: %s\n", TTF_GetError()); }
	logo1.setRenderer(renderer);
	logo1.setBlendMode(SDL_BLENDMODE_BLEND);
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

	tomeBuildState = NON;
	spellbook_scene_header.setRenderer(renderer);
	spellbook_scene_header.load(Vecna, SPELLBOOK_SCENE_TEXT, Orange);
	for (int i = 0; i != 11; i++) {
		spellbook_scene_labels[i].setRenderer(renderer);
		spellbook_scene_labels[i].load(Bookman, SPELLBOOK_INPUT_LABELS[i], Green);
	}
	tome_description = "";
	for (int i = 0; i != 11; i++) {
		if (i < 9) spellbook_details_input[i] = { ScreenWidth/2 + 40, 140 + 50*i, 100, 40 };
		else if (i == 9) spellbook_details_input[i] = { ScreenWidth/2 + 40, 590, 430, 40 };
		else spellbook_details_input[i] = {ScreenWidth/2 + 150, 640, 100, 40 };
	}

	for (int i = 0; i != 11; i++)  {
		inputTextDisplay[i].setRenderer(renderer);
	}

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
		case STARTUP: scene_00_startup(); break;
		case MAIN_MENU: scene_01_main_menu(); break;
		case HOARD_LOOT: scene_02_hoard_loot(); break;
		case SPELLBOOK_CREATE: scene_03_spellbook(); break;
		case SCROLL_ROLLER: scene_04_scroll(); break;
		case OTHER_TOOLS: scene_05_other_tools(); break;
		case EXIT: scene_99_exit(); break;
		}
	}
}


bool SceneManager::checkTextToIntWithClamp(const std::string &input, const int &upper_limit) {
	int tmp = 0;
	//make sure string is only numeric digits
	if (input.find_first_not_of("0123456789") == std::string::npos) {

	} else {
		std::cout << "string has non-numeric digits in it - blasting\n";
		return false;
	}
	try {
		tmp = stoi(input);
	} catch (std::invalid_argument) {
		std::cout << "conversion to int failed\n";
		return (bool)tmp;
	}

	std::cout << "conversion to int seems okay\n";

	if (tmp <= upper_limit && tmp != 0)
		return true;
	else {
		std::cout << "but my spoon is too big\n";
		return false;
	}
}
