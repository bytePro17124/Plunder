#include "scenemanager.h"
#include "random_gen.h"
#include <iostream>

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
						Sound_Engine.playmenusound();
					} else if ( (mouseLeftX > ScreenWidth/2 + offset && mouseLeftX < ScreenWidth/2 + offset + spellbookicon.getWidth()) && (mouseLeftY > (ScreenHeight/2 - offset - spellbookicon.getHeight()) && mouseLeftY < (ScreenHeight/2 - offset)) ) {  // click spellbook
						scene = SPELLBOOK_CREATE;
						Sound_Engine.playmenusound();
					} else if ( (mouseLeftX > ScreenWidth/2 - scrollicon.getWidth() - offset && mouseLeftX < ScreenWidth/2 - offset) && (mouseLeftY > ScreenHeight/2 + offset && mouseLeftY < ScreenHeight/2 + offset + scrollicon.getHeight()) ) {  // click scroll+
						scene = SCROLL_ROLLER;
						Sound_Engine.playmenusound();
					} else if ( (mouseLeftX > ScreenWidth/2 + offset && mouseLeftX < ScreenWidth/2 + offset + toolsicon.getWidth()) && (mouseLeftY > (ScreenHeight/2 + offset) && mouseLeftY < (ScreenHeight/2 + offset + toolsicon.getHeight())) ) {
						scene = OTHER_TOOLS;
					}
					break;
				case HOARD_LOOT:
					if ((mouseLeftX > 75 && mouseLeftX < 75 + backarrow.getWidth()) && (mouseLeftY > ScreenHeight - 150 && mouseLeftY < ScreenHeight - 150 + backarrow.getHeight())) {  //back button clicked
						if (!loot_results_ready) scene = MAIN_MENU;
						if (!loot_results_ready) Sound_Engine.playcancelsound();
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
						Sound_Engine.playcancelsound();
					}
					for (int i = 0; i != 9; i++) {  // spellbook level key clicks
						if ((mouseLeftX > ScreenWidth/2 + 40 && mouseLeftX < ScreenWidth/2 + 40 + spellbook_details_input[i].w) && (mouseLeftY > 140 + 50*i && mouseLeftY < 140 + 50*i + spellbook_details_input[i].h)) {
							tomeBuildState = (TOMEBUILDSTATE)i;
						}
					}
					for (int i = 9; i != 11; i++) { // spellbook description or max pages key clicks
						if ((mouseLeftX > ScreenWidth/2 + 40 && mouseLeftX < ScreenWidth/2 + 40 + spellbook_details_input[i].w) && (mouseLeftY > 590 && mouseLeftY < 590 + spellbook_details_input[i].h) && i == 9) {
							tomeBuildState = (TOMEBUILDSTATE)i;
						}
						if ((mouseLeftX > ScreenWidth/2 + 150 && mouseLeftX < ScreenWidth/2 + 150 + spellbook_details_input[i].w) && (mouseLeftY > 640 && mouseLeftY < 640 + spellbook_details_input[i].h) && i == 10) {
							tomeBuildState = (TOMEBUILDSTATE)i;
						}
					}

					/*
						if (i < 9) spellbook_details_input[i] = { ScreenWidth/2 + 40, 140 + 50*i, 100, 40 };
		else if (i == 9) spellbook_details_input[i] = { ScreenWidth/2 + 40, 590, 210, 40 };
		else spellbook_details_input[i] = {ScreenWidth/2 + 150, 640, 100, 40 };
		*/

					//					switch (tomeBuildState) {
					//					case NON: break;
					//					case L1: break;
					//					case L2: break;
					//					case L3: break;
					//					case L4: break;
					//					case L5: break;
					//					case L6: break;
					//					case L7: break;
					//					case L8: break;
					//					case L9: break;
					//					case DESCRIPTION: break;
					//					case PAGES: break;
					//					default: break;
					//					}




					break;
				case SCROLL_ROLLER:
					if ((mouseLeftX > 75 && mouseLeftX < 75 + backarrow.getWidth()) && (mouseLeftY > ScreenHeight - 150 && mouseLeftY < ScreenHeight - 150 + backarrow.getHeight())) {  //back button clicked
						if (!loot_results_ready) scene = MAIN_MENU;
						loot_results_ready = false;
						Sound_Engine.playcancelsound();
					}
					if (!loot_results_ready) {
						for (int i = 1; i < 10; i++) {
							if ((mouseLeftX > ScreenWidth/2 - scroll_menu_display[i].getWidth()/2 && mouseLeftX < ScreenWidth/2 + scroll_menu_display[i].getWidth()/2) && ( mouseLeftY > 80 + i * 55 && mouseLeftY < 80 + i * 55 + scroll_menu_display[i].getWidth()) ) {
								switch (i) {
								case 1:
									scroll_loot_display.load(Vecna, GenerateScroll(1), White);
									loot_results_ready = true;
									break;
								case 2:
									scroll_loot_display.load(Vecna, GenerateScroll(2), White);
									loot_results_ready = true;
									break;
								case 3:
									scroll_loot_display.load(Vecna, GenerateScroll(3), White);
									loot_results_ready = true;
									break;
								case 4:
									scroll_loot_display.load(Vecna, GenerateScroll(4), White);
									loot_results_ready = true;
									break;
								case 5:
									scroll_loot_display.load(Vecna, GenerateScroll(5), White);
									loot_results_ready = true;
									break;
								case 6:
									scroll_loot_display.load(Vecna, GenerateScroll(6), White);
									loot_results_ready = true;
									break;
								case 7:
									scroll_loot_display.load(Vecna, GenerateScroll(7), White);
									loot_results_ready = true;
									break;
								case 8:
									scroll_loot_display.load(Vecna, GenerateScroll(8), White);
									loot_results_ready = true;
									break;
								case 9:
									scroll_loot_display.load(Vecna, GenerateScroll(9), White);
									loot_results_ready = true;
									break;
								default:break;
								}
							}
						}
					}
					break;
				case OTHER_TOOLS:
					if ((mouseLeftX > 75 && mouseLeftX < 75 + backarrow.getWidth()) && (mouseLeftY > ScreenHeight - 150 && mouseLeftY < ScreenHeight - 150 + backarrow.getHeight())) {  //back button clicked
						if (!loot_results_ready) scene = MAIN_MENU;
						loot_results_ready = false;
						Sound_Engine.playcancelsound();
					}
					break;


				case EXIT: break;  //disallow key clicks
				}
				break;
			}
			break;
		case SDL_KEYDOWN:

			switch (scene) {
			case STARTUP: break;
			case MAIN_MENU: break;
			case HOARD_LOOT: break;
			case SPELLBOOK_CREATE:
				if (e.key.keysym.sym == SDLK_BACKSPACE)
					switch (tomeBuildState) {
					case NON: break;
					case L1: if (inputText[0].length() > 0) inputText[0].pop_back(); break;
					case L2: if (inputText[1].length() > 0) inputText[1].pop_back(); break;
					case L3: if (inputText[2].length() > 0) inputText[2].pop_back(); break;
					case L4: if (inputText[3].length() > 0) inputText[3].pop_back(); break;
					case L5: if (inputText[4].length() > 0) inputText[4].pop_back(); break;
					case L6: if (inputText[5].length() > 0) inputText[5].pop_back(); break;
					case L7: if (inputText[6].length() > 0) inputText[6].pop_back(); break;
					case L8: if (inputText[7].length() > 0) inputText[7].pop_back(); break;
					case L9: if (inputText[8].length() > 0) inputText[8].pop_back(); break;
					case DESCRIPTION: if (inputText[9].length() > 0) inputText[9].pop_back(); break;
					case PAGES: if (inputText[10].length() > 0) inputText[10].pop_back(); break;
					default: break;
					}
			case SCROLL_ROLLER: break;
			case OTHER_TOOLS: break;
			default: break;
			}
			break;

		case SDL_TEXTINPUT:

			switch (scene) {
			case STARTUP: break;
			case MAIN_MENU: break;
			case HOARD_LOOT: break;
			case SPELLBOOK_CREATE:
				switch (tomeBuildState) {
				case NON: break;
				case L1: inputText[0] += e.text.text; break;
				case L2: inputText[1] += e.text.text; break;
				case L3: inputText[2] += e.text.text; break;
				case L4: inputText[3] += e.text.text; break;
				case L5: inputText[4] += e.text.text; break;
				case L6: inputText[5] += e.text.text; break;
				case L7: inputText[6] += e.text.text; break;
				case L8: inputText[7] += e.text.text; break;
				case L9: inputText[8] += e.text.text; break;
				case DESCRIPTION: inputText[9] += e.text.text; break;
				case PAGES: inputText[10] += e.text.text; break;
				default: break;
				}
			case SCROLL_ROLLER: break;
			case OTHER_TOOLS: break;
			default: break;
			}
			break;
			//		case SDL_MOUSEMOTION:
			//			mouseLeftX = e.button.x;
			//			mouseLeftY = e.button.y;

			//			break;
		}
	}
}

