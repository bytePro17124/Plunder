#include "scenemanager.h"
#include <iostream>

using namespace std;

void SceneManager::scene_03_spellbook() {
	// reset scene defaults here
	SDL_StartTextInput();
	while (scene == SPELLBOOK_CREATE) {  	// scene loop
		Graphics_Engine.clear();            //reset screen
		process_mouse_and_keyboard();       //check for any key presses	or mouse clicks



		if (spellbookReadyToDisplay) {  //Spellbook created
			displayBuiltSpellbook();
			//add - draw save button and create save function (should be close to hoard loot save)
		} else {               //Spellbook has not been created yet
			spellbook_scene_header.draw(ScreenWidth/2 - spellbook_scene_header.getWidth()/2, spellbook_scene_header.getHeight()); //title text
			SDL_SetRenderDrawColor(SDL_graphics::renderer, 255, 255, 0, 255); //ready yellow input boxes
			for (int i = 0; i != 11; i++) {  //Draw Spellbook Labels and Entry Rectangles
				spellbook_scene_labels[i].draw(ScreenWidth/2 - spellbook_scene_labels[i].getWidth(), 148 + 50*i);
				SDL_RenderDrawRect(SDL_graphics::renderer, &SPELLBOOK_ENTRY_RECTANGLES[i]);
			}
			if (entryCellsNeedChecked) {
				spellbookInputValidator();
				entryCellsNeedChecked = false;
			}
			for (int i = 0; i != 11; i++) {   //Draw Any Text Inside the Entry Rectangles
				if (!entriesText[i].empty()) {
					entryDisplay[i].draw(&SPELLBOOK_ENTRY_RECTANGLES[i]);
				}
			}
			if (hasSpells) pagesUsedDisplay.draw(&spellbook_pages_used_draw);  //display number of pages used in current spellbook setup
			if (hasSpells && hasDescription && hasValidTotalPages) { //draw the makeSpellbook button if all the input is currently sufficient
				create_spellbook_button.draw( \
				            ScreenWidth/2 + ScreenWidth/4 - create_spellbook_button.getWidth()/2,\
				            ScreenHeight/2 - create_spellbook_button.getHeight()/2);
			}
		}

		backarrow.draw( 75, ScreenHeight - 75 - backarrow.getHeight());
		SDL_SetRenderDrawColor(SDL_graphics::renderer, 0, 0, 0, 255); //black background
		Graphics_Engine.render();  //update screen
	}
	SDL_StopTextInput();
}


