GOCC=6g
GOLD=6l

PROJECT=webserver

all: $(PROJECT)

$(PROJECT).6: $(PROJECT).go
	$(GOCC) $(CFLAGS) $^

$(PROJECT): $(PROJECT).6
	$(GOLD) -o $@ $^ 

run: $(PROJECT)
	./$^

clean:
	rm -f $(PROJECT).6 $(PROJECT)
