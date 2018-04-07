#include "scenemanager.h"
#include <string>
#include <stdexcept>
#include <iostream>

SceneManager::SceneManager() {
	std::cout << "started initializing scene variables\n";
	isSoundOn = true;
	mouseLeftX = mouseLeftY = 0;
	scene = STARTUP;
	ScreenHeight = Graphics_Engine.getScreenHeight();
	ScreenWidth = Graphics_Engine.getScreenWidth();

	//load general reused res
	Bookman = TTF_OpenFont("../res/fonts/Bookman.ttf", 23);
	if(!Bookman) { printf("TTF_OpenFont Bookman: %s\n", TTF_GetError()); }
	//	TTF_SetFontHinting(Bookman, TTF_HINTING_LIGHT);
	Vecna = TTF_OpenFont("../res/fonts/Vecna.otf", 55);
	if(!Vecna) { printf("TTF_OpenFont Vecna: %s\n", TTF_GetError()); }
	logo1.setBlendMode(SDL_BLENDMODE_BLEND);
	backarrow.load("../res/textures/button_back_arrow_75x75.png");
	logo1.load("../res/textures/getdatloot-322x256.png");
	toolsicon.load("../res/textures/main_menu_other_tools.png");
	soundbutton_off.load("../res/textures/checkbox_sound_off_100x50.png");
	soundbutton_on.load("../res/textures/checkbox_sound_on_100x50.png");
	quitbutton.load("../res/textures/button_quit_90x38.png");
	resetbutton.load("../res/textures/button_reset_120x50.png");

	//load hoard loot res
	hoardlooticon.load("../res/textures/main_menu_hoard_loot.png");
	displaytext1.setBlendMode(SDL_BLENDMODE_BLEND);
	hoard_menu_display.resize(5);
	scroll_menu_display.resize(10);
	hoard_menu_display.resize(5);
	for (int i = 0; i < 5; i++) {
		if (i == 0)	hoard_menu_display[i].load(Vecna, hoard_loot_menu_items[i], Orange);
		else hoard_menu_display[i].load(Vecna, hoard_loot_menu_items[i], Green);
	}

	//load scroll generator res
	scrollicon.load("../res/textures/main_menu_scroll.png");
	scroll_menu_display.resize(10);
	for (int i = 0; i < 10; i++) {
		if (i == 0)	scroll_menu_display[i].load(Vecna, scroll_level_menu_items[i], Orange);
		else scroll_menu_display[i].load(Vecna, scroll_level_menu_items[i], Green);
	}

	loot_found_header.load(Vecna, "Treasure Pile: ", Orange);
	save_loot_button.load("../res/textures/button_save_100x75.png");


	//load spellbook generator res
	spellbookicon.load("../res/textures/main_menu_spellbook.png");
	create_spellbook_button.load("../res/textures/button_make_spellbook_75x75.png");
	tomeClickEntries = NON;
	spellbook_scene_header.load(Vecna, SPELLBOOK_SCENE_TEXT, Orange);
	for (int i = 0; i != 11; i++) {
		spellbook_scene_labels[i].load(Bookman, SPELLBOOK_INPUT_LABELS[i], Orange);
	}
	for (int i = 0; i != 11; i++) {  //init the rectangles that are clickable to enter in spellbook creation details
		if (i < 9) SPELLBOOK_ENTRY_RECTANGLES[i] = { ScreenWidth/2 + 40, 140 + 50*i, 50, 40 };
		else if (i == 9) SPELLBOOK_ENTRY_RECTANGLES[i] = { ScreenWidth/2 + 40, 590, 430, 40 };
		else SPELLBOOK_ENTRY_RECTANGLES[i] = {ScreenWidth/2 + 150, 640, 100, 40 };
	}
	spellbook_pages_used_draw = { ScreenWidth/2 + 40, 640, 100, 40 }; //hidden box where current pages used is displayed


	other_tools_header.load(Vecna, OTHER_TOOLS_HEADER_TEXT, Orange);
	button_gen_random_name.load("../res/textures/button_gen_random_name_120x50.png");

	for (int i = 0; i != 4; i++) {  //allows alpha blending
		texture_of_generated_names[i].setBlendMode(SDL_BLENDMODE_BLEND);
	}

	std::cout << "finished initilizing scene variables\n";
}

SceneManager::~SceneManager() {
	TTF_CloseFont(Vecna);
	Vecna = NULL;
	TTF_CloseFont(Bookman);
	Bookman = NULL;
}

void SceneManager::scene_selector() {
//	std::cout << "scene selecter choosing...\n";
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
//	std::cout << "scene selecter choosing success...\n";

}



