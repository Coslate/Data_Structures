//MatrixWDigraph.hpp
#include <MatrixWDigraph.h>
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
void MatrixWDigraph<T>::ShortestPath(const int n, const int v){//Dijkstra's Algorithm
    bool *s = new bool [n];
    T    *dist = new T [n];
    int  *prev = new int[n];

    for(int i=0;i<n;++i){
        s[i] = false;
        dist[i] = length[v][i];
        prev[i] = v;
    }

    s[v] = true;
    dist[v] = 0;

    //Print
    std::cout<<"Iteration\tVertex Selected\t";
    for(int i=0;i<n;++i){
        std::cout<<"["<<i<<"]\t";
    }
    std::cout<<std::endl;
    std::cout<<"Initial\t\t----\t\t";
    for(int i=0;i<n;++i){
        if(dist[i] == ConvertTo<T>(std::to_string(INT_MAX))){
            std::cout<<"INF"<<"\t";
        }else{
            std::cout<<dist[i]<<"\t";
        }
    }
    std::cout<<std::endl;

    for(int i=0;i<n-1;++i){
        //choose u that is not in s and has smallest dist[u]
        T min_dist = ConvertTo<T>(std::to_string(INT_MAX));
        int min_u;
        bool pick_one = false;
        for(int u=0;u<n;++u){
            if(!s[u]){//not in s
                if(dist[u] < min_dist){
                    min_dist = dist[u];
                    min_u = u;
                    pick_one = true;
                }
            }

        }

        if(!pick_one){
            break;
        }

        s[min_u] = true;

        //foreach <u, w> in the graph, update it
        for(int w=0;w<n;++w){
            if(length[min_u][w] == ConvertTo<T>(std::to_string(INT_MAX))){//not edge
                continue;
            }

            if(!s[w] && (dist[min_u]+length[min_u][w] < dist[w])){//edge out of s
                dist[w] = dist[min_u] + length[min_u][w];
                prev[w] = min_u;
            }
        }

        //Print
        std::cout<<i+1<<"\t\t"<<min_u<<"\t\t";
        for(int i=0;i<n;++i){
            if(dist[i] == ConvertTo<T>(std::to_string(INT_MAX))){
                std::cout<<"INF"<<"\t";
            }else{
                std::cout<<dist[i]<<"\t";
            }
        }
        std::cout<<std::endl;
    }

    //Print the Shortest Paths
    std::cout<<std::endl;
    std::cout<<"Paths\t\t\tLength"<<std::endl;
    for(int i=0;i<n;++i){
        if(dist[i] == ConvertTo<T>(std::to_string(INT_MAX))){
            continue;
        }

        if(i == v){
            continue;
        }

        std::stack<int> stack_prev;
        int prev_pt = prev[i];
        while(prev_pt != v){
            stack_prev.push(prev_pt);
            prev_pt = prev[prev_pt];
        }

        std::cout<<v<<" -> ";
        int count_t = 0;
        while(!stack_prev.empty()){
            int top = stack_prev.top();
            stack_prev.pop();
            std::cout<<top<<" -> ";
            count_t++;
        }
        std::cout<<i<<"\t";

        if(count_t == 0){
            std::cout<<"\t\t";
        }else{
            for(int j=0;j<(n-count_t-print_shift);++j){
                std::cout<<"\t";
            }
        }
        std::cout<<dist[i]<<std::endl;
    }
}

template <class T>
void MatrixWDigraph<T>::SetupG2p(){//Build a specific graph
    if(Graph<T>::n != 0){
        //Delete original data
        for(int i=0;i<Graph<T>::n;++i){
            delete [] length[i];
        }
        delete [] length;
    }

    Graph<T>::n = 3;
    length= new T *[Graph<T>::n];
    for(int i=0;i<Graph<T>::n;++i){
        length[i] = new T [Graph<T>::n];
    }

    for(int i=0;i<Graph<T>::n;++i){
        for(int j=0;j<Graph<T>::n;++j){
            length[i][j] = ConvertTo<T>(std::to_string(INT_MAX));
        }
    }

    length[0][1] = ConvertTo<T>(std::to_string(7));
    length[0][2] = ConvertTo<T>(std::to_string(5));
    length[1][2] = ConvertTo<T>(std::to_string(-5));
}

