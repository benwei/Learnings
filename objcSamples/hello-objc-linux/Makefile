STEPFLAGS= $(shell gnustep-config --objc-flags) -lgnustep-base
OBJCFLAGS= -g $(STEPFLAGS) -O
OBJCFILES= hello.m main.m
OBJS = $(OBJCFILES:.m=.o)

.SUFFIXES: .m .o

all: hello 

.m.o:
	$(CC) $(OBJCFLAGS) -c $<

hello: $(OBJS)
	$(CC) -o $@ $^ -lobjc -lgnustep-base

run: hello
	./$^

clean:
	rm -f *.o *.d hello

