//main.cpp
#include <iostream>
#include <solution.h>


int main(){
    Polynomial<float, int> test_poly_a(0, 10, "test_poly_a");
    Polynomial<float, int> test_poly_b(0, 10, "test_poly_b");

    while(std::cin >> test_poly_a){
        std::string end_input;
        std::cout<< test_poly_a;

        std::cout<<"End of the input[Y/N]? : ";
        std::cin>> end_input;
        if(end_input == "Y" || end_input == "y"){
            break;
        }
    }

    while(std::cin >> test_poly_b){
        std::string end_input;
        std::cout<< test_poly_b;

        std::cout<<"End of the input[Y/N]? : ";
        std::cin>> end_input;
        if(end_input == "Y" || end_input == "y"){
            break;
        }
    }

    return EXIT_SUCCESS;
}
