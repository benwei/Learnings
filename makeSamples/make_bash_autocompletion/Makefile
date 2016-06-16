.PHONY: target1 target2.x help

CFILES=hello_target.c
OBJS=$(CFILES:.c=.o)
TARGETS=target1 target2
all: $(TARGETS)	

HELP_MSG="\
1.make sure the following package installed\n\
\n\
\tsudo apt-get install bash-completion\n\
2.issue 'make' command with <tab><tab> to list targets\n\
\n\
make_bash_autocompletion$$ make\n\
all        clean      help       target1    target2.x\n\
make_bash_autocompletion$$ make"

help:
	@echo $(HELP_MSG)
	
target1: $(CFILES)
	$(CC) -o $@ -DTARGET=\"$@\" $^
target2.x: $(CFILES)
	$(CC) -o $@ -DTARGET=\"$@\" $^

.hiddentarget: 
	$(CC) -o $@ -DTARGET=\"$@\" $^

clean:
	@find | grep -v "\.[c|h]$$" | grep target | (while read fn ; do echo "cleaning $$fn"; rm -f $$fn ; done)
