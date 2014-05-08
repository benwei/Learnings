#!/bin/bash
# sample from http://stackoverflow.com/questions/6046176/bash-adding-a-name-value-to-a-structure-using-bash
# OSX 10.9.2 is not supported
declare -A a=(
        [LC1]="Test1 Test2"
        [LC2]="Test3 Test4"
        [LC3]="Test5 Test6"
        ) 

for k in "${!a[@]}"; do
    printf '%s\n' "$k"
    set -- ${a["$k"]} # by default split on white space, tab and newline
    # you can use another delimiter, if you wish
    for e; do
        printf '\t => %s\n' "$e"
    done
done 
