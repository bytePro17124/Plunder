#include "scenemanager.h"

void SceneManager::scene_99_exit() {
	std::string displaytext = "Roll For Dexterity!";
	displaytext1.load(Vecna, displaytext, Orange);
	displaytext1.setAlpha(0);
	Sound_Engine.playshutdownsound();

	for (Uint8 currentalpha = 0; currentalpha < 255; currentalpha++) {
		Graphics_Engine.clear();

		if (currentalpha == 195) {
			displaytext = "Thanks For Using Plunder!";
			displaytext1.load(Vecna, displaytext, Orange);
		}

		displaytext1.setAlpha(currentalpha);

		displaytext1.draw( ((ScreenWidth - displaytext1.getWidth())/2), ((ScreenHeight - displaytext1.getHeight())/2) );

		Graphics_Engine.render();
	}

	for (Uint8 currentalpha = 255; currentalpha > 0; currentalpha--) {
		Graphics_Engine.clear();

		if (currentalpha == 195) {
			displaytext = "https://github.com/bytePro17124/Plunder";
			displaytext1.load(Vecna, displaytext, Orange);
		}

		displaytext1.setAlpha(currentalpha);

		displaytext1.draw( ((ScreenWidth - displaytext1.getWidth())/2), ((ScreenHeight - displaytext1.getHeight())/2) );

		Graphics_Engine.render();
	}


}
