#!/bin/bash

for file in test_*.c
do
	gcc -L ../release/ -o $file.run $file -lgord
	LD_LIBRARY_PATH=../release:$LB_LIBRARY_PATH ./$file.run
	rm $file.run
done
