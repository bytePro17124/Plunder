# Plunder D&D Loot

<img src="plunder_screenshot_main_menu.png" height="180px" align="right">


## Features 

1. Generate Piles of Treasure (Horde Loot Logic, See 5e DM Guide)
2. Generate Spellbooks and Scrolls prefilled with Random Spells
3. Generate Random Names ([based on Kismet's list](http://www.dnd.kismetrose.com/pdfs/KismetsFantasyNames.pdf))
* Save treasure and spellbook results to a text file.
* Hours of game time saved!

#### get to lootin' (BUILD & RUN instructions - linux: ubuntu, mint)

1. ````git clone https://github.com/bytePro17124/Plunder.git```` : downloads the source code
2. ````cd plunder```` : moves to directory
3. ````make dep```` : installs all dependencies using apt-get (you will need the SDL2 libraries and a C++ compiler to build)
4. ````make```` : builds the program
5. ````./plunder```` : runs the program (or go double click the executable object)

-- CURRENTLY WORKING ON A CROSSPLATFORM BUILD SOLUTION WITH CMAKE

#### process updates

1. ````git pull```` : download latest changes
2. ````make clean```` : in case any headers were changed...
3. ````make```` : rebuild with the latest code

#### notes

* this program is still a work in progress
	* everything is currently functional but may be a little wonky in some cases
* there are ways to get this running in Windows and macOS but I haven't tested it yet - you just need the SDL2 libraries and a C++ compiler pretty much
* running **plunder** within a virtual machine will not use vsync correctly, and some screens may fly by at an alarming rate. This is to be expected in a vm but shouldn't effect core functionality. I'll cap frame rate at some point.
* tried to focus on things that WotC didn't provide good tools for in its latest online tool suite

#### continual development
I am making this program for myself and will continually update it as I see fit. Open source contributions are welcome.

*Anyone out there that uses this - please notify me of any issues!*
