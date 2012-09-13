#!/bin/sh

jarcc_dir=$(HOME)/.clc/closure-compiler
jarcc=$(jarcc_dir)/compiler.jar
clc=java -jar $(jarcc)

# --compilation_level [WHITESPACE_ONLY | : 
# Specifies the compilation level to use
# SIMPLE_OPTIMIZATIONS | ADVANCED_OPTIM : . 
# Options: WHITESPACE_ONLY, SIMPLE_OPTIZATIONS] 

CLC_FLAGS=--compilation_level SIMPLE_OPTIMIZATIONS

JSFILES=sample.js strangers.js talk.js

PREFIX=build

SJSFILES=$(addprefix src/, $(JSFILES))
OJSFILES=$(addprefix $(PREFIX)/, $(JSFILES))

SJSMOD=./src/main.js
JSMOD=$(PREFIX)/main.js

all: prebuild setup $(JSMOD)

prebuild:
	@mkdir -p $(PREFIX)

setup: $(jarcc)

$(jarcc):
	# reference: https://developers.google.com/closure/compiler/docs/gettingstarted_app
	mkdir -p $(jarcc_dir) ; cd $(jarcc_dir) ; \
		wget -O clc.zip http://closure-compiler.googlecode.com/files/compiler-latest.zip ; \
		unzip clc.zip
$(PREFIX)/%.js : src/%.js
	@$(clc) $(CLC_FLAGS) --js $< --js_output_file $@ ; \
		echo "compiling [$<]" ; 
	

$(JSMOD): $(OJSFILES)
	ln -f $(SJSMOD) $@ 

run: prebuild $(JSMOD)
	@node $(JSMOD)

clean:
	@rm -f $(JSMOD) $(OJSFILES)  ; \
	rm -rf build
