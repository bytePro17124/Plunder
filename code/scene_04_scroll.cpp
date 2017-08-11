#include "scenemanager.h"
#include <iostream>
#include <fstream>

using namespace std;

void SceneManager::scene_04_scroll() {
	// reset scene defaults here

	while (scene == SCROLL_ROLLER) {  	// scene loop
		Graphics_Engine.clear();  //reset screen
		process_mouse_and_keyboard();  //check for any keypresses




		backarrow.draw( 75, ScreenHeight - 75 - backarrow.getHeight());
		Graphics_Engine.render();  //update screen
	}
}
