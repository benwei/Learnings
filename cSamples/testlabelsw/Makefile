include ../Makefile.defines

ifeq ($(CROSS),1)
ifeq ($(PLATFORM),Darwin)
	CROSS_COMPILE=/usr/local/gcc-4.5.2-for-linux64/bin/x86_64-pc-linux-
	CC=$(CROSS_COMPILE)gcc
	AS=$(CROSS_COMPILE)as
	LD=$(CROSS_COMPILE)ld
	ifeq ($(DUMP_AD),1)
	CFLAGS = -Wa,-a,-ad
	endif
endif
endif

ifeq ($(DEBUG),1)
CFLAGS+=-g
endif

ifeq ($(NO_O2),1)
CFLAGS += --save-temps 
else
CFLAGS += -O2 --save-temps
endif

all: testla testsw

.c.o:
	$(CC) -c $< -I. $(CFLAGS) 

testla: %:%.o main.o 
	$(CC) -o $@ $^ 

testsw: %:%.o main.o
	$(CC) -o $@ $^ 

unit: testla testsw
	@./testsw -vs ; \
	ret_sw=$$? ; \
	./testla -vs ; \
	ret_la=$$? ; \
	if [ $$ret_la -eq $$ret_sw ]; then \
	echo "result equal"; \
	else \
	echo "reqult is'nt equal"; \
	exit 1 ; \
	fi
	

run: testla testsw
	time ./testla 
	@echo
	time ./testsw 

clean:
	rm -f *.o testla testsw *.i *.s 
