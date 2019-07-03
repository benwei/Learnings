
# * tested on osx 10.14.5 with android studio 3.4.1
#   gcc
#     MacOSX10.14.sdk/usr/include/c++/4.2.1
#     Apple LLVM version 10.0.1 (clang-1001.0.46.4)
NDK=/opt/android-ndk-r10e
target ?= x86

ifeq ($(target),arm)
NDK_TOOLCHAIN=/opt/android-ndk-r10e/toolchains/arm-linux-androideabi-4.8/prebuilt/$(PREBUILT_ARCH)/bin/arm-linux-androideabi-
else
NDK_TOOLCHAIN=/opt/android-ndk-r10e/toolchains/x86-4.8/prebuilt/$(PREBUILT_ARCH)/bin/i686-linux-android-
endif

NDK_SYSROOT=/opt/android-ndk-r10e/platforms/android-14/arch-$(target)
CROSS_COMPILE=${NDK_TOOLCHAIN}
EXTNAME=.so
LIBNAME=hellolib

ifeq ($(shell uname -s),Linux)
PREBUILT_ARCH=linux-x86_64
else
PREBUILT_ARCH=darwin-x86_64
LIBLDFLAGS=-shared -Wl,-soname,$(LIBNAME)
ifeq ($(target),arm)
SYSROOT=--sysroot=${NDK_SYSROOT}
else
CROSS_COMPILE=
EXTNAME=.jnilib
LIBLDFLAGS=-dynamiclib -framework JavaVM

incdir = "/Applications/Android Studio.app//Contents/jre/jdk/Contents/Home/include"
CFLAGS+=-I$(incdir) -I$(incdir)/darwin
JDK_DIR="/Applications/Android Studio.app//Contents/jre/jdk/Contents/Home/bin"
JAVAC=$(JDK_DIR)/javac
JAVA=$(JDK_DIR)/java
endif # target arch
endif

CFLAGS+=$(SYSROOT)

LDFLAGS +=$(SYSROOT)

CC = $(CROSS_COMPILE)gcc
AR = $(CROSS_COMPILE)ar
LD = $(CROSS_COMPILE)ld

RANLIB = $(CROSS_COMPILE)ranlib

CFILES = HelloJNI.c
OBJS  = $(CFILES:.c=.o)
HELLOLIB = lib$(LIBNAME)$(EXTNAME)

JAVACLS=org/juluos/sample/HelloJNI.class mytest.class

all: $(HELLOLIB) $(JAVACLS)

.c.o:
	$(CC) -c $(CFLAGS) -fPIC -o $@ $<

$(HELLOLIB): $(OBJS)
	$(CC) $(LDFLAGS) $(OBJS) $(LIBLDFLAGS) -o $@

clean:
	rm -f *.o $(HELLOLIB)

$(JAVACLS): %.class: %.java
	$(JAVAC) $<

run: $(JAVACLS)
	@export LD_LIBRARY_PATH=. ; \
	$(JAVA) mytest

