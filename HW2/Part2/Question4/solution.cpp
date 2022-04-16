//solution.cpp
#include<solution.h>
#include<fstream>
#include<sstream>

void Path(const std::vector<std::vector<bool>> &maze, const int &m, const int &p){
    std::vector<std::vector<bool>> mark(m, std::vector<bool> (p, 0));
    Offset<int> move[8];
    move[0].di = -1; //N
    move[0].dj =  0;
    move[1].di = -1; //NE
    move[1].dj =  1;
    move[2].di =  0; //E
    move[2].dj =  1;
    move[3].di =  1; //SE
    move[3].dj =  1;
    move[4].di =  1; //S
    move[4].dj =  0;
    move[5].di =  1; //SW
    move[5].dj = -1;
    move[6].di =  0; //W
    move[6].dj = -1;
    move[7].di = -1; //NW
    move[7].dj = -1;

    //Start from maze[1][1];
    mark[1][1] = 1;
    Stack<Node<int>> stack_traverse(m*p, "stack");

    //Initialized point
    Node<int> temp(1, 1, E);
    stack_traverse.Push(temp);
    std::cout<<"stack 'push' occurs, push item: "<<temp<<", "<<stack_traverse;

    while(!stack_traverse.IsEmpty()){
        temp = stack_traverse.Top();
        stack_traverse.Pop();
        std::cout<<"stack 'pop' occurs, "<<stack_traverse;
        int i = temp.x;
        int j = temp.y;
        int d = temp.dir;

        while(d<8){
            int g = i+move[d].di;
            int h = j+move[d].dj;

            if(g==m && h==p){
                temp.x = i;
                temp.y = j;
                temp.dir = d;
                stack_traverse.Push(temp);
                std::cout<<"stack 'push' occurs, push item: "<<temp<<", "<<stack_traverse;
                std::cout<<std::endl;
                std::cout<<"Find a path : "<<std::endl;
                stack_traverse.PrintPath(m, p);
                std::cout<<std::endl;
                return;
            }

            if(!maze[g][h] && !mark[g][h]){
                mark[g][h] = true;
                temp.x = i;
                temp.y = j;
                temp.dir = d;
                stack_traverse.Push(temp);
                std::cout<<"stack 'push' occurs, push item: "<<temp<<", "<<stack_traverse;
                i = g;
                j = h;
                d = N;
            }else{
                d++;
            }
        }
    }
    std::cout<<"No path in maze."<<std::endl;
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
    m = rows;
    p = cols;
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

void PrintMatrix(const std::string &name, const std::vector<std::vector<bool>> &matrix, const int &rows, const int &cols){
    std::cout<<name<<" = "<<std::endl;
    for(int i = 0; i < rows; ++i){
        for(int j = 0; j < cols; ++j){
            std::cout<<matrix[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
    std::cout<<std::endl;
}