template <class T>
void MatrixWDigraph<T>::SetupG2(){//Build a specific graph
    if(Graph<T>::n != 0){
        //Delete original data
        for(int i=0;i<Graph<T>::n;++i){
            delete [] length[i];
        }
        delete [] length;
    }

    Graph<T>::n = 7;
    length= new T *[Graph<T>::n];
    for(int i=0;i<Graph<T>::n;++i){
        length[i] = new T [Graph<T>::n];
    }

    for(int i=0;i<Graph<T>::n;++i){
        for(int j=0;j<Graph<T>::n;++j){
            length[i][j] = ConvertTo<T>(std::to_string(INT_MAX));
        }
    }

    length[0][1] = ConvertTo<T>(std::to_string(6));
    length[0][2] = ConvertTo<T>(std::to_string(5));
    length[0][3] = ConvertTo<T>(std::to_string(5));
    length[1][4] = ConvertTo<T>(std::to_string(-1));
    length[2][1] = ConvertTo<T>(std::to_string(-2));
    length[2][4] = ConvertTo<T>(std::to_string(1));
    length[3][2] = ConvertTo<T>(std::to_string(-2));
    length[3][5] = ConvertTo<T>(std::to_string(-1));
    length[4][6] = ConvertTo<T>(std::to_string(3));
    length[5][6] = ConvertTo<T>(std::to_string(3));
}

template <class T>
void MatrixWDigraph<T>::SetupG1pp(){//Build a specific graph
    if(Graph<T>::n != 0){
        //Delete original data
        for(int i=0;i<Graph<T>::n;++i){
            delete [] length[i];
        }
        delete [] length;
    }

    Graph<T>::n = 6;
    length= new T *[Graph<T>::n];
    for(int i=0;i<Graph<T>::n;++i){
        length[i] = new T [Graph<T>::n];
    }

    for(int i=0;i<Graph<T>::n;++i){
        for(int j=0;j<Graph<T>::n;++j){
            length[i][j] = ConvertTo<T>(std::to_string(INT_MAX));
        }
    }

    length[0][1] = ConvertTo<T>(std::to_string(20));
    length[0][2] = ConvertTo<T>(std::to_string(15));
    length[1][0] = ConvertTo<T>(std::to_string(2));
    length[1][4] = ConvertTo<T>(std::to_string(10));
    length[1][5] = ConvertTo<T>(std::to_string(30));
    length[2][3] = ConvertTo<T>(std::to_string(4));
    length[2][5] = ConvertTo<T>(std::to_string(10));
    length[4][3] = ConvertTo<T>(std::to_string(3));
    length[5][3] = ConvertTo<T>(std::to_string(4));
    length[5][4] = ConvertTo<T>(std::to_string(10));
}

template <class T>
void MatrixWDigraph<T>::SetupG1p(){//Build a specific graph
    if(Graph<T>::n != 0){
        //Delete original data
        for(int i=0;i<Graph<T>::n;++i){
            delete [] length[i];
        }
        delete [] length;
    }

    Graph<T>::n = 6;
    length= new T *[Graph<T>::n];
    for(int i=0;i<Graph<T>::n;++i){
        length[i] = new T [Graph<T>::n];
    }

    for(int i=0;i<Graph<T>::n;++i){
        for(int j=0;j<Graph<T>::n;++j){
            length[i][j] = ConvertTo<T>(std::to_string(INT_MAX));
        }
    }

    length[0][1] = ConvertTo<T>(std::to_string(50));
    length[0][2] = ConvertTo<T>(std::to_string(45));
    length[0][3] = ConvertTo<T>(std::to_string(10));
    length[1][2] = ConvertTo<T>(std::to_string(10));
    length[1][3] = ConvertTo<T>(std::to_string(15));
    length[2][4] = ConvertTo<T>(std::to_string(30));
    length[3][0] = ConvertTo<T>(std::to_string(20));
    length[3][4] = ConvertTo<T>(std::to_string(15));
    length[4][1] = ConvertTo<T>(std::to_string(20));
    length[4][2] = ConvertTo<T>(std::to_string(35));
    length[5][4] = ConvertTo<T>(std::to_string(3));
}

