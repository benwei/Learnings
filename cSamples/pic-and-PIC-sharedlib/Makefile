ifeq ($(DEBUG),1)
CFLAGS +=-g
endif
CFLAGS += -Wall
CFILES=foo.c
VERSION=0.1
fooname1=libfoo1_pic.so.1
fooname2=libfoo2_PIC.so.1
TARGETS=$(fooname1).$(VERSION) $(fooname2).$(VERSION)

# notes: -fpic and -fPIC in x86 is the same.

all: $(TARGETS)

foo1_pic.o: foo.c
	$(CC) -fpic -o $(@:.o=.s) -S $<
	$(CC) $(CFLAGS) -fpic -c $< -o $@ 

libfoo1_pic.so.1.0.1: foo1_pic.o
	$(CC) -shared -Wl,-soname,$(fooname1) -o $@ $< -lc

foo2_PIC.o: foo.c
	$(CC) -fPIC -o $(@:.o=.s) -S $<
	$(CC) $(CFLAGS) -fPIC -c $< -o $@ 

libfoo2_PIC.so.1.0.1: foo2_PIC.o
	$(CC) -shared -Wl,-soname,$(fooname2) -o$@ $< -lc

compare_s: $(TARGETS)
	@diff foo1_pic.s foo2_PIC.s ; \
	if [ $$? -eq 0 ]; then \
		echo "The same!" ; \
	fi

compare_by_vim: $(TARGETS)
	vim -d foo1_pic.s foo2_PIC.s

clean:
	rm -f *.o *.so.* *.s
