#include "scenemanager.h"

void SceneManager::scene_02_horde_loot() {
	// reset scene defaults here
	while (scene == HORDE_LOOT) {  	// scene loop
		Graphics_Engine.clear();  //reset screen
		process_mouse_and_keyboard();  //check for any keypresses

		for (int i = 0; i < 5; i++) {
			horde_menu_display[i].setAlpha(190);
			horde_menu_display[i].draw(((ScreenWidth/2)-(horde_menu_display[i].getWidth()/2)), 110 + i * 95);
		}

		backarrow.draw( 75, ScreenHeight - 150);

		Graphics_Engine.render();  //update screen
	}
}
