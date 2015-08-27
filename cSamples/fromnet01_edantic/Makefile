CFILES=main.c
OBJS=$(CFILES:.c=.o)
TARGET= c_struct_flexible_array
ifneq ($(USE_C89),)
CFLAGS=-Wall -std=c89 -pedantic
else
CFLAGS=-Wall -std=c99 -pedantic
endif
LDFLAGS=

all: $(TARGET)

include ../rules.mk
