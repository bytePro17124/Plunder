OBJ = graphics.o \
sound.o \
scenemanager.o \
keybindings.o \
main.o \
texture.o \
scene_00_startup.o \
scene_01_main_menu.o \
scene_02_horde_loot.o \
scene_99_exit.o
CPP_FLAGS = -std=c++11 -Wall
LINK_ALL_SDL2 = -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf

all: $(OBJ)
	g++ $(OBJ) $(LINK_ALL_SDL2) -o ../plunder

clean:
	-rm $(OBJ)
	
.cpp.o:
	g++ -c $< $(CPP_FLAGS) $(LINK_ALL_SDL2) -o $@
