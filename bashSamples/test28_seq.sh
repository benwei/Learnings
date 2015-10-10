#!/bin/bash
echo 'seq positive int'
seq 1 3 10
echo 'seq positive int and padding zero'
seq -w 1 3 10
echo 'seq negative int'
seq 12 -3 1
echo 'seq positive float'
seq 4 0.4 5
echo 'seq negative float'
seq -w 5 -0.4 4
