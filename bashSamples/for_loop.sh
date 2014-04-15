#!/bin/bash
# written by Ben Wei
# reference: http://stackoverflow.com/questions/3723818/bash-shell-script-for-100-iteration-and-log-time-taken

# compatible with /bin/sh
echo "for style 1: using number list"
for i in 1 2 3 ; do
    echo $i
done

echo "for style 2: using .."
for i in {1..5} ; do
    echo $i
done

# compatible with /bin/sh
echo "for style 3: with seq command"
for i in `seq 1 3` ; do
echo $i
done

echo "for style 4: c-like"
for ((i=0; i < 2; ++i)); do
    echo $i
done

echo "for style 5: using set"
set -- 1 2 3 4
for e; do
echo $e
done
