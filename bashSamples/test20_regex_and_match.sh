#!/bin/bash
function regex_contain()
{
    word=$1
    keyword=$2
    if [[ "$word" =~ $keyword ]]; then
        msg="contains"
        ret=1
    else
        msg="does'nt contain"
        ret=0
    fi
    echo [regex way] \"$word\" $msg \"$keyword\" 
    return $ret
}

function match_left()
{
    word=$1
    keyword=$2
    if [[ "$word" == $keyword* ]]; then
        msg="contains"
        ret=1
    else
        msg="not matched"
        ret=0
    fi
    echo [equal leftpart] \"$word\" $msg \"$keyword\" 
    return $ret
}

#main

word=hello
keyword=ell

regex_contain hello ell
regex_contain hello mhel
match_left hello hel
match_left hello ell

