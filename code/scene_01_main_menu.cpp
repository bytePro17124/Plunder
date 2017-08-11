#include "scenemanager.h"

void SceneManager::scene_01_main_menu() {
	// reset scene defaults here
	while (scene == MAIN_MENU) {  	// scene loop
		Graphics_Engine.clear();  //reset screen
		process_mouse_and_keyboard();  //check for any keypresses

		hoardlooticon.draw( ScreenWidth/2 - offset - hoardlooticon.getWidth(), ScreenHeight/2 - offset - hoardlooticon.getHeight() );
		spellbookicon.draw( ScreenWidth/2 + offset, ScreenHeight/2 - offset - spellbookicon.getHeight() );
		scrollicon.draw( ScreenWidth/2 - offset - scrollicon.getWidth(), ScreenHeight/2 + offset);

		Graphics_Engine.render();  //update screen
	}
}
