
CURR_OS_VERSION=$(shell sw_vers -productVersion | cut -d"." -f1 -f2)
CURR_OS=$(shell sw_vers -productName)
ifeq ($(CURR_OS),Mac OS X)
CC=gcc
OBJCFLAGS= 
LDFLAGS= -ObjC -framework Foundation
else
STEPFLAGS= $(shell gnustep-config --objc-flags) -lgnustep-base
OBJCFLAGS= $(STEPFLAGS) 
LDFLAGS=-lobjc -lgnustep-base
endif
CFLAGS= -g -O $(OBJCFLAGS) 
OBJCFILES= hello.m main.m
OBJS = $(OBJCFILES:.m=.o)

.SUFFIXES: .m .o

all: prebuild hello 

prebuild:
ifeq ($(CURR_OS),Mac OS X)
#	ln -sf $(FOUNDATION_PATH) Foundation
endif

.m.o:
	$(CC) $(OBJCFLAGS) -c $<

hello: $(OBJS)
	$(CC) -o $@ $^ $(LDFLAGS)

run: hello
	./$^

clean:
	rm -f *.o *.d hello

