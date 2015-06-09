

VPATH += build/
INCS = -I.
files= hello.c foo.c
objs = $(files:.c=.o)
exe  = hello
depends = $(objs:.o=.o.p) $(exe:=.p)

.PHONY: run

all: $(exe) run

.c.o:
	@echo "building [$<]->[$@]"
	$(CC) -MMD -MF $(<:.c=.p) -c $< -o $@ $(INCS)

$(exe): $(objs)
	@echo "linking [$^]->[$@]"
	$(CC) -o $@ $^

run: $(exe)
	./$<

clean:
	rm -f *.o $(exe) $(depends)
	rm -rf build

-include $(depends)
