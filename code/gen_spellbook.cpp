#include <iostream>
#include "scenemanager.h"
#include <stdexcept>

using namespace std;

/// spellbookInputValidator is triggered by a new keyboard entry on the spellbook
/// pre: input may not be valid
/// post1: strings for text entries on the spellbook will be removed if invalid and the variables will be reset
/// post2: hasSpells and hasValidTotalPages will be updated properly after this function
/// post3: pages of the spellbook variable will be updated correctly after this function
void SceneManager::spellbookInputValidator() {
	int numberCheckerVar = 0;
	//CHECK THE SPELLS
	cout << "checking input\n";
	hasSpells = false; //assume no spells base case since we are about to recheck next
	for (int i = 0; i != 11; i++) {
		if (i == 9) continue;
		if (!entriesText[i].empty()) {
			if (entriesText[i].find_first_not_of("0123456789") == std::string::npos) { //if no letters
				try {
					numberCheckerVar = stoi(entriesText[i]);
				} catch (const std::invalid_argument& e) {
					cerr << e.what();
					entriesText[i] = "";
					continue;
				}
				if (numberCheckerVar <= SPELLBOOK_LIMITS[i] && numberCheckerVar != 0) {
					hasSpells = true;
					entryDisplay[i].load(Vecna, entriesText[i], Green);
					cout << " --valid " << i+1 << "\n";
				} else {
					entriesText[i] = ""; //reset
				}
			} else {
				entriesText[i] = "";
			}
		}
	}
	//UPDATE THE SPELL PAGES CURRENTLY IN USE
	cout << "updating pages in use\n";
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
		if ((int)entriesText[9].size() > SPELLBOOK_LIMITS[9]) {
			entriesText[9].pop_back();  ///GET WRECKED BY THE LIMITS FOOL
		}
		hasDescription = true;
		entryDisplay[9].load(Vecna, entriesText[9], Green);
		cout << " --true\n";
	}
	cout << "checking hasValidTotalPages\n";
	hasValidTotalPages = false;  //assume false as we are about to recheck next
	if (!entriesText[10].empty()) {
		if (pagesNeededForCurrentSpells <= stoi(entriesText[10])) {
			entryDisplay[10].load(Vecna, entriesText[10], Green);
			hasValidTotalPages = true;
			cout << " --true\n";
		} else {
			entryDisplay[10].load(Vecna, entriesText[10], Red);
		}
	}
	cout << "DONE CHECKING\n";
	/* ONLY GOOD ENTRIES BEYOND THIS POINT */
}

void SceneManager::makeSpellbook() {  //the big kahuhna
	spellbookReadyToDisplay = false;
	bool debug = true;
	spellholder.clear();  //for updating the render text
	string trySpell = "";
	bool not_duplicateSpell;

	spellholder.push_back("New Spellbook Description: " + entriesText[9] + ", Pages: " + std::to_string(pagesNeededForCurrentSpells) + " used / " + entriesText[10] + " total " );

	//ALL IN ONE VERSION!?!
	//iterate over the 9 possible spell levels
	for (int lvl = 0; lvl != 9; lvl++) {
		if (!entriesText[lvl].empty()) {  //if this level has at least one spell of this level c, do the populating
			if (debug) std::cout << "finding " << entriesText[lvl] << "x Level " << lvl+1 << " spells\n";
			spellholder.push_back("~Level " + std::to_string(lvl+1) + " Spells~");  //header for this level of spells
			for (int i = 0; i < stoi(entriesText[lvl]); i++) { // find the all the spells at this level
				trySpell = GenerateScroll(lvl+1);
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
			if (debug) std::cout << " -- SKIPPING " << lvl+1 << ": No level " << lvl+1 << " spells in entries\n";
		}
	}


	//build it into SDL2 Textures. Requires a Vector of Textures called completedSpellbookTextures
	if (debug) std::cout << "turing " << spellholder.size() << " total headers and spells finds into textures...\n";
	completedSpellbookTextures.clear();
	completedSpellbookTextures.resize(spellholder.size());  //change to needed size for textures
	for (uint i = 0; i < spellholder.size(); i++) {
		if (spellholder[i].find_first_of("~") != std::string::npos) {
			completedSpellbookTextures[i].load(Bookman, spellholder[i], Orange);  //load up all the textures with the spellholder data text
		} else {
			completedSpellbookTextures[i].load(Bookman, spellholder[i], White);  //load up all the textures with the spellholder data text
		}
	}
	if (debug) std::cout << " --++SUCCESS\n";
	spellbookReadyToDisplay = true;
}


void SceneManager::displayBuiltSpellbook() {
	int n = completedSpellbookTextures.size();

	for (int i = 0; i < n; i++) {
		if (i == 0)
			completedSpellbookTextures[i].draw(ScreenWidth/2-completedSpellbookTextures[i].getWidth()/2, offset);
		else if (i < n/2)
			completedSpellbookTextures[i].draw\
					(250, offset + i*completedSpellbookTextures[i].getHeight() + completedSpellbookTextures[0].getHeight());
		else
			completedSpellbookTextures[i].draw\
					(250+ScreenWidth/2, offset + (i - n/2) * completedSpellbookTextures[i].getHeight()+ completedSpellbookTextures[0].getHeight());
	}
}
