#include "scenemanager.h"
#include <iostream>
#include <fstream>

using namespace std;

void SceneManager::scene_03_spellbook() {
	// reset scene defaults here

	while (scene == SPELLBOOK_CREATE) {  	// scene loop
		Graphics_Engine.clear();  //reset screen
		process_mouse_and_keyboard();  //check for any keypresses




		backarrow.draw( 75, ScreenHeight - 75 - backarrow.getHeight());
		Graphics_Engine.render();  //update screen
	}
}
