#include "scenemanager.h"


void SceneManager::scene_05_other_tools() {
	// reset scene defaults here

	while (scene == OTHER_TOOLS) {    // scene loop
		Graphics_Engine.clear();  //reset screen
		process_mouse_and_keyboard();  //check for any keypresses
		other_tools_header.draw(ScreenWidth / 2 - other_tools_header.getWidth() / 2, 40);
		button_gen_random_name.draw(ScreenWidth / 2 - ScreenWidth / 4 - button_gen_random_name.getWidth() / 2,
									ScreenHeight / 2 - ScreenHeight / 4 - button_gen_random_name.getHeight() / 2);

		for (int i = 0; i != 5; i++) {
			if (list_of_generated_names[i].size() > 1)
				texture_of_generated_names[i].draw(480, ScreenHeight / 2 - ScreenHeight / 4 -
														texture_of_generated_names[i].getHeight() / 2 + i * 32);

		}


		backarrow.draw(75, ScreenHeight - 75 - backarrow.getHeight());
		Graphics_Engine.render();  //update screen
	}
}
