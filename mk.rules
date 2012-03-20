
mk-nothing:
	@echo "do nothing. this makefile is used for "make clean" before rsync or git commit"

mk-clean:
	@for i in $(dirs) ; do \
	if [ -d $$i -a -f "$$i/Makefile" ]; then \
	echo make -C $$i clean ; \
	make -C $$i clean ; \
	fi \
	done

mk-build:
	@for i in $(dirs) ; do \
	if [ -d $$i -a -f "$$i/Makefile" ]; then \
	echo "building [$$i]"; \
	make -C $$i; \
	fi \
	done
