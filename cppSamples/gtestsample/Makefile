CXX=test.cc
OBJS=$(patsubst %,build/%,$(CXX:.cc=.o))
BIN=test1

all: prebuild buildalls run

prebuild:
	mkdir -p build

buildalls: $(BIN)

build/%.o : %.cc
	g++ -c -o $@ $^ -I.

$(BIN): $(OBJS)
	g++ -o $@ $^ -lgtest

run: prebuild ./$(BIN)
	./$(BIN) $(ARGS)

clean:
	rm -rf  test1 build
