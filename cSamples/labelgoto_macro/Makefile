include ../../mk.defines
CFILES=$(wildcard *.c)
OBJS=$(CFILES:.c=.o)
BINARIES=$(CFILES:.c=$(EXEEXT))
TARGET?=labelgoto_macro
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
		echo "build[$$obj]->[$${i}]"; \
		make -s mk-exe EXE=$$i OBJ=$$obj ; \
	done


run: 
	@target="$(TARGET)"; \
        if [ ! -n "$$target" ] ; then \
            echo "make run TARGET=youbinaryname" ; \
            exit 1 ; \
        fi ; \
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
