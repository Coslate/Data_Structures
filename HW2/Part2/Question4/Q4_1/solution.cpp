//solution.cpp
#include<solution.h>
#include<fstream>
#include<sstream>

void Path(const std::vector<std::vector<bool>> &maze, const int &m, const int &p){

}

void AugmentedMazeBuildWall(const std::vector<std::vector<bool>> &tmp_maze, std::vector<std::vector<bool>> &maze, const int &rows, const int &cols, int &m, int &p){
    for(int i=0;i<rows+2;++i){
        std::vector<bool> row_maze;
        if(i==0 || i==rows+1){
            for(int j=0;j<cols+2;++j){
                row_maze.push_back(1);
            }
        }else{
            for(int j=0;j<cols+2;++j){
                if(j==0 || j==cols+1){
                    row_maze.push_back(1);
                }else{
                    row_maze.push_back(tmp_maze[i-1][j-1]);
                }
            }
        }
        maze.push_back(row_maze);
    }
    m = rows+2;
    p = cols+2;
}

void ReadFile(std::string filename, std::vector<std::vector<bool>> &maze, int &rows, int &cols){
    std::string line;
    std::ifstream myfile (filename);

    if (myfile.is_open()){
        int count = 0;
        while ( std::getline (myfile,line) ){
            std::vector<bool> row_maze;
            std::istringstream iss(line); 
            std::string s;

            if(count == 0){
                iss>>s;
                rows = std::stoi(s);
                iss>>s;
                cols = std::stoi(s);
                ++count;
                continue;
            }

            for(;iss >> s;){
                row_maze.push_back(bool(std::stoi(s)));
            }
            maze.push_back(row_maze);
        }
        myfile.close();
    }else std::cout << "Unable to open file"; 
}
