
# file exists check in header part 
ifneq ($(wildcard hello.o),)
OBJEXISTED=1
endif

# file exists check by shell
define fileexists
@if [ -f "$1" ]; then \
	echo "found $1 before build" ; \
fi
endef

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
	$(eval files:= hello.c $(tempfile)) 
	$(eval exes= $(files:.c=.exe))
endef

define dump-vars
	@echo "$(files) -> $(exes)";
endef

tempfile=build/hello-temp.c

all:

ifeq ($(OBJEXISTED),1)
	$(call fileexists,hello.o)
endif

# check variable state 
	@echo $(flavor INNERVAR)

# call for variable api definition
ifeq ($(flavor INNERVAR),undefined)
	$(call TEST, TestA)
endif
	@echo INNERVAR is defined with \'$(INNERVAR)\'
	@echo "call define(testvargs)"
	# call for arguments
	@$(call testvargs,1,2,3,4)
	@mkdir -p build 
	@if [ ! -f "$(tempfile)" ] ; then \
	   cp hello.c $(tempfile); \
	   echo "cp hello.c $(tempfile)" ; \
	fi 
	make -s mk-prebuild


.c.o:
	echo "building[$<]->[$@] with index($(index))"
	$(CC) -DINDEX=$(index) -c $< -o $@  

define build-exe
	dst="$(1)";obj="$${dst%.exe}.o";\
	echo "building[$${obj}]->[$@]";\
	gcc -o $(1) $${obj}
endef

mk-prebuild: 
	$(build-vars)
	$(dump-vars)
	make mk-build exes="$(exes)"

mk-build: 
	index=1 ; \
	for i in $(exes) ; do \
	   make exename=$$i objname=$${i%.exe}.o $$i index=$$index ; \
	   echo make $$i index=$$index ; \
           index=`expr $$index + 1` ; \
	done

hello.exe: hello.o
	$(call build-exe,$@,$<)

build/hello-temp.exe: build/hello-temp.o
	$(call build-exe,$@,$<)

build/hello.o:hello.c

run:
	$(build-vars)	
	for i in $(exes); do \
	 echo $$i ; \
	 ./$$i ;  \
	done


clean:
	$(build-vars)
	rm -f *.o $(exes) $(tempfile)
	rm -rf build
