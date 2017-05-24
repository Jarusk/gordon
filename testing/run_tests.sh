#!/bin/bash

gcc -L ../release/ -Wall -o test_gord.run test_gord.c -lgord
LD_LIBRARY_PATH=../release:$LB_LIBRARY_PATH ./test_gord.run

gcc -L ../release/ -Wall -o test_bool.run test_bool.c -lgord
LD_LIBRARY_PATH=../release:$LB_LIBRARY_PATH ./test_bool.run
