PLATFORM=$(shell uname -s)
CFLAGS=-O2 -Wall -I. -std=c99
CFLAGS+= -D_BSD_SOURCE  # usleep()

ifneq ($(PLATFORM),Darwin)
# clock_gettime
LDFLAGS=-lrt
endif

include ../Makefile.bins

