CFILES=main.c 
OBJS=$(CFILES:.c=.o)

CFLAGS=-Wall -std=c99 -pedantic -I.
LDFLAGS=-L. -lshared-lib

LIB_NAME=libshared-lib.so

LIB_CFILES=foo.c
LIB_OBJS=$(LIB_CFILES:.c=.o)
LIB_TARGET=$(LIB_NAME)

LIB_LDFLAGS = -shared -Wl,--soname,$(LIB_NAME)
RUNENV = LD_LIBRARY_PATH=.

TARGET= c-shared-lib

all: $(LIB_TARGET) $(TARGET) clean-others

-include $(LIB_OBJS:.o=.p)

include ../rules.mk

$(LIB_OBJS): %.o:%.c
	$(CC) -MMD -MF ${@:.o=.p} -c -fPIC $< -o $@ 

$(LIB_TARGET): $(LIB_OBJS)
	$(CC) $(LIB_LDFLAGS) -o $@ $(LIB_OBJS)

clean-others:
	- rm -f $(LIB_TARGET) *.p
