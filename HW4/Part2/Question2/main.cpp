//main.cpp
#include <iostream>
#include <MaxHeap.h>
#include <MinHeap.h>

int main(){
    std::cout<<std::endl;
    std::cout<<"|======================================|"<<std::endl;
    std::cout<<"|===========MaxHeap test===============|"<<std::endl;
    std::cout<<"|======================================|"<<std::endl;
    std::cout<<std::endl;
    MaxHeap<int> max_heap_a(10, "max_heap_a");
    MaxHeap<int> max_heap_b(10, "max_heap_b");
    int max_arr[] = {50, 5, 30, 40, 80, 35, 2, 20, 15, 60, 70, 8, 10};

    std::cout<<std::endl;
    std::cout<<"------------IsEmpty() Test--------------"<<std::endl;
    if(max_heap_a.IsEmpty()){
        std::cout<<"max_heap_a.IsEmpty() = true"<<std::endl;
    }else{
        std::cout<<"max_heap_a.IsEmpty() = false"<<std::endl;
    }

    if(max_heap_b.IsEmpty()){
        std::cout<<"max_heap_b.IsEmpty() = true"<<std::endl;
    }else{
        std::cout<<"max_heap_b.IsEmpty() = false"<<std::endl;
    }

    std::cout<<std::endl;
    std::cout<<"------------Initialization with Push() Test--------------"<<std::endl;
    max_heap_a.Push(50);
    max_heap_a.Push(5);
    max_heap_a.Push(30);
    max_heap_a.Push(40);
    max_heap_a.Push(80);
    max_heap_a.Push(35);
    max_heap_a.Push(2);
    max_heap_a.Push(20);
    max_heap_a.Push(15);
    max_heap_a.Push(60);
    max_heap_a.Push(70);
    max_heap_a.Push(8);
    max_heap_a.Push(10);
    std::cout<<">max_heap_a.Push(50)"<<std::endl;
    std::cout<<">max_heap_a.Push(5)"<<std::endl;
    std::cout<<">max_heap_a.Push(30)"<<std::endl;
    std::cout<<">max_heap_a.Push(40)"<<std::endl;
    std::cout<<">max_heap_a.Push(80)"<<std::endl;
    std::cout<<">max_heap_a.Push(35)"<<std::endl;
    std::cout<<">max_heap_a.Push(2)"<<std::endl;
    std::cout<<">max_heap_a.Push(20)"<<std::endl;
    std::cout<<">max_heap_a.Push(15)"<<std::endl;
    std::cout<<">max_heap_a.Push(60)"<<std::endl;
    std::cout<<">max_heap_a.Push(70)"<<std::endl;
    std::cout<<">max_heap_a.Push(8)"<<std::endl;
    std::cout<<">max_heap_a.Push(10)"<<std::endl;
    std::cout<<"> std::cout<<max_heap_a"<<std::endl;
    std::cout<<max_heap_a;

    std::cout<<std::endl;
    std::cout<<"------------Initialization with  BottomUpConstruction() Test--------------"<<std::endl;
    std::cout<<"> int max_arr[] = {50, 5, 30, 40, 80, 35, 2, 20, 15, 60, 70, 8, 10};"<<std::endl;
    std::cout<<"> max_heap_b.BottomUpConstruction(max_arr, 13);"<<std::endl;
    max_heap_b.BottomUpConstruction(max_arr, 13);
    std::cout<<"> std::cout<<max_heap_b"<<std::endl;
    std::cout<<max_heap_b;

    std::cout<<std::endl;
    std::cout<<"------------Push() Test--------------"<<std::endl;
    std::cout<<">max_heap_a.Push(999)"<<std::endl;
    max_heap_a.Push(999);
    std::cout<<max_heap_a;
    std::cout<<">max_heap_a.Push(1)"<<std::endl;
    max_heap_a.Push(1);
    std::cout<<max_heap_a;
    std::cout<<">max_heap_a.Push(97)"<<std::endl;
    max_heap_a.Push(97);
    std::cout<<max_heap_a;
    std::cout<<std::endl;

    std::cout<<">max_heap_b.Push(666)"<<std::endl;
    max_heap_b.Push(666);
    std::cout<<max_heap_b;
    std::cout<<">max_heap_b.Push(0)"<<std::endl;
    max_heap_b.Push(0);
    std::cout<<max_heap_b;
    std::cout<<">max_heap_b.Push(49)"<<std::endl;
    max_heap_b.Push(49);
    std::cout<<max_heap_b;

    std::cout<<std::endl;
    std::cout<<"------------Pop() Test--------------"<<std::endl;
    std::cout<<">max_heap_a.Pop()"<<std::endl;
    max_heap_a.Pop();
    std::cout<<max_heap_a;
    std::cout<<">max_heap_a.Pop()"<<std::endl;
    max_heap_a.Pop();
    std::cout<<max_heap_a;
    std::cout<<">max_heap_a.Pop()"<<std::endl;
    max_heap_a.Pop();
    std::cout<<max_heap_a;
    std::cout<<std::endl;
    std::cout<<">max_heap_b.Pop()"<<std::endl;
    max_heap_b.Pop();
    std::cout<<max_heap_b;
    std::cout<<">max_heap_b.Pop()"<<std::endl;
    max_heap_b.Pop();
    std::cout<<max_heap_b;
    std::cout<<">max_heap_b.Pop()"<<std::endl;
    max_heap_b.Pop();
    std::cout<<max_heap_b;

    std::cout<<std::endl;
    std::cout<<"------------Top() Test--------------"<<std::endl;
    std::cout<<">max_heap_a.Top() = "<<max_heap_a.Top()<<std::endl;
    std::cout<<">max_heap_b.Top() = "<<max_heap_b.Top()<<std::endl;

    std::cout<<std::endl;
    std::cout<<"|======================================|"<<std::endl;
    std::cout<<"|===========MinHeap test===============|"<<std::endl;
    std::cout<<"|======================================|"<<std::endl;
    std::cout<<std::endl;
    MinHeap<int> min_heap_a(10, "min_heap_a");
    MinHeap<int> min_heap_b(10, "min_heap_b");
    int min_arr[] = {50, 5, 30, 40, 80, 35, 2, 20, 15, 60, 70, 8, 10};

    std::cout<<std::endl;
    std::cout<<"------------IsEmpty() Test--------------"<<std::endl;
    if(min_heap_a.IsEmpty()){
        std::cout<<"min_heap_a.IsEmpty() = true"<<std::endl;
    }else{
        std::cout<<"min_heap_a.IsEmpty() = false"<<std::endl;
    }

    if(min_heap_b.IsEmpty()){
        std::cout<<"min_heap_b.IsEmpty() = true"<<std::endl;
    }else{
        std::cout<<"min_heap_b.IsEmpty() = false"<<std::endl;
    }

    std::cout<<std::endl;
    std::cout<<"------------Initialization with Push() Test--------------"<<std::endl;
    min_heap_a.Push(50);
    min_heap_a.Push(5);
    min_heap_a.Push(30);
    min_heap_a.Push(40);
    min_heap_a.Push(80);
    min_heap_a.Push(35);
    min_heap_a.Push(2);
    min_heap_a.Push(20);
    min_heap_a.Push(15);
    min_heap_a.Push(60);
    min_heap_a.Push(70);
    min_heap_a.Push(8);
    min_heap_a.Push(10);
    std::cout<<">min_heap_a.Push(50)"<<std::endl;
    std::cout<<">min_heap_a.Push(5)"<<std::endl;
    std::cout<<">min_heap_a.Push(30)"<<std::endl;
    std::cout<<">min_heap_a.Push(40)"<<std::endl;
    std::cout<<">min_heap_a.Push(80)"<<std::endl;
    std::cout<<">min_heap_a.Push(35)"<<std::endl;
    std::cout<<">min_heap_a.Push(2)"<<std::endl;
    std::cout<<">min_heap_a.Push(20)"<<std::endl;
    std::cout<<">min_heap_a.Push(15)"<<std::endl;
    std::cout<<">min_heap_a.Push(60)"<<std::endl;
    std::cout<<">min_heap_a.Push(70)"<<std::endl;
    std::cout<<">min_heap_a.Push(8)"<<std::endl;
    std::cout<<">min_heap_a.Push(10)"<<std::endl;
    std::cout<<"> std::cout<<min_heap_a"<<std::endl;
    std::cout<<min_heap_a;

    std::cout<<std::endl;
    std::cout<<"------------Initialization with  BottomUpConstruction() Test--------------"<<std::endl;
    std::cout<<"> int min_arr[] = {50, 5, 30, 40, 80, 35, 2, 20, 15, 60, 70, 8, 10};"<<std::endl;
    std::cout<<"> min_heap_b.BottomUpConstruction(min_arr, 13);"<<std::endl;
    min_heap_b.BottomUpConstruction(min_arr, 13);
    std::cout<<"> std::cout<<min_heap_b"<<std::endl;
    std::cout<<min_heap_b;

    std::cout<<std::endl;
    std::cout<<"------------Push() Test--------------"<<std::endl;
    std::cout<<">min_heap_a.Push(999)"<<std::endl;
    min_heap_a.Push(999);
    std::cout<<min_heap_a;
    std::cout<<">min_heap_a.Push(1)"<<std::endl;
    min_heap_a.Push(1);
    std::cout<<min_heap_a;
    std::cout<<">min_heap_a.Push(97)"<<std::endl;
    min_heap_a.Push(97);
    std::cout<<min_heap_a;
    std::cout<<std::endl;

    std::cout<<">min_heap_b.Push(666)"<<std::endl;
    min_heap_b.Push(666);
    std::cout<<min_heap_b;
    std::cout<<">min_heap_b.Push(0)"<<std::endl;
    min_heap_b.Push(0);
    std::cout<<min_heap_b;
    std::cout<<">min_heap_b.Push(49)"<<std::endl;
    min_heap_b.Push(49);
    std::cout<<min_heap_b;

    std::cout<<std::endl;
    std::cout<<"------------Pop() Test--------------"<<std::endl;
    std::cout<<">min_heap_a.Pop()"<<std::endl;
    min_heap_a.Pop();
    std::cout<<min_heap_a;
    std::cout<<">min_heap_a.Pop()"<<std::endl;
    min_heap_a.Pop();
    std::cout<<min_heap_a;
    std::cout<<">min_heap_a.Pop()"<<std::endl;
    min_heap_a.Pop();
    std::cout<<min_heap_a;
    std::cout<<">min_heap_a.Pop()"<<std::endl;
    min_heap_a.Pop();
    std::cout<<min_heap_a;
    std::cout<<std::endl;
    std::cout<<">min_heap_b.Pop()"<<std::endl;
    min_heap_b.Pop();
    std::cout<<min_heap_b;
    std::cout<<">min_heap_b.Pop()"<<std::endl;
    min_heap_b.Pop();
    std::cout<<min_heap_b;
    std::cout<<">min_heap_b.Pop()"<<std::endl;
    min_heap_b.Pop();
    std::cout<<min_heap_b;

    std::cout<<std::endl;
    std::cout<<"------------Top() Test--------------"<<std::endl;
    std::cout<<">min_heap_a.Top() = "<<min_heap_a.Top()<<std::endl;
    std::cout<<">min_heap_b.Top() = "<<min_heap_b.Top()<<std::endl;




    std::cout<<std::endl;
    return EXIT_SUCCESS;
}
