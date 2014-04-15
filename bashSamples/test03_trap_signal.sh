#!/bin/sh
trap -l
# trap -p EXIT
## echo command, while EXIT sigal
# trap "echo exit signal received" EXIT
running=1
signal_handler ()
{
    echo "got signal -- graceful shutdown"
    running=0
}

trap signal_handler 2 15

# The -l option
# causes the shell to print a list of signal names and their
# corresponding  numbers.

cnt=0
max=10
while [ $running -eq 1 -a $cnt -lt $max ]; do
echo "$cnt"
sleep 1
cnt=$((cnt + 1))
done

# disable EXIT trap
trap - EXIT

