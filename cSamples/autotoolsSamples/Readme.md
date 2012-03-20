# This is a testing sample for autotools
# information from fourdollars.github.com/autotools/#slide13
# build
## create files for configure
autoreconf -if

## build files
mkdir build
cd build
../configure
make
## install to specific folder
make install prefix=$PWD/test

## uninstall from specific folder
make uninstall prefix=$PWD/test

# create deb package

## create tarball
 make dist

## rename hello-1.0.tar.gz
 mv hello-1.0.tar.gz hello_1.0_orig.tar.gz

## extract tarball
 tar zxvf hello_1.0.orig.tar.gz
 cd hello-1.0
 dh-make -f hello_1.0.orig.tar.gz 
 Type of package: single binary, indep binary, multiple binary, library, kernel module, kernel patch or cdbs?
 [s/i/m/l/k/n/b] s
- Note: type s for single binary

## create source package
 dpkg-buildpackage -S -us -uc
 hello_1.0-1.debian.tar.gz
 hello_1.0-1.dsc
 hello_1.0-1_i386.changes
 hello_1.0-1_source.changes
 hello_1.0.orig.tar.gz

## create binary package
 dpkg-buildpackage -us -uc
- got package
 hello_1.0-1_i386.deb

