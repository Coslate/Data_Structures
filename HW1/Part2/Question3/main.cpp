//main.cpp
#include <iostream>
#include <solution.h>
#include <cstring>


int main(){
    std::string str = "oafwfnvuuw";
    char *a = new char[str.length()];
    strcpy(a, str.c_str());
    String test_a_str(a, str.length(), "test_a_str");
    std::cout<<test_a_str;
    delete [] a;

    str = "icuccu";
    char *b = new char[str.length()];
    strcpy(b, str.c_str());
    String test_b_str(b, str.length(), "test_b_str");
    std::cout<<test_b_str;
    delete [] b;

    std::cout<<"------------operator==() Test--------------"<<std::endl;
    if(test_a_str == test_b_str){
        std::cout<<"test_a_str == test_b_str."<<std::endl;
    }else{
        std::cout<<"test_a_str != test_b_str."<<std::endl;
    }
    /*
    try{std::cout<<"test_a_str == test_b_str = "<<(test_a_str==test_b_str)<<std::endl;}
    catch(std::runtime_error &e){
        std::cerr<<e.what()<<std::endl;
    }
    */

    return EXIT_SUCCESS;
}
