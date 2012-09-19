deps=$(wildcard src/*.js)
out_dir=out
deps_dir=.deps
deps_js=app.js
deps_d=$(patsubst %.js,$(deps_dir)/%.d,$(deps_js))
targetjs=$(out_dir)/entry.js

all: $(targetjs)

$(targetjs): $(deps) $(deps_d)
	#node node_modules/.bin/r.js -o name=entry $(out_dir)=$@ baseUrl=src
	# method 2 for comipling entry.js by app.build.js
	node ./node_modules/.bin/r.js -o app.build.js

install:
	npm install

$(out_dir):
	mkdir -p $(out_dir) 

$(deps_dir):
	mkdir -p $@

$(deps_dir)/app.d: $(deps_dir) $(out_dir)
	touch $@
	# symbolic link can't use as a dependency rule, used .d file instead.
	ln -f src/app.js $(out_dir)/ 

run: $(targetjs)
	node out/app.js

clean:
	@rm -f $(targetjs) ;\
	rm -rf $(deps_dir) $(out_dir)

dist-clean: clean
