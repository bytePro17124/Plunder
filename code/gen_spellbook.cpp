#include <iostream>
#include "scenemanager.h"

using namespace std;

void SceneManager::makeSpellbook() {

    bool debug = true;
    std::vector<std::string> spellholder;  //for making the actual spellbook
    string tmp = "";
    bool not_duplicateSpell;

    //ALL IN ONE VERSION!?!
    //iterate over the 9 possible spell levels
    for (int c = 0; c != 9; c++) {
        if (tomeSpells[c] > 0) {  //if this level has at least one spell of this level c, do the populating
            if (debug) std::cout << "finding " << tomeSpells[c] << "x Level " << c+1 << " spells\n";
            spellholder.push_back("~Level " + std::to_string(c+1) + " Spells~");  //header for this level of spells
            for (int i = 0; i < tomeSpells[i]; i++) { // find the all the spells at this level
                tmp = GenerateScroll(c+1);
                if (tmp.find("wizard") != std::string::npos) {  //a wizard spell was found
                    tmp.erase(0,18);  //remove scroll formatting as it is for a spellbook
                    tmp.erase((tmp.begin()+tmp.find_first_of("(")-1), \
                              (tmp.begin()+tmp.find_first_of(")")+1)); //removes the class details property as we already know it is for a wizard if it is in the wizard spellbook
                } else { //a wizard spell was not found
                    i--;  // i must be an int so it can handle going to negative 1 if necessary
                    continue;  //start the loop over with the same iteration and hopefully find a wizard spell this time
                }
                not_duplicateSpell = true;
                for (auto it : spellholder) {
                    if (it == tmp) not_duplicateSpell = false;
                }
                if (not_duplicateSpell) {
                    spellholder.push_back(tmp);
                } else {
                    i--;  //spell was a duplicate, we need to begin this iteration over
                    continue;
                }
            }
            if (debug) std::cout << " --success\n";
        }
    }


    //build it into SDL2 Textures. Requires a Vector of Textures called built_spellbook_textures
    if (debug) std::cout << "turing spells into textures...\n";

    if (!spellholder.empty()) {
        built_spellbook_textures.clear();
        built_spellbook_textures.resize(spellholder.size());  //change to needed size for textures
        for (uint i = 0; i < spellholder.size(); i++) {
            built_spellbook_textures[i].load(Bookman, spellholder[i], White);  //load up all the textures with the spellholder data textb
        }
    }

    if (debug) std::cout << " --++SUCCESS\n";



}
/*

//LEVEL 1 SPELLS
if (tomeSpells[0] > 0) {
    if (debug) std::cout << "finding " << tomeSpells[0] << " lvl1 spells\n";
    spellholder.push_back("~Level 1 Spells~");  //header for spell level
    for (uint i = 0; i < tomeSpells[0]; i++) {  //start random gen procedure
        string tmp = GenerateScroll(1);
        if (tmp.find("wizard") != std::string::npos) { //if scroll is a wizard spell
            tmp.erase(0, 18);  //removes the scroll property
            tmp.erase((tmp.begin()+tmp.find_first_of("(")-1), (tmp.begin()+tmp.find_first_of(")")+1)); //removes the class details property
        } else {
            i--;   //didn't roll a wizard spell, trying again.
            continue;
        }
        bool not_duplicateSpell = true;
        for (auto i : spellholder) {
            if (i == tmp) not_duplicateSpell = false;
        }
        if (not_duplicateSpell) {
            spellholder.push_back(tmp);
        } else {
            i--;
            continue;
        }
    }
    if (debug) std::cout << " --success\n";
}



//LEVEL 2 SPELLS
if (tomeSpells[1] > 0) {
    if (debug) std::cout << "finding " << tomeSpells[1] << " lvl2 spells\n";
    spellholder.push_back("~Level 2 Spells~");  //header for spell level
    for (uint i = 0; i < tomeSpells[1]; i++) {
        string tmp = GenerateScroll(2);
        if (tmp.find("wizard") != std::string::npos) { //if scroll is a wizard scroll
            tmp.erase(0, 18);  //removes the scroll property
            tmp.erase((tmp.begin()+tmp.find_first_of("(")-1), (tmp.begin()+tmp.find_first_of(")")+1)); //removes the class details property
        } else {
            i--;   //didn't roll a wizard spell, trying again.
            continue;
        }
        bool not_duplicateSpell = true;
        for (auto i : spellholder) {
            if (i == tmp) not_duplicateSpell = false;
        }
        if (not_duplicateSpell) {
            spellholder.push_back(tmp);
        } else {
            i--;
            continue;
        }
    }
    if (debug) std::cout << " --success\n";
}

//LEVEL 3 SPELLS
if (tomeSpells[2] > 0) {
    if (debug) std::cout << "finding " << tomeSpells[2] << " lvl3 spells\n";

    spellholder.push_back("~Level 3 Spells~");  //header for spell level
    for (uint i = 0; i < tomeSpells[2]; i++) {
        string tmp = GenerateScroll(3);
        if (tmp.find("wizard") != std::string::npos) { //if scroll is a wizard scroll
            tmp.erase(0, 18);  //removes the scroll property
            tmp.erase((tmp.begin()+tmp.find_first_of("(")-1), (tmp.begin()+tmp.find_first_of(")")+1)); //removes the class details property
        } else {
            i--;   //didn't roll a wizard spell, trying again.
            continue;
        }
        bool not_duplicateSpell = true;
        for (auto i : spellholder) {
            if (i == tmp) not_duplicateSpell = false;
        }
        if (not_duplicateSpell) {
            spellholder.push_back(tmp);
        } else {
            i--;
            continue;
        }
    }
    if (debug) std::cout << " --success\n";

}
//LEVEL 4 SPELLS
if (tomeSpells[3] > 0) {
    if (debug) std::cout << "finding " << tomeSpells[3] << " lvl4 spells\n";

    spellholder.push_back("~Level 4 Spells~");  //header for spell level
    for (uint i = 0; i < tomeSpells[3]; i++) {
        string tmp = GenerateScroll(4);
        if (tmp.find("wizard") != std::string::npos) { //if scroll is a wizard scroll
            tmp.erase(0, 18);  //removes the scroll property
            tmp.erase((tmp.begin()+tmp.find_first_of("(")-1), (tmp.begin()+tmp.find_first_of(")")+1)); //removes the class details property
        } else {
            i--;   //didn't roll a wizard spell, trying again.
            continue;
        }
        bool not_duplicateSpell = true;
        for (auto i : spellholder) {
            if (i == tmp) not_duplicateSpell = false;
        }
        if (not_duplicateSpell) {
            spellholder.push_back(tmp);
        } else {
            i--;
            continue;
        }
    }
    if (debug) std::cout << " --success\n";

}
//LEVEL 5 SPELLS
if (tomeSpells[4] > 0) {
    if (debug) std::cout << "finding " << tomeSpells[4] << " lvl5 spells\n";

    spellholder.push_back("~Level 5 Spells~");  //header for spell level
    for (uint i = 0; i < tomeSpells[4]; i++) {
        string tmp = GenerateScroll(5);
        if (tmp.find("wizard") != std::string::npos) { //if scroll is a wizard scroll
            tmp.erase(0, 18);  //removes the scroll property
            tmp.erase((tmp.begin()+tmp.find_first_of("(")-1), (tmp.begin()+tmp.find_first_of(")")+1)); //removes the class details property
        } else {
            i--;   //didn't roll a wizard spell, trying again.
            continue;
        }
        bool not_duplicateSpell = true;
        for (auto i : spellholder) {
            if (i == tmp) not_duplicateSpell = false;
        }
        if (not_duplicateSpell) {
            spellholder.push_back(tmp);
        } else {
            i--;
            continue;
        }
    }
    if (debug) std::cout << " --success\n";

}
//LEVEL 6 SPELLS
if (tomeSpells[5] > 0) {
    if (debug) std::cout << "finding " << tomeSpells[5] << " lvl6 spells\n";

    spellholder.push_back("~Level 6 Spells~");  //header for spell level
    for (uint i = 0; i < tomeSpells[5]; i++) {
        string tmp = GenerateScroll(6);
        if (tmp.find("wizard") != std::string::npos) { //if scroll is a wizard scroll
            tmp.erase(0, 18);  //removes the scroll property
            tmp.erase((tmp.begin()+tmp.find_first_of("(")-1), (tmp.begin()+tmp.find_first_of(")")+1)); //removes the class details property
        } else {
            i--;   //didn't roll a wizard spell, trying again.
            continue;
        }
        bool not_duplicateSpell = true;
        for (auto i : spellholder) {
            if (i == tmp) not_duplicateSpell = false;
        }
        if (not_duplicateSpell) {
            spellholder.push_back(tmp);
        } else {
            i--;
            continue;
        }
    }
    if (debug) std::cout << " --success\n";
}
//LEVEL 7 SPELLS
if (tomeSpells[6] > 0) {
    if (debug) std::cout << "finding " << tomeSpells[6] << " lvl7 spells\n";

    spellholder.push_back("~Level 7 Spells~");  //header for spell level
    for (uint i = 0; i < tomeSpells[6]; i++) {
        string tmp = GenerateScroll(7);
        if (tmp.find("wizard") != std::string::npos) { //if scroll is a wizard scroll
            tmp.erase(0, 18);  //removes the scroll property
            tmp.erase((tmp.begin()+tmp.find_first_of("(")-1), (tmp.begin()+tmp.find_first_of(")")+1)); //removes the class details property
        } else {
            i--;   //didn't roll a wizard spell, trying again.
            continue;
        }
        bool not_duplicateSpell = true;
        for (auto i : spellholder) {
            if (i == tmp) not_duplicateSpell = false;
        }
        if (not_duplicateSpell) {
            spellholder.push_back(tmp);
        } else {
            i--;
            continue;
        }
    }
    if (debug) std::cout << " --success\n";
}
//LEVEL 8 SPELLS
if (tomeSpells[7] > 0) {
    if (debug) std::cout << "finding " << tomeSpells[7] << " lvl8 spells\n";

    spellholder.push_back("~Level 8 Spells~");  //header for spell level
    for (uint i = 0; i < tomeSpells[7]; i++) {
        string tmp = GenerateScroll(8);
        if (tmp.find("wizard") != std::string::npos) { //if scroll is a wizard scroll
            tmp.erase(0, 18);  //removes the scroll property
            tmp.erase((tmp.begin()+tmp.find_first_of("(")-1), (tmp.begin()+tmp.find_first_of(")")+1)); //removes the class details property
        } else {
            i--;   //didn't roll a wizard spell, trying again.
            continue;
        }
        bool not_duplicateSpell = true;
        for (auto i : spellholder) {
            if (i == tmp) not_duplicateSpell = false;
        }
        if (not_duplicateSpell) {
            spellholder.push_back(tmp);
        } else {
            i--;
            continue;
        }
    }
    if (debug) std::cout << " --success\n";


}
//LEVEL 9 SPELLS
if (tomeSpells[8] > 0) {
    if (debug) std::cout << "finding " << tomeSpells[8] << " lvl9 spells\n";

    spellholder.push_back("~Level 9 Spells~");  //header for spell level
    for (uint i = 0; i < tomeSpells[8]; i++) {
        string tmp = GenerateScroll(9);
        if (tmp.find("wizard") != std::string::npos) { //if scroll is a wizard scroll
            tmp.erase(0, 18);  //removes the scroll property
            tmp.erase((tmp.begin()+tmp.find_first_of("(")-1), (tmp.begin()+tmp.find_first_of(")")+1)); //removes the class details property
        } else {
            i--;   //didn't roll a wizard spell, trying again.
            continue;
        }
        bool not_duplicateSpell = true;
        for (auto i : spellholder) {
            if (i == tmp) not_duplicateSpell = false;
        }
        if (not_duplicateSpell) {
            spellholder.push_back(tmp);
        } else {
            i--;
            continue;
        }
    }
    if (debug) std::cout << " --success\n";
}

*/


