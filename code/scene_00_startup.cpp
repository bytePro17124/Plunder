#include "scenemanager.h"

void SceneManager::scene_00_startup() {
	//display some kind of logo...
	for (int i = 1; i < 201; i++) {
		//		printf("in Startup loop %d of 100\n", i);
		Graphics_Engine.clear();
		logo1.draw( ((ScreenWidth / 2) - (logo1.getWidth() / 2)), ((ScreenHeight / 2) - (logo1.getHeight() / 2)) );
		Graphics_Engine.render();
	}
	//	Sound_Engine.playstartupsound();
	scene = MAIN_MENU;
}
