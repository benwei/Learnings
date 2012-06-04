mtarget=sample.js
msrc:=$(mtarget:.js=.coffee)

SRCFILE=$(wildcard *.coffee)
OUTBINS=$(SRCFILE:.coffee=.js)

all: build

$(mtarget):$(msrc)
	@echo "building $^ -> $(mtarget)"
	coffee -c $(msrc)

post-build: $(mtarget)

build:
	@for i in $(OUTBINS) ; do \
	make post-build mtarget="$$i" ; \
	done

debug: $(SRCFILE) 
	coffee $^

run: $(OUTBINS)
	@for i in $^ ; do \
	echo "====> run [$$i] <====" ; \
	node "$$i" ; \
	done

clean:
	rm -f *.js
