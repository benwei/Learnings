include ../../mk.defines

CFILES=$(wildcard *.c)
OBJS=$(CFILS:.c=.o)
BINARIES=$(CFILES:.c=$(EXEEXT))

CFLAGS=-Wall

all: mk-binaries

.c.o:
	$(CC) -c $< -o $@ $(CFLAGS) 

$(EXE): $(OBJ)
	$(CC) -o $@ $< $(LDFLAGS) 

mk-exe: $(EXE)

mk-binaries:
	@for i in $(BINARIES) ; do \
	obj="$${i%$(EXEEXT)}.o" ; \
        if [ ! -x "$$i" ]; then \
		echo "build[$$obj]->[$${i}]"; \
		make -s mk-exe EXE=$$i OBJ=$$obj ; \
	else \
		echo "existed [$$i]"; \
        fi \
	done


run: $(TARGET)
	@target="$(TARGET)"; \
	target="$${target%.c}" ; \
	if [ -x "$${target}" ] ; then \
            $(call show-split,40,=); \
	    ./$${target} ; \
            $(call show-split,40,-); \
	else \
	    echo "ex: make TARGET=<filename>"; \
        fi

clean:
	rm -f *.o $(BINARIES)
