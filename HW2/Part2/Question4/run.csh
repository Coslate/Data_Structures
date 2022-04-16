#! /bin/csh -f

make clean
make


#run formal released case
./main -input_maze ./maze.txt
