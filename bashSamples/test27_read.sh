#!/bin/bash
# tested following bash
# * GNU bash, version 3.2.57(1)-release (x86_64-apple-darwin14)
# * GNU bash, version 4.3.8(1)-release (x86_64-pc-linux-gnu)
read a b c < <(echo 1 2 3)
echo $a $b $c
read a b c < <(echo 4-5-6|tr -s '-' ' ')
echo $a $b $c
IFS="-" read a b c < <(echo 7-8-9)
echo $a $b $c
