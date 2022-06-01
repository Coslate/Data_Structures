//main.cpp
#include <iostream>
#include <MatrixWDigraph.h>

int main(){
    std::cout<<std::endl;
    std::cout<<"===================================================="<<std::endl;
    std::cout<<"======================  (a)  ======================="<<std::endl;
    std::cout<<"===================================================="<<std::endl;
    MatrixWDigraph<int> g1(8, 11, 6);
    MatrixWDigraph<int> g1p(6, 11, 4);
    MatrixWDigraph<int> g1pp(6, 10, 4);
    g1.SetName("g1");
    g1p.SetName("g1p");
    g1pp.SetName("g1pp");

    std::cout<<std::endl;
    std::cout<<"------------SetupG1() Test--------------"<<std::endl;
    std::cout<<"> g1.SetupG1()"<<std::endl;
    std::cout<<"> std::cout<<g1;"<<std::endl;
    g1.SetupG1();
    std::cout<<g1;

    std::cout<<std::endl;
    std::cout<<"------------ShortestPath(Dijkstra) of G1 Test--------------"<<std::endl;
    std::cout<<"> g1.ShortestPath(8, 4);"<<std::endl;
    g1.ShortestPath(8, 4);

    std::cout<<std::endl;
    std::cout<<"------------SetupG1p() Test--------------"<<std::endl;
    std::cout<<"> g1p.SetupG1p()"<<std::endl;
    std::cout<<"> std::cout<<g1p;"<<std::endl;
    g1p.SetupG1p();
    std::cout<<g1p;

    std::cout<<std::endl;
    std::cout<<"------------ShortestPath(Dijkstra) of G1' Test--------------"<<std::endl;
    std::cout<<"> g1p.ShortestPath(6, 0);"<<std::endl;
    g1p.ShortestPath(6, 0);

    std::cout<<std::endl;
    std::cout<<"------------SetupG1pp() Test--------------"<<std::endl;
    std::cout<<"> g1pp.SetupG1pp()"<<std::endl;
    std::cout<<"> std::cout<<g1pp;"<<std::endl;
    g1pp.SetupG1pp();
    std::cout<<g1pp;

    std::cout<<std::endl;
    std::cout<<"------------ShortestPath(Dijkstra) G1'' Test--------------"<<std::endl;
    std::cout<<"> g1pp.ShortestPath(6, 0);"<<std::endl;
    g1pp.ShortestPath(6, 0);

    std::cout<<std::endl;
    return EXIT_SUCCESS;
}
