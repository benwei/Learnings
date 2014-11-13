GOFILES = $(shell find . -name "*.go")

all: run

loader: $(GOFILES)
	go build sample
	go build loader.go

run: loader
	./loader

clean:
	rm -f loader
