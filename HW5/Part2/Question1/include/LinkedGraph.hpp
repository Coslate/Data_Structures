//LinkedGraph.hpp
#include <LinkedGraph.h>
#include <algorithm>
#include <unordered_map>
#include <stack>
#include <queue>
#include <cstdlib>
#include <cmath>
#include <sstream>

template <typename T>
T ConvertTo (const std::string &str){
    std::istringstream ss(str);
    T num;
    ss >> num;
    return num;
}

template <class T>
void LinkedGraph<T>::DFSRecursive(T v, std::unordered_map<T, bool> &visited, std::unordered_map<T, int> &t_to_index){
    std::cout<<v<<" ";
    visited[v] = true;
    //for all adjacent points
    for(typename Chain<T>::Iterator j = adj_list[t_to_index[v]].Begin(); j!=adj_list[t_to_index[v]].End(); j++){
        T adj_point_w = *j;
        if(!visited[adj_point_w]){
            DFSRecursive(adj_point_w, visited, t_to_index);
        }
    }
}

template <class T>
void LinkedGraph<T>::DFS(T v){
    std::unordered_map<T, bool> visited;
    std::unordered_map<T, int>  t_to_index;
    //Initialization visited arr
    for(int i=0;i<Graph<T>::n;++i){
        visited[ConvertTo<T>(std::to_string(i))] = false;
        t_to_index[ConvertTo<T>(std::to_string(i))] = i;
    }

    DFSRecursive(v, visited, t_to_index);
}

template <class T>
void LinkedGraph<T>::BFS(T v){
    std::unordered_map<T, bool> visited;
    std::unordered_map<T, int>  t_to_index;
    //Initialization visited arr
    for(int i=0;i<Graph<T>::n;++i){
        visited[ConvertTo<T>(std::to_string(i))] = false;
        t_to_index[ConvertTo<T>(std::to_string(i))] = i;
    }

    visited[v] = true;
    std::queue<T> q;
    q.push(v);
    std::cout<<v<<" ";
    while(!q.empty()){
        T top = q.front();
        q.pop();

        //for all adjacent points
        for(typename Chain<T>::Iterator j = adj_list[t_to_index[top]].Begin(); j!=adj_list[t_to_index[top]].End(); j++){
            T adj_point_w = *j;
            if(!visited[adj_point_w]){
                q.push(adj_point_w);
                visited[adj_point_w] = true;
                std::cout<<*j<<" ";
            }
        }
    }
}

template <class T>
void LinkedGraph<T>::Setup1(){//Build a specific graph
    if(Graph<T>::n != 0){
        //Delete original data
        for(int i=0;i<Graph<T>::n;++i){
            //Traverse all the chain of the node i
            if(!adj_list[i].IsEmpty()){
                for(typename Chain<T>::Iterator j = adj_list[i].Begin(); j!=adj_list[i].End(); j++){
                    adj_list[i].DeleteFront();
                }
            }
        }

        delete [] adj_list;
        adj_list = NULL;
    }

    Graph<T>::n = 8;
    adj_list = new Chain<T> [Graph<T>::n];

    //Set name
    for(int i=0;i<Graph<T>::n;++i){
        //Traverse all the chain of the node i
        std::string str_name = "adj_list["+std::to_string(i)+"]";
        adj_list[i].SetName(str_name);
    }

    adj_list[0].InsertBack(ConvertTo<T>("1"));
    adj_list[0].InsertBack(ConvertTo<T>("2"));
    adj_list[1].InsertBack(ConvertTo<T>("0"));
    adj_list[1].InsertBack(ConvertTo<T>("3"));
    adj_list[2].InsertBack(ConvertTo<T>("0"));
    adj_list[2].InsertBack(ConvertTo<T>("3"));
    adj_list[3].InsertBack(ConvertTo<T>("1"));
    adj_list[3].InsertBack(ConvertTo<T>("2"));
    adj_list[4].InsertBack(ConvertTo<T>("5"));
    adj_list[5].InsertBack(ConvertTo<T>("4"));
    adj_list[5].InsertBack(ConvertTo<T>("6"));
    adj_list[6].InsertBack(ConvertTo<T>("5"));
    adj_list[6].InsertBack(ConvertTo<T>("7"));
    adj_list[7].InsertBack(ConvertTo<T>("6"));
}

template <class T>
void LinkedGraph<T>::operator=(const LinkedGraph &other){
    std::cout<<"("<<name<<", Assignment operator=() is called...)"<<std::endl;
    if(Graph<T>::n != 0){
        //Delete original data
        for(int i=0;i<Graph<T>::n;++i){
            //Traverse all the chain of the node i
            if(!adj_list[i].IsEmpty()){
                for(typename Chain<T>::Iterator j = adj_list[i].Begin(); j!=adj_list[i].End(); j++){
                    adj_list[i].DeleteFront();
                }
            }
        }

        delete [] adj_list;
        adj_list = NULL;
    }

    Graph<T>::n = other.n;
    Graph<T>::e = other.e;

    if(Graph<T>::n != 0){
        adj_list = new Chain<T> [Graph<T>::n];
        for(int i=0;i<Graph<T>::n;++i){
            //Traverse all the chain of the node i
            std::string str_name = "adj_list["+std::to_string(i)+"]";
            adj_list[i].SetName(str_name);
            for(typename Chain<T>::Iterator j = other.adj_list[i].Begin(); j!=other.adj_list[i].End(); j++){
                adj_list[i].InsertBack(*j);
            }
        }
    }
    std::cout<<"("<<name<<", Assignment operator=() ends...)"<<std::endl;
}

template <class T>
std::ostream & operator<<(std::ostream &os, const LinkedGraph<T> &out_graph){
    if(out_graph.IsEmpty()){
        throw std::runtime_error(std::string("Warning: Not available. The LinkedGraph is empty."));
        return os;
    }

    if(out_graph.n != 0){
        os<<"-----Print of "<<out_graph.name<<"-----"<<std::endl;
        os<<out_graph.name<<": "<<std::endl;
        for(int i=0;i<out_graph.n;++i){
            //Traverse all the chain of the node i
            os<<out_graph.adj_list[i];
        }
        os<<"-----End of "<<out_graph.name<<"-----"<<std::endl;
    }else{
        os<<"-----Print of "<<out_graph.name<<"-----"<<std::endl;
        os<<out_graph.name<<" = NULL"<<std::endl;
        os<<"-----End of "<<out_graph.name<<"-----"<<std::endl;
    }

    return os;
}


