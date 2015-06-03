#!/usr/bin/env bash

trap "__EXCEPTION_TYPE__=\"\$_\" command_not_found_handle \$BASH_COMMAND" ERR
#set -o errtrace  # trace ERR through 'time command' and other functions

command_not_found_handle()
{
    echo "not found funcname: $1 args: $2"
}

ERR()
{
    echo "error $@"
}

function string_result() {
    eval "$1=\"$2\""
}

int_ret=0
string_ret=""

# tested dict with GNU bash, version 4.3.8(1)-release (x86_64-pc-linux-gnu)
declare -A class_vars
A() {
    a="$1"
    echo create function
    # method variable
    # eval "${a}.getVar() { string_result "$" "${class_vars[\"$1\"]}"; }"
    # method show
    # eval "${a}.a=10"
    eval function "${a}.show" \{ "echo ${a}.show\(\) executed." \; \}
    eval shift 2 \; function "${a}.setVar" \{ "echo ${a}.setVar"'\($1 $2\)' \; 'class_vars['$a'$1]=$2' \; \}
    eval shift 2 \; function "${a}.getVarInt" \{ "echo getVarInt "'$1' \; "int_ret="'${class_vars['$a'$1]}' \; \}
    eval shift 2 \; function "${a}.getVarString" \{ "echo getVarString "'$1' \; "string_ret="'${class_vars['$a'$1]}' \; \}
}

A 't'
t.show
t.setVar "a" 10
t.setVar "s" "123456"

A 't1'
t1.setVar "a" 20
t1.setVar "s" "7890123"
t1.getVarInt "a"
echo $int_ret
t1.getVarString "s"
echo $string_ret

t.getVarInt "a"
echo $int_ret
t.getVarString "s"
echo $string_ret
