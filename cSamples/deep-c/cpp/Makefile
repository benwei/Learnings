include ../../../mk.defines
CXX=g++

CXXFILES=$(wildcard *.cpp)
CXXOBJS=$(CXXFILES:.cpp=.o)
CXXBINARIES=$(CXXFILES:.cpp=$(EXEEXT))

CXXFLAGS=-Wall

all: mk-cxxbinaries

.cpp.o:
	@echo "building [$<]->$@"
	$(CXX) -c $< $(CXXFLAGS) 

$(CXXEXE): $(CXXOBJ)
	@echo "building [$<]->$@"
	$(CXX) -o $@ $< $(CXXLDFLAGS) 

mk-cxxexe: $(CXXEXE)

mk-cxxbinaries:
	@for i in $(CXXBINARIES) ; do \
		obj="$${i%$(EXEEXT)}.o" ; \
		echo "build[$$obj]->[$${i}]"; \
		make -s mk-cxxexe CXXEXE=$$i CXXOBJ=$$obj ; \
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
	rm -f *.o $(CXXBINARIES)
