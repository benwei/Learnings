
all: run

testnum: test.c
	gcc -o $@  $^

run: testnum
	./$^

clean:
	rm -f testnum
