SUBDIRS=lib
CURRENTPATH=$(shell /bin/pwd)
INCLUDES=-I$(CURRENTPATH)/include -I$(CURRENTPATH)/lib
export INCLUDES

AUTOMAKE_OPTIONS= foreign

hello_SOURCES=hello.c config.h
hello_LDADD=$(top_srcdir)/lib/libfoo.a
hello_LDFLAGS=-D_GNU_SOURCE
DEFS+=-D_GNU_SOURCE
#LIBS=-lpthread

bin_PROGRAMS=hello
