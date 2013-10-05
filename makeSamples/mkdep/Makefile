

VPATH += build/
INCS = -I.
files= hello.c 
objs = $(files:.c=.o)
exe  = hello
depends = $(objs:.o=.o.p) $(exe:=.p)

all: $(exe)

.c.o:
	@echo "building [$<]->[$@]"
	$(CC) -MMD -MF $@.p -c $< -o $@ $(INCS)

$(exe): $(objs)
	@echo "linking [$^]->[$@]"
	$(CC) -o $@ $^

run: $(exe)
	./$<

clean:
	rm -f *.o $(exe) $(depends)
	rm -rf build

-include $(depends)
