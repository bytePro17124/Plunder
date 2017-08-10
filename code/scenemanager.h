#pragma once

#include "graphics.h"
#include "sound.h"
#include "texture.h"
#include "horde_loot.h"
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
	enum SCENE { STARTUP, MAIN_MENU, HORDE_LOOT, SPELLBOOK_CREATE, SCROLL_ROLLER, EXIT };  //core scenes
	SCENE scene;
	void scene_00_startup();  //startup logo and such
	void scene_01_main_menu();  // display main menu
	void scene_02_horde_loot();
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
	Texture hordelooticon, spellbookicon, scrollicon;
	const int offset = 10;
	Texture displaytext1;
	Texture backarrow;
	std::vector<Texture> horde_menu_display;
	const std::vector<std::string> horde_loot_menu_items = { "Party Loot Level: ", "0-4", "5-10", "11-16", "17+" };
	bool loot_results_ready = false;
	Texture loot_found_header;
	std::vector<Texture> horde_loot_display;
	Horde_Loot treasure_pile;
	bool update_horde_display = false;
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
};
