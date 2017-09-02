#include "scenemanager.h"
#include <iostream>

using namespace std;

void SceneManager::scene_03_spellbook() {
    // reset scene defaults here
    SDL_StartTextInput();
    while (scene == SPELLBOOK_CREATE) {  	// scene loop
        Graphics_Engine.clear();  //reset screen
        process_mouse_and_keyboard();  //check for any keypresses
        if (readyToDisplay) {
            displayBuiltSpellbook();
            //draw save button
            //create save function (should be close to hoard loot save)
        } else {
            spellbook_scene_header.draw(((ScreenWidth/2)-(spellbook_scene_header.getWidth()/2)), 70); //title text
            SDL_SetRenderDrawColor(SDL_graphics::renderer, 255, 255, 0, 255); //ready yellow input boxes
            for (int i = 0; i != 11; i++) {  //draw input box labels
                spellbook_scene_labels[i].draw(ScreenWidth/2 - spellbook_scene_labels[i].getWidth(), 148 + 50*i);
                SDL_RenderDrawRect(SDL_graphics::renderer, &spellbook_details_input[i]);
            }
            for (int i = 0; i != 11; i++) {   //load and draw all the text that is ready
                if (!entriesText[i].empty()) {
                    entryDisplay[i].draw(&spellbook_details_input[i]);
                }
            }
            if (hasSpells) pagesUsedDisplay.draw(&spellbook_pages_used_draw);  //display number of pages used in current spellbook setup
            if (hasSpells && hasDescription && hasValidPages) { //draw the makeSpellbook button if all the input is currently sufficient
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


