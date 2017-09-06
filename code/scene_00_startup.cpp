#include "scenemanager.h"

void SceneManager::scene_00_startup() {
	//display some kind of logo...
	std::cout << "startup scene beginning\n";
	currentalpha = 0;
	logo1.setAlpha(currentalpha);
	frame_count = 0;  //reset frame count

	std::cout << "displaying the get dat loot logo\n";
	while (frame_count < 127) {
		Graphics_Engine.clear();
		currentalpha += 2;
		logo1.setAlpha(currentalpha);   //fade in logo
		logo1.draw(ScreenWidth/2 - logo1.getWidth()/2, ScreenHeight/2 - logo1.getHeight()/2);
		Graphics_Engine.render();
		frame_count++;
	}
	std::cout << "finished displaying the get dat loot logo\n";

//	if (isSoundOn) Sound_Engine.playstartupsound();
	std::cout << "startup finished\n";
	scene = MAIN_MENU;
}
