#
# This makefile is reference from http://clang.llvm.org/get_started.html
# It is used to test from the page of "get stated"
################################################################################

all: prepocessing typechecking gccoptions print_from_ast code_gen_with_llvm

prepocessing: t.c
	clang -E $^

typechecking: t.c
	clang -fsyntax-only $^

gccoptions: t.c
	clang -fsyntax-only $^ -pedantic

print_from_ast: t.c 
	clang -cc1 $^ -ast-print

code_gen_with_llvm: t.c
	clang $^ -S -emit-llvm -o -
	clang -fomit-frame-pointer -O3 -S -o - t.c # On x86_64

clean:
