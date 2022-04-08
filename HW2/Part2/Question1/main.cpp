//main.cpp
#include <iostream>
#include <solution.h>


int main(){
    Queue<int> queue_a(10, "queue_a");
    Queue<int> queue_b(10, "queue_b");
    Queue<int> queue_c(10, "queue_c");
    Queue<int> queue_d(10, "queue_d");

    std::cout<<"------------IsEmpty() Test--------------"<<std::endl;
    if(queue_a.IsEmpty()){
        std::cout<<"queue_a.IsEmpty() = true"<<std::endl;
    }else{
        std::cout<<"queue_a.IsEmpty() = false"<<std::endl;
    }

    std::cout<<std::endl;
    std::cout<<"------------Push() Test--------------"<<std::endl;
    std::cout<<"> queue_a.Push(2)"<<std::endl;
    queue_a.Push(2);
    std::cout<<"> queue_a.Push(4)"<<std::endl;
    queue_a.Push(4);
    std::cout<<"> queue_a.Push(20)"<<std::endl;
    queue_a.Push(20);
    std::cout<<"> queue_a.Push(999)"<<std::endl;
    queue_a.Push(999);
    std::cout<<"> queue_a.Push(38)"<<std::endl;
    queue_a.Push(38);
    std::cout<<queue_a;

    std::cout<<std::endl;
    std::cout<<"------------Pop() Test--------------"<<std::endl;
    std::cout<<"> queue_a.Pop()"<<std::endl;
    queue_a.Pop();
    std::cout<<"> queue_a.Pop()"<<std::endl;
    queue_a.Pop();
    std::cout<<"> queue_a.Pop()"<<std::endl;
    queue_a.Pop();
    std::cout<<queue_a;

    std::cout<<std::endl;
    std::cout<<"------------Front() Test--------------"<<std::endl;
    std::cout<<"queue_a.Front() = "<<queue_a.Front()<<std::endl;

    std::cout<<std::endl;
    std::cout<<"------------Rear() Test--------------"<<std::endl;
    std::cout<<"queue_a.Rear() = "<<queue_a.Rear()<<std::endl;

    std::cout<<std::endl;
    std::cout<<"------------Size() Test--------------"<<std::endl;
    std::cout<<"queue_a.Size() = "<<queue_a.Size()<<std::endl;
    std::cout<<"> queue_a.Push(111)"<<std::endl;
    queue_a.Push(111);
    std::cout<<"> queue_a.Push(33)"<<std::endl;
    queue_a.Push(33);
    std::cout<<"queue_a.Size() = "<<queue_a.Size()<<std::endl;
    std::cout<<"> queue_a.Pop()"<<std::endl;
    queue_a.Pop();
    std::cout<<"queue_a.Size() = "<<queue_a.Size()<<std::endl;
    std::cout<<queue_a;

    std::cout<<std::endl;
    std::cout<<"------------Capacity() Test--------------"<<std::endl;
    std::cout<<"queue_a.Capacity() = "<<queue_a.Capacity()<<std::endl;
    std::cout<<"> queue_a.Push(6)"<<std::endl;
    queue_a.Push(6);
    std::cout<<"> queue_a.Push(100)"<<std::endl;
    queue_a.Push(100);
    std::cout<<"> queue_a.Push(200)"<<std::endl;
    queue_a.Push(200);
    std::cout<<"> queue_a.Push(300)"<<std::endl;
    queue_a.Push(300);
    std::cout<<"> queue_a.Push(400)"<<std::endl;
    queue_a.Push(400);
    std::cout<<"> queue_a.Push(500)"<<std::endl;
    queue_a.Push(500);
    std::cout<<"> queue_a.Push(600)"<<std::endl;
    queue_a.Push(600);
    std::cout<<"queue_a.Capacity() = "<<queue_a.Capacity()<<std::endl;
    std::cout<<queue_a;

    std::cout<<std::endl;
    std::cout<<"------------Merge() Test--------------"<<std::endl;
    queue_b.Push(1);
    queue_b.Push(3);
    queue_b.Push(5);
    queue_b.Push(7);
    std::cout<<queue_b;
    queue_c.Push(2);
    queue_c.Push(4);
    queue_c.Push(6);
    queue_c.Push(8);
    std::cout<<queue_c;
    std::cout<<"> queue_d = queue_b.MergeQueue(queue_c)"<<std::endl;
    queue_d = queue_b.MergeQueue(queue_c);
    std::cout<<queue_d;


    return EXIT_SUCCESS;
}
