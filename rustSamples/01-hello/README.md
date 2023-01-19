# How to build

## Brief

This is a build templates for rust-lang based proejcts

## Build the binary

```shell
make
```

## how to run

```shell
make runit
```

## example of build and run

```shell
$ make clean
rm -f hello
01-hello$ make
rustc hello.rs -o output/hello
01-hello$ make runit
file ./output/hello
./output/hello: ELF 64-bit LSB shared object, x86-64, ... , for GNU/Linux 3.2.0, with debug_info, not stripped
./output/hello
Hello Rustc!
cp ./output/hello ./output/hello_stripped
strip ./output/hello_stripped
file ./output/hello_stripped
./output/hello_stripped: ELF 64-bit LSB shared object, x86-64, ... , for GNU/Linux 3.2.0, stripped
./output/hello_stripped
Hello Rustc!
```
