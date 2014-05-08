#!/bin/bash

set -x
function afunction_return_string() {
    eval "$1='string from a function'"
}

return_str=''
afunction_return_string return_str
echo $return_str
