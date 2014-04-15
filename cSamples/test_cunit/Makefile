CFILES = main.c
OBJS = $(CFILES:.c=.o)
TARGET = test_cunit

CUNIT_BASE_DIR = $(HOME)/shared/CUnit-2.1-2/CUnit

CFLAGS = -Wall -I$(CUNIT_BASE_DIR)/Headers

LIBCUINTA = $(CUNIT_BASE_DIR)/Sources/.libs/libcunit.a
LDFLAGS = $(LIBCUINTA)


all: $(LIBCUINTA) $(TARGET)

$(LIBCUINTA):
	sh cunit_setup.sh

include ../mk.rules
