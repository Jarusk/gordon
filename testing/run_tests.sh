#!/bin/bash

gcc -L ../release/ -Wall -o test1 test1.c -lgord
LD_LIBRARY_PATH=../release:$LB_LIBRARY_PATH ./test1.run
