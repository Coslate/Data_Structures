//main.cpp
#include <iostream>
#include <iomanip>
#include <circular_headerlist.h>
#include <polynomial.h>


int main(){
    Polynomial test_poly_a(0, "test_poly_a");
    Polynomial test_poly_b(0, "test_poly_b");
    Polynomial test_poly_a_plus_b_result(0, "test_poly_a_plus_b_result");
    Polynomial test_poly_a_minus_b_result(0, "test_poly_a_minus_b_result");
    Polynomial test_poly_a_mul_b_result (0, "test_poly_a_mul_b_result");
    std::string skip;


    std::cout<<"Please enter the terms in decreasing order of exponential for polynomial "<<test_poly_a.GetName()<<std::endl;
    std::cout<<"If want to SKIP[Y/N]? : ";
    std::cin >> skip;
    if(skip != "Y" && skip != "y"){
        while(std::cin >> test_poly_a){
            std::string end_input;
            std::cout<<test_poly_a.GetName()<<" = "<<test_poly_a;

            std::cout<<"End of the input[Y/N]? : ";
            std::cin>> end_input;
            if(end_input == "Y" || end_input == "y"){
                break;
            }
        }
    }

    std::cout<<"Please enter the terms in decreasing order of exponential for polynomial "<<test_poly_b.GetName()<<std::endl;
    std::cout<<"If want to SKIP[Y/N]? : ";
    std::cin >> skip;
    if(skip != "Y" && skip != "y"){
        while(std::cin >> test_poly_b){
            std::string end_input;
            std::cout<<test_poly_b.GetName()<<" = "<<test_poly_b;

            std::cout<<"End of the input[Y/N]? : ";
            std::cin>> end_input;
            if(end_input == "Y" || end_input == "y"){
                break;
            }
        }
    }

    std::cout<<std::endl;
    std::cout<<"You just entered:"<<std::endl;
    try{std::cout<<test_poly_a.GetName()<<" = "<<test_poly_a;}
    catch(std::runtime_error &e){
        std::cerr<<e.what()<<std::endl;
    }

    try{std::cout<<test_poly_b.GetName()<<" = "<<test_poly_b;}
    catch(std::runtime_error &e){
        std::cerr<<e.what()<<std::endl;
    }
    std::cout<<std::endl;

    std::cout<<std::endl;
    std::cout<<"------------Copy Constructor() Test--------------"<<std::endl;
    std::cout<<"> Polynomial copy_b = test_poly_a;"<<std::endl;
    Polynomial copy_b = test_poly_a;
    std::cout<<"> std::cout<<copy_b"<<std::endl;
    try{std::cout<<"copy_b"<<" = "<<copy_b;}
    catch(std::runtime_error &e){
        std::cerr<<e.what()<<std::endl;
    }

    std::cout<<std::endl;
    std::cout<<"------------Operator=() Test--------------"<<std::endl;
    std::cout<<"> Polynomial assign_b;"<<std::endl;
    std::cout<<"> assign_b = test_poly_a;"<<std::endl;
    Polynomial assign_b;
    assign_b = test_poly_a;
    std::cout<<"> std::cout<<assign_b"<<std::endl;
    try{std::cout<<"assign_b"<<" = "<<assign_b;}
    catch(std::runtime_error &e){
        std::cerr<<e.what()<<std::endl;
    }

    std::cout<<std::endl;
    std::cout<<"------------Operator+() Test--------------"<<std::endl;
    std::cout<<"> test_poly_a_plus_b_result = test_poly_a+test_poly_b"<<std::endl;
    try {test_poly_a_plus_b_result = test_poly_a + test_poly_b;}
    catch(std::runtime_error &e){
        std::cerr<<e.what()<<std::endl;
    }

    try{std::cout<<test_poly_a_plus_b_result.GetName()<<" = "<<test_poly_a_plus_b_result;}
    catch(std::runtime_error &e){
        std::cerr<<e.what()<<std::endl;
    }

    std::cout<<std::endl;
    std::cout<<"------------Operator-() Test--------------"<<std::endl;
    std::cout<<"> test_poly_a_minus_b_result = test_poly_a-test_poly_b"<<std::endl;
    try {test_poly_a_minus_b_result = test_poly_a - test_poly_b;}
    catch(std::runtime_error &e){
        std::cerr<<e.what()<<std::endl;
    }

    try{std::cout<<test_poly_a_minus_b_result.GetName()<<" = "<<test_poly_a_minus_b_result;}
    catch(std::runtime_error &e){
        std::cerr<<e.what()<<std::endl;
    }

    std::cout<<std::endl;
    std::cout<<"------------Operator*() Test--------------"<<std::endl;
    std::cout<<"> test_poly_a_mul_b_result = test_poly_a*test_poly_b"<<std::endl;
    try {test_poly_a_mul_b_result = test_poly_a * test_poly_b;}
    catch(std::runtime_error &e){
        std::cerr<<e.what()<<std::endl;
    }

    try{std::cout<<test_poly_a_mul_b_result.GetName()<<" = "<<test_poly_a_mul_b_result;}
    catch(std::runtime_error &e){
        std::cerr<<e.what()<<std::endl;
    }

    std::cout<<std::endl;
    std::cout<<"------------Evaluate() Test--------------"<<std::endl;
    try {std::cout<<std::fixed<<std::setw(11)<<std::setprecision(10);
         std::cout<<test_poly_a.GetName()<<"(5)                    = "<<test_poly_a.Evaluate(5)<<std::endl;}
    catch(std::runtime_error &e){
        std::cerr<<e.what()<<std::endl;
    }
    try {std::cout<<test_poly_a.GetName()<<"(3.3)                  = "<<test_poly_a.Evaluate(3.3)<<std::endl;}
    catch(std::runtime_error &e){
        std::cerr<<e.what()<<std::endl;
    }

    try {std::cout<<test_poly_b.GetName()<<"(9)                    = "<<test_poly_b.Evaluate(9)<<std::endl;}
    catch(std::runtime_error &e){
        std::cerr<<e.what()<<std::endl;
    }
    try {std::cout<<test_poly_b.GetName()<<"(2.7)                  = "<<test_poly_b.Evaluate(2.7)<<std::endl;}
    catch(std::runtime_error &e){
        std::cerr<<e.what()<<std::endl;
    }

    try {std::cout<<test_poly_a_plus_b_result.GetName()<<"(5)      = "<<test_poly_a_plus_b_result.Evaluate(5)<<std::endl;}
    catch(std::runtime_error &e){
        std::cerr<<e.what()<<std::endl;
    }
    try {std::cout<<test_poly_a_plus_b_result.GetName()<<"(3.3)    = "<<test_poly_a_plus_b_result.Evaluate(3.3)<<std::endl;}
    catch(std::runtime_error &e){
        std::cerr<<e.what()<<std::endl;
    }

    try {std::cout<<test_poly_a_minus_b_result.GetName()<<"(9)     = "<<test_poly_a_minus_b_result.Evaluate(9)<<std::endl;}
    catch(std::runtime_error &e){
        std::cerr<<e.what()<<std::endl;
    }
    try {std::cout<<test_poly_a_minus_b_result.GetName()<<"(2.7)   = "<<test_poly_a_minus_b_result.Evaluate(2.7)<<std::endl;}
    catch(std::runtime_error &e){
        std::cerr<<e.what()<<std::endl;
    }

    try {std::cout<<test_poly_a_mul_b_result.GetName()<<"(5)       = "<<test_poly_a_mul_b_result.Evaluate(5)<<std::endl;}
    catch(std::runtime_error &e){
        std::cerr<<e.what()<<std::endl;
    }
    try {std::cout<<test_poly_a_mul_b_result.GetName()<<"(3.3)     = "<<test_poly_a_mul_b_result.Evaluate(3.3)<<std::endl;}
    catch(std::runtime_error &e){
        std::cerr<<e.what()<<std::endl;
    }

    return EXIT_SUCCESS;
}
