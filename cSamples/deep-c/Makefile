include ../../mk.defines
CXX=g++
CFILES=$(wildcard *.c)
OBJS=$(CFILS:.c=.o)
BINARIES=$(CFILES:.c=$(EXEEXT))

CXXFILES=$(wildcard *.cpp)
CXXOBJS=$(CXXFILES:.cpp=.o)
CXXBINARIES=$(CXXFILES:.cpp=$(EXEEXT))

CFLAGS=-Wall
CXXFLAGS=-Wall

.SUFFIXES: .o .cpp

all: mk-binaries mk-cxxbinaries

.c.o:
	$(CC) -c $< -o $@ $(CFLAGS) 

$(EXE): $(OBJ)
	$(CC) -o $@ $< $(LDFLAGS) 

.cpp.o:
	$(CXX) -c $< -o $@ $(CXXFLAGS) 

$(CXXEXE): $(CXXOBJ)
	$(CXX) -o $@ $< $(CXXLDFLAGS) 

mk-cxxexe: $(CXXEXE)

mk-exe: $(EXE)

mk-binaries:
	@for i in $(BINARIES) ; do \
	obj="$${i%$(EXEEXT)}.o" ; \
        [ -f "$$i" ] && exit 0 ; \
	echo "build[$$obj]->[$${i}]"; \
	make -s mk-exe EXE=$$i OBJ=$$obj ; \
	done

mk-cxxbinaries:
	@for i in $(CXXBINARIES) ; do \
	obj="$${i%$(EXEEXT)}.o" ; \
        [ -f "$$i" ] && exit 0 ; \
	echo "build[$$obj]->[$${i}]"; \
	make mk-cxxexe CXXEXE=$$i CXXOBJ=$$obj ; \
	done

run: $(TARGET)$(EXEEXT)
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
	rm -f *.o $(BINARIES) $(CXXBINARIES)
