CFLAGS = --save-temps -g -Wa,-a,-ad
all: run

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
	rm -f *.o testla testsw
