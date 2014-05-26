VPATH += ../simple_hash
CFILES = main.c hash.c
OBJS = $(CFILES:.c=.o)
INCS =-I. -I../simple_hash
CFLAGS = -Wall -std=c99 -pedantic -D_BSD_SOURCE
CFLAGS += $(INCS)
LDFLAGS =

TARGET = chash

all: $(TARGET)

include ../mk.rules
