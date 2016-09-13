CFILES=main.c 
OBJS=$(CFILES:.c=.o)

CFLAGS=-g -Wall -std=c99 -pedantic 
LDFLAGS=

TARGET= c-sample-base
OBJCOPY=objcopy
STRIP=strip
BIN_STRIPPED=$(TARGET).stripped
SYM_FILE    =$(TARGET).symbols
CLEAN_FILES = $(BIN_STRIPPED) $(SYM_FILE)

all: $(TARGET) $(SYM_FILE) $(BIN_STRIPPED) gdb-help

include ../rules.mk

$(SYM_FILE): $(TARGET)
	$(OBJCOPY) --only-keep-debug $(TARGET) $@

$(BIN_STRIPPED): $(TARGET)
	cp -f $(TARGET) $@
	$(STRIP) $@

gdb-help:
	@echo "=======================================\ngdb\n(gdb) exec-file $(BIN_STRIPPED)\n(gdb) symbol-file $(SYM_FILE)"

