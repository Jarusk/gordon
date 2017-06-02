#!/bin/bash

SEP="----------------------------------------"


for file in test_*.c
do
	gcc -g -L ../release/ -Wall -o $file.run $file -lgord
done

echo -e "\n\n"

for file in test_*.c.run
do
	echo $SEP
	echo -e "Running test: $file \n"
	LD_LIBRARY_PATH=../release:$LB_LIBRARY_PATH ./$file
	rm $file
	echo -e "$SEP\n"
done
