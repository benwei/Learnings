#!/bin/sh

# set -x equal to sh -x ./test.sh
## argument x mean echo on for xtrace 
set -x
echo 1

## disable x trace
set +x
echo 2
## run xtrace only one line
(set -x ; echo only one line)

# update command line arguments
set -- myargv1 myargv2
echo argc is ${#@}
echo $1
echo $2
