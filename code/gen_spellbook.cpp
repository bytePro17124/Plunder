#include <iostream>
#include "scenemanager.h"

using namespace std;

void SceneManager::makeSpellbook() {	
    bool debug = true;
    std::vector<std::string> spellholder;  //for making the actual spellbook

    //	vector<string> spellholder;  //headers of ~Level X Spells~ before each level list of spells
    //todo make spells sorted without effecting this header
    //LEVEL 1 SPELLS
    if (tomeSpells[0] > 0) {
        if (debug) std::cout << "finding " << tomeSpells[0] << "spells\n";
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

        /*        sort(spellholder.begin(), spellholder.end());
        for (auto i : spellholder) {  //output all spells
            cout << i << endl;
        }
        spellholder.clear();  */
    }
    //LEVEL 2 SPELLS
    if (tomeSpells[1] > 0) {
        if (debug) std::cout << "finding " << tomeSpells[0] << "spells\n";

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

        /*        sort(spellholder.begin(), spellholder.end());
        for (auto i : spellholder) {  //output all spells
            cout << i << endl;
        }
        spellholder.clear();  */
    }
    //LEVEL 3 SPELLS
    if (tomeSpells[2] > 0) {
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
        /*        sort(spellholder.begin(), spellholder.end());
        for (auto i : spellholder) {  //output all spells
            cout << i << endl;
        }
        spellholder.clear();  */
    }
    //LEVEL 4 SPELLS
    if (tomeSpells[3] > 0) {
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
        /*        sort(spellholder.begin(), spellholder.end());
        for (auto i : spellholder) {  //output all spells
            cout << i << endl;
        }
        spellholder.clear();  */
    }
    //LEVEL 5 SPELLS
    if (tomeSpells[4] > 0) {
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
        /*        sort(spellholder.begin(), spellholder.end());
        for (auto i : spellholder) {  //output all spells
            cout << i << endl;
        }
        spellholder.clear();  */
    }
    //LEVEL 6 SPELLS
    if (tomeSpells[5] > 0) {
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
        /*        sort(spellholder.begin(), spellholder.end());
        for (auto i : spellholder) {  //output all spells
            cout << i << endl;
        }
        spellholder.clear();  */
    }
    //LEVEL 7 SPELLS
    if (tomeSpells[6] > 0) {
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
        /*        sort(spellholder.begin(), spellholder.end());
        for (auto i : spellholder) {  //output all spells
            cout << i << endl;
        }
        spellholder.clear();  */
    }
    //LEVEL 8 SPELLS
    if (tomeSpells[7] > 0) {
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
        /*        sort(spellholder.begin(), spellholder.end());
        for (auto i : spellholder) {  //output all spells
            cout << i << endl;
        }
        spellholder.clear();  */
    }
    //LEVEL 9 SPELLS
    if (tomeSpells[8] > 0) {
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
        /*        sort(spellholder.begin(), spellholder.end());
        for (auto i : spellholder) {  //output all spells
            cout << i << endl;
        }
        spellholder.clear();  */
    }

    //build it into SDL2 Textures. Requires a Vector of Textures called built_spellbook_textures
    if (debug) std::cout << "turing spells into textures\n";

    if (!spellholder.empty()) {
        built_spellbook_textures.clear();
        built_spellbook_textures.resize(spellholder.size());  //change to needed size for textures
        for (uint i = 0; i < spellholder.size(); i++) {
            built_spellbook_textures[i].load(Bookman, spellholder[i], White);  //load up all the textures with the spellholder data textb
        }
    }

    if (debug) std::cout << " -- success\n";

}

