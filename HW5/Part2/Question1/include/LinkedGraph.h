#ifndef _LinkedGraph_H_
#define _LinkedGraph_H_

#include <string>
#include <unordered_map>
#include <cfloat>
#include <stack>
#include <queue>
#include <iostream>
#include <Graph.h>
#include <Chain.h>

template <class T>
class LinkedGraph;

template <typename T>
std::ostream & operator<<(std::ostream &os, const LinkedGraph<T> &out_graph);

template <typename T>
T ConvertTo (const std::string &str);

template <class T>
class LinkedGraph : public Graph<T>{
    private:
        std::string    name;
        Chain<T>  *adj_list;

    public:
        LinkedGraph(): Graph<T>(), name("NULL"), adj_list(NULL){Graph<T>::n = 0; Graph<T>::e = 0;}
        LinkedGraph(const int n, const int e=0): Graph<T>(), name("NULL"){
            Graph<T>::n = n;
            Graph<T>::e = e;

            if(n != 0){
                adj_list = new Chain<T> [n];
                for(int i=0;i<Graph<T>::n;++i){
                    //Traverse all the chain of the node i
                    std::string str_name = "adj_list["+std::to_string(i)+"]";
                    adj_list[i].SetName(str_name);
                }
            }
        }
        LinkedGraph(const std::string &name = "NULL", Chain<T> *adj_list = NULL, const int n=0, const int e=0): Graph<T>(), name(name), adj_list(adj_list){
            Graph<T>::n = n;
            Graph<T>::e = e;

            if(n != 0){
                adj_list = new Chain<T> [n];
                for(int i=0;i<Graph<T>::n;++i){
                    //Traverse all the chain of the node i
                    std::string str_name = "adj_list["+std::to_string(i)+"]";
                    adj_list[i].SetName(str_name);
                }
            }
        }

        //Copy consturctor
        LinkedGraph(const LinkedGraph &p) : Graph<T>(){
            Graph<T>::n = p.n;
            Graph<T>::e = p.e;

            if(Graph<T>::n != 0){
                adj_list = new Chain<T> [Graph<T>::n];
                for(int i=0;i<Graph<T>::n;++i){
                    //Traverse all the chain of the node i
                    std::string str_name = "adj_list["+std::to_string(i)+"]";
                    adj_list[i].SetName(str_name);
                    for(typename Chain<T>::Iterator j = p.adj_list[i].Begin(); j!=p.adj_list[i].End(); j++){
                        adj_list[i].InsertBack(*j);
                    }
                }
            }
        }

        //Destructor
        ~LinkedGraph(){
            std::cout<<"("<<name<<", Destructor is called...)"<<std::endl;
            if(Graph<T>::n != 0){
                for(int i=0;i<Graph<T>::n;++i){
                    //Traverse all the chain of the node i
                    for(typename Chain<T>::Iterator j = adj_list[i].Begin(); j!=adj_list[i].End(); j++){
                        adj_list[i].DeleteFront();
                    }
                }
            }
            delete [] adj_list;
            adj_list = NULL;
            std::cout<<"("<<name<<", Destructor ends...)"<<std::endl;
        }

        bool                               IsEmpty             ()              const {return (Graph<T>::n==0);}
        void                               Setup1              ();
        void                               Setup2              ();
        void                               Setup3              ();

        void                               BFS                 (T v);
        void                               DFS                 (T v, const bool print_value=true);
        void                               DFSRecursive        (T v, std::unordered_map<T, bool> &visited, std::unordered_map<T, int> &t_to_index, const bool print_value=true);
        void                               DFSRecursive        (T v, std::unordered_map<T, bool> &visited, std::unordered_map<T, int> &t_to_index, std::queue<T> &all_connected_component, const bool print_value=true);
        void                               Components          ();
        void                               OutputNewComponent  (std::queue<T> &all_connected_component);

        void                               DfnLow              (const T x);
        void                               DfnLow              (const T u, const T v, std::unordered_map<T, int> &t_to_index, int *&dfn, int *&low, int &num);

        std::string                        Name                ()              const {return name;}
        void                               SetName             (const std::string &in_name)    {name = in_name;}

        //static bool SortFunction(const Term<CoefType, ExpType> &a, const Term<CoefType, ExpType> &b);
        void operator=(const LinkedGraph &gaph);
        friend std::ostream & operator<<<T>(std::ostream &os, const LinkedGraph<T> &out_graph);
};

#include <LinkedGraph.hpp>
#endif

