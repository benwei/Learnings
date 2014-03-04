ASM_FILES=$(wildcard *.s)
targets=$(ASM_FILES:.s=)
LDFLAGS=
all: build

out/%.o: %.s
	@echo == build [$@] ; \
	$(AS) -o $@ $<

%: out/%.o
	@echo = link [$@] ; \
	$(LD) -o $@ $< $(LDFLAGS)

build: 
	@mkdir -p out ; \
	for i in $(targets); do \
	  if [ ! -f $$i.d ] ; then \
	    echo "out/$$i.o : $$i.s" > out/$$i.d ; \
	  fi ; \
	  make $$i ; \
	done

run: $(targets)
	bash tests.sh "$^"

clean:
	rm -f *.o $(targets) *.d
	rm -rf out

-include out/*.d
