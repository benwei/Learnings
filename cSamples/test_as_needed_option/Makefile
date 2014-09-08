CFLAGS=-O2 -Wall -I. -std=c99
LDFLAGS=-lm

ifeq ($(AS_NEEDED),1)
LDFLAGS+=  --as-needed
endif

include ../Makefile.bins


listlinks:
	ldd ./hello
