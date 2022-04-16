//main.cpp
#include <iostream>
#include <Stack.h>
#include <solution.h>

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

    AugmentedMazeBuildWall(tmp_maze, maze, rows, cols, m, p);

    /*
    std::cout<<"input_maze = "<<input_maze<<std::endl;
    std::cout<<"rows = "<<rows<<std::endl;
    std::cout<<"cols = "<<cols<<std::endl;
    std::cout<<"m    = "<<m<<std::endl;
    std::cout<<"p    = "<<p<<std::endl;
    std::cout<<"tmp_maze = "<<std::endl;
    for(int i = 0; i < rows; ++i){
        for(int j = 0; j < cols; ++j){
            std::cout<<tmp_maze[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
    std::cout<<std::endl;
    */
    std::cout<<"maze = "<<std::endl;
    for(int i = 0; i < rows+2; ++i){
        for(int j = 0; j < cols+2; ++j){
            std::cout<<maze[i][j]<<" ";
        }
        std::cout<<std::endl;
    }

    Path(maze, m, p);

    return EXIT_SUCCESS;
}
