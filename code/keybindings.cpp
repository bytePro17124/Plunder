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
				case STARTUP:
					//DO NOTHING
					break;
				case MAIN_MENU:
					if ( (mouseLeftX > (ScreenWidth/2 - hordelooticon.getWidth()/2) && mouseLeftX < (ScreenWidth/2 + hordelooticon.getWidth()/2)) && (mouseLeftY > (ScreenHeight/2 - hordelooticon.getHeight()/2) && mouseLeftY < (ScreenWidth/2 + hordelooticon.getHeight()/2)))
					{
						scene = HORDE_LOOT;
					}
					//todo click spellbook
					//todo click scrolls
					//todo click saved data
					break;
				case HORDE_LOOT:
					//click for the horde loot area
					break;
				case EXIT: break;  //disallow key clicks
				}
				break;
			}
			break;
		}
	}
}

