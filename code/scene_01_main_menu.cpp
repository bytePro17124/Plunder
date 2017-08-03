#include "scenemanager.h"

void SceneManager::scene_01_main_menu() {

	// reset scene defaults here
	

	while (scene == MAIN_MENU) {  	// scene loop

		Graphics_Engine.clear();  //reset screen

		process_mouse_and_keyboard();  //check for any keypresses

		//process changes

		//draw to screen buffer
		
		Graphics_Engine.render();  //update screen

	}

}
