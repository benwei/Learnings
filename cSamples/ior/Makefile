CFLAGS=-Wall -I.  -g
CFILES=ior.c
OBJS=$(CFILES:.c=.o)
TARGET=bitwise_testing

all: run

include ../rules.mk

leak-check:
	valgrind --leak-check=full ./$(TARGET)
