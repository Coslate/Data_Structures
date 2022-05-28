//main.cpp
#include <iostream>
#include <LinkedGraph.h>

int main(){
    LinkedGraph<int> g1(8);
    g1.SetName("g1");

    std::cout<<std::endl;
    std::cout<<"------------Setup1() Test--------------"<<std::endl;
    std::cout<<"> g1.Setup1()"<<std::endl;
    std::cout<<"> std::cout<<g1;"<<std::endl;
    g1.Setup1();
    std::cout<<g1;

    std::cout<<"------------BFS() Test--------------"<<std::endl;
    //BFS
    std::cout<<"> g1.BFS(0) = ";
    g1.BFS(0);
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<"> g1.BFS(3) = ";
    g1.BFS(3);
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<"> g1.BFS(7) = ";
    g1.BFS(7);
    std::cout<<std::endl;

    std::cout<<"------------DFS() Test--------------"<<std::endl;
    //DFS
    std::cout<<"> g1.DFS(0) = ";
    g1.DFS(0);
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<"> g1.DFS(3) = ";
    g1.DFS(3);
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<"> g1.DFS(7) = ";
    g1.DFS(7);
    std::cout<<std::endl;

    return EXIT_SUCCESS;
}
