//main.cpp
#include <iostream>
#include <time.h>
#include <cstdlib>
#include <unistd.h>
#include <HashTable.h>

int main(){
    srand((unsigned)time(NULL) * getpid());

    std::cout<<std::endl;
    std::cout<<"================================================================================="<<std::endl;
    std::cout<<"================================= SymbolTable1 =================================="<<std::endl;
    std::cout<<"================================================================================="<<std::endl;

    std::cout<<"> SymbolTable1 d1."<<std::endl;
    std::cout<<"> The hash table d1 has 26 buckets, numbering from 0-25."<<std::endl;
    SymbolTable1<char> d1("d1", 26);
    int bucket_pos = 0;

    std::cout<<std::endl;
    std::cout<<"> Setup at least 10 key objects."<<std::endl;
    pair<char> key_obj1(15);
    pair<char> key_obj2(10);
    pair<char> key_obj3(3);
    pair<char> key_obj4(5);
    pair<char> key_obj5(6);
    pair<char> key_obj6(2);
    pair<char> key_obj7(13);
    pair<char> key_obj8(20);
    pair<char> key_obj9(17);
    pair<char> key_obj10(33);

    std::cout<<"key_obj1 = "<<key_obj1<<std::endl;
    std::cout<<"key_obj2 = "<<key_obj2<<std::endl;
    std::cout<<"key_obj3 = "<<key_obj3<<std::endl;
    std::cout<<"key_obj4 = "<<key_obj4<<std::endl;
    std::cout<<"key_obj5 = "<<key_obj5<<std::endl;
    std::cout<<"key_obj6 = "<<key_obj6<<std::endl;
    std::cout<<"key_obj7 = "<<key_obj7<<std::endl;
    std::cout<<"key_obj8 = "<<key_obj8<<std::endl;
    std::cout<<"key_obj9 = "<<key_obj9<<std::endl;
    std::cout<<"key_obj10 = "<<key_obj10<<std::endl;

    std::cout<<std::endl;
    std::cout<<"> Inset those 10 keys into d1."<<std::endl;
    d1.Insert(key_obj1);
    std::cout<<"d1.Insert(key_obj1)."<<std::endl;
    d1.Insert(key_obj2);
    std::cout<<"d1.Insert(key_obj2)."<<std::endl;
    d1.Insert(key_obj3);
    std::cout<<"d1.Insert(key_obj3)."<<std::endl;
    d1.Insert(key_obj4);
    std::cout<<"d1.Insert(key_obj4)."<<std::endl;
    d1.Insert(key_obj5);
    std::cout<<"d1.Insert(key_obj5)."<<std::endl;
    d1.Insert(key_obj6);
    std::cout<<"d1.Insert(key_obj6)."<<std::endl;
    d1.Insert(key_obj7);
    std::cout<<"d1.Insert(key_obj7)."<<std::endl;
    d1.Insert(key_obj8);
    std::cout<<"d1.Insert(key_obj8)."<<std::endl;
    d1.Insert(key_obj9);
    std::cout<<"d1.Insert(key_obj9)."<<std::endl;
    d1.Insert(key_obj10);
    std::cout<<"d1.Insert(key_obj10)."<<std::endl;

    std::cout<<std::endl;
    std::cout<<"> Display d1."<<std::endl;
    d1.Display();

    std::cout<<std::endl;
    std::cout<<"> Demo the Search() function."<<std::endl;
    std::cout<<"d1.Search(key_obj1.arr, key_obj1.size, bucket_pos);"<<std::endl;
    pair<char> *search_result = d1.Search(key_obj1.arr, key_obj1.size, bucket_pos);
    if(search_result == NULL){
        std::cout<<"=> "<<key_obj1<<" not found in d1"<<std::endl;
    }else{
        std::cout<<"=> "<<key_obj1<<" is in bucket number "<<bucket_pos<<" in d1."<<std::endl;
    }

    std::cout<<"d1.Search(key_obj2.arr, key_obj2.size, bucket_pos);"<<std::endl;
    search_result = d1.Search(key_obj2.arr, key_obj2.size, bucket_pos);
    if(search_result == NULL){
        std::cout<<"=> "<<key_obj2<<" not found in d1"<<std::endl;
    }else{
        std::cout<<"=> "<<key_obj2<<" is in bucket number "<<bucket_pos<<" in d1."<<std::endl;
    }

    std::cout<<"d1.Search(key_obj10.arr, key_obj10.size, bucket_pos);"<<std::endl;
    search_result = d1.Search(key_obj10.arr, key_obj10.size, bucket_pos);
    if(search_result == NULL){
        std::cout<<"=> "<<key_obj10<<" not found in d1"<<std::endl;
    }else{
        std::cout<<"=> "<<key_obj10<<" is in bucket number "<<bucket_pos<<" in d1."<<std::endl;
    }

    std::cout<<"d1.Search(key_obj7.arr, key_obj7.size, bucket_pos);"<<std::endl;
    search_result = d1.Search(key_obj7.arr, key_obj7.size, bucket_pos);
    if(search_result == NULL){
        std::cout<<"=> "<<key_obj7<<" not found in d1"<<std::endl;
    }else{
        std::cout<<"=> "<<key_obj7<<" is in bucket number "<<bucket_pos<<" in d1."<<std::endl;
    }

    std::cout<<"d1.Search(key_obj5.arr, key_obj5.size, bucket_pos);"<<std::endl;
    search_result = d1.Search(key_obj5.arr, key_obj5.size, bucket_pos);
    if(search_result == NULL){
        std::cout<<"=> "<<key_obj5<<" not found in d1"<<std::endl;
    }else{
        std::cout<<"=> "<<key_obj5<<" is in bucket number "<<bucket_pos<<" in d1."<<std::endl;
    }

    std::cout<<std::endl;
    return EXIT_SUCCESS;
}