#!/usr/bin/env bash
declare -x __oo__path="my/oo_syntax"

# /bin/sh got error: `Name.test': not a valid identifier
Name.test()
{
    echo Name.test __oo__path = $__oo__path
}

Name.test
