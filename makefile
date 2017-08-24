TARGET = plunder
PREREQUISITES = build-essential libsdl2-dev libsdl2-image-dev libsdl2-ttf-dev libsdl2-mixer-dev
SOURCE_PATH = code
BUILD_PATH = code/build
SAVE_PATH = saved_loot

all:
	mkdir -p $(BUILD_PATH)
	+$(MAKE) -C $(SOURCE_PATH)
	mkdir -p $(SAVE_PATH) 
	@echo "\nUPGRADE COMPLETE\n"

clean:
	-rm $(TARGET)
	+$(MAKE) -C $(SOURCE_PATH) $@

dep:
	apt-get install $(PREREQUISITES)	
	
#install:
#	mkdir $(HOME)/.plunder
#	install -m 755 plunder /usr/local/bin/plunder

.PHONY: all clean dep
