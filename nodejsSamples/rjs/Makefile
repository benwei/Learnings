targetjs=entry.js

all: run

$(targetjs):
	# node node_modules/.bin/r.js -o name=entry out=$@ baseUrl=src
	node ./node_modules/.bin/r.js -o app.build.js

install:
	npm install

app.js: $(targetjs)
	@if [ ! -h $@ ] ; then \
	ln -sf src/app.js . ; \
	fi

run: app.js
	@echo run app; node app.js

clean:
	rm -f $(targetjs)

dist-clean: clean
	rm -f app.js
