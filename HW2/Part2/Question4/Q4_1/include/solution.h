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
class Offset{
    public:
        T di;
        T dj;
    public:
        Offset(const T &di=0, const T &dj=0):di(di), dj(dj){}
};

enum directions {
    N,
    NE,
    E,
    SE,
    S,
    SW,
    W,
    NW
};

template <class T>
class Node{
    public:
        T x;
        T y;
        T dir;
        static std::unordered_map<T, std::string> dir_map;
    public:
        Node(const T x=0, const T y=0, const T dir=0):x(x), y(y), dir(dir){}

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
            os<<"("<<out_node.x<<", "<<out_node.y<<", "<<dir_map[out_node.dir]<<")";
            return os;
        }
};

template <class T>
std::unordered_map<T, std::string> Node<T>::dir_map = {
                {N,  "N"},
                {NE, "NE"},
                {E,  "E"},
                {SE, "SE"},
                {S,  "S"},
                {SW, "SW"},
                {W,  "W"},
                {NW, "NW"},
};

void Path(const std::vector<std::vector<bool>> &maze, const int &m, const int &p);
void AugmentedMazeBuildWall(const std::vector<std::vector<bool>> &tmp_maze, std::vector<std::vector<bool>> &maze, const int &rows, const int &cols, int &m, int &p);
void ReadFile(std::string filename, std::vector<std::vector<bool>> &maze, int &rows, int &cols);
void PrintMatrix(const std::string &name, const std::vector<std::vector<bool>> &matrix, const int &rows, const int &cols);

#include <solution.hpp>
#endif
