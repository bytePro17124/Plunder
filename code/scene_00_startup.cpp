#include "scenemanager.h"

void SceneManager::scene_00_startup() {
	//display some kind of logo...

//	currentalpha = 0;
//	logo1.setAlpha(currentalpha);
//	frame_count = 0;  //reset frame count

//	while (frame_count < 127) {
//		Graphics_Engine.clear();
//		currentalpha += 2;
//		logo1.setAlpha(currentalpha);   //fade in logo
//		logo1.draw( ((ScreenWidth / 2) - (logo1.getWidth() / 2)), ((ScreenHeight / 2) - (logo1.getHeight() / 2)) );
//		Graphics_Engine.render();
//		frame_count++;
//	}

	Sound_Engine.playstartupsound();
	scene = MAIN_MENU;
}
