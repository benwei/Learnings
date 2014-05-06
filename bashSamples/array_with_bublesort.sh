#!/bin/bash
# written by Ben Wei 2014
# Reference algorithm from http://en.wikipedia.org/wiki/Bubble_sort
# The algorithm can be expressed as (0-based array):
# procedure bubbleSort( A : list of sortable items )
#   n = length(A)
#   repeat     
#     swapped = false
#     for i = 1 to  n-1 inclusive do
#       /* if this pair is out of order */
#       if A[i-1] > A[i] then
#         /* swap them and remember something changed */
#         swap( A[i-1], A[i] )
#         swapped = true
#       end if
#     end for
#   until not swapped
# end procedure
## 
# procedure bubbleSort( A : list of sortable items )
#   n = length(A)
#   repeat
#     newn = 0
#     for i = 1 to n-1 inclusive do
#       if A[i-1] > A[i] then
#         swap(A[i-1], A[i])
#         newn = i
#       end if
#     end for
#     n = newn
#   until n = 0
# end procedure 
#

debug_verbose=0
if [ "$1" = "-d" ]; then
debug_verbose=1
fi

bubble_sort_without_optimization() {
    i=1
    count=${#myarray[@]}
    i=$((count - 1))
    while [ $i -gt 0 ]; do
        j=0
        while [ $j -lt $i ]; do
            if [ ${myarray[$j]} -gt ${myarray[$i]} ] ; then
                tmp=${myarray[$i]}
                myarray[$i]=${myarray[$j]}
                myarray[$j]=$tmp
            fi

            j=$((j+1))
        done
        i=$((i-1))
    done
}


bubble_sort_optimization() {
    n=${#myarray[@]}
    until [ $n = 0 ]; do
        newn=0
        i=1
        while [ $i -lt $n ]; do
            prev_i=$((i-1))
            if [ ${myarray[$prev_i]} -gt ${myarray[$i]} ] ; then
                tmp=${myarray[$prev_i]}
                myarray[$prev_i]=${myarray[$i]}
                myarray[$i]=$tmp
                newn=$i
            fi
            i=$((i+1))
        done
        n=$newn
    done
}

dumparray ()
{
    echo "--- dump array ---"
    j=0
    while [ $j -lt ${#myarray[@]} ]; do
        echo ${myarray[$j]}
        j=$((j+1))
    done
}

# main
cmd="$1"
stress_count=3000
test_bublesort()
{
    time for ((m=0; m < stress_count; ++m)) ; do
    #        1 2 3 4 5 6 7 8 9 0 1 2 3 4 5
    myarray=(6 8 9 0 3 2 1 5 7 4 9 8 5 7 1)
    bubble_sort_without_optimization
    done
}


test_bublesort_optimatization()
{
    time for ((m=0; m < stress_count; ++m)) ; do
    myarray=(6 8 9 0 3 2 1 5 7 4 9 8 5 7 1)
    bubble_sort_optimization
    done
}


test_bublesort
test_bublesort_optimatization
