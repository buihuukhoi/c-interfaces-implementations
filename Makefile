SRC_DIR = ./src
INC_DIR = ./include

SOURCES=$(wildcard  $(SRC_DIR)/*.c)
OBJECTS=$(patsubst %.c, %.o, $(SOURCES))

CC = gcc
CFLAGS = -Wall -I $(INC_DIR)


all: $(OBJECTS)

# clean:
# 	-rm *.o
