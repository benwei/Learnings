
DEMO1=demo-block
BINS=$(DEMO1)

all: $(BINS)

$(DEMO1): blocks.c
	$(CC) -o $@ $^

run: 
	./$(DEMO1)

clean:
	rm -f $(DEMO1)
