include ../../mk.defines

ASFILES = $(wildcard *.s)
OBJS = $(ASFILES:.s=.o)
binfile = hello$(EXEEXT)

all: run

.s.o:
	as -o $@ $<

$(binfile): $(OBJS)
	cc -o $@ $^ -lc

run: $(binfile)
	./$^

clean:
	rm -f *.o $(binfile)
