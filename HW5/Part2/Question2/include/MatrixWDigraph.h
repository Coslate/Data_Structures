#ifndef _MATRIXWDIGRAPH_H_
#define _MATRIXWDIGRAPH_H_

#include <string>
#include <unordered_map>
#include <cfloat>
#include <stack>
#include <queue>
#include <iostream>
#include <climits>
#include <Graph.h>

template <class T>
class MatrixWDigraph;

template <typename T>
std::ostream & operator<<(std::ostream &os, const MatrixWDigraph<T> &out_graph);

template <typename T>
T ConvertTo (const std::string &str);

template <class T>
class MatrixWDigraph : public Graph<T>{
    private:
        std::string    name;
        T          **length;
        int            print_shift;//for standard output format

    public:
        MatrixWDigraph(): Graph<T>(), name("NULL"), print_shift(0){Graph<T>::n = 0; Graph<T>::e = 0;}
        MatrixWDigraph(const int n, const int e=0, const int print_shift=0): Graph<T>(), name("NULL"), print_shift(print_shift){
            Graph<T>::n = n;
            Graph<T>::e = e;

            if(n != 0){
                length= new T *[n];
                for(int i=0;i<n;++i){
                    length[i] = new T [n];
                }

                for(int i=0;i<n;++i){
                    for(int j=0;j<n;++j){
                        length[i][j] = ConvertTo<T>(std::to_string(INT_MAX));
                    }
                }
            }
        }
        MatrixWDigraph(const std::string &name = "NULL", const int n=0, const int e=0, const int print_shift=0): Graph<T>(), name(name), print_shift(print_shift){
            Graph<T>::n = n;
            Graph<T>::e = e;

            if(n != 0){
                length= new T *[n];
                for(int i=0;i<n;++i){
                    length[i] = new T [n];
                }

                for(int i=0;i<n;++i){
                    for(int j=0;j<n;++j){
                        length[i][j] = ConvertTo<T>(std::to_string(INT_MAX));
                    }
                }
            }
        }

        //Copy consturctor
        MatrixWDigraph(const MatrixWDigraph &p) : Graph<T>(){
            Graph<T>::n = p.n;
            Graph<T>::e = p.e;

            if(Graph<T>::n != 0){
                length= new T *[Graph<T>::n];
                for(int i=0;i<Graph<T>::n;++i){
                    length[i] = new T [Graph<T>::n];
                }

                for(int i=0;i<Graph<T>::n;++i){
                    for(int j=0;j<Graph<T>::n;++j){
                        length[i][j] = p.length[i][j];
                    }
                }
            }
        }

        //Destructor
        ~MatrixWDigraph(){
            std::cout<<"("<<name<<", Destructor is called...)"<<std::endl;
            for(int i=0;i<Graph<T>::n;++i){
                delete [] length[i];
            }
            delete [] length;
            std::cout<<"("<<name<<", Destructor ends...)"<<std::endl;
        }

        bool                               IsEmpty             ()              const {return (Graph<T>::n==0);}
        void                               SetupG1             ();
        void                               SetupG1p            ();
        void                               SetupG1pp           ();

        void                               SetupG2             ();
        void                               SetupG2p            ();


        void                               ShortestPath        (const int n, const int v);//Dijkstra
        void                               BellmanFord         (const int v);

        std::string                        Name                ()              const {return name;}
        void                               SetName             (const std::string &in_name)    {name = in_name;}
        void                               SetPrintShift       (const int in_print_shift=0)    {print_shift = in_print_shift;}

        //static bool SortFunction(const Term<CoefType, ExpType> &a, const Term<CoefType, ExpType> &b);
        void operator=(const MatrixWDigraph &gaph);
        friend std::ostream & operator<<<T>(std::ostream &os, const MatrixWDigraph<T> &out_graph);
};

#include <MatrixWDigraph.hpp>
#endif

