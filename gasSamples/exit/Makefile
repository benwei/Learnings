target=myexit
all: $(target)

.s.o:
	$(AS) -o $@ $<

$(target): exit.o
	$(LD) -o $@ $^

run: $(target)
	@ ./$(target) 10 ; \
	echo $$?

clean:
	rm -f *.o $(target)
