#!/bin/bash - 
#===============================================================================
#
#          FILE: test.sh
# 
#         USAGE: ./test.sh 
# 
#   DESCRIPTION: 
# 
#       OPTIONS: ---
#  REQUIREMENTS: ---
#          BUGS: ---
#         NOTES: this is used bash-support to create init the file
#        AUTHOR: Ben Wei (ben@staros.mobi), 
#  ORGdNIZATION: 
#       CREATED: 04/18/2014 01:58
#      REVISION:  0.01
#===============================================================================

case $1 in
a)
echo -e "test\n"
;;

b)
printf "%s\n" "hello"
;;

*)
echo "syntax"
;;

esac    # --- end of case ---

