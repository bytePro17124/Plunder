#include "scenemanager.h"
#include <iostream>

using namespace std;

void SceneManager::scene_03_spellbook() {
	// reset scene defaults here
	SDL_StartTextInput();

	while (scene == SPELLBOOK_CREATE) {  	// scene loop
		Graphics_Engine.clear();  //reset screen
		process_mouse_and_keyboard();  //check for any keypresses

		SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255); //yellow input boxes
		for (int i = 0; i != 11; i++) {
			//draw labels
			spellbook_scene_labels[i].draw(ScreenWidth/2 - spellbook_scene_labels[i].getWidth(), 148 + 50*i);
			//draw input boxes
			SDL_RenderDrawRect(renderer, &spellbook_details_input[i]);
		}

		//		switch (tomeBuildState) {
		//		case NON: break;
		//		case DESCRIPTION: break;
		//		case PAGES: break;
		//		case L1: break;
		//		case L2: break;
		//		case L3: break;
		//		case L4: break;
		//		case L5: break;
		//		case L6: break;
		//		case L7: break;
		//		case L8: break;
		//		case L9: break;
		//		default: break;
		//		}

		for (int i = 0; i != 11; i++) {
			if (!inputText[i].empty()) {
				if (i < 9 || i == 10) {
					if (checkTextToIntWithClamp(inputText[i], maxSpellsPerLevel[i])) {
						if (i < 9) std::cout << "success clamping on level " << i+1 << " spells\n";
						else std::cout << "success clamping on setting pages\n";
					} else {
						std::cout << "invalid entry on " << i+1 << "\n";
						inputText[i] = "";
					}
				}
			}
			if (!inputText[i].empty()) {
				inputTextDisplay[i].load(Vecna, inputText[i], Green);
				inputTextDisplay[i].draw(&spellbook_details_input[i]);
			}
		}

		spellbook_scene_header.draw(((ScreenWidth/2)-(spellbook_scene_header.getWidth()/2)), 70);
		backarrow.draw( 75, ScreenHeight - 75 - backarrow.getHeight());
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); //black background
		Graphics_Engine.render();  //update screen
	}

	SDL_StopTextInput();
}


