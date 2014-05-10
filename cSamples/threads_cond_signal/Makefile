CFLAGS=-Wall -I.  -g
LDFLAGS=-lpthread
CFILES=threads.c
OBJS=$(CFILES:.c=.o)
TARGET=case_threads

all: run

include ../mk.rules

leak-check:
	valgrind --leak-check=full ./$(TARGET)
