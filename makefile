TARGET = plunder
PREREQUISITES = build-essential gcc git libsdl2-dev libsdl2-image-dev libsdl2-ttf-dev libsdl2-mixer-dev
SOURCE_PATH = code

all:
	+$(MAKE) -C $(SOURCE_PATH)
	mkdir -p saved_loot
	@echo "\nUPGRADE COMPLETE"

clean:
	-rm $(TARGET)
	+$(MAKE) -C $(SOURCE_PATH) $@

dep:
	sudo apt-get install $(PREREQUISITES)	
	
install:
	mkdir /home/mje/.plunder
	sudo cp -u plunder /usr/bin
