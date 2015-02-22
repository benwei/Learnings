# reference https://lord.io/blog/2014/assembly-on-osx/
include ../../mk.defines

ASFILES = $(wildcard *.s)
OBJS = $(ASFILES:.s=.o)
CFLAGS = -Wl,-no_pie
binfile = hello$(EXEEXT)

all: run

.s.o:
	nasm -f macho64 -l $@.lst $<

$(binfile): $(OBJS)
	gcc -m64 $(CFLAGS) -o hello  hello.o

run: $(binfile)
	./$^

clean:
	rm -f *.o $(binfile) *.lst
