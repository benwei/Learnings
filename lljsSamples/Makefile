
# LLJS: 
LJC=./LLJS/bin/ljc

all: run

test.js: test.ljs
	@ echo "build [$<] --> [$@]" ; $(LJC) -o $@ $<

run: test.js
	@node test.js

clean:
	rm -rf test.js
