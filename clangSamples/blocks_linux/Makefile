prefix?=.
BLOCKS_RT_DIR=$(prefix)/BlocksRuntime/
BLOCKS_RT= -I$(BLOCKS_RT_DIR) -L$(BLOCKS_RT_DIR) -lBlocksRuntime

all: prebuild demoblocks

prebuild:
	cd $(BLOCKS_RT_DIR); cmake CMakeLists.txt
	make -C $(BLOCKS_RT_DIR)

demoblocks: main.m
	clang $(BLOCKS_RT) -fblocks $^ -o demoblocks

run: demoblocks
	export LD_LIBRARY_PATH=$(BLOCKS_RT_DIR) ; \
	./demoblocks

clean:
	rm -f ./demoblocks
