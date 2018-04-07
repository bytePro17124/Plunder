#include "random_gen.h"
#include "scenemanager.h"
#include <fstream>
#include <limits>

using namespace std;

void SceneManager::newRandomName() {
	cout << "genearting new random name\n";
	list_of_generated_names[4] = list_of_generated_names[3];
	list_of_generated_names[3] = list_of_generated_names[2];
	list_of_generated_names[2] = list_of_generated_names[1];
	list_of_generated_names[1] = list_of_generated_names[0];
	list_of_generated_names[0] = grabRandomName();
	updateRandomNameTextures();
}

std::string SceneManager::grabRandomName() {
	ifstream fileOfNames;
	string tmpName;
	fileOfNames.open("../res/data/names.dat");
	if (fileOfNames.is_open()) {
		auto chosenSeed = randomNumber(1, 7732);
		for (auto i = 1; i < chosenSeed; i++) {
			fileOfNames.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		getline(fileOfNames, tmpName, '\n');
	} else {
		tmpName = "error with name file - check src";
		cout << "error grabbing name\n";
	}
	return tmpName;
}


void SceneManager::clearNames() {
	cout << "settings all names to blank\n";
	for (int i = 0; i != 5; i++) {
		if (list_of_generated_names[i].size() > 1)
			list_of_generated_names[i] = "";
	}
}


void SceneManager::updateRandomNameTextures() {
	cout << "updating the randomname textures\n";
	for (int i = 0; i != 5; i++) {
		if (list_of_generated_names[i].size() > 1)
			texture_of_generated_names[i].load(Bookman, list_of_generated_names[i], White);
		texture_of_generated_names[i].setAlpha(static_cast<Uint8>(255 - i * 37));
	}

}
