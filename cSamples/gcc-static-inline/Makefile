CFILES = hello.c helloO2.c
# the -save-temps option is used to inform gcc
# to generate more information during preprocessing and comipling period
# .i  the source code after preprocessor procceed
# .s  the assembly code gcc created
# both information is useful while you want to know what's the machine code from C functions.
# You can clear know what the preprocessor and optimazation does by comparing .s generate
# from code appending flags -O2 or without -O option.
# you can leverage the information to reverse the binary file to assembly and then assembly to c files.
# added
# normal, static , and static inline

CFLAGS = -save-temps
CC =gcc

all: prebuild hello helloO2 postbuild

prebuild:
	cp -f hello.c helloO2.c

hello: % : %.c
	$(CC) -o $@ $^ $(CFLAGS)  

helloO2: % : %.c
	$(CC) -o $@ $^ $(CFLAGS) -O2

postbuild:
	diff hello.s helloO2.s || exit 0

clean:
	rm -f hello *.i *.s *.o helloO2.c helloO2
