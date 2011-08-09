# this sample is tested on cygwin + windows xp

EXEEXT = .exe
DLLEXT = .dll
LIBNAME= test

all: run

foo$(EXEEXT): main.c  $(LIBNAME)$(DLLEXT)
	$(CC) -o $@ $^ -l$(LIBNAME) -L.

$(LIBNAME)$(DLLEXT): test.c
	$(CC) -o $@ -shared $^

run: foo$(EXEEXT)
	@./foo.exe ; if [ $$? -eq 3 ]; then \
	  echo "binary link passed" ; \
	  python main.py ; \
	  if [ $$? -eq 4 ] ; then \
	  echo "python load passed" ; \
	  else \
	  echo "python load failed" ; \
	  fi \
	else \
	  echo "binary link failed" ; \
	fi
clean:
	rm -f foo$(EXEEXT) $(LIBNAME)$(DLLEXT)
