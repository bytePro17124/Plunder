#include <iostream>
#include "scenemanager.h"
#include <stdexcept>

using namespace std;

//triggered by a new keyboard entry on the spellbook
//post: strings for text entries on the spellbook will be removed if invalid
//        and the variables will be reset
//post: hasSpells and hasValidPages will be updated properly after this function
//post: pages of the spellbook variable will be updated correctly after this function
void SceneManager::spellbookInputValidator() {
	int numberCheckerVar = 0;
	//CHECK THE SPELLS
	cout << "checking input\n";
	hasSpells = false; //assume no spells base case since we are about to recheck next
	for (int i = 0; i != 9; i++) {
		if (!entriesText[i].empty()) {
			if (entriesText[i].find_first_not_of("0123456789") == std::string::npos) { //if no letters
				try {
					numberCheckerVar = stoi(entriesText[i]);
				} catch (const std::invalid_argument& e) {
					cerr << e.what();
					entriesText[i] = "";
					continue;
				}
				if (numberCheckerVar <= SPELLBOOK_LIMITS[i]) {
					hasSpells = true;
					entryDisplay[i].load(Vecna, entriesText[i], Green);
				}
			} else {
				entriesText[i] = "";
			}
		}
	}
	//UPDATE THE SPELL PAGES CURRENTLY IN USE
	cout << "checking pagesNeededForCurrentSpells\n";
	pagesNeededForCurrentSpells = 0; //assume 0 since we are about to start a new check
	if (hasSpells) {
		for (int i = 0; i != 9; i++) {
			if (!entriesText[i].empty()) pagesNeededForCurrentSpells += stoi(entriesText[i]) * (i+1);
		}
		pagesUsedDisplay.load(Vecna, std::to_string(pagesNeededForCurrentSpells), Orange);
	}
	cout << "checking hasDescription\n";
	hasDescription = false;  //assume false since we are about to recheck
	if (!entriesText[9].empty()) {
		hasDescription = true;
		entryDisplay[9].load(Vecna, entriesText[9], Green);
	}
	cout << "checking hasValidPages\n";
	hasValidPages = false;  //assume false as we are about to recheck next
	if (pagesNeededForCurrentSpells < stoi(entriesText[10])) {
		hasValidPages = true;
		entryDisplay[10].load(Vecna, entriesText[10], Green);
	}
	/* ONLY GOOD ENTRIES BEYOND THIS POINT */
}

void SceneManager::makeSpellbook() {  //the big kahuhna
	readyToDisplay = false;
	bool debug = true;
	std::vector<std::string> spellholder;  //for updating the render text
	string trySpell = "";
	bool not_duplicateSpell;

	//ALL IN ONE VERSION!?!
	//iterate over the 9 possible spell levels
	for (int c = 0; c != 9; c++) {
		if (!entriesText[c].empty()) {  //if this level has at least one spell of this level c, do the populating
			if (debug) std::cout << "finding " << entriesText[c] << "x Level " << c+1 << " spells\n";
			spellholder.push_back("~Level " + std::to_string(c+1) + " Spells~");  //header for this level of spells
			for (int i = 0; i < stoi(entriesText[i]); i++) { // find the all the spells at this level
				trySpell = GenerateScroll(c+1);
				if (trySpell.find("wizard") != std::string::npos) {  //a wizard spell was found
					trySpell.erase(0,18);  //remove scroll formatting as it is for a spellbook
					trySpell.erase((trySpell.begin()+trySpell.find_first_of("(")-1), \
					               (trySpell.begin()+trySpell.find_first_of(")")+1)); //removes the class details property as we already know it is for a wizard if it is in the wizard spellbook
				} else { //a wizard spell was not found
					i--;  // i must be an int so it can handle going to negative 1 if necessary
					continue;  //start the loop over with the same iteration and hopefully find a wizard spell this time
				}
				not_duplicateSpell = true;
				for (auto it : spellholder) {
					if (it == trySpell) not_duplicateSpell = false;
				}
				if (not_duplicateSpell) {
					spellholder.push_back(trySpell);
				} else {
					i--;  //spell was a duplicate, we need to begin this iteration over
					continue;
				}
			}
			if (debug) std::cout << " --success\n";
		} else {
			if (debug) std::cout << "No level " << c+1 << " spells\n";
		}
	}


	//build it into SDL2 Textures. Requires a Vector of Textures called completedSpellbookTextures
	if (debug) std::cout << "turing spells into textures...\n";
	if (!spellholder.empty()) {
		completedSpellbookTextures.clear();
		completedSpellbookTextures.resize(spellholder.size());  //change to needed size for textures
		for (uint i = 0; i < spellholder.size(); i++) {
			completedSpellbookTextures[i].load(Bookman, spellholder[i], White);  //load up all the textures with the spellholder data text
		}
	}
	if (debug) std::cout << " --++SUCCESS\n";
	readyToDisplay = true;
}


void SceneManager::displayBuiltSpellbook() {
	int n = completedSpellbookTextures.size();
	for (int i = 0; i < n; i++) {
		if (i < n/2) completedSpellbookTextures[i].draw(offset, offset + i*completedSpellbookTextures[i].getHeight());
		else completedSpellbookTextures[i].draw(offset+ScreenWidth/2, offset + (i - n/2) * completedSpellbookTextures[i].getHeight());
	}
}
