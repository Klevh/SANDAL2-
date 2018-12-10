#!/bin/makefile

SRC=$(wildcard *.cpp)
OFILES=$(SRC:.o=.cpp)
EXEC=a.out
LDFLAGS=-lSANDAL2
CFLAGS=
CC=g++
CLEAN=*.o *~
all:$(EXEC)
$(EXEC):$(OFILES)
	$(CC) $^ -o $@ $(LDFLAGS)
%.o:%.c
	$(CC) -c $< $(CFLAGS)
clean:
	rm $(CLEAN)
clear: clean
cleaner:
	rm $(EXEC) $(CLEAN)
