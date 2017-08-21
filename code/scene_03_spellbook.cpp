#include "scenemanager.h"

using namespace std;

void SceneManager::scene_03_spellbook() {
	// reset scene defaults here
	SDL_StartTextInput();

	while (scene == SPELLBOOK_CREATE) {  	// scene loop
		Graphics_Engine.clear();  //reset screen
		process_mouse_and_keyboard();  //check for any keypresses

		switch (textState) {
		case NON: break;
		case DESCRIPTION: break;
		case NUMBER: break;
		default: break;
		}



		spellbook_scene_header.draw(((ScreenWidth/2)-(spellbook_scene_header.getWidth()/2)), 80);
		backarrow.draw( 75, ScreenHeight - 75 - backarrow.getHeight());
		Graphics_Engine.render();  //update screen
	}

	SDL_StopTextInput();
}
