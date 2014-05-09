#!/bin/bash
# reference: http://stackoverflow.com/questions/85880/determine-if-a-function-exists-in-bash
function a()
{
    echo "a function defined";
    return;
}

#main
declare -f -F a > /dev/null
echo "check a : $?"
declare -f -F b
echo "check b : $?"
