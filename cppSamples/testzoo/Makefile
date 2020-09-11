target=testzoo

all: $(target)

$(target): $(target).cpp
	g++ -std=c++11 -g -o $@ $^

run: $(target)
	$(URUN) ./$(target) $(UARGS)

drun: $(target)
	gdb ./$(target)

clean:
	rm -f *.o $(target) 
	rm -rf *.dSYM
