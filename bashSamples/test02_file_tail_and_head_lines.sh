#!/bin/bash - 
#===============================================================================
#
#          FILE: file_operate.sh
# 
#         USAGE: ./file_operate.sh 
# 
#   DESCRIPTION: sample for file_operate
# 
#       OPTIONS: ---
#  REQUIREMENTS: ---
#          BUGS: ---
#         NOTES: ---
#        AUTHOR: Ben Wei 
#  ORGANIZATION: 
#       CREATED: 04/18/2014 02:40
#      REVISION:  ---
#===============================================================================

set -o nounset                              # Treat unset variables as an error

tail -n 3 $0 | head -n 1
# display with be "# last 3rd line"

# last 3rd line
# last 2nd line
# last 1st line
