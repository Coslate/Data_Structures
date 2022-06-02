//LinkedGraph.hpp
#include <LinkedGraph.h>
#include <algorithm>
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
void LinkedGraph<T>::DfnLow(const T u, const T v, std::unordered_map<T, int> &t_to_index, int *&dfn, int *&low, int &num){
    dfn[t_to_index[u]] = num;
    low[t_to_index[u]] = num;
    num++;

    //for all adjacent points
    for(typename Chain<T>::Iterator j = adj_list[t_to_index[u]].Begin(); j!=adj_list[t_to_index[u]].End(); j++){
        T adj_point_w = *j;
        if(dfn[t_to_index[adj_point_w]] == 0){
            DfnLow(adj_point_w, u, t_to_index, dfn, low, num);
            low[u] = std::min(low[u], low[adj_point_w]);
        }else if(adj_point_w != v){
            //back edge
            low[u] = std::min(low[u], dfn[adj_point_w]);
        }
    }
}

template <class T>
void LinkedGraph<T>::DfnLow(const T x){
    int num = 1;
    int *dfn = new int [Graph<T>::n]();
    int *low = new int [Graph<T>::n]();
    std::unordered_map<T, int>  t_to_index;
    //Initialization visited arr
    for(int i=0;i<Graph<T>::n;++i){
        t_to_index[ConvertTo<T>(std::to_string(i))] = i;
    }

    DfnLow(x, ConvertTo<T>(std::to_string(-1)), t_to_index, dfn, low, num);

    //Output dfn
    for(int i=0;i<Graph<T>::n;++i){
        std::cout<<"dfn["<<i<<"] = "<<dfn[i]<<std::endl;
    }
    std::cout<<std::endl;
    //Output low
    for(int i=0;i<Graph<T>::n;++i){
        std::cout<<"low["<<i<<"] = "<<low[i]<<std::endl;
    }

    delete [] dfn;
    delete [] low;
}

template <class T>
void LinkedGraph<T>::OutputNewComponent(std::queue<T> &all_connected_component){
    std::cout<<"Connected Component: ";
    while(!all_connected_component.empty()){
        T top = all_connected_component.front();
        all_connected_component.pop();
        std::cout<<top<<" ";
    }
    std::cout<<std::endl;
}

template <class T>
void LinkedGraph<T>::Components(){
    std::unordered_map<T, bool> visited;
    std::unordered_map<T, int>  t_to_index;
    std::queue<T> all_connected_component;
    //Initialization visited arr
    for(int i=0;i<Graph<T>::n;++i){
        visited[ConvertTo<T>(std::to_string(i))] = false;
        t_to_index[ConvertTo<T>(std::to_string(i))] = i;
    }

    //All DFS
    for(int i=0;i<Graph<T>::n;++i){
        T v = ConvertTo<T>(std::to_string(i));
        if(!visited[v]){
            DFSRecursive(v, visited, t_to_index, all_connected_component, false);
            OutputNewComponent(all_connected_component);
        }
    }
}

template <class T>
void LinkedGraph<T>::DFSRecursive(T v, std::unordered_map<T, bool> &visited, std::unordered_map<T, int> &t_to_index, std::queue<T> &all_connected_component, const bool print_value){
    if(print_value){
        std::cout<<v<<" ";
    }

    visited[v] = true;
    all_connected_component.push(v);

    //for all adjacent points
    for(typename Chain<T>::Iterator j = adj_list[t_to_index[v]].Begin(); j!=adj_list[t_to_index[v]].End(); j++){
        T adj_point_w = *j;
        if(!visited[adj_point_w]){
            DFSRecursive(adj_point_w, visited, t_to_index, all_connected_component, print_value);
        }
    }
}

template <class T>
void LinkedGraph<T>::DFSRecursive(T v, std::unordered_map<T, bool> &visited, std::unordered_map<T, int> &t_to_index, const bool print_value){
    if(print_value){
        std::cout<<v<<" ";
    }
    visited[v] = true;
    //for all adjacent points
    for(typename Chain<T>::Iterator j = adj_list[t_to_index[v]].Begin(); j!=adj_list[t_to_index[v]].End(); j++){
        T adj_point_w = *j;
        if(!visited[adj_point_w]){
            DFSRecursive(adj_point_w, visited, t_to_index, print_value);
        }
    }
}

