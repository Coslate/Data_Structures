//main.cpp
#include <iostream>
#include <LinkedGraph.h>

int main(){
    std::cout<<std::endl;
    std::cout<<"===================================================="<<std::endl;
    std::cout<<"=======================  G1  ======================="<<std::endl;
    std::cout<<"===================================================="<<std::endl;
    LinkedGraph<int> g1(8);
    g1.SetName("g1");

    std::cout<<std::endl;
    std::cout<<"------------Setup1() Test--------------"<<std::endl;
    std::cout<<"> g1.Setup1()"<<std::endl;
    std::cout<<"> std::cout<<g1;"<<std::endl;
    g1.Setup1();
    std::cout<<g1;

    std::cout<<std::endl;
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

    //Components & DfnFlow
    std::cout<<std::endl;
    std::cout<<"------------Components() Test--------------"<<std::endl;
    std::cout<<"> g1.Components();"<<std::endl;
    g1.Components();
    std::cout<<std::endl;

    std::cout<<std::endl;
    std::cout<<"------------DfnLow() Test--------------"<<std::endl;
    std::cout<<"> g1.DfnLow(3);"<<std::endl;
    g1.DfnLow(3);
    std::cout<<std::endl;

    std::cout<<"===================================================="<<std::endl;
    std::cout<<"=======================  G2  ======================="<<std::endl;
    std::cout<<"===================================================="<<std::endl;
    LinkedGraph<int> g2(8);
    g2.SetName("g2");

    std::cout<<std::endl;
    std::cout<<"------------Setup2() Test--------------"<<std::endl;
    std::cout<<"> g2.Setup2()"<<std::endl;
    std::cout<<"> std::cout<<g2;"<<std::endl;
    g2.Setup2();
    std::cout<<g2;

    std::cout<<std::endl;
    std::cout<<"------------BFS() Test--------------"<<std::endl;
    //BFS
    std::cout<<"> g2.BFS(0) = ";
    g2.BFS(0);
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<"> g2.BFS(3) = ";
    g2.BFS(3);
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<"> g2.BFS(7) = ";
    g2.BFS(7);
    std::cout<<std::endl;

    std::cout<<std::endl;
    std::cout<<"------------DFS() Test--------------"<<std::endl;
    //DFS
    std::cout<<"> g2.DFS(0) = ";
    g2.DFS(0);
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<"> g2.DFS(3) = ";
    g2.DFS(3);
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<"> g2.DFS(7) = ";
    g2.DFS(7);
    std::cout<<std::endl;

    //Components & DfnFlow
    std::cout<<std::endl;
    std::cout<<"------------Components() Test--------------"<<std::endl;
    std::cout<<"> g2.Components();"<<std::endl;
    g2.Components();
    std::cout<<std::endl;

    std::cout<<std::endl;
    std::cout<<"------------DfnLow() Test--------------"<<std::endl;
    std::cout<<"> g2.DfnLow(3);"<<std::endl;
    g2.DfnLow(3);
    std::cout<<std::endl;

    std::cout<<"===================================================="<<std::endl;
    std::cout<<"=======================  G3  ======================="<<std::endl;
    std::cout<<"===================================================="<<std::endl;
    LinkedGraph<int> g3(10);
    g3.SetName("g3");

    std::cout<<std::endl;
    std::cout<<"------------Setup3() Test--------------"<<std::endl;
    std::cout<<"> g3.Setup3()"<<std::endl;
    std::cout<<"> std::cout<<g3;"<<std::endl;
    g3.Setup3();
    std::cout<<g3;

    std::cout<<std::endl;
    std::cout<<"------------BFS() Test--------------"<<std::endl;
    //BFS
    std::cout<<"> g3.BFS(0) = ";
    g3.BFS(0);
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<"> g3.BFS(3) = ";
    g3.BFS(3);
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<"> g3.BFS(7) = ";
    g3.BFS(7);
    std::cout<<std::endl;

    std::cout<<std::endl;
    std::cout<<"------------DFS() Test--------------"<<std::endl;
    //DFS
    std::cout<<"> g3.DFS(0) = ";
    g3.DFS(0);
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<"> g3.DFS(3) = ";
    g3.DFS(3);
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<"> g3.DFS(7) = ";
    g3.DFS(7);
    std::cout<<std::endl;

    //Components & DfnFlow
    std::cout<<std::endl;
    std::cout<<"------------Components() Test--------------"<<std::endl;
    std::cout<<"> g3.Components();"<<std::endl;
    g3.Components();
    std::cout<<std::endl;

    std::cout<<std::endl;
    std::cout<<"------------DfnLow() Test--------------"<<std::endl;
    std::cout<<"> g3.DfnLow(3);"<<std::endl;
    g3.DfnLow(3);
    std::cout<<std::endl;

    return EXIT_SUCCESS;
}
