//main.cpp
#include <iostream>
#include <iomanip>
#include <solution.h>


int main(){
    Matrix mat_a(NULL, "mat_a");
    Matrix mat_b(NULL, "mat_b");
    std::string skip;


    std::cout<<"Please enter the information of matrix: "<<mat_a.GetName()<<std::endl;
    std::cout<<"If want to SKIP[Y/N]? : ";
    std::cin >> skip;
    if(skip != "Y" && skip != "y"){
        while(std::cin >> mat_a){
            break;
        }
    }

    std::cout<<"Please enter the information of matrix: "<<mat_b.GetName()<<std::endl;
    std::cout<<"If want to SKIP[Y/N]? : ";
    std::cin >> skip;
    if(skip != "Y" && skip != "y"){
        while(std::cin >> mat_b){
            break;
        }
    }

    std::cout<<std::endl;
    std::cout<<"You just entered:"<<std::endl;
    try{std::cout<<mat_a;}
    catch(std::runtime_error &e){
        std::cerr<<e.what()<<std::endl;
    }

    std::cout<<std::endl;
    try{std::cout<<mat_b;}
    catch(std::runtime_error &e){
        std::cerr<<e.what()<<std::endl;
    }

    std::cout<<std::endl;
    std::cout<<"----------------Copy Constructor test---------------------"<<std::endl;
    std::cout<<"> Matrix mat_d = mat_a;"<<std::endl;
    Matrix mat_d = mat_a;
    mat_d.SetName("mat_d");

    std::cout<<"> std::cout<<mat_d;"<<std::endl;
    try{std::cout<<mat_d;}
    catch(std::runtime_error &e){
        std::cerr<<e.what()<<std::endl;
    }

    std::cout<<std::endl;
    std::cout<<"----------------Assignment Operator=() test---------------------"<<std::endl;
    std::cout<<"> Matrix mat_c(NULL, 'mat_c');"<<std::endl;
    std::cout<<"> mat_c = mat_a;"<<std::endl;
    Matrix mat_c(NULL, "mat_c");
    mat_c = mat_a;

    std::cout<<"> std::cout<<mat_c;"<<std::endl;
    try{std::cout<<mat_c;}
    catch(std::runtime_error &e){
        std::cerr<<e.what()<<std::endl;
    }

    std::cout<<std::endl;
    std::cout<<"----------------Operator+() test---------------------"<<std::endl;
    std::cout<<"> Matrix mat_a_plus_b  = mat_a + mat_b;"<<std::endl;
    try{Matrix mat_a_plus_b = mat_a + mat_b;
        mat_a_plus_b.SetName("mat_a_plus_b");
        std::cout<<"> std::cout<<mat_a_plus_b;"<<std::endl;
        std::cout<<mat_a_plus_b;
    }
    catch(std::runtime_error &e){
        std::cerr<<e.what()<<std::endl;
    }



    return EXIT_SUCCESS;
}
