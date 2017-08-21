# Plunder

*currently this runs on linux on any distro that uses apt-get, its all free*

#### get to lootin'

<img src="plunder_screenshot_main_menu.png" height="180px" align="right">

````make && ./plunder````

* builds the program, then runs it

#### need dependencies to compile this?

````make dep````

* installs all dependencies using apt-get

#### fook it just do this the first time:

````git clone https://github.com/bytePro17124/Plunder.git && cd Plunder && make dep && make && ./plunder```` 

* clones this program, moves to directory, installs all dependencies, builds the program, runs the program

#### after you have built it

````./plunder```` 

* runs the plunder program

#### notes and todo

* this program is still a work in progress
	* functional : Hoard Loot, Spell Scrolls
	* being built/not yet functional : Spellbooks, Other Tools
* there are plenty of other ways to get this running but I won't be covering them here
* running within a virtual machine will not use vsync correctly, and some screens may fly by at an alarming rate. This is to be expected in a vm but shouldn't effect core functionality

*please notify me of any issues!*
