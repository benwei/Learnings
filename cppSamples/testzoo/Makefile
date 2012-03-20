target=testzoo

all: $(target)

$(target): $(target).cpp
	g++ -g -o $@ $^

run: $(target)
	./$(target)

drun: $(target)
	gdb ./$(target)

clean:
	rm -f *.o $(target) 
	rm -rf *.dSYM
