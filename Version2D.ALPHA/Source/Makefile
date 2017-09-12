# Variables
CC=gcc
CFLAGS=-lSDL
EXEC=RicochetRobot
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)

# all
all: $(EXEC)

RicochetRobot: $(OBJ) 
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean mrproper

clean:
	rm *.o

mrproper:
	rm -rf $(EXEC)
	clean