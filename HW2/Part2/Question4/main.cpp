//main.cpp
#include <iostream>
#include <Stack.h>
#include <solution.h>
#include <cstring>

std::vector<std::vector<bool>> tmp_maze;
std::vector<std::vector<bool>> maze;
int rows=0;
int cols=0;
int m = 0, p = 0;
std::string input_maze = "NO-INPUT";

int main(int argc, char*argv[]){
    if(argc < 3){
        std::cerr<<"Error: There should be at least one input argument like ./main -input_maze arg1."<<std::endl;
        return EXIT_FAILURE;
    }

    if( (argc > 1) && (strcmp(argv[1], "-input_maze") == 0)){
        input_maze = argv[2];
    }

    ReadFile(input_maze, tmp_maze, rows, cols);

    std::cout<<"> Initialization..."<<std::endl;
    AugmentedMazeBuildWall(tmp_maze, maze, rows, cols, m, p);
    PrintMatrix("maze", maze, rows+2, cols+2);

    std::cout<<"> Path..."<<std::endl;
    Path(maze, m, p);

    return EXIT_SUCCESS;
}
