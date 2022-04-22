//main.cpp
#include <iostream>
#include <linkedlist.h>


int main(){
    Chain<int> chain_a("chain_a");
    Chain<int> chain_b("chain_b");
    Chain<int> chain_c("chain_c");
    Chain<int> chain_d("chain_d");
    Chain<int> chain_e("chain_e");

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

    std::cout<<std::endl;
    std::cout<<"------------Front() Test--------------"<<std::endl;
    std::cout<<"> chain_a.Front() = "<<chain_a.Front()<<std::endl;

    std::cout<<std::endl;
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

    std::cout<<std::endl;
    std::cout<<"------------Back() Test--------------"<<std::endl;
    std::cout<<"> chain_a.InsertFront(111)"<<std::endl;
    chain_a.InsertFront(111);
    std::cout<<"> chain_a.InsertFront(222)"<<std::endl;
    chain_a.InsertFront(222);
    std::cout<<"> chain_a.Back() = "<<chain_a.Back()<<std::endl;
    std::cout<<"> std::cout<<chain_a"<<std::endl;
    std::cout<<chain_a;

    std::cout<<std::endl;
    std::cout<<"------------Get(i) Test--------------"<<std::endl;
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

    std::cout<<std::endl;
    std::cout<<"------------Delete(i) Test--------------"<<std::endl;
    std::cout<<"> chain_a.Delete(1)"<<std::endl;
    chain_a.Delete(1);
    std::cout<<"> std::cout<<chain_a"<<std::endl;
    std::cout<<chain_a;
    std::cout<<"> chain_a.Delete(2)"<<std::endl;
    chain_a.Delete(2);
    std::cout<<"> std::cout<<chain_a"<<std::endl;
    std::cout<<chain_a;
    std::cout<<"> chain_a.Delete(4)"<<std::endl;
    try{chain_a.Delete(4);}
    catch(std::runtime_error &e){
        std::cerr<<e.what()<<std::endl;
    }

    std::cout<<std::endl;
    std::cout<<"------------Insert(i, e) Test--------------"<<std::endl;
    std::cout<<"> chain_a.Insert(2, 100)"<<std::endl;
    chain_a.Insert(2, 100);
    std::cout<<"> std::cout<<chain_a"<<std::endl;
    std::cout<<chain_a;
    std::cout<<"> chain_a.Insert(4, 200)"<<std::endl;
    chain_a.Insert(4, 200);
    std::cout<<"> std::cout<<chain_a"<<std::endl;
    std::cout<<chain_a;
    std::cout<<"> chain_a.Insert(6, 700)"<<std::endl;
    try{chain_a.Insert(6, 700);}
    catch(std::runtime_error &e){
        std::cerr<<e.what()<<std::endl;
    }

    std::cout<<std::endl;
    std::cout<<"------------NumOfNodes() Test--------------"<<std::endl;
    std::cout<<"> chain_a.NumOfNodes() = "<<chain_a.NumOfNodes()<<std::endl;
    std::cout<<"> chain_a.Insert(1, 300)"<<std::endl;
    chain_a.Insert(1, 300);
    std::cout<<"> std::cout<<chain_a"<<std::endl;
    std::cout<<chain_a;
    std::cout<<"> chain_a.NumOfNodes() = "<<chain_a.NumOfNodes()<<std::endl;
    std::cout<<"> chain_a.Delete(1)"<<std::endl;
    chain_a.Delete(1);
    std::cout<<"> std::cout<<chain_a"<<std::endl;
    std::cout<<chain_a;
    std::cout<<"> chain_a.NumOfNodes() = "<<chain_a.NumOfNodes()<<std::endl;

    std::cout<<std::endl;
    std::cout<<"------------ChangeData(k, Y) Test--------------"<<std::endl;
    std::cout<<"> std::cout<<chain_a"<<std::endl;
    std::cout<<chain_a;
    std::cout<<"> chain_a.ChangeData(1, 20000)"<<std::endl;
    chain_a.ChangeData(1, 20000);
    std::cout<<"> std::cout<<chain_a"<<std::endl;
    std::cout<<chain_a;
    std::cout<<"> chain_a.ChangeData(4, -19)"<<std::endl;
    chain_a.ChangeData(4, -19);
    std::cout<<"> std::cout<<chain_a"<<std::endl;
    std::cout<<chain_a;
    std::cout<<"> chain_a.ChangeData(5, -1)"<<std::endl;
    try{chain_a.ChangeData(5, -1);}
    catch(std::runtime_error &e){
        std::cerr<<e.what()<<std::endl;
    }
    std::cout<<"> std::cout<<chain_a"<<std::endl;
    std::cout<<chain_a;

    std::cout<<std::endl;
    std::cout<<"------------InsertBeforeK(k, Y) Test--------------"<<std::endl;
    std::cout<<"> std::cout<<chain_a"<<std::endl;
    std::cout<<chain_a;
    std::cout<<"> chain_a.InsertBeforeK(1, 11)"<<std::endl;
    chain_a.InsertBeforeK(1, 11);
    std::cout<<"> std::cout<<chain_a"<<std::endl;
    std::cout<<chain_a;
    std::cout<<"> chain_a.InsertBeforeK(6, -11)"<<std::endl;
    chain_a.InsertBeforeK(6, -11);
    std::cout<<"> std::cout<<chain_a"<<std::endl;
    std::cout<<chain_a;
    std::cout<<"> chain_a.InsertBeforeK(20, 121)"<<std::endl;
    try{chain_a.InsertBeforeK(20, 121);}
    catch(std::runtime_error &e){
        std::cerr<<e.what()<<std::endl;
    }
    std::cout<<"> std::cout<<chain_a"<<std::endl;
    std::cout<<chain_a;

    std::cout<<std::endl;
    std::cout<<"------------DeleteEveryOtherNode() Test--------------"<<std::endl;
    std::cout<<"> std::cout<<chain_a"<<std::endl;
    std::cout<<chain_a;
    std::cout<<"> chain_a.DeleteEveryOtherNode()"<<std::endl;
    chain_a.DeleteEveryOtherNode();
    std::cout<<"> std::cout<<chain_a"<<std::endl;
    std::cout<<chain_a;


    std::cout<<std::endl;
    std::cout<<"------------DivideMid() Test--------------"<<std::endl;
    std::cout<<"> std::cout<<chain_a"<<std::endl;
    std::cout<<chain_a;
    std::cout<<"> chain_a.InsertFront(1)"<<std::endl;
    chain_a.InsertFront(1);
    std::cout<<"> chain_a.InsertFront(2)"<<std::endl;
    chain_a.InsertFront(2);
    std::cout<<"> chain_a.InsertFront(3)"<<std::endl;
    chain_a.InsertFront(3);
    std::cout<<"> std::cout<<chain_a"<<std::endl;
    std::cout<<chain_a;
    std::cout<<"> std::cout<<chain_b"<<std::endl;
    try{std::cout<<chain_b;}
    catch(std::runtime_error &e){
        std::cerr<<e.what()<<std::endl;
    }
    std::cout<<"> chain_a.DivideMid(chain_b)"<<std::endl;
    chain_a.DivideMid(chain_b);
    std::cout<<"> std::cout<<chain_a"<<std::endl;
    std::cout<<chain_a;
    std::cout<<"> std::cout<<chain_b"<<std::endl;
    std::cout<<chain_b;

    std::cout<<std::endl;
    std::cout<<"------------Deconcatenate(split, sub_list) Test--------------"<<std::endl;
    std::cout<<"> std::cout<<chain_a"<<std::endl;
    std::cout<<chain_a;
    std::cout<<"> std::cout<<chain_c"<<std::endl;
    try{std::cout<<chain_c;}
    catch(std::runtime_error &e){
        std::cerr<<e.what()<<std::endl;
    }

    std::cout<<"> split = chain_a.GetNode(2)"<<std::endl;
    ChainNode<int> *split = chain_a.GetNode(2);
    std::cout<<"> chain_a.Deconcatenate(split, chain_c)"<<std::endl;
    chain_a.Deconcatenate(split, chain_c);
    std::cout<<"> std::cout<<chain_a"<<std::endl;
    std::cout<<chain_a;
    std::cout<<"> std::cout<<chain_c"<<std::endl;
    std::cout<<chain_c;

    std::cout<<std::endl;
    std::cout<<"------------Merge(L1, L2) Test--------------"<<std::endl;
    std::cout<<"> std::cout<<chain_a"<<std::endl;
    std::cout<<chain_a;
    std::cout<<"> std::cout<<chain_b"<<std::endl;
    std::cout<<chain_b;
    std::cout<<"> std::cout<<chain_c"<<std::endl;
    std::cout<<chain_c;
    std::cout<<"> chain_a.Merge(chain_b, chain_c);"<<std::endl;
    chain_a.Merge(chain_b, chain_c);
    std::cout<<"> std::cout<<chain_a"<<std::endl;
    std::cout<<chain_a;
    std::cout<<"> chain_d.InsertFront(2221)"<<std::endl;
    chain_d.InsertFront(2221);
    std::cout<<"> chain_d.InsertFront(2223)"<<std::endl;
    chain_d.InsertFront(2223);
    std::cout<<"> chain_d.InsertFront(2225)"<<std::endl;
    chain_d.InsertFront(2225);
    std::cout<<"> chain_d.InsertFront(2227)"<<std::endl;
    chain_d.InsertFront(2227);
    std::cout<<"> chain_d.InsertFront(2229)"<<std::endl;
    chain_d.InsertFront(2229);
    std::cout<<"> chain_d.InsertFront(2231)"<<std::endl;
    chain_d.InsertFront(2231);
    std::cout<<"> chain_d.InsertFront(2233)"<<std::endl;
    chain_d.InsertFront(2233);
    std::cout<<"> chain_d.InsertFront(2235)"<<std::endl;
    chain_d.InsertFront(2235);
    std::cout<<"> std::cout<<chain_d"<<std::endl;
    std::cout<<chain_d;
    std::cout<<"> chain_e.Merge(chain_a, chain_d);"<<std::endl;
    chain_e.Merge(chain_a, chain_d);
    std::cout<<"> std::cout<<chain_e"<<std::endl;
    std::cout<<chain_e;



    return EXIT_SUCCESS;
}
