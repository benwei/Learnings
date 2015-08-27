all: t1
t1: test.v
	iverilog -o t1 test.v

run: t1
	./t1

clean:
	@rm -f t1
