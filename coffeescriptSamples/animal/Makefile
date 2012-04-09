
SRCFILE=animal.coffee
OUTBIN=animal.js

all: $(OUTBIN)

animal.js: $(SRCFILE)
	coffee -c $^

debug: $(SRCFILE) 
	coffee $^

run: $(OUTBIN)
	node $^

clean:
	rm -f animal.js
