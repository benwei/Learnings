
define TEST
$(eval INNERVAR := $(1))
echo Using EVAL: INNERVAR = $(INNERVAR)
endef

# debug macro define for gnu make
debug-enter = $(if $(debug_trace),\
                 $(warning Entering $0($(echo-args))))
debug-leave = $(if $(debug_trace),$(warning Leaving $0))

debug_trace=1
define testvargs 
$(debug-enter)
echo "$(0)($(1),$(2),$(3),$(4)) $($)"
$(debug-leave)
endef

define build-vars
$(eval files := $(wildcard *.c))
$(eval exes := $(files:.c=.exe))
$(eval objs := $(files:.c=.o))
endef

define dump-vars
echo $(files)
echo $(exes)
echo $(objs)
endef

all:
# check variable state 
	@echo $(flavor INNERVAR)
# call for variable api definition
ifeq ($(flavor INNERVAR),undefined)
	$(call TEST, TestA)
endif
	@echo INNERVAR is defined with \'$(INNERVAR)\'
	@echo "call define(testvargs)"
	# call for arguments
	if [ ! -f hello1.c ]; then \
	   cp hello.c hello1.c; \
	fi
	$(build-vars)
	@$(call testvargs,1,2,3,4)
	$(dump-vars)
	make -s mk-test exes="$(exes)" objs="$(objs)"


define build-objs
	echo "building[$<]->[$@]"
	$(CC) -DINDEX=$(index) -c $< -o $@  
endef
index=1

define incindex
	$(eval index:=$(shell expr $(index) + 1)) 
endef

.c.o:
	@echo "index=$(index)"
	$(build-objs)
	$(incindex)

define build-exes
	dst="$@";obj="$${dst%.exe}.o";\
	echo "building[$${obj}]->[$@]";\
	gcc -o $@ $${obj}
endef

mk-test: $(exes)

run:
	$(build-vars)	
	for i in $(exes); do \
	 echo $$i ; \
	 ./$$i ;  \
	done

$(exes): $(objs)
	$(call build-exes,$@)

clean:
	$(build-vars)
	rm -f *.o $(exes)
