//main.cpp
#include <iostream>
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


    /*
    std::cout<<"---------------------------------------------------------------------------"<<std::endl;
    std::cout<<"-------------CircularLinkedList with Dummy Header Node Test----------------"<<std::endl;
    std::cout<<"---------------------------------------------------------------------------"<<std::endl;
    std::cout<<std::endl;

    CircularHeaderList<Term> circular_header_list_a("circular_header_list_a");
    CircularHeaderList<Term> circular_header_list_b("circular_header_list_b");
    CircularHeaderList<Term> circular_header_list_c("circular_header_list_c");

    std::cout<<"------------NumOfNodes() Test--------------"<<std::endl;
    std::cout<<"> circular_header_list_a.NumOfNodes() = "<<circular_header_list_a.NumOfNodes()<<std::endl;
    std::cout<<"> circular_header_list_a.InsertFront(Term(77, 9))"<<std::endl;
    Term a(77, 9);
    circular_header_list_a.InsertFront(a);
    std::cout<<"> std::cout<<circular_header_list_a"<<std::endl;
    std::cout<<circular_header_list_a;
    std::cout<<"> circular_header_list_a.NumOfNodes() = "<<circular_header_list_a.NumOfNodes()<<std::endl;
    Term b(78, 8);
    std::cout<<"> circular_header_list_a.InsertFront(Term(78, 8))"<<std::endl;
    circular_header_list_a.InsertFront(b);
    std::cout<<"> std::cout<<circular_header_list_a"<<std::endl;
    std::cout<<circular_header_list_a;
    std::cout<<"> circular_header_list_a.NumOfNodes() = "<<circular_header_list_a.NumOfNodes()<<std::endl;

    std::cout<<std::endl;
    std::cout<<"------------InsertFront() Test--------------"<<std::endl;
    std::cout<<"> circular_header_list_a.InsertFront(Term(2, 7))"<<std::endl;
    Term c(2, 7);
    circular_header_list_a.InsertFront(c);
    Term d(4, 6);
    std::cout<<"> circular_header_list_a.InsertFront(Term(4, 6))"<<std::endl;
    circular_header_list_a.InsertFront(d);
    Term e(20, 5);
    std::cout<<"> circular_header_list_a.InsertFront(Term(20, 5))"<<std::endl;
    circular_header_list_a.InsertFront(e);
    Term f(999, 4);
    std::cout<<"> circular_header_list_a.InsertFront(Term(999, 4))"<<std::endl;
    circular_header_list_a.InsertFront(f);
    Term g(38, 3);
    std::cout<<"> circular_header_list_a.InsertFront(Term(38, 3))"<<std::endl;
    circular_header_list_a.InsertFront(g);
    std::cout<<"> std::cout<<circular_header_list_a"<<std::endl;
    std::cout<<circular_header_list_a;

    std::cout<<std::endl;
    std::cout<<"------------InsertBack() Test--------------"<<std::endl;
    Term h(12, 2);
    std::cout<<"> circular_header_list_a.InsertBack(Term(12, 2))"<<std::endl;
    circular_header_list_a.InsertBack(h);
    Term i(14, 1);
    std::cout<<"> circular_header_list_a.InsertBack(Term(14, 1))"<<std::endl;
    circular_header_list_a.InsertBack(i);
    Term j(120, 10);
    std::cout<<"> circular_header_list_a.InsertBack(Term(120, 10))"<<std::endl;
    circular_header_list_a.InsertBack(j);
    std::cout<<"> std::cout<<circular_header_list_a"<<std::endl;
    std::cout<<circular_header_list_a;

    std::cout<<std::endl;
    std::cout<<"------------DeleteFirst() Test--------------"<<std::endl;
    std::cout<<"> circular_header_list_a.DeleteFirst()"<<std::endl;
    circular_header_list_a.DeleteFirst();
    std::cout<<"> circular_header_list_a.DeleteFirst()"<<std::endl;
    circular_header_list_a.DeleteFirst();
    std::cout<<"> circular_header_list_a.DeleteFirst()"<<std::endl;
    circular_header_list_a.DeleteFirst();
    std::cout<<"> std::cout<<circular_header_list_a"<<std::endl;
    std::cout<<circular_header_list_a;

    std::cout<<std::endl;
    std::cout<<"------------DeleteLast() Test--------------"<<std::endl;
    std::cout<<"> circular_header_list_a.DeleteLast()"<<std::endl;
    circular_header_list_a.DeleteLast();
    std::cout<<"> circular_header_list_a.DeleteLast()"<<std::endl;
    circular_header_list_a.DeleteLast();
    std::cout<<"> circular_header_list_a.DeleteLast()"<<std::endl;
    circular_header_list_a.DeleteLast();
    std::cout<<"> std::cout<<circular_header_list_a"<<std::endl;
    std::cout<<circular_header_list_a;
    */

    return EXIT_SUCCESS;
}
