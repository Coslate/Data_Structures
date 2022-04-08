//main.cpp
#include <iostream>
#include <solution.h>

int main(){
    Stack<int> stack_a(10, "stack_a");
    Queue<int> queue_a(10, "queue_a");

    std::cout<<"------------IsEmpty() Test--------------"<<std::endl;
    if(stack_a.IsEmpty()){
        std::cout<<"stack_a.IsEmpty() = true"<<std::endl;
    }else{
        std::cout<<"stack_a.IsEmpty() = false"<<std::endl;
    }

    std::cout<<std::endl;
    std::cout<<"------------Push() Test--------------"<<std::endl;
    std::cout<<"> stack_a.Push(2)"<<std::endl;
    stack_a.Push(2);
    std::cout<<"> stack_a.Push(4)"<<std::endl;
    stack_a.Push(4);
    std::cout<<"> stack_a.Push(20)"<<std::endl;
    stack_a.Push(20);
    std::cout<<"> stack_a.Push(999)"<<std::endl;
    stack_a.Push(999);
    std::cout<<"> stack_a.Push(38)"<<std::endl;
    stack_a.Push(38);
    std::cout<<std::endl;
    std::cout<<stack_a;

    std::cout<<std::endl;
    std::cout<<"------------Pop() Test--------------"<<std::endl;
    std::cout<<"> stack_a.Pop()"<<std::endl;
    stack_a.Pop();
    std::cout<<"> stack_a.Pop()"<<std::endl;
    stack_a.Pop();
    std::cout<<"> stack_a.Pop()"<<std::endl;
    stack_a.Pop();
    std::cout<<std::endl;
    std::cout<<stack_a;

    std::cout<<std::endl;
    std::cout<<"------------Top() Test--------------"<<std::endl;
    std::cout<<"> stack_a.Top() = "<<stack_a.Top()<<std::endl;
    std::cout<<"> stack_a.Push(19)"<<std::endl;
    stack_a.Push(19);
    std::cout<<"> stack_a.Push(199)"<<std::endl;
    stack_a.Push(199);
    std::cout<<"> stack_a.Push(299)"<<std::endl;
    stack_a.Push(299);
    std::cout<<"> stack_a.Top() = "<<stack_a.Top()<<std::endl;
    std::cout<<std::endl;
    std::cout<<stack_a;

    std::cout<<std::endl;
    std::cout<<"------------Capacity() Test--------------"<<std::endl;
    std::cout<<"stack_a.Capacity() = "<<stack_a.Capacity()<<std::endl;
    std::cout<<"> stack_a.Push(6)"<<std::endl;
    stack_a.Push(6);
    std::cout<<"> stack_a.Push(100)"<<std::endl;
    stack_a.Push(100);
    std::cout<<"> stack_a.Push(200)"<<std::endl;
    stack_a.Push(200);
    std::cout<<"> stack_a.Push(300)"<<std::endl;
    stack_a.Push(300);
    std::cout<<"> stack_a.Push(400)"<<std::endl;
    stack_a.Push(400);
    std::cout<<"stack_a.Capacity() = "<<stack_a.Capacity()<<std::endl;
    std::cout<<std::endl;
    std::cout<<stack_a;
    std::cout<<std::endl;
    std::cout<<"> stack_a.Push(500)"<<std::endl;
    stack_a.Push(500);
    std::cout<<"stack_a.Capacity() = "<<stack_a.Capacity()<<std::endl;
    std::cout<<std::endl;
    std::cout<<stack_a;

    std::cout<<std::endl;
    std::cout<<"------------reverseQueue() Test--------------"<<std::endl;
    queue_a.Push(1001);
    queue_a.Push(1002);
    queue_a.Push(1003);
    queue_a.Push(1004);
    queue_a.Push(1005);
    queue_a.Push(1006);
    queue_a.Push(1007);
    std::cout<<queue_a;
    std::cout<<"reverseQueue(queue_a)"<<std::endl;
    reverseQueue(queue_a);
    std::cout<<queue_a;

    return EXIT_SUCCESS;
}
