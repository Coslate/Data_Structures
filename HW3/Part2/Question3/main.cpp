//main.cpp
#include <iostream>
#include <list.h>


int main(){
    List<int> list_a("list_a");
    List<int> list_b("list_b");
    List<int> list_c("list_c");
    List<int> list_d("list_d");
    List<int> list_e("list_e");

    std::cout<<"------------InsertFront() Test--------------"<<std::endl;
    std::cout<<"> list_a.InsertFront(2)"<<std::endl;
    list_a.InsertFront(2);
    std::cout<<"> list_a.InsertFront(4)"<<std::endl;
    list_a.InsertFront(4);
    std::cout<<"> list_a.InsertFront(20)"<<std::endl;
    list_a.InsertFront(20);
    std::cout<<"> list_a.InsertFront(999)"<<std::endl;
    list_a.InsertFront(999);
    std::cout<<"> list_a.InsertFront(38)"<<std::endl;
    list_a.InsertFront(38);
    std::cout<<"> std::cout<<list_a"<<std::endl;
    std::cout<<list_a;
    std::cout<<"list_a.NumOfNodes() = "<<list_a.NumOfNodes()<<std::endl;

    std::cout<<std::endl;
    std::cout<<"------------Front() Test--------------"<<std::endl;
    std::cout<<"> list_a.Front() = "<<list_a.Front()<<std::endl;

    std::cout<<std::endl;
    std::cout<<"------------DeleteFront() Test--------------"<<std::endl;
    std::cout<<"> list_a.DeleteFront()"<<std::endl;
    list_a.DeleteFront();
    std::cout<<"> list_a.DeleteFront()"<<std::endl;
    list_a.DeleteFront();
    std::cout<<"> list_a.DeleteFront()"<<std::endl;
    list_a.DeleteFront();
    std::cout<<"> std::cout<<list_a"<<std::endl;
    std::cout<<list_a;
    std::cout<<"list_a.NumOfNodes() = "<<list_a.NumOfNodes()<<std::endl;
    std::cout<<"> list_a.DeleteFront()"<<std::endl;
    list_a.DeleteFront();
    std::cout<<"> list_a.DeleteFront()"<<std::endl;
    list_a.DeleteFront();
    std::cout<<"> std::cout<<list_a"<<std::endl;
    try{std::cout<<list_a;}
    catch(std::runtime_error &e){
        std::cerr<<e.what()<<std::endl;
    }
    std::cout<<"list_a.NumOfNodes() = "<<list_a.NumOfNodes()<<std::endl;

    std::cout<<std::endl;
    std::cout<<"------------Back() Test--------------"<<std::endl;
    std::cout<<"> list_a.InsertFront(111)"<<std::endl;
    list_a.InsertFront(111);
    std::cout<<"> list_a.InsertFront(222)"<<std::endl;
    list_a.InsertFront(222);
    std::cout<<"> list_a.Back() = "<<list_a.Back()<<std::endl;
    std::cout<<"> std::cout<<list_a"<<std::endl;
    std::cout<<list_a;
    std::cout<<"list_a.NumOfNodes() = "<<list_a.NumOfNodes()<<std::endl;

    std::cout<<std::endl;
    std::cout<<"------------Get(i) Test--------------"<<std::endl;
    std::cout<<"> list_a.InsertFront(32)"<<std::endl;
    list_a.InsertFront(32);
    std::cout<<"> list_a.InsertFront(34)"<<std::endl;
    list_a.InsertFront(34);
    std::cout<<"> std::cout<<list_a"<<std::endl;
    std::cout<<list_a;
    std::cout<<"list_a.NumOfNodes() = "<<list_a.NumOfNodes()<<std::endl;
    std::cout<<"> list_a.Get(1) = "<<&list_a.Get(1)<<std::endl;
    std::cout<<"> list_a.Get(2) = "<<&list_a.Get(2)<<std::endl;
    std::cout<<"> list_a.Get(3) = "<<&list_a.Get(3)<<std::endl;
    std::cout<<"> list_a.Get(4) = "<<&list_a.Get(4)<<std::endl;
    try{std::cout<<"> list_a.Get(5) = "<<&list_a.Get(5)<<std::endl;}
    catch(std::runtime_error &e){
        std::cerr<<e.what()<<std::endl;
    }

    std::cout<<std::endl;
    std::cout<<"------------Delete(i) Test--------------"<<std::endl;
    std::cout<<"> list_a.Delete(1)"<<std::endl;
    list_a.Delete(1);
    std::cout<<"> std::cout<<list_a"<<std::endl;
    std::cout<<list_a;
    std::cout<<"> list_a.Delete(2)"<<std::endl;
    list_a.Delete(2);
    std::cout<<"> std::cout<<list_a"<<std::endl;
    std::cout<<list_a;
    std::cout<<"> list_a.Delete(4)"<<std::endl;
    try{list_a.Delete(4);}
    catch(std::runtime_error &e){
        std::cerr<<e.what()<<std::endl;
    }
    std::cout<<"list_a.NumOfNodes() = "<<list_a.NumOfNodes()<<std::endl;

    std::cout<<std::endl;
    std::cout<<"------------Insert(i, e) Test--------------"<<std::endl;
    std::cout<<"> list_a.Insert(2, 100)"<<std::endl;
    list_a.Insert(2, 100);
    std::cout<<"> std::cout<<list_a"<<std::endl;
    std::cout<<list_a;
    std::cout<<"> list_a.Insert(4, 200)"<<std::endl;
    list_a.Insert(4, 200);
    std::cout<<"> std::cout<<list_a"<<std::endl;
    std::cout<<list_a;
    std::cout<<"> list_a.Insert(6, 700)"<<std::endl;
    try{list_a.Insert(6, 700);}
    catch(std::runtime_error &e){
        std::cerr<<e.what()<<std::endl;
    }
    std::cout<<"list_a.NumOfNodes() = "<<list_a.NumOfNodes()<<std::endl;

    std::cout<<std::endl;
    std::cout<<"------------InsertBack() Test--------------"<<std::endl;
    std::cout<<"> list_a.InsertBack(555)"<<std::endl;
    list_a.InsertBack(555);
    std::cout<<"> list_a.InsertBack(666)"<<std::endl;
    list_a.InsertBack(666);
    std::cout<<"> list_a.InsertBack(777)"<<std::endl;
    list_a.InsertBack(777);
    std::cout<<"> list_a.InsertBack(888)"<<std::endl;
    list_a.InsertBack(888);
    std::cout<<"> std::cout<<list_a"<<std::endl;
    std::cout<<list_a;
    std::cout<<"list_a.NumOfNodes() = "<<list_a.NumOfNodes()<<std::endl;

    std::cout<<std::endl;
    std::cout<<"------------Concatenate() Test--------------"<<std::endl;
    std::cout<<"> std::cout<<list_b"<<std::endl;
    try{std::cout<<list_b;}
    catch(std::runtime_error &e){
        std::cerr<<e.what()<<std::endl;
    }
    std::cout<<"> list_b.InsertBack(99)"<<std::endl;
    list_b.InsertBack(99);
    std::cout<<"> list_b.InsertBack(98)"<<std::endl;
    list_b.InsertBack(98);
    std::cout<<"> list_b.InsertBack(97)"<<std::endl;
    list_b.InsertBack(97);
    std::cout<<"> list_b.InsertBack(96)"<<std::endl;
    list_b.InsertBack(96);
    std::cout<<"> std::cout<<list_b"<<std::endl;
    std::cout<<list_b;
    std::cout<<"> std::cout<<list_a"<<std::endl;
    std::cout<<list_a;
    std::cout<<"> list_b.Concatenate(list_a)"<<std::endl;
    list_b.Concatenate(list_a);
    std::cout<<"> std::cout<<list_b"<<std::endl;
    std::cout<<list_b;
    std::cout<<"> std::cout<<list_a"<<std::endl;
    try{std::cout<<list_a;}
    catch(std::runtime_error &e){
        std::cerr<<e.what()<<std::endl;
    }
    std::cout<<"> list_a.Concatenate(list_b)"<<std::endl;
    list_a.Concatenate(list_b);
    std::cout<<"> std::cout<<list_a"<<std::endl;
    std::cout<<list_a;
    std::cout<<"> std::cout<<list_b"<<std::endl;
    try{std::cout<<list_b;}
    catch(std::runtime_error &e){
        std::cerr<<e.what()<<std::endl;
    }

    std::cout<<std::endl;
    std::cout<<"------------Reverse() Test--------------"<<std::endl;
    std::cout<<"> std::cout<<list_a"<<std::endl;
    std::cout<<list_a;
    std::cout<<"> list_a.Reverse()"<<std::endl;
    list_a.Reverse();
    std::cout<<"> std::cout<<list_a"<<std::endl;
    std::cout<<list_a;

    return EXIT_SUCCESS;
}
