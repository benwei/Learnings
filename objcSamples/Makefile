dirs=$(wildcard *)

all:
	@echo "do nothing. this makefile is used for "make clean" before rsync"

clean:
	@for i in $(dirs) ; do \
	if [ -d $$i -a -f "$$i/Makefile" ]; then \
	echo make -C $$i clean ; \
	make -C $$i clean ; \
	fi \
	done
