//main.cpp
#include <iostream>
#include <solution.h>


int main(){
    SparseMatrix<int> test_sparse_matrix_a(6, 6, 0, 10, "test_sparse_matrix_a");
    SparseMatrix<int> test_sparse_matrix_b(6, 6, 0, 10, "test_sparse_matrix_b");
    SparseMatrix<int> test_sparse_matrix_a_trans_result (6, 6, 0, 10, "test_sparse_matrix_a_trans_result");
    SparseMatrix<int> test_sparse_matrix_b_trans_result (6, 6, 0, 10, "test_sparse_matrix_b_trans_result");
    SparseMatrix<int> test_sparse_matrix_a_add_b_result (6, 6, 0, 10, "test_sparse_matrix_a_add_b_result");
    SparseMatrix<int> test_sparse_matrix_a_mul_b_result (6, 6, 0, 10, "test_sparse_matrix_a_mul_b_result");
    std::string skip;


    std::cout<<"Please enter the terms in"<<test_sparse_matrix_a.GetName()<<std::endl;
    std::cout<<"If want to SKIP[Y/N]? : ";
    std::cin >> skip;
    if(skip != "Y" && skip != "y"){
        while(std::cin >> test_sparse_matrix_a){
            std::string end_input;

            try{std::cout<<test_sparse_matrix_a.GetName()<<" = "<<test_sparse_matrix_a;}
            catch(std::runtime_error &e){std::cerr<<e.what()<<std::endl;}

            std::cout<<"End of the input[Y/N]? : ";
            std::cin>> end_input;
            if(end_input == "Y" || end_input == "y"){
                break;
            }
        }
    }

    std::cout<<"Please enter the terms in"<<test_sparse_matrix_b.GetName()<<std::endl;
    std::cout<<"If want to SKIP[Y/N]? : ";
    std::cin >> skip;
    if(skip != "Y" && skip != "y"){
        while(std::cin >> test_sparse_matrix_b){
            std::string end_input;

            try{std::cout<<test_sparse_matrix_b.GetName()<<" = "<<test_sparse_matrix_b;}
            catch(std::runtime_error &e){std::cerr<<e.what()<<std::endl;}

            std::cout<<"End of the input[Y/N]? : ";
            std::cin>> end_input;
            if(end_input == "Y" || end_input == "y"){
                break;
            }
        }
    }

    std::cout<<std::endl;
    std::cout<<"You just entered:"<<std::endl;
    try{std::cout<<test_sparse_matrix_a.GetName()<<" = "<<test_sparse_matrix_a;}
    catch(std::runtime_error &e){
        std::cerr<<e.what()<<std::endl;
    }

    try{std::cout<<test_sparse_matrix_b.GetName()<<" = "<<test_sparse_matrix_b;}
    catch(std::runtime_error &e){
        std::cerr<<e.what()<<std::endl;
    }

    std::cout<<"------------Transpose() Test--------------"<<std::endl;
    test_sparse_matrix_a_trans_result = test_sparse_matrix_a.Transpose();
    try{std::cout<<test_sparse_matrix_a.GetName()<<".Transpos() = "<<test_sparse_matrix_a_trans_result;}
    catch(std::runtime_error &e){
        std::cerr<<e.what()<<std::endl;
    }
    test_sparse_matrix_b_trans_result = test_sparse_matrix_b.Transpose();
    try{std::cout<<test_sparse_matrix_b.GetName()<<".Transpos() = "<<test_sparse_matrix_b_trans_result;}
    catch(std::runtime_error &e){
        std::cerr<<e.what()<<std::endl;
    }

    std::cout<<"------------Add() Test--------------"<<std::endl;
//    test_sparse_matrix_a.SortAccordingToRow();
//    try{std::cout<<"After sorting by row: test_sparse_matrix_a = "<<test_sparse_matrix_a;}
    test_sparse_matrix_a.SortAll();
    try{std::cout<<"After sorting by all: test_sparse_matrix_a = "<<test_sparse_matrix_a;}
    catch(std::runtime_error &e){
        std::cerr<<e.what()<<std::endl;
    }
//    test_sparse_matrix_b.SortAccordingToRow();
//    try{std::cout<<"After sorting by row: test_sparse_matrix_b = "<<test_sparse_matrix_b;}
    test_sparse_matrix_b.SortAll();
    try{std::cout<<"After sorting by all: test_sparse_matrix_b = "<<test_sparse_matrix_b;}
    catch(std::runtime_error &e){
        std::cerr<<e.what()<<std::endl;
    }
    test_sparse_matrix_a_add_b_result = test_sparse_matrix_a.Add(test_sparse_matrix_b);
    try{std::cout<<"test_sparse_matrix_a + test_sparse_matrix_b = "<<test_sparse_matrix_a_add_b_result<<std::endl;}
    catch(std::runtime_error &e){
        std::cerr<<e.what()<<std::endl;
    }

    std::cout<<"------------Mul() Test--------------"<<std::endl;


    return EXIT_SUCCESS;
}
