#!/bin/bash
# == Sample code from ben wei 2011, please reserved this line ==

# APSequence() is used for Arithmetic progression
# Output: display each term and sum.
# formula:
#   a_n = a_m + (n - m)*d

APSequence()
{
	arithmeticFirst=$1
       	difference=$2
	numOfTerm=$(($3 + 1))
	temp=$arithmeticFirst
	sum=0
	i=1
	while [ $i -lt $numOfTerm ]; do
		echo "a$i=$((temp))"
		sum=$((sum + temp))
		temp=$((temp + difference))
		i=$((i + 1))
	done
	echo "Sum = $sum"
}

APSequence 3 2 5