template <class T>
void MatrixWDigraph<T>::SetupG1(){//Build a specific graph
    if(Graph<T>::n != 0){
        //Delete original data
        for(int i=0;i<Graph<T>::n;++i){
            delete [] length[i];
        }
        delete [] length;
    }

    Graph<T>::n = 8;
    length= new T *[Graph<T>::n];
    for(int i=0;i<Graph<T>::n;++i){
        length[i] = new T [Graph<T>::n];
    }

    for(int i=0;i<Graph<T>::n;++i){
        for(int j=0;j<Graph<T>::n;++j){
            length[i][j] = ConvertTo<T>(std::to_string(INT_MAX));
        }
    }

    length[1][0] = ConvertTo<T>(std::to_string(300));
    length[2][1] = ConvertTo<T>(std::to_string(800));
    length[2][0] = ConvertTo<T>(std::to_string(1000));
    length[3][2] = ConvertTo<T>(std::to_string(1200));
    length[4][3] = ConvertTo<T>(std::to_string(1500));
    length[4][5] = ConvertTo<T>(std::to_string(250));
    length[5][3] = ConvertTo<T>(std::to_string(1000));
    length[5][7] = ConvertTo<T>(std::to_string(1400));
    length[5][6] = ConvertTo<T>(std::to_string(900));
    length[6][7] = ConvertTo<T>(std::to_string(1000));
    length[7][0] = ConvertTo<T>(std::to_string(1700));
}

template <class T>
void MatrixWDigraph<T>::operator=(const MatrixWDigraph &other){
    std::cout<<"("<<name<<", Assignment operator=() is called...)"<<std::endl;
    if(Graph<T>::n != 0){
        //Delete original data
        for(int i=0;i<Graph<T>::n;++i){
            delete [] length[i];
        }
        delete [] length;
    }

    Graph<T>::n = other.n;
    Graph<T>::e = other.e;

    if(Graph<T>::n != 0){
        length= new T *[Graph<T>::n];
        for(int i=0;i<Graph<T>::n;++i){
            length[i] = new T [Graph<T>::n];
        }

        for(int i=0;i<Graph<T>::n;++i){
            for(int j=0;j<Graph<T>::n;++j){
                length[i][j] = other.length[i][j];
            }
        }
    }
    std::cout<<"("<<name<<", Assignment operator=() ends...)"<<std::endl;
}

template <class T>
std::ostream & operator<<(std::ostream &os, const MatrixWDigraph<T> &out_graph){
    if(out_graph.IsEmpty()){
        throw std::runtime_error(std::string("Warning: Not available. The MatrixWDigraph is empty."));
        return os;
    }

    if(out_graph.n != 0){
        os<<"-----Print of "<<out_graph.name<<"-----"<<std::endl;
        os<<out_graph.name<<" adjacency matrix: "<<std::endl;
        os<<"\t";
        for(int i=0;i<out_graph.n;++i){
            os<<"["<<i<<"]\t";
        }
        os<<std::endl;

        for(int i=0;i<out_graph.n;++i){
            os<<"["<<i<<"]\t";
            for(int j=0;j<out_graph.n;++j){
                if(out_graph.length[i][j] == ConvertTo<T>(std::to_string(INT_MAX))){
                    os<<"INF"<<"\t";
                }else{
                    os<<out_graph.length[i][j]<<"\t";
                }
            }
            os<<std::endl;
        }
        os<<"-----End of "<<out_graph.name<<"-----"<<std::endl;
    }else{
        os<<"-----Print of "<<out_graph.name<<"-----"<<std::endl;
        os<<out_graph.name<<" = NULL"<<std::endl;
        os<<"-----End of "<<out_graph.name<<"-----"<<std::endl;
    }

    return os;
}


