#include "scenemanager.h"


void SceneManager::scene_05_other_tools() {
	// reset scene defaults here

	while (scene == OTHER_TOOLS) {  	// scene loop
		Graphics_Engine.clear();  //reset screen
		process_mouse_and_keyboard();  //check for any keypresses




		backarrow.draw( 75, ScreenHeight - 75 - backarrow.getHeight());
		Graphics_Engine.render();  //update screen
	}
}
