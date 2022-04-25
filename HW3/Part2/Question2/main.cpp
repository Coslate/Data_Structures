//main.cpp
#include <iostream>
#include <circular_linkedlist.h>
#include <circular_headerlist.h>


int main(){
    CircularList<int> circular_list_a("circular_list_a");
    CircularList<int> circular_list_b("circular_list_b");
    CircularList<int> circular_list_c("circular_list_c");

    std::cout<<"------------NumOfNodes() Test--------------"<<std::endl;
    std::cout<<"> circular_list_a.NumOfNodes() = "<<circular_list_a.NumOfNodes()<<std::endl;
    std::cout<<"> circular_list_a.InsertFront(77)"<<std::endl;
    circular_list_a.InsertFront(77);
    std::cout<<"> std::cout<<circular_list_a"<<std::endl;
    std::cout<<circular_list_a;
    std::cout<<"> circular_list_a.NumOfNodes() = "<<circular_list_a.NumOfNodes()<<std::endl;
    std::cout<<"> circular_list_a.InsertFront(78)"<<std::endl;
    circular_list_a.InsertFront(78);
    std::cout<<"> std::cout<<circular_list_a"<<std::endl;
    std::cout<<circular_list_a;
    std::cout<<"> circular_list_a.NumOfNodes() = "<<circular_list_a.NumOfNodes()<<std::endl;

    std::cout<<std::endl;
    std::cout<<"------------InsertFront() Test--------------"<<std::endl;
    std::cout<<"> circular_list_a.InsertFront(2)"<<std::endl;
    circular_list_a.InsertFront(2);
    std::cout<<"> circular_list_a.InsertFront(4)"<<std::endl;
    circular_list_a.InsertFront(4);
    std::cout<<"> circular_list_a.InsertFront(20)"<<std::endl;
    circular_list_a.InsertFront(20);
    std::cout<<"> circular_list_a.InsertFront(999)"<<std::endl;
    circular_list_a.InsertFront(999);
    std::cout<<"> circular_list_a.InsertFront(38)"<<std::endl;
    circular_list_a.InsertFront(38);
    std::cout<<"> std::cout<<circular_list_a"<<std::endl;
    std::cout<<circular_list_a;

    std::cout<<std::endl;
    std::cout<<"------------InsertBack() Test--------------"<<std::endl;
    std::cout<<"> circular_list_a.InsertBack(12)"<<std::endl;
    circular_list_a.InsertBack(12);
    std::cout<<"> circular_list_a.InsertBack(14)"<<std::endl;
    circular_list_a.InsertBack(14);
    std::cout<<"> circular_list_a.InsertBack(120)"<<std::endl;
    circular_list_a.InsertBack(120);
    std::cout<<"> std::cout<<circular_list_a"<<std::endl;
    std::cout<<circular_list_a;

    std::cout<<std::endl;
    std::cout<<"------------DeleteFirst() Test--------------"<<std::endl;
    std::cout<<"> circular_list_a.DeleteFirst()"<<std::endl;
    circular_list_a.DeleteFirst();
    std::cout<<"> circular_list_a.DeleteFirst()"<<std::endl;
    circular_list_a.DeleteFirst();
    std::cout<<"> circular_list_a.DeleteFirst()"<<std::endl;
    circular_list_a.DeleteFirst();
    std::cout<<"> std::cout<<circular_list_a"<<std::endl;
    std::cout<<circular_list_a;

    std::cout<<std::endl;
    std::cout<<"------------DeleteLast() Test--------------"<<std::endl;
    std::cout<<"> circular_list_a.DeleteLast()"<<std::endl;
    circular_list_a.DeleteLast();
    std::cout<<"> circular_list_a.DeleteLast()"<<std::endl;
    circular_list_a.DeleteLast();
    std::cout<<"> circular_list_a.DeleteLast()"<<std::endl;
    circular_list_a.DeleteLast();
    std::cout<<"> std::cout<<circular_list_a"<<std::endl;
    std::cout<<circular_list_a;

    std::cout<<std::endl;
    std::cout<<"------------DeleteEveryOtherNode() Test--------------"<<std::endl;
    std::cout<<"> circular_list_a.InsertBack(223)"<<std::endl;
    circular_list_a.InsertBack(223);
    std::cout<<"> circular_list_a.InsertBack(224)"<<std::endl;
    circular_list_a.InsertBack(224);
    std::cout<<"> circular_list_a.InsertBack(225)"<<std::endl;
    circular_list_a.InsertBack(225);
    std::cout<<"> circular_list_a.InsertFront(66)"<<std::endl;
    circular_list_a.InsertFront(66);
    std::cout<<"> circular_list_a.InsertFront(67)"<<std::endl;
    circular_list_a.InsertFront(67);
    std::cout<<"> circular_list_a.InsertFront(68)"<<std::endl;
    circular_list_a.InsertFront(68);
    std::cout<<"> std::cout<<circular_list_a"<<std::endl;
    std::cout<<circular_list_a;
    std::cout<<"> circular_list_a.DeleteEveryOtherNode()"<<std::endl;
    circular_list_a.DeleteEveryOtherNode();
    std::cout<<"> std::cout<<circular_list_a"<<std::endl;
    std::cout<<circular_list_a;

    std::cout<<std::endl;
    std::cout<<"------------Deconcatenate() Test--------------"<<std::endl;
    std::cout<<"> circular_list_a.InsertBack(56)"<<std::endl;
    circular_list_a.InsertBack(56);
    std::cout<<"> circular_list_a.InsertBack(57)"<<std::endl;
    circular_list_a.InsertBack(57);
    std::cout<<"> circular_list_a.InsertBack(58)"<<std::endl;
    circular_list_a.InsertBack(58);
    std::cout<<"> circular_list_a.InsertFront(43)"<<std::endl;
    circular_list_a.InsertFront(43);
    std::cout<<"> circular_list_a.InsertFront(44)"<<std::endl;
    circular_list_a.InsertFront(44);
    std::cout<<"> circular_list_a.InsertFront(45)"<<std::endl;
    circular_list_a.InsertFront(45);
    std::cout<<"> std::cout<<circular_list_a"<<std::endl;
    std::cout<<circular_list_a;
    std::cout<<"> We get the address of the 4th node in circular_list_a and stored in split_node4:"<<std::endl;
    std::cout<<"> split_node4 = circular_list_a.GetNode(4)"<<std::endl;
    CircularListNode<int> *split_node4 = circular_list_a.GetNode(4);
    std::cout<<"> circular_list_a.Deconcatenate(split_node4, circular_list_b)"<<std::endl;
    circular_list_a.Deconcatenate(split_node4, circular_list_b);
    std::cout<<"> std::cout<<circular_list_a"<<std::endl;
    std::cout<<circular_list_a;
    std::cout<<"> std::cout<<circular_list_b"<<std::endl;
    std::cout<<circular_list_b;

    std::cout<<std::endl;
    std::cout<<"------------Merge() Test--------------"<<std::endl;
    std::cout<<"> std::cout<<circular_list_b"<<std::endl;
    std::cout<<circular_list_b;
    std::cout<<"> circular_list_c.InsertFront(2)"<<std::endl;
    circular_list_c.InsertFront(2);
    std::cout<<"> circular_list_c.InsertFront(4)"<<std::endl;
    circular_list_c.InsertFront(4);
    std::cout<<"> circular_list_c.InsertFront(20)"<<std::endl;
    circular_list_c.InsertFront(20);
    std::cout<<"> circular_list_c.InsertFront(999)"<<std::endl;
    circular_list_c.InsertFront(999);
    std::cout<<"> circular_list_c.InsertFront(38)"<<std::endl;
    circular_list_c.InsertFront(38);
    std::cout<<"> std::cout<<circular_list_c"<<std::endl;
    std::cout<<circular_list_c;
    std::cout<<"> circular_list_a.Merge(circular_list_b, circular_list_c);"<<std::endl;
    circular_list_a.Merge(circular_list_b, circular_list_c);
    std::cout<<"> std::cout<<circular_list_a"<<std::endl;
    std::cout<<circular_list_a;

    std::cout<<std::endl;
    std::cout<<"---------------------------------------------------------------------------"<<std::endl;
    std::cout<<"-------------CircularLinkedList with Dummy Header Node Test----------------"<<std::endl;
    std::cout<<"---------------------------------------------------------------------------"<<std::endl;
    std::cout<<std::endl;

    CircularHeaderList<int> circular_header_list_a("circular_header_list_a");
    CircularHeaderList<int> circular_header_list_b("circular_header_list_b");
    CircularHeaderList<int> circular_header_list_c("circular_header_list_c");

    std::cout<<"------------NumOfNodes() Test--------------"<<std::endl;
    std::cout<<"> circular_header_list_a.NumOfNodes() = "<<circular_header_list_a.NumOfNodes()<<std::endl;
    std::cout<<"> circular_header_list_a.InsertFront(77)"<<std::endl;
    circular_header_list_a.InsertFront(77);
    std::cout<<"> std::cout<<circular_header_list_a"<<std::endl;
    std::cout<<circular_header_list_a;
    std::cout<<"> circular_header_list_a.NumOfNodes() = "<<circular_header_list_a.NumOfNodes()<<std::endl;
    std::cout<<"> circular_header_list_a.InsertFront(78)"<<std::endl;
    circular_header_list_a.InsertFront(78);
    std::cout<<"> std::cout<<circular_header_list_a"<<std::endl;
    std::cout<<circular_header_list_a;
    std::cout<<"> circular_header_list_a.NumOfNodes() = "<<circular_header_list_a.NumOfNodes()<<std::endl;

    std::cout<<std::endl;
    std::cout<<"------------InsertFront() Test--------------"<<std::endl;
    std::cout<<"> circular_header_list_a.InsertFront(2)"<<std::endl;
    circular_header_list_a.InsertFront(2);
    std::cout<<"> circular_header_list_a.InsertFront(4)"<<std::endl;
    circular_header_list_a.InsertFront(4);
    std::cout<<"> circular_header_list_a.InsertFront(20)"<<std::endl;
    circular_header_list_a.InsertFront(20);
    std::cout<<"> circular_header_list_a.InsertFront(999)"<<std::endl;
    circular_header_list_a.InsertFront(999);
    std::cout<<"> circular_header_list_a.InsertFront(38)"<<std::endl;
    circular_header_list_a.InsertFront(38);
    std::cout<<"> std::cout<<circular_header_list_a"<<std::endl;
    std::cout<<circular_header_list_a;

    std::cout<<std::endl;
    std::cout<<"------------InsertBack() Test--------------"<<std::endl;
    std::cout<<"> circular_header_list_a.InsertBack(12)"<<std::endl;
    circular_header_list_a.InsertBack(12);
    std::cout<<"> circular_header_list_a.InsertBack(14)"<<std::endl;
    circular_header_list_a.InsertBack(14);
    std::cout<<"> circular_header_list_a.InsertBack(120)"<<std::endl;
    circular_header_list_a.InsertBack(120);
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

    std::cout<<std::endl;
    std::cout<<"------------DeleteEveryOtherNode() Test--------------"<<std::endl;
    std::cout<<"> circular_header_list_a.InsertBack(100)"<<std::endl;
    circular_header_list_a.InsertBack(100);
    std::cout<<"> circular_header_list_a.InsertBack(200)"<<std::endl;
    circular_header_list_a.InsertBack(200);
    std::cout<<"> circular_header_list_a.InsertBack(300)"<<std::endl;
    circular_header_list_a.InsertBack(300);
    std::cout<<"> circular_header_list_a.InsertFront(50)"<<std::endl;
    circular_header_list_a.InsertFront(50);
    std::cout<<"> circular_header_list_a.InsertFront(51)"<<std::endl;
    circular_header_list_a.InsertFront(51);
    std::cout<<"> circular_header_list_a.InsertFront(52)"<<std::endl;
    circular_header_list_a.InsertFront(52);
    std::cout<<"> std::cout<<circular_header_list_a"<<std::endl;
    std::cout<<circular_header_list_a;
    std::cout<<"> circular_header_list_a.DeleteEveryOtherNode()"<<std::endl;
    circular_header_list_a.DeleteEveryOtherNode();
    std::cout<<"> std::cout<<circular_header_list_a"<<std::endl;
    std::cout<<circular_header_list_a;

    std::cout<<std::endl;
    std::cout<<"------------Deconcatenate() Test--------------"<<std::endl;
    std::cout<<"> circular_header_list_a.InsertBack(56)"<<std::endl;
    circular_header_list_a.InsertBack(56);
    std::cout<<"> circular_header_list_a.InsertBack(57)"<<std::endl;
    circular_header_list_a.InsertBack(57);
    std::cout<<"> circular_header_list_a.InsertBack(58)"<<std::endl;
    circular_header_list_a.InsertBack(58);
    std::cout<<"> circular_header_list_a.InsertFront(43)"<<std::endl;
    circular_header_list_a.InsertFront(43);
    std::cout<<"> circular_header_list_a.InsertFront(44)"<<std::endl;
    circular_header_list_a.InsertFront(44);
    std::cout<<"> circular_header_list_a.InsertFront(45)"<<std::endl;
    circular_header_list_a.InsertFront(45);
    std::cout<<"> std::cout<<circular_header_list_a"<<std::endl;
    std::cout<<circular_header_list_a;
    std::cout<<"> We get the address of the 5th node in circular_header_list_a and stored in split_node5:"<<std::endl;
    std::cout<<"> split_node5 = circular_header_list_a.GetNode(5)"<<std::endl;
    CircularHeaderListNode<int> *split_node5 = circular_header_list_a.GetNode(5);
    std::cout<<"> circular_header_list_a.Deconcatenate(split_node5, circular_header_list_b)"<<std::endl;
    circular_header_list_a.Deconcatenate(split_node5, circular_header_list_b);
    std::cout<<"> std::cout<<circular_header_list_a"<<std::endl;
    std::cout<<circular_header_list_a;
    std::cout<<"> std::cout<<circular_header_list_b"<<std::endl;
    std::cout<<circular_header_list_b;

    std::cout<<std::endl;
    std::cout<<"------------Merge() Test--------------"<<std::endl;
    std::cout<<"> std::cout<<circular_header_list_b"<<std::endl;
    std::cout<<circular_header_list_b;
    std::cout<<"> circular_header_list_c.InsertFront(2)"<<std::endl;
    circular_header_list_c.InsertFront(2);
    std::cout<<"> circular_header_list_c.InsertFront(4)"<<std::endl;
    circular_header_list_c.InsertFront(4);
    std::cout<<"> circular_header_list_c.InsertFront(20)"<<std::endl;
    circular_header_list_c.InsertFront(20);
    std::cout<<"> circular_header_list_c.InsertFront(999)"<<std::endl;
    circular_header_list_c.InsertFront(999);
    std::cout<<"> circular_header_list_c.InsertFront(38)"<<std::endl;
    circular_header_list_c.InsertFront(38);
    std::cout<<"> std::cout<<circular_header_list_c"<<std::endl;
    std::cout<<circular_header_list_c;
    std::cout<<"> circular_header_list_a.Merge(circular_header_list_b, circular_header_list_c);"<<std::endl;
    circular_header_list_a.Merge(circular_header_list_b, circular_header_list_c);
    std::cout<<"> std::cout<<circular_header_list_a"<<std::endl;
    std::cout<<circular_header_list_a;


    return EXIT_SUCCESS;
}
