BUILD_DIR = build/
CFLAGS = -std=c++11 -Wall
LINK_ALL_SDL2 = -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf
SRC = $(wildcard *.cpp)
O = $(addsuffix .o,$(basename $(SRC)))
OBJ = $(addprefix $(BUILD_DIR), $(O))

../plunder: $(OBJ)
	g++ -o ../plunder $(OBJ) $(LINK_ALL_SDL2) 

clean:
	-rm $(OBJ)
	
$(BUILD_DIR)%.o: %.cpp
	g++ -c -o $@ $< $(CFLAGS) $(LINK_ALL_SDL2)

.PHONY: clean
