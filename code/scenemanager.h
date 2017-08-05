#pragma once

#include "graphics.h"
#include "sound.h"
#include "texture.h"
#include <vector>

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
	enum SCENE { STARTUP, MAIN_MENU, HORDE_LOOT, EXIT };  //core scenes
	SCENE scene;
	void scene_00_startup();  //startup logo and such
	void scene_01_main_menu();  // display main menu
	void scene_02_horde_loot();
	void scene_99_exit();  // do exit scene
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
	SDL_sound Sound_Engine;
	Texture logo1;
	Texture hordelooticon;
	Texture displaytext1;
	Texture backarrow;
	std::vector<Texture> horde_menu_display;
	const std::vector<std::string> horde_loot_menu_items = { "Party Loot Level: ", "0-4", "5-10", "11-16", "17+" };
	std::vector<Texture> horde_loot_display;
	std::vector<std::string> horde_loot_found_items = { "Nothing here" };
};
