CFLAGS=-Wall -I.  -g
CFILES=test_fork.c
OBJS=$(CFILES:.c=.o)
TARGET=case_fork

all: run

include ../rules.mk

leak-check:
	valgrind --leak-check=full ./$(TARGET)
