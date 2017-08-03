#include "scenemanager.h"

void SceneManager::process_mouse_and_keyboard() {
	while (SDL_PollEvent (&e) != 0) {
		switch (e.type) {
		case SDL_QUIT:  // the Operating System's Window Manager Red X is clicked.
			scene = EXIT;
			break;
		case SDL_MOUSEBUTTONDOWN:  // any click
			switch (e.button.button) {
			case SDL_BUTTON_LEFT:
				mouseLeftX = e.button.x;
				mouseLeftY = e.button.y;
				switch (scene) {
				case EXIT: break;  //disallow key clicks
				case MAIN_MENU:
					//click horde loot?
					//todo click spellbook
					//todo click scrolls
					//todo click saved data
					break;
				case HORDE_LOOT:
					//click for the horde loot area
					break;
				}
				break;
			}
			break;
		}
	}
}

