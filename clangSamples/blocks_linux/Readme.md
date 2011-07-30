# Introduction
  it is a sample for clang to work with blocks on linux (Ubuntu-10.10)

# download compiler 
  - svn checkout http://llvm.org/svn/llvm-project/compiler-rt/trunk compiler-rt
  - for compile the ./BlocksRuntime/libBlocksRuntime.so
    1. cd compiler-rt/BlocksRuntime/
    2. create ./BlocksRuntime/config.h 
	#define HAVE_SYNC_BOOL_COMPARE_AND_SWAP_INT 1
	#define HAVE_SYNC_BOOL_COMPARE_AND_SWAP_LONG 1
    3. make
  
# build and run this sample
  - make run prefix=<your-path-compiler-rt with BlocksRuntime dir>    
  (ps: my environment has mv the "BlocksRuntime/" to current directory.

# results

clang -I./BlocksRuntime/ -L./BlocksRuntime/ -lBlocksRuntime -fblocks main.m -o demoblocks
export LD_LIBRARY_PATH=./BlocksRuntime/ ; \
	./demoblocks
11
21
31
