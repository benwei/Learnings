CFLAGS=-O2 -Wall -I. -std=c99
LDFLAGS=-lm

ifeq ($(AS_NEEDED),1)
LDFLAGS+= -Xlinker -Map -Xlinker output.map -Xlinker --as-needed

endif

include ../Makefile.bins


listlinks:
	ldd ./hello
