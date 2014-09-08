# reference: http://sigquit.wordpress.com/2011/02/16/why-asneeded-doesnt-work-as-expected-for-your-libraries-on-your-autotools-project/
OBJS=hello.o
CFLAGS=-O2 -Wall -I. -std=c99 -fPIC -DPIC $(shell pkg-config --cflags glib-2.0)

LDFLAGS1= -shared $(shell pkg-config --libs glib-2.0 gthread-2.0 gio-2.0 gmodule-2.0)
LDFLAGS2= -shared -Wl,--as-needed $(shell pkg-config --libs glib-2.0 gthread-2.0 gio-2.0 gmodule-2.0)

all: run

.c.o:
	$(CC) -c $< -o $@ $(CFLAGS)

libhello1.so: $(OBJS)
	$(CC) -o $@ $^ $(LDFLAGS1)

libhello2.so: $(OBJS)
	$(CC) -o $@ $^ $(LDFLAGS2)

run: libhello1.so libhello2.so
	ldd -u -r libhello1.so || exit 0
	ldd -u -r libhello2.so || exit 0

clean:
	rm -f *.so *.o
