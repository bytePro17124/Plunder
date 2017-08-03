#include "scenemanager.h"

void SceneManager::scene_selector() {
	while (!fullQuit) {
		switch (scene) {
		case EXIT:
			scene_00_exit();
			fullQuit = true;
			break;
		case MAIN_MENU:
			scene_01_main_menu(); break;
//		case HORDE_LOOT:
//			scene_02_horde_loot(); break;
		}
	}
}
