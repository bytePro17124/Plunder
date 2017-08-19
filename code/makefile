BUILD_DIR = build/
CPP_FLAGS = -std=c++11 -Wall
LINK_ALL_SDL2 = -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf
OBJ = $(BUILD_DIR)graphics.o \
$(BUILD_DIR)sound.o \
$(BUILD_DIR)scenemanager.o \
$(BUILD_DIR)keybindings.o \
$(BUILD_DIR)main.o \
$(BUILD_DIR)texture.o \
$(BUILD_DIR)gear.o \
$(BUILD_DIR)random_gen.o \
$(BUILD_DIR)gen_scroll.o \
$(BUILD_DIR)hoard_loot.o \
$(BUILD_DIR)scene_00_startup.o \
$(BUILD_DIR)scene_01_main_menu.o \
$(BUILD_DIR)scene_02_hoard_loot.o \
$(BUILD_DIR)scene_03_spellbook.o \
$(BUILD_DIR)scene_04_scroll.o \
$(BUILD_DIR)scene_05_other_tools.o \
$(BUILD_DIR)scene_99_exit.o


all: $(OBJ)
	g++ -o ../plunder $(OBJ) $(LINK_ALL_SDL2) 

clean:
	-rm $(OBJ)
	
.cpp.o:
	g++ -c -o $(BUILD_DIR)$@ $< $(CPP_FLAGS) $(LINK_ALL_SDL2) 


.PHONY: clean
