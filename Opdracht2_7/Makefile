#############################################################################
#
# Project Makefile
#
# (c) Wouter van Ooijen (www.voti.nl) 2016
#
# This file is in the public domain.
# 
#############################################################################

# source & header files in this project (main.cpp is automatically assumed)

HEADERS += note.hpp
HEADERS += melody.hpp
HEADERS += note_player.hpp
HEADERS += fur_elise.hpp

HEADERS += note_player_gpio.hpp
SOURCES += note_player_gpio.cpp

HEADERS += rtttl_player.hpp
SOURCES += rtttl_player.cpp

# other places to look for files for this project
SEARCH  := 

# set REATIVE to the next higher directory 
# and defer to the Makefile.due there
RELATIVE := $(RELATIVE)../
include $(RELATIVE)Makefile.due

.PHONY: generator melody

generator:
	make -f maakfile && ./generator.exe

melody:
	make -f maakfile && ./generator.exe > newMelody.hpp

generator.exe: generator.o note_player_cout.o rtttl_player.o
	g++ -std=c++17 generator.o note_player_cout.o -o generator.exe

generator.o : generator.cpp note_player_cout.hpp note_player.hpp rtttl_player.hpp note.hpp
	g++ -std=c++17 -c generator.cpp -o generator.o