#!/bin/env sh

## following syntax is tested in both of
## busybox sh 1.0.0 and gnu 4.2.37(1)-release (i486-pc-linux-gnu)

a="/dev/abc.log"  ; echo ${a##*/}
## result
# abc.log

a="dev/abc.log"  ; echo ${a%%/*}
## result
# dev

a="abc.log"  ; echo ${a%.log}
## result
# abc

a="abc.log"  ; echo ${a#abc}
## result
# .log


