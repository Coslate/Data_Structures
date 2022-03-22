//main.cpp
#include <iostream>
#include <solution.h>


int main(){
    Polynomial<float, int> test_poly_a(0, 10, "test_poly_a");
    Polynomial<float, int> test_poly_b(0, 10, "test_poly_b");
    Polynomial<float, int> test_poly_a_plus_b_result(0, 10, "test_poly_a_plus_b_result");
    int exp_est;
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
    std::cout<<test_poly_a.GetName()<<" = "<<test_poly_a;
    std::cout<<"test_poly_a.LeadExp() = "<<test_poly_a.LeadExp()<<std::endl;
    std::cout<<test_poly_b.GetName()<<" = "<<test_poly_b;
    std::cout<<"test_poly_b.LeadExp() = "<<test_poly_b.LeadExp()<<std::endl;

    std::cout<<"------------Add Test--------------"<<std::endl;
    test_poly_a_plus_b_result = test_poly_a.Add(test_poly_b);
    std::cout<<test_poly_a_plus_b_result.GetName()<<" = "<<test_poly_a.GetName()<<" + "<<test_poly_b.GetName()<<" = "<<test_poly_a_plus_b_result;
    std::cout<<"test_poly_a_plus_b_result.LeadExp() = "<<test_poly_a_plus_b_result.LeadExp()<<std::endl;
    std::cout<<"------------Coef Test--------------"<<std::endl;
    std::cout<<"First for "<<test_poly_a.GetName()<<std::endl;
    std::cout<<"Please enter n for test_poly_a.Coef(n) : ";
    while(std::cin >> exp_est){
        std::string end_input;
        try {std::cout<<"test_poly_a.Coef("<<exp_est<<") = "<<test_poly_a.Coef(exp_est)<<std::endl;}
        catch(std::runtime_error &e){
            std::cerr<<e.what()<<std::endl;
        }
        std::cout<<"End of the Coef Test[Y/N]? : ";
        std::cin>> end_input;
        if(end_input == "Y" || end_input == "y"){
            break;
        }
        std::cout<<"Please enter n for test_poly_a.Coef(n) : ";
    }

    std::cout<<"Then for "<<test_poly_b.GetName()<<std::endl;
    std::cout<<"Please enter n for test_poly_b.Coef(n) : ";
    while(std::cin >> exp_est){
        std::string end_input;
        try {std::cout<<"test_poly_b.Coef("<<exp_est<<") = "<<test_poly_b.Coef(exp_est)<<std::endl;}
        catch(std::runtime_error &e){
            std::cerr<<e.what()<<std::endl;
        }
        std::cout<<"End of the Coef Test[Y/N]? : ";
        std::cin>> end_input;
        if(end_input == "Y" || end_input == "y"){
            break;
        }
        std::cout<<"Please enter n for test_poly_b.Coef(n) : ";
    }
    std::cout<<"------------Operator! Test--------------"<<std::endl;
    std::cout<<"!"<<test_poly_a.GetName()<<" = "<<(!test_poly_a)<<std::endl;
    std::cout<<"!"<<test_poly_b.GetName()<<" = "<<(!test_poly_b)<<std::endl;

    return EXIT_SUCCESS;
}
