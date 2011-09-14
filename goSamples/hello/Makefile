GOCC=6g
GOLD=6l

all: hello

hello.6: hello.go
	$(GOCC) $(CFLAGS) $^

hello: hello.6
	$(GOLD) -o $@ $^ 

run: hello
	./$^

clean:
	rm -f hello.6 hello
