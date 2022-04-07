//main.cpp
#include <iostream>
#include <solution.h>


int main(){
    Polynomial<float, int> test_poly_a(0, 10, "test_poly_a");
    std::cout<<"------------Add() Test--------------"<<std::endl;
    try {test_poly_a_plus_b_result = test_poly_a.Add(test_poly_b);}
    catch(std::runtime_error &e){
        std::cerr<<e.what()<<std::endl;
    }

    return EXIT_SUCCESS;
}
