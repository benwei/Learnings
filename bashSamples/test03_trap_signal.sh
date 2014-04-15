#!/bin/sh
trap -l
# trap -p EXIT
## echo command, while EXIT sigal
# trap "echo exit signal received" EXIT
echo "PID=$$"
running=1
signal_handler ()
{
    echo "got signal -- graceful shutdown"
    running=0
}

trap signal_handler 2 15

signal_reload()
{
    echo "got signal SIGHUB"
}

trap signal_reload 1


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

