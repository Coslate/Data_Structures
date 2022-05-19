//main.cpp
#include <iostream>
#include <BST.h>

int main(){
    BST<int, char> bst_a("bst_a");
    pair<int, char> data_1 (50, 'A');
    pair<int, char> data_2 (5,  'B');
    pair<int, char> data_3 (30, 'C');
    pair<int, char> data_4 (40, 'D');
    pair<int, char> data_5 (80, 'E');
    pair<int, char> data_6 (35, 'F');
    pair<int, char> data_7 (2,  'G');
    pair<int, char> data_8 (20, 'H');
    pair<int, char> data_9 (15, 'I');
    pair<int, char> data_10(60, 'J');
    pair<int, char> data_11(70, 'K');
    pair<int, char> data_12(8,  'L');
    pair<int, char> data_13(10, 'M');

    std::cout<<std::endl;
    std::cout<<"------------IsEmpty() Test--------------"<<std::endl;
    if(bst_a.IsEmpty()){
        std::cout<<"bst_a.IsEmpty() = true"<<std::endl;
    }else{
        std::cout<<"bst_a.IsEmpty() = false"<<std::endl;
    }

    std::cout<<std::endl;
    std::cout<<"------------Insert() Test--------------"<<std::endl;
    std::cout<<"> bst_a.Insert("<<data_1<<")"<<std::endl;
    std::cout<<"> bst_a.Insert("<<data_2<<")"<<std::endl;
    std::cout<<"> bst_a.Insert("<<data_3<<")"<<std::endl;
    std::cout<<"> bst_a.Insert("<<data_4<<")"<<std::endl;
    std::cout<<"> bst_a.Insert("<<data_5<<")"<<std::endl;
    std::cout<<"> bst_a.Insert("<<data_6<<")"<<std::endl;
    std::cout<<"> bst_a.Insert("<<data_7<<")"<<std::endl;
    std::cout<<"> bst_a.Insert("<<data_8<<")"<<std::endl;
    std::cout<<"> bst_a.Insert("<<data_9<<")"<<std::endl;
    std::cout<<"> bst_a.Insert("<<data_10<<")"<<std::endl;
    std::cout<<"> bst_a.Insert("<<data_11<<")"<<std::endl;
    std::cout<<"> bst_a.Insert("<<data_12<<")"<<std::endl;
    std::cout<<"> bst_a.Insert("<<data_13<<")"<<std::endl;
    bst_a.Insert(data_1);
    bst_a.Insert(data_2);
    bst_a.Insert(data_3);
    bst_a.Insert(data_4);
    bst_a.Insert(data_5);
    bst_a.Insert(data_6);
    bst_a.Insert(data_7);
    bst_a.Insert(data_8);
    bst_a.Insert(data_9);
    bst_a.Insert(data_10);
    bst_a.Insert(data_11);
    bst_a.Insert(data_12);
    bst_a.Insert(data_13);
    std::cout<<std::endl;
    std::cout<<"> bst_a.Inorder() = "<<std::endl;
    bst_a.Inorder();
    std::cout<<std::endl;
    std::cout<<"> bst_a.Preorder() = "<<std::endl;
    bst_a.Preorder();
    std::cout<<std::endl;
    std::cout<<"> bst_a.Postorder() = "<<std::endl;
    bst_a.Postorder();
    std::cout<<std::endl;
    std::cout<<"> bst_a.LevelOrder() = "<<std::endl;
    bst_a.LevelOrder();
    std::cout<<std::endl;

    std::cout<<std::endl;
    std::cout<<"------------Get() Test--------------"<<std::endl;
    std::cout<<"pair<int, char> *get_15 = bst_a.Get(15);"<<std::endl;
    pair<int, char> *get_15 = bst_a.Get(15);
    std::cout<<"std::cout<<*get_15"<<std::endl;
    if(get_15){
        std::cout<<*get_15<<std::endl;
    }else{
        std::cout<<"NULL"<<std::endl;
    }

    std::cout<<std::endl;
    std::cout<<"pair<int, char> *get_50 = bst_a.Get(50);"<<std::endl;
    pair<int, char> *get_50 = bst_a.Get(50);
    std::cout<<"std::cout<<*get_50"<<std::endl;
    if(get_50){
        std::cout<<*get_50<<std::endl;
    }else{
        std::cout<<"NULL"<<std::endl;
    }

    std::cout<<std::endl;
    std::cout<<"pair<int, char> *get_80 = bst_a.Get(80);"<<std::endl;
    pair<int, char> *get_80 = bst_a.Get(80);
    std::cout<<"std::cout<<*get_80"<<std::endl;
    if(get_80){
        std::cout<<*get_80<<std::endl;
    }else{
        std::cout<<"NULL"<<std::endl;
    }

    std::cout<<std::endl;
    std::cout<<"pair<int, char> *get_100 = bst_a.Get(100);"<<std::endl;
    pair<int, char> *get_100 = bst_a.Get(100);
    std::cout<<"std::cout<<*get_100"<<std::endl;
    if(get_100){
        std::cout<<*get_100<<std::endl;
    }else{
        std::cout<<"NULL"<<std::endl;
    }

    std::cout<<std::endl;
    std::cout<<"------------Delete() Test--------------"<<std::endl;

    std::cout<<std::endl;
    return EXIT_SUCCESS;
}
