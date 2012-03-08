#!/bin/sh

a='yourkey=yourvalue'

key=`echo "${a%%=*}"`

value=`echo "${a##*=}"`

echo "data for test: $a"
echo "key=$key"
echo "value=$value"
