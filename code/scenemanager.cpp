#include "scenemanager.h"

void SceneManager::scene_selector() {
	while (!fullQuit) {
		switch (scene) {
		case EXIT:
			s00_exit();
			fullQuit = true;
			break;
		case MAIN_MENU:
			s01_main_menu(); break;
		case LOOT:
			s02_horde_loot(); break;
		}
	}
}
