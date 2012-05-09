#!/bin/sh

# show failed with EXIT trapped
trap "echo fialed" EXIT

cnt=0
max=2
while [ $cnt -lt $max ]; do
echo "$cnt"
sleep 1
cnt=$((cnt + 1))
done

# disable EXIT trap
trap - EXIT

