//main.cpp
#include <iostream>
#include <Stack.h>

int main(){
    std::cout<<std::endl;
    std::cout<<"|======================================|"<<std::endl;
    std::cout<<"|===========stack_a test===============|"<<std::endl;
    std::cout<<"|======================================|"<<std::endl;
    std::cout<<std::endl;
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

    std::cout<<std::endl;
    std::cout<<"|======================================|"<<std::endl;
    std::cout<<"|===========stack_b test===============|"<<std::endl;
    std::cout<<"|======================================|"<<std::endl;
    std::cout<<std::endl;
    Stack<float> stack_b(10, "stack_b");

    std::cout<<"------------IsEmpty() Test--------------"<<std::endl;
    if(stack_b.IsEmpty()){
        std::cout<<"stack_b.IsEmpty() = true"<<std::endl;
    }else{
        std::cout<<"stack_b.IsEmpty() = false"<<std::endl;
    }

    std::cout<<std::endl;
    std::cout<<"------------Push() Test--------------"<<std::endl;
    std::cout<<"> stack_b.Push(0.2)"<<std::endl;
    stack_b.Push(0.2);
    std::cout<<"> stack_b.Push(0.04)"<<std::endl;
    stack_b.Push(0.04);
    std::cout<<"> stack_b.Push(20.2)"<<std::endl;
    stack_b.Push(20.2);
    std::cout<<"> stack_b.Push(999.1)"<<std::endl;
    stack_b.Push(999.1);
    std::cout<<"> stack_b.Push(3.8)"<<std::endl;
    stack_b.Push(3.8);
    std::cout<<"> stack_b.Push(4.22)"<<std::endl;
    stack_b.Push(4.22);
    std::cout<<"> stack_b.Push(89.1)"<<std::endl;
    stack_b.Push(89.1);
    std::cout<<std::endl;
    std::cout<<stack_b;
    std::cout<<"stack_b.Size() = "<<stack_b.Size()<<std::endl;

    std::cout<<std::endl;
    std::cout<<"------------Pop() Test--------------"<<std::endl;
    std::cout<<"> stack_b.Pop()"<<std::endl;
    stack_b.Pop();
    std::cout<<"> stack_b.Pop()"<<std::endl;
    stack_b.Pop();
    std::cout<<"> stack_b.Pop()"<<std::endl;
    stack_b.Pop();
    std::cout<<std::endl;
    std::cout<<stack_b;
    std::cout<<"stack_b.Size() = "<<stack_b.Size()<<std::endl;

    std::cout<<std::endl;
    std::cout<<"------------Top() Test--------------"<<std::endl;
    std::cout<<"> stack_b.Top() = "<<stack_b.Top()<<std::endl;
    std::cout<<"> stack_b.Push(0.19)"<<std::endl;
    stack_b.Push(0.19);
    std::cout<<"> stack_b.Push(199.2)"<<std::endl;
    stack_b.Push(199.2);
    std::cout<<"> stack_b.Push(29.9)"<<std::endl;
    stack_b.Push(29.9);
    std::cout<<"> stack_b.Top() = "<<stack_b.Top()<<std::endl;
    std::cout<<std::endl;
    std::cout<<stack_b;
    std::cout<<"stack_b.Size() = "<<stack_b.Size()<<std::endl;

    std::cout<<std::endl;
    std::cout<<"------------Size() Test--------------"<<std::endl;
    std::cout<<stack_b;
    std::cout<<"stack_b.Size() = "<<stack_b.Size()<<std::endl;
    std::cout<<"> stack_b.Pop()"<<std::endl;
    stack_b.Pop();
    std::cout<<"> stack_b.Pop()"<<std::endl;
    stack_b.Pop();
    std::cout<<"> stack_b.Push(111.11)"<<std::endl;
    stack_b.Push(111.11);
    std::cout<<stack_b;
    std::cout<<"stack_b.Size() = "<<stack_b.Size()<<std::endl;

    return EXIT_SUCCESS;
}
