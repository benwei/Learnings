CFILES = main.c 
OBJS = $(CFILES:.c=.o)
INCS =-I.
CFLAGS = -Wall -std=c99 -pedantic -g
CFLAGS += $(INCS)
LDFLAGS =
CLEAN_FILES+= file01.txt

TARGET = test_mmap

all: $(TARGET)

include ../mk.rules
