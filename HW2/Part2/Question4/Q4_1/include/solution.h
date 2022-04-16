#ifndef _SOLUTION_H_
#define _SOLUTION_H_

#include <vector>
#include <string>
#include <cfloat>
#include <climits>
#include <math.h>
#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <Stack.h>

template <class T>
class Node{
    private:
        int x;
        int y;
        int dir;
    public:
        Node(const int x=0, const int y=0, const int dir=0):x(x), y(y), dir(dir){}

        //Copy consturctor
        Node(const Node &p){
            x   = p.x;
            y   = p.y;
            dir = p.dir;
        }

        //Destructor
        ~Node(){}

        //static bool SortFunction(const Term<CoefType, ExpType> &a, const Term<CoefType, ExpType> &b);
        void operator=(const Node &out_node);

        friend std::ostream & operator<<(std::ostream &os, const Node<T> &out_node){
            os<<"("<<out_node.x<<", "<<out_node.y<<", "<<out_node.dir<<")"<<std::endl;
            return os;
        }

        friend class Stack<T>;
};

void Path(const std::vector<std::vector<bool>> &maze, const int &m, const int &p);
void AugmentedMazeBuildWall(const std::vector<std::vector<bool>> &tmp_maze, std::vector<std::vector<bool>> &maze, const int &rows, const int &cols, int &m, int &p);
void ReadFile(std::string filename, std::vector<std::vector<bool>> &maze, int &rows, int &cols);

#include <solution.hpp>
#endif
