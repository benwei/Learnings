# Design Patterns

## Singleton

tested c++11

* macos 10.14.6
  * Apple clang version 11.0.0 (clang-1100.0.33.17)
  * Target: x86_64-apple-darwin18.7.0
* ubuntu 18.04
  * g++ (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0

```
testzoo.cpp
```

## example output

```
~ $ make run
./testzoo 
Animal()::Animal() set name as default
Singleton::instance 0
Singleton::instance 0
Zoo()::Zoo() set name as default
Singleton::instance 1
Singleton::instance 1
Singleton::instance 0
Animal()::setName() <= It is an abnormal dog.
Animal()::setName() set name as It is an abnormal dog.
Zoo()::setName() <= It is a the one
Zoo()::setName() set name as It is a the one
[0]Animal()::show() name is It is an abnormal dog.
[1]Zoo()::show() name is It is a the one
[0]Animal()::show() name is It is an abnormal dog.
[0]Animal()::show() name is It is an abnormal dog.
[1] ~Zoo()
[0] ~Animal()
```

## check memory leak with valgrind is ok

```
ci$ make run URUN=valgrind >> README.md
==6671== Memcheck, a memory error detector
==6671== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==6671== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==6671== Command: ./testzoo
==6671==
==6671==
==6671== HEAP SUMMARY:
==6671==     in use at exit: 0 bytes in 0 blocks
==6671==   total heap usage: 5 allocs, 5 frees, 76,895 bytes allocated
==6671==
==6671== All heap blocks were freed -- no leaks are possible
==6671==
==6671== For counts of detected and suppressed errors, rerun with: -v
==6671== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
