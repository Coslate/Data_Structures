#! /bin/csh -f

make clean
make


#run formal released case
./main

#You can revise Makefile to choose main.execution_trace1.o or main.execution_trace2.o for different input test pattterns to test the functions.
