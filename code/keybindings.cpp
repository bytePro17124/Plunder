#include "scenemanager.h"
#include "random_gen.h"
#include <iostream>

void SceneManager::process_mouse_and_keyboard() {
    while (SDL_PollEvent (&e) != 0) {
        switch (e.type) {
        case SDL_QUIT:  // the Operating System's Window Manager Red X is clicked.
            scene = EXIT;
            break;
        case SDL_MOUSEBUTTONDOWN:  // any click
            switch (e.button.button) {
            case SDL_BUTTON_LEFT:
                mouseLeftX = e.button.x;
                mouseLeftY = e.button.y;
                switch (scene) {
                case STARTUP: break;
                case MAIN_MENU:
                    if ( (mouseLeftX > (ScreenWidth/2 - hoardlooticon.getWidth() - offset) && mouseLeftX < (ScreenWidth/2 - offset)) && (mouseLeftY > (ScreenHeight/2 - hoardlooticon.getHeight() - offset) && mouseLeftY < (ScreenHeight/2 - offset)) ) {  // click hoard loot
                        scene = HOARD_LOOT;
                        if (isSoundOn) Sound_Engine.playmenusound();
                    } else if ( (mouseLeftX > ScreenWidth/2 + offset && mouseLeftX < ScreenWidth/2 + offset + spellbookicon.getWidth()) && (mouseLeftY > (ScreenHeight/2 - offset - spellbookicon.getHeight()) && mouseLeftY < (ScreenHeight/2 - offset)) ) {  // click spellbook
                        scene = SPELLBOOK_CREATE;
                        if (isSoundOn) Sound_Engine.playmenusound();
                    } else if ( (mouseLeftX > ScreenWidth/2 - scrollicon.getWidth() - offset && mouseLeftX < ScreenWidth/2 - offset) && (mouseLeftY > ScreenHeight/2 + offset && mouseLeftY < ScreenHeight/2 + offset + scrollicon.getHeight()) ) {  // click scroll+
                        scene = SCROLL_ROLLER;
                        if (isSoundOn) Sound_Engine.playmenusound();
                    } else if ( (mouseLeftX > ScreenWidth/2 + offset && mouseLeftX < ScreenWidth/2 + offset + toolsicon.getWidth()) && (mouseLeftY > (ScreenHeight/2 + offset) && mouseLeftY < (ScreenHeight/2 + offset + toolsicon.getHeight())) ) {
                        scene = OTHER_TOOLS;
                    } else if ( mouseLeftX > (ScreenWidth - soundbutton_off.getWidth()) && mouseLeftY > (ScreenHeight - soundbutton_off.getHeight()) ) {
                        if (isSoundOn) isSoundOn = false;
                        else isSoundOn = true;
                    }

                    //click sound on/off

                    break;
                case HOARD_LOOT:
                    if ((mouseLeftX > 75 && mouseLeftX < 75 + backarrow.getWidth()) && (mouseLeftY > ScreenHeight - 150 && mouseLeftY < ScreenHeight - 150 + backarrow.getHeight())) {  //back button clicked
                        if (!loot_results_ready) scene = MAIN_MENU;
                        if (!loot_results_ready) if (isSoundOn) Sound_Engine.playcancelsound();
                        loot_results_ready = false;
                        hoard_loot_display.clear();
                        treasure_pile.full_gear_list.clear();
                    }
                    if (!loot_results_ready) {
                        for (int i = 1; i < 5; i++) {
                            if ((mouseLeftX > ScreenWidth/2 - hoard_menu_display[i].getWidth()/2 && mouseLeftX < ScreenWidth/2 + hoard_menu_display[i].getWidth()/2) && ( mouseLeftY > 110 + i * 75 && mouseLeftY < 110 + i * 75 + hoard_menu_display[i].getWidth()) ) {
                                switch (i) {
                                case 1:
                                    treasure_pile.GenerateHoardTreasureCR_0_4();
                                    update_hoard_display = loot_results_ready = true;
                                    break;
                                case 2:
                                    treasure_pile.GenerateHoardTreasureCR_5_10();
                                    update_hoard_display = loot_results_ready = true;
                                    //                                    Sound_Engine.playlootsound();
                                    break;
                                case 3:
                                    treasure_pile.GenerateHoardTreasureCR_11_16();
                                    update_hoard_display = loot_results_ready = true;
                                    //                                    Sound_Engine.playlootsound();
                                    break;
                                case 4:
                                    treasure_pile.GenerateHoardTreasureCR_17();
                                    update_hoard_display = loot_results_ready = true;
                                    //                                    Sound_Engine.playlootsound();
                                    break;
                                default:break;
                                }
                            }
                        }
                    } else {
                        if (mouseLeftX > ScreenWidth - 75 - save_loot_button.getWidth() && mouseLeftX < ScreenWidth - 75 && mouseLeftY > ScreenHeight - 75 - save_loot_button.getHeight() && mouseLeftY < ScreenHeight - 75) {
                            loot_write_out = true;
                        }
                    }
                    break;
                case SPELLBOOK_CREATE:
                    if ((mouseLeftX > 75 && mouseLeftX < 75 + backarrow.getWidth()) && (mouseLeftY > ScreenHeight - 150 && mouseLeftY < ScreenHeight - 150 + backarrow.getHeight())) {  //back button clicked
                        //BACK BUTTON CLICKED
                        if (readyToDisplay) readyToDisplay = false;
                        else scene = MAIN_MENU;
                        if (isSoundOn) Sound_Engine.playcancelsound();
                    }
                    for (int i = 0; i != 9; i++) {  // spellbook level key clicks
                        if ((mouseLeftX > ScreenWidth/2 + 40 && mouseLeftX < ScreenWidth/2 + 40 + spellbook_details_input[i].w) && (mouseLeftY > 140 + 50*i && mouseLeftY < 140 + 50*i + spellbook_details_input[i].h)) {
                            tomeClickEntries = (TOMECLICKENTRIES)i;
                        }
                    }
                    for (int i = 9; i != 11; i++) { // spellbook description or max pages key clicks
                        if ((mouseLeftX > ScreenWidth/2 + 40 && mouseLeftX < ScreenWidth/2 + 40 + spellbook_details_input[i].w) && (mouseLeftY > 590 && mouseLeftY < 590 + spellbook_details_input[i].h) && i == 9) {
                            tomeClickEntries = (TOMECLICKENTRIES)i;
                        }
                        if ((mouseLeftX > ScreenWidth/2 + 150 && mouseLeftX < ScreenWidth/2 + 150 + spellbook_details_input[i].w) && (mouseLeftY > 640 && mouseLeftY < 640 + spellbook_details_input[i].h) && i == 10) {
                            tomeClickEntries = (TOMECLICKENTRIES)i;
                        }
                    }
                    if (hasSpells && hasDescription && (mouseLeftX > ScreenWidth/2 + ScreenWidth/4 - create_spellbook_button.getWidth()/2 && mouseLeftX < ScreenWidth/2 + ScreenWidth/4 + create_spellbook_button.getWidth()/2) && (mouseLeftY > ScreenHeight/2 - create_spellbook_button.getHeight()/2 && mouseLeftY < ScreenHeight/2 + create_spellbook_button.getHeight()/2)) {
                        makeSpellbook();
                    }

                    break;
                case SCROLL_ROLLER:
                    if ((mouseLeftX > 75 && mouseLeftX < 75 + backarrow.getWidth()) && (mouseLeftY > ScreenHeight - 150 && mouseLeftY < ScreenHeight - 150 + backarrow.getHeight())) {  //back button clicked
                        if (!loot_results_ready) scene = MAIN_MENU;
                        loot_results_ready = false;
                        if (isSoundOn) Sound_Engine.playcancelsound();
                    }
                    if (!loot_results_ready) {
                        for (int i = 1; i < 10; i++) {
                            if ((mouseLeftX > ScreenWidth/2 - scroll_menu_display[i].getWidth()/2 && mouseLeftX < ScreenWidth/2 + scroll_menu_display[i].getWidth()/2) && ( mouseLeftY > 80 + i * 55 && mouseLeftY < 80 + i * 55 + scroll_menu_display[i].getWidth()) ) {
                                switch (i) {
                                case 1:
                                    scroll_loot_display.load(Vecna, GenerateScroll(1), White);
                                    loot_results_ready = true;
                                    break;
                                case 2:
                                    scroll_loot_display.load(Vecna, GenerateScroll(2), White);
                                    loot_results_ready = true;
                                    break;
                                case 3:
                                    scroll_loot_display.load(Vecna, GenerateScroll(3), White);
                                    loot_results_ready = true;
                                    break;
                                case 4:
                                    scroll_loot_display.load(Vecna, GenerateScroll(4), White);
                                    loot_results_ready = true;
                                    break;
                                case 5:
                                    scroll_loot_display.load(Vecna, GenerateScroll(5), White);
                                    loot_results_ready = true;
                                    break;
                                case 6:
                                    scroll_loot_display.load(Vecna, GenerateScroll(6), White);
                                    loot_results_ready = true;
                                    break;
                                case 7:
                                    scroll_loot_display.load(Vecna, GenerateScroll(7), White);
                                    loot_results_ready = true;
                                    break;
                                case 8:
                                    scroll_loot_display.load(Vecna, GenerateScroll(8), White);
                                    loot_results_ready = true;
                                    break;
                                case 9:
                                    scroll_loot_display.load(Vecna, GenerateScroll(9), White);
                                    loot_results_ready = true;
                                    break;
                                default:break;
                                }
                            }
                        }
                    }
                    break;
                case OTHER_TOOLS:
                    if ((mouseLeftX > 75 && mouseLeftX < 75 + backarrow.getWidth()) && (mouseLeftY > ScreenHeight - 150 && mouseLeftY < ScreenHeight - 150 + backarrow.getHeight())) {  //back button clicked
                        if (!loot_results_ready) scene = MAIN_MENU;
                        loot_results_ready = false;
                        if (isSoundOn) Sound_Engine.playcancelsound();
                    }
                    break;


                case EXIT: break;  //disallow key clicks
                }
                break;
            }
            break;
        case SDL_KEYDOWN:

            switch (scene) {
            case STARTUP: break;
            case MAIN_MENU: break;
            case HOARD_LOOT: break;
            case SPELLBOOK_CREATE:
                if (e.key.keysym.sym == SDLK_BACKSPACE)
                    switch (tomeClickEntries) {
                    case NON: break;
                    case L1: if (entriesText[0].length() > 0) entriesText[0].pop_back(); spellbookInputValidator(); break;
                    case L2: if (entriesText[1].length() > 0) entriesText[1].pop_back(); spellbookInputValidator(); break;
                    case L3: if (entriesText[2].length() > 0) entriesText[2].pop_back(); spellbookInputValidator(); break;
                    case L4: if (entriesText[3].length() > 0) entriesText[3].pop_back(); spellbookInputValidator(); break;
                    case L5: if (entriesText[4].length() > 0) entriesText[4].pop_back(); spellbookInputValidator(); break;
                    case L6: if (entriesText[5].length() > 0) entriesText[5].pop_back(); spellbookInputValidator(); break;
                    case L7: if (entriesText[6].length() > 0) entriesText[6].pop_back(); spellbookInputValidator(); break;
                    case L8: if (entriesText[7].length() > 0) entriesText[7].pop_back(); spellbookInputValidator(); break;
                    case L9: if (entriesText[8].length() > 0) entriesText[8].pop_back(); spellbookInputValidator(); break;
                    case DESCRIPTION: if (entriesText[9].length() > 0) entriesText[9].pop_back(); spellbookInputValidator(); break;
                    case PAGES: if (entriesText[10].length() > 0) entriesText[10].pop_back(); spellbookInputValidator(); break;
                    default: break;
                    }
            case SCROLL_ROLLER: break;
            case OTHER_TOOLS: break;
            default: break;
            }
            break;

        case SDL_TEXTINPUT:

            switch (scene) {
            case STARTUP: break;
            case MAIN_MENU: break;
            case HOARD_LOOT: break;
            case SPELLBOOK_CREATE:
                switch (tomeClickEntries) {
                case NON: break;
                case L1: entriesText[0] += e.text.text; spellbookInputValidator(); break;
                case L2: entriesText[1] += e.text.text; spellbookInputValidator(); break;
                case L3: entriesText[2] += e.text.text; spellbookInputValidator(); break;
                case L4: entriesText[3] += e.text.text; spellbookInputValidator(); break;
                case L5: entriesText[4] += e.text.text; spellbookInputValidator(); break;
                case L6: entriesText[5] += e.text.text; spellbookInputValidator(); break;
                case L7: entriesText[6] += e.text.text; spellbookInputValidator(); break;
                case L8: entriesText[7] += e.text.text; spellbookInputValidator(); break;
                case L9: entriesText[8] += e.text.text; spellbookInputValidator(); break;
                case DESCRIPTION: entriesText[9] += e.text.text;
                    if ((int)entriesText[9].size() > SPELLBOOK_LIMITS[9]) {
                        entriesText[9].pop_back();  ///GET WRECKED BY THE LIMITS FOOL
                    }
                    break;
                case PAGES: entriesText[10] += e.text.text; spellbookInputValidator(); break;
                default: break;
                }
            case SCROLL_ROLLER: break;
            case OTHER_TOOLS: break;
            default: break;
            }
            break;
            //		case SDL_MOUSEMOTION:
            //			mouseLeftX = e.button.x;
            //			mouseLeftY = e.button.y;

            //			break;
        }
    }
}

