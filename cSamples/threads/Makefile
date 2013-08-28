CFLAGS=-Wall -I.  -g
CFILES=threads.c
OBJS=$(CFILES:.c=.o)
TARGET=case_threads

all: run

include ../mk.rules

leak-check:
	valgrind --leak-check=full ./$(TARGET)
