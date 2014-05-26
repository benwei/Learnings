#!/bin/bash - 
#===============================================================================
#
#          FILE: string_array.sh
# 
#         USAGE: ./string_array.sh 
# 
#   DESCRIPTION: testing element array in string type
# 
#       OPTIONS: ---
#  REQUIREMENTS: ---
#          BUGS: ---
#         NOTES: ---
#        AUTHOR: Ben Wei
#  ORGANIZATION: 
#       CREATED: 05/21/2014 12:48
#      REVISION:  ---
#===============================================================================
str_array=("aaa" "bbb" "ccc")

for ((m=0; m < ${#str_array[@]}; ++m)) ; do
echo "str$m=${str_array[$m]}"
done

