#BUILD_DIR = build/
CPP_FLAGS = -std=c++11 -Wall
LINK_ALL_SDL2 = -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf
SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)

all: $(OBJ)
	g++ -o ../plunder $(OBJ) $(LINK_ALL_SDL2) 

clean:
	-rm $(OBJ)
	
.cpp.o:
	g++ -c -o $@ $< $(CPP_FLAGS) $(LINK_ALL_SDL2)


.PHONY: clean
