//main.cpp
#include <iostream>
#include <circular_headerlist.h>
#include <solution.h>


int main(){
    std::cout<<std::endl;
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


    return EXIT_SUCCESS;
}
