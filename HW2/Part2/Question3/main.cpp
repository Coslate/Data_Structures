//main.cpp
#include <iostream>
#include <Stack.h>

int main(){
    Stack<int> stack_a(10, "stack_a");

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
    std::cout<<"> stack_a.Push(422)"<<std::endl;
    stack_a.Push(422);
    std::cout<<"> stack_a.Push(89)"<<std::endl;
    stack_a.Push(89);
    std::cout<<std::endl;
    std::cout<<stack_a;
    std::cout<<"stack_a.Size() = "<<stack_a.Size()<<std::endl;

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
    std::cout<<"stack_a.Size() = "<<stack_a.Size()<<std::endl;

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
    std::cout<<"stack_a.Size() = "<<stack_a.Size()<<std::endl;

    std::cout<<std::endl;
    std::cout<<"------------Size() Test--------------"<<std::endl;
    std::cout<<stack_a;
    std::cout<<"stack_a.Size() = "<<stack_a.Size()<<std::endl;
    std::cout<<"> stack_a.Pop()"<<std::endl;
    stack_a.Pop();
    std::cout<<"> stack_a.Pop()"<<std::endl;
    stack_a.Pop();
    std::cout<<"> stack_a.Push(11111)"<<std::endl;
    stack_a.Push(11111);
    std::cout<<stack_a;
    std::cout<<"stack_a.Size() = "<<stack_a.Size()<<std::endl;

    return EXIT_SUCCESS;
}
