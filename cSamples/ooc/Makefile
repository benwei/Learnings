CFILES = main.c class.c object.c point.c inherit_simple.c
OBJS = $(CFILES:.c=.o)
INCS =-I.
CFLAGS = -Wall -std=c99 -pedantic 
CFLAGS += $(INCS)
LDFLAGS =

TARGET = ooc_point

all: $(TARGET)

include ../rules.mk
