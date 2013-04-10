ASCRIPT=ex.scpt
TARGETS=ex_exc ex_exc1

all: $(TARGETS) 

ex_exc: $(ASCRIPT)
	osacompile -o $@ $<

ex_exc1: $(ASCRIPT)
	@# man osacompile to get the following line, but the  will generate \
	   ex_exc1 with zero size 
	osacompile -r scpt:128 -t osas -c EXAM -o ex_exc1 $<

run: ex_exc
	osascript $^

clean:
	rm ex_exc*
