#include "scenemanager.h"
#include <iostream>
#include <fstream>
#include <chrono>

using namespace std;

void SceneManager::scene_03_spellbook() {
	// reset scene defaults here
	SDL_StartTextInput();
	while (scene == SPELLBOOK_CREATE) {  	// scene loop
		Graphics_Engine.clear();            //reset screen
		process_mouse_and_keyboard();       //check for any key presses	or mouse clicks



		if (spellbookReadyToDisplay) {  //Spellbook created
			displayBuiltSpellbook();
			save_loot_button.draw(ScreenWidth - 75 - save_loot_button.getWidth(), ScreenHeight - 75 - save_loot_button.getHeight());


			if (loot_write_out) {
				now = time(0);			//update time to now
				ltm = localtime(&now);  //save time into struct
				fileoutputname = "saved_loot/spellbook" + std::to_string(1900+ltm->tm_year) +  std::to_string(1+ltm->tm_mon) +  std::to_string(ltm->tm_mday) + "_" +  std::to_string(ltm->tm_hour) +  std::to_string(ltm->tm_min) +  std::to_string(ltm->tm_sec) + "_" +  std::to_string(loot_rolls_this_session) + ".txt";
				save_to_file.open(fileoutputname);
				if (!save_to_file) {
					cout << "Could not open to save. Check code or file.\n\n";
					return;
				} else {
					if (spellholder.size() < 1) {
						cout << "Nothing to save, spellbook has no entries\n.";
						return;
					}
					for (auto & it : spellholder) {  //output to file in 2 lines, name then date+time
						save_to_file << it << "\n";
					}
					save_to_file.close();
				}
				loot_write_out = false;
				notification_text.load(Bookman, "Output written to: " + fileoutputname, Green);
				notification_text.setBlendMode(SDL_BLENDMODE_BLEND);
				currentalpha = 0;  //reset alpha and frame count
				frame_count = 0;
				loot_write_out_notification = true;
			}


			if (loot_write_out_notification) {
				//display this notification for 6 seconds (or 360 frames @60fps)
				//the first 2 seconds are a fade in, middle 2 seconds are full visibility, last 2 seconds are a fade out

				//its not perfect right now but this works
				if (frame_count <= 119) {     // alpha changing fade effects
					currentalpha += 2;
					notification_text.setAlpha(currentalpha);
				} else if (frame_count == 120) {
					currentalpha = 255;
					notification_text.setAlpha(currentalpha);
				} else if (frame_count > 238 && frame_count < 360) {
					currentalpha -= 2;
					notification_text.setAlpha(currentalpha);
				} else if (frame_count == 360) {
					loot_write_out_notification = false;
				}
				notification_text.draw(ScreenWidth/2 - notification_text.getWidth()/2, ScreenHeight - notification_text.getHeight() - 10);
				frame_count++;
			}




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
			if (hasSpells || hasDescription || hasValidTotalPages) {
				resetbutton.draw(ScreenWidth/2 - ScreenWidth/4 - resetbutton.getWidth()/2,\
				                 ScreenHeight/2 - resetbutton.getHeight()/2);
			}
		}

		backarrow.draw( 75, ScreenHeight - 75 - backarrow.getHeight());
		SDL_SetRenderDrawColor(SDL_graphics::renderer, 0, 0, 0, 255); //black background
		Graphics_Engine.render();  //update screen
	}
	SDL_StopTextInput();
}


