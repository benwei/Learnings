OS=$(shell uname -s)

ifeq ($(CROSS),1)
ifeq ($(OS),Darwin)
	CROSS_COMPILE=/usr/local/gcc-4.5.2-for-linux64/bin/x86_64-pc-linux-
	CC=$(CROSS_COMPILE)gcc
	AS=$(CROSS_COMPILE)as
	LD=$(CROSS_COMPILE)ld
	ifeq ($(DUMP_AD),1)
	CFLAGS = -Wa,-a,-ad
	endif
endif
endif

CFLAGS += --save-temps -g 
all: testla testsw

.c.o:
	$(CC) -c $< -I. $(CFLAGS) 

testla: main.o testla.o
	$(CC) -O2 -o $@ $^ 

testsw: main.o testsw.o
	$(CC) -O2 -o $@ $^ 

run: testla testsw
	time ./testla 
	time ./testsw 

clean:
	rm -f *.o testla testsw *.i *.s *.txt
