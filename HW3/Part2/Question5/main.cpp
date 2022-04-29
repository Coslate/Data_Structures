//main.cpp
#include <iostream>
#include <iomanip>
#include <solution.h>


int main(){
    Matrix mat_a(NULL, "mat_a");
    std::string skip;


    std::cout<<"Please enter the information of matrix: "<<mat_a.GetName()<<std::endl;
    std::cout<<"If want to SKIP[Y/N]? : ";
    std::cin >> skip;
    if(skip != "Y" && skip != "y"){
        while(std::cin >> mat_a){
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
    std::cout<<"----------------Copy Constructor test---------------------"<<std::endl;
    std::cout<<"> Matrix mat_b = mat_a;"<<std::endl;
    Matrix mat_b = mat_a;
    mat_b.SetName("mat_b");

    std::cout<<"> std::cout<<mat_b;"<<std::endl;
    try{std::cout<<mat_b;}
    catch(std::runtime_error &e){
        std::cerr<<e.what()<<std::endl;
    }



    return EXIT_SUCCESS;
}
