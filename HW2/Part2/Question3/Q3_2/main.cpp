//main.cpp
#include <iostream>
#include <Queue.h>

int main(){
    std::cout<<std::endl;
    std::cout<<"|======================================|"<<std::endl;
    std::cout<<"|===========queue_a test===============|"<<std::endl;
    std::cout<<"|======================================|"<<std::endl;
    std::cout<<std::endl;
    Queue<int> queue_a(10, "queue_a");

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
    std::cout<<"> queue_a.Push(422)"<<std::endl;
    queue_a.Push(422);
    std::cout<<"> queue_a.Push(89)"<<std::endl;
    queue_a.Push(89);
    std::cout<<std::endl;
    std::cout<<queue_a;
    std::cout<<"queue_a.Size() = "<<queue_a.Size()<<std::endl;

    std::cout<<std::endl;
    std::cout<<"------------Pop() Test--------------"<<std::endl;
    std::cout<<"> queue_a.Pop()"<<std::endl;
    queue_a.Pop();
    std::cout<<"> queue_a.Pop()"<<std::endl;
    queue_a.Pop();
    std::cout<<"> queue_a.Pop()"<<std::endl;
    queue_a.Pop();
    std::cout<<std::endl;
    std::cout<<queue_a;
    std::cout<<"queue_a.Size() = "<<queue_a.Size()<<std::endl;

    std::cout<<std::endl;
    std::cout<<"------------Size() Test--------------"<<std::endl;
    std::cout<<queue_a;
    std::cout<<"queue_a.Size() = "<<queue_a.Size()<<std::endl;
    std::cout<<"> queue_a.Pop()"<<std::endl;
    queue_a.Pop();
    std::cout<<"> queue_a.Pop()"<<std::endl;
    queue_a.Pop();
    std::cout<<"> queue_a.Push(11111)"<<std::endl;
    queue_a.Push(11111);
    std::cout<<queue_a;
    std::cout<<"queue_a.Size() = "<<queue_a.Size()<<std::endl;

    std::cout<<std::endl;
    std::cout<<"|======================================|"<<std::endl;
    std::cout<<"|===========queue_b test===============|"<<std::endl;
    std::cout<<"|======================================|"<<std::endl;
    std::cout<<std::endl;
    Queue<float> queue_b(10, "queue_b");

    std::cout<<"------------IsEmpty() Test--------------"<<std::endl;
    if(queue_b.IsEmpty()){
        std::cout<<"queue_b.IsEmpty() = true"<<std::endl;
    }else{
        std::cout<<"queue_b.IsEmpty() = false"<<std::endl;
    }

    std::cout<<std::endl;
    std::cout<<"------------Push() Test--------------"<<std::endl;
    std::cout<<"> queue_b.Push(0.2)"<<std::endl;
    queue_b.Push(0.2);
    std::cout<<"> queue_b.Push(0.04)"<<std::endl;
    queue_b.Push(0.04);
    std::cout<<"> queue_b.Push(20.2)"<<std::endl;
    queue_b.Push(20.2);
    std::cout<<"> queue_b.Push(999.1)"<<std::endl;
    queue_b.Push(999.1);
    std::cout<<"> queue_b.Push(3.8)"<<std::endl;
    queue_b.Push(3.8);
    std::cout<<"> queue_b.Push(4.22)"<<std::endl;
    queue_b.Push(4.22);
    std::cout<<"> queue_b.Push(89.1)"<<std::endl;
    queue_b.Push(89.1);
    std::cout<<std::endl;
    std::cout<<queue_b;
    std::cout<<"queue_b.Size() = "<<queue_b.Size()<<std::endl;

    std::cout<<std::endl;
    std::cout<<"------------Pop() Test--------------"<<std::endl;
    std::cout<<"> queue_b.Pop()"<<std::endl;
    queue_b.Pop();
    std::cout<<"> queue_b.Pop()"<<std::endl;
    queue_b.Pop();
    std::cout<<"> queue_b.Pop()"<<std::endl;
    queue_b.Pop();
    std::cout<<std::endl;
    std::cout<<queue_b;
    std::cout<<"queue_b.Size() = "<<queue_b.Size()<<std::endl;

    std::cout<<std::endl;
    std::cout<<"------------Size() Test--------------"<<std::endl;
    std::cout<<queue_b;
    std::cout<<"queue_b.Size() = "<<queue_b.Size()<<std::endl;
    std::cout<<"> queue_b.Pop()"<<std::endl;
    queue_b.Pop();
    std::cout<<"> queue_b.Pop()"<<std::endl;
    queue_b.Pop();
    std::cout<<"> queue_b.Push(111.11)"<<std::endl;
    queue_b.Push(111.11);
    std::cout<<queue_b;
    std::cout<<"queue_b.Size() = "<<queue_b.Size()<<std::endl;

    return EXIT_SUCCESS;
}
