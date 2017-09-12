# Variables
CC=gcc
CFLAGS=
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

mrproper: clean
	rm -rf $(EXEC)