TARGET = plunder
PREREQUISITES = build-essential libsdl2-dev libsdl2-image-dev libsdl2-ttf-dev libsdl2-mixer-dev
SOURCE_PATH = code

all:
	+$(MAKE) -C $(SOURCE_PATH)
	mkdir -p saved_loot
	@echo "\nUPGRADE COMPLETE"

clean:
	-rm $(TARGET)
	+$(MAKE) -C $(SOURCE_PATH) $@

dep:
	apt-get install $(PREREQUISITES)	
	
#install:
#	mkdir $(HOME)/.plunder
#	install -m 755 plunder /usr/local/bin/plunder

.PHONY: all clean dep
