#!/bin/bash - 
#===============================================================================
#
#          FILE: test10_bc_as_calc.sh
# 
#         USAGE: ./test10_bc_as_calc.sh 
# 
#   DESCRIPTION: use bc as calculator
# 
#       OPTIONS: 'expression' <scale>
#  REQUIREMENTS: bc
#          BUGS: ---
#         NOTES: ---
#        AUTHOR: Ben Wei (ben6) 
#  ORGANIZATION: 
#       CREATED: 05/07/2014 00:18
#      REVISION:  2
#===============================================================================
scale=$2
if [ -z "$scale" ]; then
    scale=8
fi
exp="$1"
if [ ! -n "$exp" ]; then
    exp='(3^3+6.34*1.5)/23'
    cat <<- EOF
syntax: expression
ex:$exp
EOF
fi

bc <<< "scale=$scale;$exp"
exit $?
