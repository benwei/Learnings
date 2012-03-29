
all: run

testla: %: %.c
	$(CC) -O2 -o $@ $@.c --save-temps

run: testla
	./testla

clean:
	rm -f *.o testla
