//main.cpp
#include <iostream>
#include <MatrixWDigraph.h>

int main(){
    std::cout<<std::endl;
    std::cout<<"=================================================================================="<<std::endl;
    std::cout<<"=====================================  (a)  ======================================"<<std::endl;
    std::cout<<"=================================================================================="<<std::endl;
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
    std::cout<<"=================================================================================="<<std::endl;
    std::cout<<"=====================================  (b)  ======================================"<<std::endl;
    std::cout<<"=================================================================================="<<std::endl;
    MatrixWDigraph<int> g2(7, 10, 4);
    MatrixWDigraph<int> g2p(3, 3, 0);
    g2.SetName("g2");
    g2p.SetName("g2p");

    std::cout<<std::endl;
    std::cout<<"------------SetupG2() Test--------------"<<std::endl;
    std::cout<<"> g2.SetupG2()"<<std::endl;
    std::cout<<"> std::cout<<g2;"<<std::endl;
    g2.SetupG2();
    std::cout<<g2;

    std::cout<<std::endl;
    std::cout<<"------------BellmanFord() of G2 Test--------------"<<std::endl;
    std::cout<<"> g2.BellmanFord(0);"<<std::endl;
    g2.BellmanFord(0);

    std::cout<<std::endl;
    std::cout<<"------------SetupG2p() Test--------------"<<std::endl;
    std::cout<<"> g2p.SetupG2p()"<<std::endl;
    std::cout<<"> std::cout<<g2p;"<<std::endl;
    g2p.SetupG2p();
    std::cout<<g2p;

    std::cout<<std::endl;
    std::cout<<"------------BellmanFord() of G2' Test--------------"<<std::endl;
    std::cout<<"> g2p.BellmanFord(0);"<<std::endl;
    g2p.BellmanFord(0);


    std::cout<<std::endl;
    std::cout<<"=================================================================================="<<std::endl;
    std::cout<<"=====================================  (c)  ======================================"<<std::endl;
    std::cout<<"=================================================================================="<<std::endl;
    MatrixWDigraph<int> g3(3, 5, 4);
    g3.SetName("g3");

    std::cout<<std::endl;
    std::cout<<"------------SetupG3() Test--------------"<<std::endl;
    std::cout<<"> g3.SetupG3()"<<std::endl;
    std::cout<<"> std::cout<<g3;"<<std::endl;
    g3.SetupG3();
    std::cout<<g3;

    std::cout<<std::endl;
    std::cout<<"------------AllLengths() of G3 Test--------------"<<std::endl;
    std::cout<<"> g3.AllLengths(3);"<<std::endl;
    g3.AllLengths(3);

    std::cout<<std::endl;
    std::cout<<"------------SetupG2() Test--------------"<<std::endl;
    std::cout<<"> g2.SetupG2()"<<std::endl;
    std::cout<<"> std::cout<<g2;"<<std::endl;
    g2.SetupG2();
    std::cout<<g2;

    std::cout<<std::endl;
    std::cout<<"------------AllLengths() of G2 Test--------------"<<std::endl;
    std::cout<<"> g2.AllLengths(7);"<<std::endl;
    g2.AllLengths(7);

    std::cout<<std::endl;
    return EXIT_SUCCESS;
}
