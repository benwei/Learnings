#!/bin/sh
pkgname=CUnit-2.1-2
tarball=${pkgname}-src.tar.bz2


download_cuint_tarball()
{
    if [ -f $tarball ]; then
        return 0;
    fi

    wget -O "$tarball" 'http://downloads.sourceforge.net/project/cunit/CUnit/2.1-2/CUnit-2.1-2-src.tar.bz2'
    if [ $? -ne 0 ]; then
        rm -f "$tarball"
        return 1;
    fi
}

extract_tarball()
{
    if [ ! -d "$pkgname" ]; then
        tar jxvf ${pkgname}-src.tar.bz2 ;
    fi
}

build_pkg ()
{
    cd $pkgname
    ./configure
    ret=$?
    if [ $ret -ne 0 ]; then
        return $ret
    fi
    make
    return $?
}

SHARED_ROOT="$HOME/shared" 
if [ ! -d "$SHARED_ROOT" ]; then
mkdir -p "$SHARED_ROOT"
fi
cd "$SHARED_ROOT"
download_cuint_tarball
extract_tarball
build_pkg
exit $?
