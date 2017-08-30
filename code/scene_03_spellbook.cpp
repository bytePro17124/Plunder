#include "scenemanager.h"
#include <iostream>

using namespace std;

void SceneManager::scene_03_spellbook() {
	// reset scene defaults here
	SDL_StartTextInput();
	while (scene == SPELLBOOK_CREATE) {  	// scene loop
		Graphics_Engine.clear();  //reset screen
		process_mouse_and_keyboard();  //check for any keypresses

		if (spellbook_results_ready) {
			//display resulsts
			//draw save button
			//create save function (should be close to hoard loot save)
		} else {
			spellbook_scene_header.draw(((ScreenWidth/2)-(spellbook_scene_header.getWidth()/2)), 70); //title text
			SDL_SetRenderDrawColor(SDL_graphics::renderer, 255, 255, 0, 255); //yellow input boxes
			for (int i = 0; i != 11; i++) {
				//draw labels
				spellbook_scene_labels[i].draw(ScreenWidth/2 - spellbook_scene_labels[i].getWidth(), 148 + 50*i);
				//draw input boxes
				SDL_RenderDrawRect(SDL_graphics::renderer, &spellbook_details_input[i]);
			}
			if (needsValidityCheckUpdate) {
				doValidCheck();  //gets rid of bad input, updates pages used, and decides if the create spellbook button is okay to click
			}
			for (int i = 0; i != 11; i++) {   //load and draw all the text that is ready
				if (!inputText[i].empty()) {
					inputTextDisplay[i].load(Vecna, inputText[i], Green);
					inputTextDisplay[i].draw(&spellbook_details_input[i]);
				}
			}
			if (hasSpells && hasDescription) {  //draw the make spellbook button if all the input is currently sufficient
				create_spellbook_button.draw( \
							ScreenWidth/2 + ScreenWidth/4 - create_spellbook_button.getWidth()/2,\
							ScreenHeight/2 - create_spellbook_button.getHeight()/2);
			}
			if (hasSpells) pages_used_display.draw(&spellbook_pages_used_area);  //display number of pages used in current spellbook setup
		}
		
		backarrow.draw( 75, ScreenHeight - 75 - backarrow.getHeight());
		SDL_SetRenderDrawColor(SDL_graphics::renderer, 0, 0, 0, 255); //black background
		Graphics_Engine.render();  //update screen
	}
	SDL_StopTextInput();
}


