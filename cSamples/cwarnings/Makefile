CFILES=main.c
OBJS=$(CFILES:.c=.o)
TARGET=warnings
CFLAGS=-Wall -std=c99 -pedantic 

all: $(TARGET)

.c.o:
	$(CC) -c -o $@ $< $(CFLAGS)

$(TARGET): $(OBJS)
	$(CC) -o $@ $^

clean:
	rm *.o $(TARGET)
