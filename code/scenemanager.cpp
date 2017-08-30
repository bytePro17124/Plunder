#include "scenemanager.h"
#include <string>
#include <stdexcept>
#include <iostream>


SceneManager::SceneManager() {
	isSoundOn = true;
	mouseLeftX = mouseLeftY = 0;
	scene = STARTUP;
	ScreenHeight = Graphics_Engine.getScreenHeight();
	ScreenWidth = Graphics_Engine.getScreenWidth();
	Bookman = TTF_OpenFont("assets/fonts/Bookman.ttf", 23);
	if(!Bookman) { printf("TTF_OpenFont Bookman: %s\n", TTF_GetError()); }
	//	TTF_SetFontHinting(Bookman, TTF_HINTING_LIGHT);
	Vecna = TTF_OpenFont("assets/fonts/Vecna.otf", 55);
	if(!Vecna) { printf("TTF_OpenFont Vecna: %s\n", TTF_GetError()); }
	logo1.setBlendMode(SDL_BLENDMODE_BLEND);
	backarrow.load("assets/textures/button_back_arrow_75x75.png");
	logo1.load("assets/textures/getdatloot-322x256.png");
	toolsicon.load("assets/textures/main_menu_other_tools.png");
	soundbutton_off.load("assets/textures/checkbox_sound_off_100x50.png");
	soundbutton_on.load("assets/textures/checkbox_sound_on_100x50.png");

	//hoard loot
	hoardlooticon.load("assets/textures/main_menu_hoard_loot.png");
	displaytext1.setBlendMode(SDL_BLENDMODE_BLEND);
	hoard_menu_display.resize(5);
	scroll_menu_display.resize(10);

	hoard_menu_display.resize(5);
	for (int i = 0; i < 5; i++) {
		if (i == 0)	hoard_menu_display[i].load(Vecna, hoard_loot_menu_items[i], Orange);
		else hoard_menu_display[i].load(Vecna, hoard_loot_menu_items[i], Green);
	}

	//scroll
	scrollicon.load("assets/textures/main_menu_scroll.png");
	scroll_menu_display.resize(10);
	for (int i = 0; i < 10; i++) {
		if (i == 0)	scroll_menu_display[i].load(Vecna, scroll_level_menu_items[i], Orange);
		else scroll_menu_display[i].load(Vecna, scroll_level_menu_items[i], Green);
	}

	loot_found_header.load(Vecna, "Treasure Pile: ", Orange);
	save_loot_button.load("assets/textures/button_save_100x75.png");


	//tome
	spellbookicon.load("assets/textures/main_menu_spellbook.png");
	tomeBuildState = NON;
	spellbook_scene_header.load(Vecna, SPELLBOOK_SCENE_TEXT, Orange);
	for (int i = 0; i != 11; i++) {
		spellbook_scene_labels[i].load(Bookman, SPELLBOOK_INPUT_LABELS[i], Green);
	}
	tome_description = "";
	for (int i = 0; i != 11; i++) {
		if (i < 9) spellbook_details_input[i] = { ScreenWidth/2 + 40, 140 + 50*i, 100, 40 };
		else if (i == 9) spellbook_details_input[i] = { ScreenWidth/2 + 40, 590, 430, 40 };
		else spellbook_details_input[i] = {ScreenWidth/2 + 150, 640, 100, 40 };
	}
	spellbook_pages_used_area = { ScreenWidth/2 + 40, 640, 100, 40 };
	pagesUsed = "0";
	pages_used_display.load(Bookman, pagesUsed, White);

	create_spellbook_button.load("assets/textures/button_make_spellbook_75x75.png");
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
		std::cout << "-invalid entry: data cell only accepts numeric digits\n";
		return false;
	}
	try {
		tmp = stoi(input);
	} catch (std::invalid_argument) {
	//	std::cout << "conversion to int failed\n";
		return (bool)tmp;
	}

	//std::cout << "conversion to int seems okay\n";

	if (tmp <= upper_limit && tmp != 0)
		return true;
	else {
		std::cout << "-invalid entry: your number is too large\n";
		return false;
	}
}

void SceneManager::doValidCheck() {
	hasDescription = hasSpells = false;  //reset both
	int i = 0;  //single iterator declare for the loops

	for (; i < 11; i++) {  //check clamping and valid input
		if (!inputText[i].empty()) {
			if (i < 9 || i == 10) {
				if (checkTextToIntWithClamp(inputText[i], maxSpellsPerLevel[i])) {
					//if (i < 9) std::cout << "success clamping on level " << i+1 << " spells\n";
					//else std::cout << "success clamping on setting pages\n";
				} else {
					std::cout << "--resetting spellbook cell " << i+1 << "\n";
					inputText[i] = "";
				}
			}
		}
	}

	//check if areas are ready for creating the spellbook
	for (i = 0; i < 11; i++) {
		if (i < 9) {
			if (!inputText[i].empty()) {
				hasSpells = true;
			}
		}
	}
	
	updatePagesUsed();
	
	if (!inputText[9].empty() && !inputText[10].empty() && stoi(inputText[10]) > stoi(pagesUsed)) {
		hasDescription = true;
	}

	needsValidityCheckUpdate = false;
}

void SceneManager::updatePagesUsed() {
	if (hasSpells) {
		int tmp = 0;
		for (int i = 0; i != 9; i++) {
			if (!inputText[i].empty()) {
				tmp += stoi(inputText[i]) * (i + 1) + 1;
			}
		}
		pagesUsed = std::to_string(tmp);
	} else {
		pagesUsed = "0";
	}
	pages_used_display.load(Bookman, pagesUsed, White);

}
