CFLAGS=-Wall -I.
CFILES=test.c main.c
OBJS=$(CFILES:.c=.o)

all: run

.c.o:
	gcc -c $(CFLAGS) -o $@ $<

testnum: $(OBJS)
	gcc -o $@ $^

run: testnum
	./$^

clean:
	rm -f testnum *.o
