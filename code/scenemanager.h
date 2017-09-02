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
	//	SDL_Renderer *renderer;
	int ScreenWidth, ScreenHeight;  // scene sizes
	enum SCENE { STARTUP, MAIN_MENU, HOARD_LOOT, SPELLBOOK_CREATE, SCROLL_ROLLER, OTHER_TOOLS, EXIT };  //core scenes
	SCENE scene;
	void scene_00_startup();  //startup logo and such
	void scene_01_main_menu();  // display main menu
	void scene_02_hoard_loot();
	void scene_03_spellbook();
	void scene_04_scroll();
	void scene_05_other_tools();
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
	Texture soundbutton_on, soundbutton_off;
	bool isSoundOn;
	Texture logo1;
	Texture hoardlooticon, spellbookicon, scrollicon, toolsicon;
	const int offset = 10;
	Texture displaytext1;
	Texture backarrow;
	bool loot_results_ready = false;
	int frame_count = 0;
	Uint8 currentalpha = 0;

	// hoard_loot stuff
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
	int loot_rolls_this_session = 0;
	std::time_t now;
	tm *ltm;
	std::ofstream save_to_file;

	// gen_spellbook Stuff
	// Spellbook Stuff
	enum TOMECLICKENTRIES { NON = -1, L1 = 0, L2, L3, L4, L5, L6, L7, L8, L9, DESCRIPTION, PAGES };
	TOMECLICKENTRIES tomeClickEntries;  //entry cell management
	const std::string SPELLBOOK_SCENE_TEXT = "Create a Randomized Spellbook";
	const std::string SPELLBOOK_INPUT_LABELS[11] = { "Level 1", "Level 2", "Level 3", "Level 4", "Level 5", "Level 6", "Level 7", "Level 8", "Level 9", "Spellbook Material Description", "Pages Used / Total Pages In Tome" };
	const int SPELLBOOK_LIMITS[11] = { 31, 30, 27, 23, 23, 20, 15, 14, 12, 40, 10000 };  //[0-8] are max wizard spells per level possible, [9] is max description length, [10] is the max pages allowed in a spellbook
	Texture spellbook_scene_header, spellbook_scene_labels[11], create_spellbook_button;  //basic display handler assets
	SDL_Rect spellbook_pages_used_draw, spellbook_details_input[11];  //the fill out section of the spellbook
	std::string entriesText[11];  //entries 0-8 are the spells per level entries, 9 is the description, 10 is the pages total
	void spellbookInputValidator();  //validates or removes entriesText data, updates pagesNeededForCurrentSpells, updates has bools
	int pagesNeededForCurrentSpells = 0;
	bool hasValidPages = false, hasSpells = false, hasDescription = false;  //has variables to decide things
	Texture entryDisplay[11], pagesUsedDisplay;  //used to display valid entriesText
	void makeSpellbook();  //final function to build the spellbook once all entries are valid and sufficient
	bool readyToDisplay = false;
	void displayBuiltSpellbook();  //function to display the generated spells split across the pages
	std::vector<Texture> completedSpellbookTextures;  //malleable texture for displaying the final list of spells

	// gen_scroll stuff
	// Scroll stuff
	std::vector<Texture> scroll_menu_display;
	const std::vector<std::string> scroll_level_menu_items = { "Scroll Level : ", "  1  ", "  2  ", "  3  ", "  4  ", "  5  ", "  6  ", "  7  ", "  8  ", "  9  " };
	Texture scroll_loot_display;
	std::string GenerateScroll(const int& lvl); //also used in the makeSpellbook function

};
