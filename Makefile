#!/bin/makefile

SRC=$(wildcard src/*.cpp) $(wildcard tests/*.cpp)
OFILES=$(SRC:.o=.cpp)
EXEC=a.out
LDFLAGS=-lSANDAL2 -std=c++11 -lSDL2 -lSDL2_ttf -lSDL2_image
CFLAGS=
CC=g++
CLEAN=*.o *~
all:$(EXEC)
$(EXEC):$(OFILES)
	$(CC) $^ -o $@ $(LDFLAGS)
	@mkdir -p build
	@mv $(EXEC) build
	@mv $(OFILES) build
%.o:%.c
	$(CC) -c $< $(CFLAGS)
clean:
	rm $(CLEAN)
clear: clean
cleaner:
	rm $(EXEC) $(CLEAN)
