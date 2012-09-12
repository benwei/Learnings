# go version go1.0.2
# test go in OSX Lion 10.7.4

GO=go

SAMPLES=$(wildcard *.go)
TARGETS=$(patsubst %.go,%,$(SAMPLES))


all: buildall
	
buildall: $(TARGETS)

%: %.go
	@echo build [$<]; \
	go build $<

run: hello
	./$^

clean:
	@rm -f $(TARGETS)
