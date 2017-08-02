OBJ = graphics.o keybindings.o main.o scenemananger.o
CPP_FLAGS = -std=c++11 -Wall
LINK_ALL_SDL2 = -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf

all: $(OBJ)

clean:
	-rm $(OBJ)
	
.cpp.o:
	g++ -c $(CPP_FLAGS) $< $(LINK_ALL_SDL2) -o $@
