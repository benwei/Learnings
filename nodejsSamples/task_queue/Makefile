deps=$(wildcard src/*.js)

targetjs=build/entry.js

all: checkenv $(targetjs)

build:
	mkdir -p build ; 

checkenv: build
	@which -s r.js ; \
	if [ "$$?" -ne 0 ]; then \
	    echo "npm install -g require.js"; \
	    exit 1 ; \
	fi

$(targetjs): $(deps)
	@echo "deps: $(deps)"
	r.js -o name=entry out=$@ baseUrl=src

install:
	npm install

app.js: $(targetjs)
	@if [ ! -h $@ ] ; then \
		ln -sf ../src/app.js ./build ; \
	fi

run: app.js
	node ./build/app.js

clean:
	rm -f $(targetjs)

dist-clean: clean
	rm -rf build
