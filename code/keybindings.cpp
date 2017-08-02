#include "scenemanager.h"

const int RADIO_BUTTON_SIZE = 26;

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
				case MAIN_MENU:
					//click horde loot?
                                        //click spellbook
                                        //click scrolls
                                        //click saved data
					break;
				break;
			}
			break;
                case SDL_MOUSEMOTION:          // any mouse motion
                        mouseLeftX = e.motion.x;
                        mouseLeftY = e.motion.y;
                break;
		}
	}
}

