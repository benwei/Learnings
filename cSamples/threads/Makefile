CFLAGS=-Wall -I.  -g
CFILES=threads.c
LDFLAGS=-lpthread
OBJS=$(CFILES:.c=.o)
TARGET=case_threads

all: run

include ../rules.mk

leak-check:
	valgrind --leak-check=full ./$(TARGET)
