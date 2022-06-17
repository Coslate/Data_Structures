//main.cpp
#include <iostream>
#include <time.h>
#include <cstdlib>
#include <unistd.h>
#include <SymbolTable1.h>
#include <SymbolTable2.h>

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
    pair<char> key_obj1_1(15);
    pair<char> key_obj1_2(10);
    pair<char> key_obj1_3(3);
    pair<char> key_obj1_4(5);
    pair<char> key_obj1_5(6);
    pair<char> key_obj1_6(2);
    pair<char> key_obj1_7(13);
    pair<char> key_obj1_8(20);
    pair<char> key_obj1_9(17);
    pair<char> key_obj1_10(33);

    std::cout<<"key_obj1_1 = "<<key_obj1_1<<std::endl;
    std::cout<<"key_obj1_2 = "<<key_obj1_2<<std::endl;
    std::cout<<"key_obj1_3 = "<<key_obj1_3<<std::endl;
    std::cout<<"key_obj1_4 = "<<key_obj1_4<<std::endl;
    std::cout<<"key_obj1_5 = "<<key_obj1_5<<std::endl;
    std::cout<<"key_obj1_6 = "<<key_obj1_6<<std::endl;
    std::cout<<"key_obj1_7 = "<<key_obj1_7<<std::endl;
    std::cout<<"key_obj1_8 = "<<key_obj1_8<<std::endl;
    std::cout<<"key_obj1_9 = "<<key_obj1_9<<std::endl;
    std::cout<<"key_obj1_10 = "<<key_obj1_10<<std::endl;

    std::cout<<std::endl;
    std::cout<<"> Inset those 10 keys into d1."<<std::endl;
    d1.Insert(key_obj1_1);
    std::cout<<"d1.Insert(key_obj1_1)."<<std::endl;
    d1.Insert(key_obj1_2);
    std::cout<<"d1.Insert(key_obj1_2)."<<std::endl;
    d1.Insert(key_obj1_3);
    std::cout<<"d1.Insert(key_obj1_3)."<<std::endl;
    d1.Insert(key_obj1_4);
    std::cout<<"d1.Insert(key_obj1_4)."<<std::endl;
    d1.Insert(key_obj1_5);
    std::cout<<"d1.Insert(key_obj1_5)."<<std::endl;
    d1.Insert(key_obj1_6);
    std::cout<<"d1.Insert(key_obj1_6)."<<std::endl;
    d1.Insert(key_obj1_7);
    std::cout<<"d1.Insert(key_obj1_7)."<<std::endl;
    d1.Insert(key_obj1_8);
    std::cout<<"d1.Insert(key_obj1_8)."<<std::endl;
    d1.Insert(key_obj1_9);
    std::cout<<"d1.Insert(key_obj1_9)."<<std::endl;
    d1.Insert(key_obj1_10);
    std::cout<<"d1.Insert(key_obj1_10)."<<std::endl;

    std::cout<<std::endl;
    std::cout<<"> Display d1."<<std::endl;
    d1.Display();

    std::cout<<std::endl;
    std::cout<<"> Demo the Search() function."<<std::endl;
    std::cout<<"d1.Search(key_obj1_1.arr, key_obj1_1.size, bucket_pos);"<<std::endl;
    pair<char> *search_result = d1.Search(key_obj1_1.arr, key_obj1_1.size, bucket_pos);
    if(search_result == NULL){
        std::cout<<"=> "<<key_obj1_1<<" not found in d1"<<std::endl;
    }else{
        std::cout<<"=> "<<key_obj1_1<<" is in bucket number "<<bucket_pos<<" in d1, where the buckets are numberd 0-25."<<std::endl;
    }

    std::cout<<"d1.Search(key_obj1_2.arr, key_obj1_2.size, bucket_pos);"<<std::endl;
    search_result = d1.Search(key_obj1_2.arr, key_obj1_2.size, bucket_pos);
    if(search_result == NULL){
        std::cout<<"=> "<<key_obj1_2<<" not found in d1"<<std::endl;
    }else{
        std::cout<<"=> "<<key_obj1_2<<" is in bucket number "<<bucket_pos<<" in d1, where the buckets are numbered 0-25."<<std::endl;
    }

    std::cout<<"d1.Search(key_obj1_10.arr, key_obj1_10.size, bucket_pos);"<<std::endl;
    search_result = d1.Search(key_obj1_10.arr, key_obj1_10.size, bucket_pos);
    if(search_result == NULL){
        std::cout<<"=> "<<key_obj1_10<<" not found in d1"<<std::endl;
    }else{
        std::cout<<"=> "<<key_obj1_10<<" is in bucket number "<<bucket_pos<<" in d1, where the buckets are numbered 0-25."<<std::endl;
    }

    std::cout<<"d1.Search(key_obj1_7.arr, key_obj1_7.size, bucket_pos);"<<std::endl;
    search_result = d1.Search(key_obj1_7.arr, key_obj1_7.size, bucket_pos);
    if(search_result == NULL){
        std::cout<<"=> "<<key_obj1_7<<" not found in d1"<<std::endl;
    }else{
        std::cout<<"=> "<<key_obj1_7<<" is in bucket number "<<bucket_pos<<" in d1, where the buckets are numbered 0-25."<<std::endl;
    }

    std::cout<<"d1.Search(key_obj1_5.arr, key_obj1_5.size, bucket_pos);"<<std::endl;
    search_result = d1.Search(key_obj1_5.arr, key_obj1_5.size, bucket_pos);
    if(search_result == NULL){
        std::cout<<"=> "<<key_obj1_5<<" not found in d1"<<std::endl;
    }else{
        std::cout<<"=> "<<key_obj1_5<<" is in bucket number "<<bucket_pos<<" in d1, where the buckets are numbered 0-25."<<std::endl;
    }

    std::cout<<std::endl;
    std::cout<<"================================================================================="<<std::endl;
    std::cout<<"================================= SymbolTable2 =================================="<<std::endl;
    std::cout<<"================================================================================="<<std::endl;

    std::cout<<"> SymbolTable2 d2."<<std::endl;
    std::cout<<"> The hash table d2 has 26 buckets, numbering from 0-25."<<std::endl;
    SymbolTable2<char> d2("d2", 26);
    bucket_pos = 0;

    std::cout<<std::endl;
    std::cout<<"> Setup at least 10 key objects."<<std::endl;
    pair<char> key_obj2_1(15);
    pair<char> key_obj2_2(10);
    pair<char> key_obj2_3(3);
    pair<char> key_obj2_4(5);
    pair<char> key_obj2_5(6);
    pair<char> key_obj2_6(2);
    pair<char> key_obj2_7(13);
    pair<char> key_obj2_8(20);
    pair<char> key_obj2_9(17);
    pair<char> key_obj2_10(33);

    std::cout<<"key_obj2_1 = "<<key_obj2_1<<std::endl;
    std::cout<<"key_obj2_2 = "<<key_obj2_2<<std::endl;
    std::cout<<"key_obj2_3 = "<<key_obj2_3<<std::endl;
    std::cout<<"key_obj2_4 = "<<key_obj2_4<<std::endl;
    std::cout<<"key_obj2_5 = "<<key_obj2_5<<std::endl;
    std::cout<<"key_obj2_6 = "<<key_obj2_6<<std::endl;
    std::cout<<"key_obj2_7 = "<<key_obj2_7<<std::endl;
    std::cout<<"key_obj2_8 = "<<key_obj2_8<<std::endl;
    std::cout<<"key_obj2_9 = "<<key_obj2_9<<std::endl;
    std::cout<<"key_obj2_10 = "<<key_obj2_10<<std::endl;

    std::cout<<std::endl;
    std::cout<<"> Inset those 10 keys into d2."<<std::endl;
    d2.Insert(key_obj2_1);
    std::cout<<"d2.Insert(key_obj2_1)."<<std::endl;
    d2.Insert(key_obj2_2);
    std::cout<<"d2.Insert(key_obj2_2)."<<std::endl;
    d2.Insert(key_obj2_3);
    std::cout<<"d2.Insert(key_obj2_3)."<<std::endl;
    d2.Insert(key_obj2_4);
    std::cout<<"d2.Insert(key_obj2_4)."<<std::endl;
    d2.Insert(key_obj2_5);
    std::cout<<"d2.Insert(key_obj2_5)."<<std::endl;
    d2.Insert(key_obj2_6);
    std::cout<<"d2.Insert(key_obj2_6)."<<std::endl;
    d2.Insert(key_obj2_7);
    std::cout<<"d2.Insert(key_obj2_7)."<<std::endl;
    d2.Insert(key_obj2_8);
    std::cout<<"d2.Insert(key_obj2_8)."<<std::endl;
    d2.Insert(key_obj2_9);
    std::cout<<"d2.Insert(key_obj2_9)."<<std::endl;
    d2.Insert(key_obj2_10);
    std::cout<<"d2.Insert(key_obj2_10)."<<std::endl;

    std::cout<<std::endl;
    std::cout<<"> Display d2."<<std::endl;
    d2.Display();

    std::cout<<std::endl;
    std::cout<<"> Demo the Search() function."<<std::endl;
    std::cout<<"d2.Search(key_obj2_1.arr, key_obj2_1.size, bucket_pos);"<<std::endl;
    search_result = d2.Search(key_obj2_1.arr, key_obj2_1.size, bucket_pos);
    if(search_result == NULL){
        std::cout<<"=> "<<key_obj2_1<<" not found in d2"<<std::endl;
    }else{
        std::cout<<"=> "<<key_obj2_1<<" is in bucket number "<<bucket_pos<<" in d2, where the buckets are numberd 0-25."<<std::endl;
    }

    std::cout<<"d2.Search(key_obj2_2.arr, key_obj2_2.size, bucket_pos);"<<std::endl;
    search_result = d2.Search(key_obj2_2.arr, key_obj2_2.size, bucket_pos);
    if(search_result == NULL){
        std::cout<<"=> "<<key_obj2_2<<" not found in d2"<<std::endl;
    }else{
        std::cout<<"=> "<<key_obj2_2<<" is in bucket number "<<bucket_pos<<" in d2, where the buckets are numbered 0-25."<<std::endl;
    }

    std::cout<<"d2.Search(key_obj2_10.arr, key_obj2_10.size, bucket_pos);"<<std::endl;
    search_result = d2.Search(key_obj2_10.arr, key_obj2_10.size, bucket_pos);
    if(search_result == NULL){
        std::cout<<"=> "<<key_obj2_10<<" not found in d2"<<std::endl;
    }else{
        std::cout<<"=> "<<key_obj2_10<<" is in bucket number "<<bucket_pos<<" in d2, where the buckets are numbered 0-25."<<std::endl;
    }

    std::cout<<"d2.Search(key_obj2_7.arr, key_obj2_7.size, bucket_pos);"<<std::endl;
    search_result = d2.Search(key_obj2_7.arr, key_obj2_7.size, bucket_pos);
    if(search_result == NULL){
        std::cout<<"=> "<<key_obj2_7<<" not found in d2"<<std::endl;
    }else{
        std::cout<<"=> "<<key_obj2_7<<" is in bucket number "<<bucket_pos<<" in d2, where the buckets are numbered 0-25."<<std::endl;
    }

    std::cout<<"d2.Search(key_obj2_5.arr, key_obj2_5.size, bucket_pos);"<<std::endl;
    search_result = d2.Search(key_obj2_5.arr, key_obj2_5.size, bucket_pos);
    if(search_result == NULL){
        std::cout<<"=> "<<key_obj2_5<<" not found in d2"<<std::endl;
    }else{
        std::cout<<"=> "<<key_obj2_5<<" is in bucket number "<<bucket_pos<<" in d1, where the buckets are numbered 0-25."<<std::endl;
    }

    std::cout<<std::endl;
    return EXIT_SUCCESS;
}
