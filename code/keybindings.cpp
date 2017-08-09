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
				case STARTUP: break;
				case MAIN_MENU:
					if ( (mouseLeftX > (ScreenWidth/2 - hordelooticon.getWidth() - offset) && mouseLeftX < (ScreenWidth/2 - offset)) && (mouseLeftY > (ScreenHeight/2 - hordelooticon.getHeight() - offset) && mouseLeftY < (ScreenHeight/2 - offset)) ) {  // click horde loot
						scene = HORDE_LOOT;
						Sound_Engine.playmenusound();
					} else if ( (mouseLeftX > ScreenWidth/2 + offset && mouseLeftX < ScreenWidth/2 + offset + spellbookicon.getWidth()) && (mouseLeftY > (ScreenHeight/2 - offset - spellbookicon.getHeight()) && mouseLeftY < (ScreenHeight/2 - offset)) ) {  // click spellbook
						Sound_Engine.playmenusound();
					} else if ( (mouseLeftX > ScreenWidth/2 - scrollicon.getWidth() - offset && mouseLeftX < ScreenWidth/2 - offset) && (mouseLeftY > ScreenHeight/2 + offset && mouseLeftY < ScreenHeight/2 + offset + scrollicon.getHeight()) ) {  // click scroll+
						Sound_Engine.playmenusound();
					}
					break;
				case HORDE_LOOT:
					if ((mouseLeftX > 75 && mouseLeftX < 75 + backarrow.getWidth()) && (mouseLeftY > ScreenHeight - 150 && mouseLeftY < ScreenHeight - 150 + backarrow.getHeight())) {  //back button clicked
						if (!loot_results_ready) scene = MAIN_MENU;
						if (!loot_results_ready) Sound_Engine.playcancelsound();
						loot_results_ready = false;
						horde_loot_display.clear();
						treasure_pile.full_gear_list.clear();
					}
					if (!loot_results_ready) {
						for (int i = 1; i < 5; i++) {
							if ((mouseLeftX > ScreenWidth/2 - horde_menu_display[i].getWidth()/2 && mouseLeftX < ScreenWidth/2 + horde_menu_display[i].getWidth()/2) && ( mouseLeftY > 110 + i * 95 && mouseLeftY < 110 + i * 95 + horde_menu_display[i].getWidth()) ) {
								switch (i) {
								case 1:
									treasure_pile.GenerateHoardTreasureCR_0_4();
									update_horde_display = loot_results_ready = true;
									break;
								case 2:
									treasure_pile.GenerateHoardTreasureCR_5_10();
									update_horde_display = loot_results_ready = true;
									Sound_Engine.playlootsound();
									break;
								case 3:
									treasure_pile.GenerateHoardTreasureCR_11_16();
									update_horde_display = loot_results_ready = true;
									Sound_Engine.playlootsound();
									break;
								case 4:
									treasure_pile.GenerateHoardTreasureCR_17();
									update_horde_display = loot_results_ready = true;
									Sound_Engine.playlootsound();
									break;
								default:break;
								}
							}
						}
					} else {
						if (mouseLeftX > ScreenWidth - 75 - save_loot_button.getWidth() && mouseLeftX < ScreenWidth - 75 && mouseLeftY > ScreenHeight - 75 - save_loot_button.getHeight() && mouseLeftY < ScreenHeight - 75) {
							loot_write_out = true;
						}
					}
					break;
				case EXIT: break;  //disallow key clicks
				}
				break;
			}
			break;
			//		case SDL_MOUSEMOTION:
			//			mouseLeftX = e.button.x;
			//			mouseLeftY = e.button.y;

			//			break;
		}
	}
}

