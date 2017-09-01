#include "scenemanager.h"

using namespace std;

void SceneManager::makeSpellbook() {	
    std::vector<std::string> spellholder;  //for making the actual spellbook

//	vector<string> spellholder;  //headers of ~Level X Spells~ before each level list of spells
								//todo make spells sorted without effecting this header
    //LEVEL 1 SPELLS
    if (!inputText[0].empty()) {
		spellholder.push_back("~Level 1 Spells~");
        for (int i = 0; i < inputText[0]; i++) {
            string tmp = GenerateScroll(1);
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
    //LEVEL 2 SPELLS
    if (inputText[1] > 0) {
        for (int i = 0; i < inputText[1]; i++) {
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
/*        sort(spellholder.begin(), spellholder.end());
        for (auto i : spellholder) {  //output all spells
            cout << i << endl;
        }
        spellholder.clear();  */
    }
    //LEVEL 3 SPELLS
    if (inputText[2] > 0) {
        for (int i = 0; i < inputText[2]; i++) {
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
    if (inputText[3] > 0) {
        for (int i = 0; i < inputText[3]; i++) {
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
    if (inputText[4] > 0) {
        for (int i = 0; i < inputText[4]; i++) {
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
    if (inputText[5] > 0) {
        for (int i = 0; i < inputText[5]; i++) {
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
    if (inputText[6] > 0) {
        for (int i = 0; i < inputText[6]; i++) {
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
    if (inputText[7] > 0) {
        for (int i = 0; i < inputText[7]; i++) {
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
    if (inputText[8] > 0) {
        for (int i = 0; i < inputText[8]; i++) {
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
    // add save option later
}
}
