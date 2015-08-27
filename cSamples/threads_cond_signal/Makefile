CFLAGS=-Wall -I.  -g -std=c90 -D_BSD_SOURCE
LDFLAGS=-lpthread
CFILES=threads.c
OBJS=$(CFILES:.c=.o)
TARGET=case_threads

all: run

include ../rules.mk

leak-check:
	valgrind --leak-check=full ./$(TARGET)
