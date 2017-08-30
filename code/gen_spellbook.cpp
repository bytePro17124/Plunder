#include "scenemanager.h"

void SceneManager::makeSpellbook() {	
	
    //LEVEL 1 SPELLS
    if (first > 0) {
        for (int i = 0; i < first; i++) {
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
        sort(spellholder.begin(), spellholder.end());
        for (auto i : spellholder) {  //output all spells
            cout << i << endl;
        }
        spellholder.clear();
    }
    //LEVEL 2 SPELLS
    if (second > 0) {
        for (int i = 0; i < second; i++) {
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
        sort(spellholder.begin(), spellholder.end());
        for (auto i : spellholder) {  //output all spells
            cout << i << endl;
        }
        spellholder.clear();
    }
    //LEVEL 3 SPELLS
    if (third > 0) {
        for (int i = 0; i < third; i++) {
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
        sort(spellholder.begin(), spellholder.end());
        for (auto i : spellholder) {  //output all spells
            cout << i << endl;
        }
        spellholder.clear();
    }
    //LEVEL 4 SPELLS
    if (fourth > 0) {
        for (int i = 0; i < fourth; i++) {
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
        sort(spellholder.begin(), spellholder.end());
        for (auto i : spellholder) {  //output all spells
            cout << i << endl;
        }
        spellholder.clear();
    }
    //LEVEL 5 SPELLS
    if (fifth > 0) {
        for (int i = 0; i < fifth; i++) {
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
        sort(spellholder.begin(), spellholder.end());
        for (auto i : spellholder) {  //output all spells
            cout << i << endl;
        }
        spellholder.clear();
    }
    //LEVEL 6 SPELLS
    if (sixth > 0) {
        for (int i = 0; i < sixth; i++) {
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
        sort(spellholder.begin(), spellholder.end());
        for (auto i : spellholder) {  //output all spells
            cout << i << endl;
        }
        spellholder.clear();
    }
    //LEVEL 7 SPELLS
    if (seventh > 0) {
        for (int i = 0; i < seventh; i++) {
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
        sort(spellholder.begin(), spellholder.end());
        for (auto i : spellholder) {  //output all spells
            cout << i << endl;
        }
        spellholder.clear();
    }
    //LEVEL 8 SPELLS
    if (eighth > 0) {
        for (int i = 0; i < eighth; i++) {
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
        sort(spellholder.begin(), spellholder.end());
        for (auto i : spellholder) {  //output all spells
            cout << i << endl;
        }
        spellholder.clear();
    }
    //LEVEL 9 SPELLS
    if (ninth > 0) {
        for (int i = 0; i < ninth; i++) {
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
        sort(spellholder.begin(), spellholder.end());
        for (auto i : spellholder) {  //output all spells
            cout << i << endl;
        }
        spellholder.clear();
    }
    // add save option later
    // which might need vector<string> lvl1, lvl2, lvl3, lvl4, lvl5, lvl6, lvl7, lvl8, lvl9;
}
}
