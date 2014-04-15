#!/bin/sh

echo "Method 1: use if false"
if false ; then
    Comments here,
    never run this parts, but bad part "if false" always run 
fi

echo "Method 2: use << MYCOMMENT (prefered)"

<< MYCOMMENT
Comments using stdin style,
I like comments in this way
MYCOMMENT

echo "Method 3: use insert multi lines # by editor: vi command mode: 4,10s/^/#/g\n\t(prefered+)"

method4 () {
    echo "Method 4: using : || {}"
    : || {
      comments 
      but not support on /bin/sh
    }
}

echo "Method 5: using : || ''"
: '
this is a string
second line
'
