#include "scenemanager.h"
#include <iostream>
#include <fstream>

using namespace std;

void SceneManager::scene_04_scroll() {
	// reset scene defaults here

	while (scene == SCROLL_ROLLER) {  	// scene loop
		Graphics_Engine.clear();  //reset screen
		process_mouse_and_keyboard();  //check for any keypresses

		for (int i = 0; i < 10; i++) {
			if (i == 0) scroll_menu_display[i].draw(((ScreenWidth/2)-(scroll_menu_display[i].getWidth()/2)), 110);
			else scroll_menu_display[i].draw(((ScreenWidth/2)-(scroll_menu_display[i].getWidth()/2)), 110 + i * 55);
		}


		backarrow.draw( 75, ScreenHeight - 75 - backarrow.getHeight());
		Graphics_Engine.render();  //update screen
	}
}
