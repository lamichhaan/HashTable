# File:     makefile
# Author:   Dan Brekke

# Description
# This makefile will compile the program

EXE=prog8
CC=g++
OBJECTS=main.o symbol.o
$(EXE):		$(OBJECTS)
		$(CC) -o $(EXE) $(OBJECTS)
main.o: 	main.cpp hashtable.h symbol.h
		$(CC) -c main.cpp
symbol.o:	symbol.cpp symbol.h
		$(CC) -c symbol.cpp
clean:
		rm -rf $(OBJECTS) *~ $(EXE)

