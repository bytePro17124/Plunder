all: plunder
	@ECHO UPGRADE COMPLETE

plunder:
	+(MAKE) src
	
clean:
	-rm plunder
	+(MAKE) src clean
