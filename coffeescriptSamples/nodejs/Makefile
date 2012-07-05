APP=output/test.js

all: help

help:
	@echo "syntax: <build | watch | test | run>"

build:
	coffee -b -o output -c src 

$(APP): build

run: $(APP) 
	node $(APP)

watch:
	coffee -w src

test:
	mocha -R spec -r coffee-script -r should -u tdd test/tdd*.coffee

.PHONY: test

clean:
	rm -rf output
