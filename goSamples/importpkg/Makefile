# go version go1.0.2
# test go in OSX Lion 10.7.4

GO=go

SAMPLES=$(wildcard *.go)
TARGETS=$(patsubst %.go,%,$(SAMPLES))
TARGET=zooshow

all: buildall
	
buildall: zooshow

zooshow: $(SAMPLES)
	@echo build [$^]; \
	go build $^

run: 
	go run *.go

runbin: main
	./$^

clean:
	@rm -f $(TARGETS)
