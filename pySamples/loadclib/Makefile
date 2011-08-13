# this sample is tested on cygwin + windows xp
KNAMEFULL  = $(shell uname -s | sed 's/_.*//g')
# cygwin on windows xp
# CYGWIN_NT-5.1
KNAME = $(KNAMEFULL)
ifeq ($(KNAME),CYGWIN)
EXEEXT = .exe
DLLEXT = .dll
else
# testing on ubuntu
EXEEXT =
DLLEXT = .so
endif
CFLAGS = -Wall
CFILES = main.c
OBJS= $(CFILES:.c=.o)
LIBNAME= libtest
LDFLAGS= -ltest -L.

all: run

.c.o:
	$(CC) -c -o $@ $<  $(CFLAGS)

foo$(EXEEXT): $(OBJS) $(LIBNAME)$(DLLEXT)
	$(CC) -o $@ $(OBJS) $(LDFLAGS)

$(LIBNAME)$(DLLEXT): test.o
	$(CC) -o $@ -shared $^

run: foo$(EXEEXT)
	@ export LD_LIBRARY_PATH=.; ./$^ ; \
	  if [ $$? -eq 3 ]; then \
	  echo "Binary linking passed" ; \
	  python main.py $(LIBNAME)$(DLLEXT) ; \
	  if [ $$? -ne 0 ] ; then \
	  	exit 1; \
	  fi \
	else \
	  echo "Binary link failed" ; \
	fi
clean:
	rm -f foo$(EXEEXT) $(LIBNAME)$(DLLEXT)
	rm -f *.o
