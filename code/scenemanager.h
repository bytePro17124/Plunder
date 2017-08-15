#pragma once

#include "graphics.h"
#include "sound.h"
#include "texture.h"
#include "hoard_loot.h"
#include <vector>
#include <ctime>
#include <fstream>

class SceneManager {
public:
	SceneManager();
	~SceneManager();
	void scene_selector();
private:
	bool fullQuit;  // application management
	// SCENE MANAGEMENT
	SDL_graphics Graphics_Engine;
	SDL_Renderer *renderer;
	int ScreenWidth, ScreenHeight;  // scene sizes
	enum SCENE { STARTUP, MAIN_MENU, HOARD_LOOT, SPELLBOOK_CREATE, SCROLL_ROLLER, EXIT };  //core scenes
	SCENE scene;
	void scene_00_startup();  //startup logo and such
	void scene_01_main_menu();  // display main menu
	void scene_02_hoard_loot();
	void scene_03_spellbook();
	void scene_04_scroll();
	void scene_99_exit();  // do exit scene
	SDL_Event e;  // key press management
	int mouseLeftX, mouseLeftY;  // mouse movement and clicks management
	void process_mouse_and_keyboard();
	//preloaded scene variables below
	//	SDL_Color Black = {0,0,0,0};
	SDL_Color Orange = {255,115,35,0};
	SDL_Color White = {240,248,240,0};  //offwhite cause it looks better
	//	SDL_Color Red = {255,0,0,0};
	//	SDL_Color Blue = {0,0,255,0};
	//	SDL_Color Teal = {0,191,255,0};
	SDL_Color Green = {0,255,127,0};
	TTF_Font *Bookman, *Vecna;
	SDL_sound Sound_Engine;
	Texture logo1;
	Texture hoardlooticon, spellbookicon, scrollicon, toolsicon;
	const int offset = 10;
	Texture displaytext1;
	Texture backarrow;
	bool loot_results_ready = false;

	// Hoard Loot stuff

	std::vector<Texture> hoard_menu_display;
	const std::vector<std::string> hoard_loot_menu_items = { "Challenge Rating : ", "0-4", "5-10", "11-16", "17+" };
	Texture loot_found_header;
	std::vector<Texture> hoard_loot_display;
	Hoard_Loot treasure_pile;
	bool update_hoard_display = false;
	Texture save_loot_button;
	bool loot_write_out = false;
	bool loot_write_out_notification = false;
	std::string fileoutputname;
	Texture notification_text;
	Uint8 notification_alpha = 0;
	int loot_rolls_this_session = 0;
	std::time_t now;
	tm *ltm;
	std::ofstream save_to_file;

	// Hoard Loot stuff


	// Scroll stuff

	std::vector<Texture> scroll_menu_display;
	const std::vector<std::string> scroll_level_menu_items = { "Scroll Level : ", "  1  ", "  2  ", "  3  ", "  4  ", "  5  ", "  6  ", "  7  ", "  8  ", "  9  " };
	Texture scroll_loot_display;

	// Scroll stuff


};
