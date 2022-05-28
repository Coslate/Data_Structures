//main.cpp
#include <iostream>
#include <LinkedGraph.h>

int main(){
    LinkedGraph<char> g1(8);
    g1.SetName("g1");

    std::cout<<std::endl;
    std::cout<<"------------Setup1() Test--------------"<<std::endl;
    std::cout<<"> g1.Setup1()"<<std::endl;
    std::cout<<"> std::cout<<g1;"<<std::endl;
    g1.Setup1();
    std::cout<<g1;

    return EXIT_SUCCESS;
}
