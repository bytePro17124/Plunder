#include "scenemanager.h"

void SceneManager::scene_02_horde_loot() {
	// reset scene defaults here
	while (scene == HORDE_LOOT) {  	// scene loop
		Graphics_Engine.clear();  //reset screen
		process_mouse_and_keyboard();  //check for any keypresses
		hordelooticon.draw(20,20);
		Graphics_Engine.render();  //update screen
	}
}
