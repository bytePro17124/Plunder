#include "scenemanager.h"



//Draws each section of the message for 2 seconds then exits
void SceneManager::scene_99_exit() {
	std::string displaytext = "Roll For Dexterity!";
	displaytext1.load(Vecna, displaytext, Orange);
	Uint8 currentalpha = 0;
	displaytext1.setAlpha(currentalpha);
	frame_count = 0;  //reset frame count

	//	Sound_Engine.playshutdownsound();

	while (frame_count < 360) {     //if this is 60 frames per second as per the documentation of vsync and
		Graphics_Engine.clear();    //a 60hertz monitor should be be 6 seconds total

		if (frame_count == 120) {     // message changing
			displaytext = "Thanks For Using Plunder!";
			displaytext1.load(Vecna, displaytext, Orange);
		} else if (frame_count == 240) {
			displaytext = "https://github.com/bytePro17124/Plunder";
			displaytext1.load(Vecna, displaytext, Orange);
		}


		if (frame_count <= 59) {     // alpha changing fade effects
			currentalpha += 4;
		} else if (frame_count <= 119) {
			currentalpha -= 4;
		} else if (frame_count <= 179) {
			currentalpha += 4;
		} else if (frame_count <= 239) {
			currentalpha -= 4;
		} else if (frame_count <= 299) {
			currentalpha += 4;
		} else {
			currentalpha -= 4;
		}

		displaytext1.setAlpha(currentalpha);
		displaytext1.draw( ((ScreenWidth - displaytext1.getWidth())/2), ((ScreenHeight - displaytext1.getHeight())/2) );
		Graphics_Engine.render();
		frame_count++;

	}

	fullQuit = true;
}



// old uncapped processor speed version
/*

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

*/
