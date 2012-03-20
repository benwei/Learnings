# run autoscan to create configure.scan, change configure.ac
# autoreconf -if   ==> configure.ac -> configure
bin_PROGRAMS = hello
hello_SOURCES = hello.c
hello_LDADD = libhellolib.la

lib_LTLIBRARIES = libhellolib.la
libhellolib_la_SOURCES = hellolib.c
include_HEADERS = hellolib.h

# check hello with return code (0)
TESTS=$(bin_PROGRAMS)


