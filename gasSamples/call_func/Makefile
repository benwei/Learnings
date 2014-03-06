ASM_FILES=$(wildcard *.s)
targets=$(ASM_FILES:.s=)
DYLDFLAGS=-dynamic-linker /lib/ld-linux.so.2
LDFLAGS=-lc
all: build

out/%.o: %.s
	@echo == build [$@] ; \
	$(AS) -o $@ $<

%: out/%.o
	@echo = link [$@] ; \
	$(LD) $(DYLDFLAGS) -o $@ $< $(LDFLAGS)

build: 
	@mkdir -p out ; \
	for i in $(targets); do \
	  if [ ! -f $$i.d ] ; then \
	    echo "out/$$i.o : $$i.s" > out/$$i.d ; \
	  fi ; \
	  make $$i ; \
	done

run: $(targets)
	for i in $^ ; do \
		./$$i ; \
	done

clean:
	rm -f *.o $(targets) *.d
	rm -rf out

-include out/*.d
