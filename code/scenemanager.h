#pragma once

#include "preload.h"

class SceneManager {
public:
	SceneManager() {
		fullQuit = false;
		mouseLeftX = mouseLeftX = 0;
		scene = MAIN_MENU;
	}
	~SceneManager() {}

	void scene_selector();

private:
	bool fullQuit;  // application management
	Preload sv; // scene variables
	enum SCENE { EXIT, MAIN_MENU, HORDE_LOOT };  //core scenes
	SCENE scene; 
	void s00_exit();  // do exit scene
	void s01_main_menu();  // display main menu
	void s02_horde_loot();  // todo get this working first
	//void s04_scrolls();
	
	SDL_Event e;  // key press management
	int mouseLeftX, mouseLeftY;  // mouse movement and clicks management
	void process_mouse_and_keyboard();

};
