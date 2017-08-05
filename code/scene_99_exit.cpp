#include "scenemanager.h"

void SceneManager::scene_99_exit() {
	std::string displaytext = "Thanks For Using Plunder!";
	Uint8 currentalpha = 125;
	displaytext1.load(Vecna, displaytext, Orange);
	displaytext1.setAlpha(currentalpha);
	Sound_Engine.playshutdownsound();

	for (int i = 0; i < 256; i++) {
		Graphics_Engine.clear();

		if (i < 125) currentalpha++;
		else if (i >= 125) currentalpha--;

		displaytext1.setAlpha(currentalpha);

		displaytext1.draw( ((ScreenWidth - displaytext1.getWidth())/2), ((ScreenHeight - displaytext1.getHeight())/2) );

		Graphics_Engine.render();
	}
}
