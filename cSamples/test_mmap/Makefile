CFILES = main.c filemap.c
OBJS = $(CFILES:.c=.o)
INCS =-I.
CFLAGS = -Wall -std=c99 -pedantic -g -D_BSD_SOURCE
CFLAGS += $(INCS)
LDFLAGS =
CLEAN_FILES+= file01.txt
RUNENV= bash ./tests.sh

TARGET = test_mmap

all: $(TARGET)

include ../rules.mk