template <class T>
void LinkedGraph<T>::DFS(T v, const bool print_value){
    std::unordered_map<T, bool> visited;
    std::unordered_map<T, int>  t_to_index;
    //Initialization visited arr
    for(int i=0;i<Graph<T>::n;++i){
        visited[ConvertTo<T>(std::to_string(i))] = false;
        t_to_index[ConvertTo<T>(std::to_string(i))] = i;
    }

    DFSRecursive(v, visited, t_to_index, print_value);
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
void LinkedGraph<T>::Setup3(){//Build a specific graph
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

    Graph<T>::n = 10;
    adj_list = new Chain<T> [Graph<T>::n];

    //Set name
    for(int i=0;i<Graph<T>::n;++i){
        //Traverse all the chain of the node i
        std::string str_name = "adj_list["+std::to_string(i)+"]";
        adj_list[i].SetName(str_name);
    }

    adj_list[0].InsertBack(ConvertTo<T>("1"));
    adj_list[1].InsertBack(ConvertTo<T>("0"));
    adj_list[1].InsertBack(ConvertTo<T>("2"));
    adj_list[1].InsertBack(ConvertTo<T>("3"));
    adj_list[2].InsertBack(ConvertTo<T>("1"));
    adj_list[2].InsertBack(ConvertTo<T>("4"));
    adj_list[3].InsertBack(ConvertTo<T>("4"));
    adj_list[3].InsertBack(ConvertTo<T>("1"));
    adj_list[3].InsertBack(ConvertTo<T>("5"));
    adj_list[4].InsertBack(ConvertTo<T>("2"));
    adj_list[4].InsertBack(ConvertTo<T>("3"));
    adj_list[5].InsertBack(ConvertTo<T>("3"));
    adj_list[5].InsertBack(ConvertTo<T>("6"));
    adj_list[5].InsertBack(ConvertTo<T>("7"));
    adj_list[6].InsertBack(ConvertTo<T>("5"));
    adj_list[6].InsertBack(ConvertTo<T>("7"));
    adj_list[7].InsertBack(ConvertTo<T>("5"));
    adj_list[7].InsertBack(ConvertTo<T>("6"));
    adj_list[7].InsertBack(ConvertTo<T>("9"));
    adj_list[7].InsertBack(ConvertTo<T>("8"));
    adj_list[8].InsertBack(ConvertTo<T>("7"));
    adj_list[9].InsertBack(ConvertTo<T>("7"));
}

template <class T>
void LinkedGraph<T>::Setup2(){//Build a specific graph
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
    adj_list[1].InsertBack(ConvertTo<T>("4"));
    adj_list[2].InsertBack(ConvertTo<T>("0"));
    adj_list[2].InsertBack(ConvertTo<T>("5"));
    adj_list[2].InsertBack(ConvertTo<T>("6"));
    adj_list[3].InsertBack(ConvertTo<T>("1"));
    adj_list[3].InsertBack(ConvertTo<T>("7"));
    adj_list[4].InsertBack(ConvertTo<T>("1"));
    adj_list[4].InsertBack(ConvertTo<T>("7"));
    adj_list[5].InsertBack(ConvertTo<T>("2"));
    adj_list[5].InsertBack(ConvertTo<T>("7"));
    adj_list[6].InsertBack(ConvertTo<T>("2"));
    adj_list[6].InsertBack(ConvertTo<T>("7"));
    adj_list[7].InsertBack(ConvertTo<T>("3"));
    adj_list[7].InsertBack(ConvertTo<T>("4"));
    adj_list[7].InsertBack(ConvertTo<T>("5"));
    adj_list[7].InsertBack(ConvertTo<T>("6"));
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
        os<<out_graph.name<<" adjacency list: "<<std::endl;
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


