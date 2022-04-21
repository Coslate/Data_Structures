//main.cpp
#include <iostream>
#include <linkedlist.h>


int main(){
    Chain<int> chain_a("chain_a");

    std::cout<<"------------InsertFront() Test--------------"<<std::endl;
    std::cout<<"> chain_a.InsertFront(2)"<<std::endl;
    chain_a.InsertFront(2);
    std::cout<<"> chain_a.InsertFront(4)"<<std::endl;
    chain_a.InsertFront(4);
    std::cout<<"> chain_a.InsertFront(20)"<<std::endl;
    chain_a.InsertFront(20);
    std::cout<<"> chain_a.InsertFront(999)"<<std::endl;
    chain_a.InsertFront(999);
    std::cout<<"> chain_a.InsertFront(38)"<<std::endl;
    chain_a.InsertFront(38);
    std::cout<<"> std::cout<<chain_a"<<std::endl;
    std::cout<<chain_a;

    std::cout<<"------------Front() Test--------------"<<std::endl;
    std::cout<<"> chain_a.Front() = "<<chain_a.Front()<<std::endl;

    std::cout<<"------------DeleteFront() Test--------------"<<std::endl;
    std::cout<<"> chain_a.DeleteFront()"<<std::endl;
    chain_a.DeleteFront();
    std::cout<<"> chain_a.DeleteFront()"<<std::endl;
    chain_a.DeleteFront();
    std::cout<<"> chain_a.DeleteFront()"<<std::endl;
    chain_a.DeleteFront();
    std::cout<<"> std::cout<<chain_a"<<std::endl;
    std::cout<<chain_a;
    std::cout<<"> chain_a.DeleteFront()"<<std::endl;
    chain_a.DeleteFront();
    std::cout<<"> chain_a.DeleteFront()"<<std::endl;
    chain_a.DeleteFront();
    std::cout<<"> std::cout<<chain_a"<<std::endl;
    try{std::cout<<chain_a;}
    catch(std::runtime_error &e){
        std::cerr<<e.what()<<std::endl;
    }

    std::cout<<"------------Back() Test--------------"<<std::endl;
    std::cout<<"> chain_a.InsertFront(111)"<<std::endl;
    chain_a.InsertFront(111);
    std::cout<<"> chain_a.InsertFront(222)"<<std::endl;
    chain_a.InsertFront(222);
    std::cout<<"> chain_a.Back() = "<<chain_a.Back()<<std::endl;
    std::cout<<"> std::cout<<chain_a"<<std::endl;
    std::cout<<chain_a;

    std::cout<<"------------Get() Test--------------"<<std::endl;
    std::cout<<"> chain_a.InsertFront(32)"<<std::endl;
    chain_a.InsertFront(32);
    std::cout<<"> chain_a.InsertFront(34)"<<std::endl;
    chain_a.InsertFront(34);
    std::cout<<"> std::cout<<chain_a"<<std::endl;
    std::cout<<chain_a;
    std::cout<<"> chain_a.Get(1) = "<<chain_a.Get(1)<<std::endl;
    std::cout<<"> chain_a.Get(2) = "<<chain_a.Get(2)<<std::endl;
    std::cout<<"> chain_a.Get(3) = "<<chain_a.Get(3)<<std::endl;
    std::cout<<"> chain_a.Get(4) = "<<chain_a.Get(4)<<std::endl;
    try{std::cout<<"> chain_a.Get(5) = "<<chain_a.Get(5)<<std::endl;}
    catch(std::runtime_error &e){
        std::cerr<<e.what()<<std::endl;
    }


    return EXIT_SUCCESS;
}
