#!/bin/sh

function get_a_string_back () {
    eval "$1='string return from function'"
}

ref_str="origin string"
get_a_string_back ref_str
echo $ref_str

function io_get_string () {
    echo "pass a string back"
}

out_str=`eval "io_get_string"`
echo "from stdout: $out_str"

# function keyword can ignore
function min() {
a=$1 ; b=$2
if [ $a -lt $b ]; then
        return $a
    fi
    return $b 
}

m=6; n=3
min $m $n
result=$?
echo $result

