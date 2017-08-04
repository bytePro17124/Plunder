#include "scenemanager.h"

void SceneManager::scene_01_main_menu() {
	// reset scene defaults here
	while (scene == MAIN_MENU) {  	// scene loop
		Graphics_Engine.clear();  //reset screen
		process_mouse_and_keyboard();  //check for any keypresses
		hordelooticon.draw( ((ScreenWidth / 2) - (hordelooticon.getWidth() / 2)) , ((ScreenHeight / 2) - (hordelooticon.getHeight() / 2)) );		
		Graphics_Engine.render();  //update screen
	}
}
