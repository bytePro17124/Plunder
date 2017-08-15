#include "scenemanager.h"
#include "random_gen.h"

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
					if ( (mouseLeftX > (ScreenWidth/2 - hoardlooticon.getWidth() - offset) && mouseLeftX < (ScreenWidth/2 - offset)) && (mouseLeftY > (ScreenHeight/2 - hoardlooticon.getHeight() - offset) && mouseLeftY < (ScreenHeight/2 - offset)) ) {  // click hoard loot
						scene = HOARD_LOOT;
						//                        Sound_Engine.playmenusound();
					} else if ( (mouseLeftX > ScreenWidth/2 + offset && mouseLeftX < ScreenWidth/2 + offset + spellbookicon.getWidth()) && (mouseLeftY > (ScreenHeight/2 - offset - spellbookicon.getHeight()) && mouseLeftY < (ScreenHeight/2 - offset)) ) {  // click spellbook
						scene = SPELLBOOK_CREATE;
						//                        Sound_Engine.playmenusound();
					} else if ( (mouseLeftX > ScreenWidth/2 - scrollicon.getWidth() - offset && mouseLeftX < ScreenWidth/2 - offset) && (mouseLeftY > ScreenHeight/2 + offset && mouseLeftY < ScreenHeight/2 + offset + scrollicon.getHeight()) ) {  // click scroll+
						scene = SCROLL_ROLLER;
						//                        Sound_Engine.playmenusound();
					}
					break;
				case HOARD_LOOT:
					if ((mouseLeftX > 75 && mouseLeftX < 75 + backarrow.getWidth()) && (mouseLeftY > ScreenHeight - 150 && mouseLeftY < ScreenHeight - 150 + backarrow.getHeight())) {  //back button clicked
						if (!loot_results_ready) scene = MAIN_MENU;
						//                        if (!loot_results_ready) Sound_Engine.playcancelsound();
						loot_results_ready = false;
						hoard_loot_display.clear();
						treasure_pile.full_gear_list.clear();
					}
					if (!loot_results_ready) {
						for (int i = 1; i < 5; i++) {
							if ((mouseLeftX > ScreenWidth/2 - hoard_menu_display[i].getWidth()/2 && mouseLeftX < ScreenWidth/2 + hoard_menu_display[i].getWidth()/2) && ( mouseLeftY > 110 + i * 75 && mouseLeftY < 110 + i * 75 + hoard_menu_display[i].getWidth()) ) {
								switch (i) {
								case 1:
									treasure_pile.GenerateHoardTreasureCR_0_4();
									update_hoard_display = loot_results_ready = true;
									break;
								case 2:
									treasure_pile.GenerateHoardTreasureCR_5_10();
									update_hoard_display = loot_results_ready = true;
									//                                    Sound_Engine.playlootsound();
									break;
								case 3:
									treasure_pile.GenerateHoardTreasureCR_11_16();
									update_hoard_display = loot_results_ready = true;
									//                                    Sound_Engine.playlootsound();
									break;
								case 4:
									treasure_pile.GenerateHoardTreasureCR_17();
									update_hoard_display = loot_results_ready = true;
									//                                    Sound_Engine.playlootsound();
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
				case SPELLBOOK_CREATE:
					if ((mouseLeftX > 75 && mouseLeftX < 75 + backarrow.getWidth()) && (mouseLeftY > ScreenHeight - 150 && mouseLeftY < ScreenHeight - 150 + backarrow.getHeight())) {  //back button clicked
						scene = MAIN_MENU;
						//                        Sound_Engine.playcancelsound();
					}
					break;
				case SCROLL_ROLLER:
					if ((mouseLeftX > 75 && mouseLeftX < 75 + backarrow.getWidth()) && (mouseLeftY > ScreenHeight - 150 && mouseLeftY < ScreenHeight - 150 + backarrow.getHeight())) {  //back button clicked
						if (!loot_results_ready) scene = MAIN_MENU;
						loot_results_ready = false;
						//                        Sound_Engine.playcancelsound();
					}
					if (!loot_results_ready) {
						for (int i = 1; i < 10; i++) {
							if ((mouseLeftX > ScreenWidth/2 - scroll_menu_display[i].getWidth()/2 && mouseLeftX < ScreenWidth/2 + scroll_menu_display[i].getWidth()/2) && ( mouseLeftY > 80 + i * 55 && mouseLeftY < 80 + i * 55 + scroll_menu_display[i].getWidth()) ) {
								switch (i) {
								case 1:
									scroll_loot_display.load(Bookman, GenerateScroll(1), White);
									loot_results_ready = true;
									break;
								case 2:
									scroll_loot_display.load(Bookman, GenerateScroll(2), White);
									loot_results_ready = true;
									break;
								case 3:
									scroll_loot_display.load(Bookman, GenerateScroll(3), White);
									loot_results_ready = true;
									break;
								case 4:
									scroll_loot_display.load(Bookman, GenerateScroll(4), White);
									loot_results_ready = true;
									break;
								case 5:
									scroll_loot_display.load(Bookman, GenerateScroll(5), White);
									loot_results_ready = true;
									break;
								case 6:
									scroll_loot_display.load(Bookman, GenerateScroll(6), White);
									loot_results_ready = true;
									break;
								case 7:
									scroll_loot_display.load(Bookman, GenerateScroll(7), White);
									loot_results_ready = true;
									break;
								case 8:
									scroll_loot_display.load(Bookman, GenerateScroll(8), White);
									loot_results_ready = true;
									break;
								case 9:
									scroll_loot_display.load(Bookman, GenerateScroll(9), White);
									loot_results_ready = true;
									break;
								default:break;
								}
							}
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

