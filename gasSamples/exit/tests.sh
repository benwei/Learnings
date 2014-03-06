#!/bin/bash

input_arg=(0 arg1)
expect_of_target=(0 2)
targets=($1)
for i in 0 1 ; do \
    exe=${targets[$i]}
    arg=${input_arg[$i]}
    ret=${expect_of_target[$i]}
	./$exe $arg
	if [ $? -ne $ret ]; then 
		echo "testing failure: export exit status code is $ret" 
		exit 1
    else
        echo "$exe [passed]"
	fi
done
exit 0
