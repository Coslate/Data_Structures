//main.cpp
#include <iostream>
#include <Dequeue.h>

int main(){
    std::cout<<std::endl;
    std::cout<<"|======================================|"<<std::endl;
    std::cout<<"|===========deque_a test===============|"<<std::endl;
    std::cout<<"|======================================|"<<std::endl;
    std::cout<<std::endl;
    Dequeue<int> deque_a(10, "deque_a");

    std::cout<<"------------IsEmpty() Test--------------"<<std::endl;
    if(deque_a.IsEmpty()){
        std::cout<<"deque_a.IsEmpty() = true"<<std::endl;
    }else{
        std::cout<<"deque_a.IsEmpty() = false"<<std::endl;
    }

    std::cout<<std::endl;
    std::cout<<"------------PushRear() Test--------------"<<std::endl;
    std::cout<<"> deque_a.PushRear(2)"<<std::endl;
    deque_a.PushRear(2);
    std::cout<<"> deque_a.PushRear(4)"<<std::endl;
    deque_a.PushRear(4);
    std::cout<<"> deque_a.PushRear(20)"<<std::endl;
    deque_a.PushRear(20);
    std::cout<<"> deque_a.PushRear(999)"<<std::endl;
    deque_a.PushRear(999);
    std::cout<<std::endl;
    std::cout<<deque_a;
    std::cout<<"deque_a.Size() = "<<deque_a.Size()<<std::endl;
    std::cout<<std::endl;

    std::cout<<"------------PushFront() Test--------------"<<std::endl;
    std::cout<<"> deque_a.PushFront(38)"<<std::endl;
    deque_a.PushFront(38);
    std::cout<<deque_a;
    std::cout<<"deque_a.Size() = "<<deque_a.Size()<<std::endl;
    std::cout<<std::endl;
    std::cout<<"> deque_a.PushFront(422)"<<std::endl;
    deque_a.PushFront(422);
    std::cout<<deque_a;
    std::cout<<"deque_a.Size() = "<<deque_a.Size()<<std::endl;
    std::cout<<std::endl;
    std::cout<<"> deque_a.PushFront(89)"<<std::endl;
    deque_a.PushFront(89);
    std::cout<<deque_a;
    std::cout<<"deque_a.Size() = "<<deque_a.Size()<<std::endl;
    std::cout<<std::endl;
    std::cout<<"> deque_a.PushFront(90)"<<std::endl;
    deque_a.PushFront(90);
    std::cout<<deque_a;
    std::cout<<"deque_a.Size() = "<<deque_a.Size()<<std::endl;
    std::cout<<std::endl;
    std::cout<<"> deque_a.PushFront(91)"<<std::endl;
    deque_a.PushFront(91);
    std::cout<<deque_a;
    std::cout<<"deque_a.Size() = "<<deque_a.Size()<<std::endl;
    std::cout<<std::endl;
    std::cout<<"> deque_a.PushFront(92)"<<std::endl;
    deque_a.PushFront(92);
    std::cout<<deque_a;
    std::cout<<"deque_a.Size() = "<<deque_a.Size()<<std::endl;
    std::cout<<std::endl;

    std::cout<<"------------PopFront() Test--------------"<<std::endl;
    std::cout<<"> deque_a.PopFront()"<<std::endl;
    deque_a.PopFront();
    std::cout<<"> deque_a.PopFront()"<<std::endl;
    deque_a.PopFront();
    std::cout<<"> deque_a.PopFront()"<<std::endl;
    deque_a.PopFront();
    std::cout<<std::endl;
    std::cout<<deque_a;
    std::cout<<"deque_a.Size() = "<<deque_a.Size()<<std::endl;

    std::cout<<"------------PopRear() Test--------------"<<std::endl;
    std::cout<<"> deque_a.PopRear()"<<std::endl;
    deque_a.PopRear();
    std::cout<<"> deque_a.PopRear()"<<std::endl;
    deque_a.PopRear();
    std::cout<<"> deque_a.PopRear()"<<std::endl;
    deque_a.PopRear();
    std::cout<<"> deque_a.PopRear()"<<std::endl;
    deque_a.PopRear();
    std::cout<<std::endl;
    std::cout<<deque_a;
    std::cout<<"deque_a.Size() = "<<deque_a.Size()<<std::endl;

    std::cout<<std::endl;
    std::cout<<"------------Size() Test--------------"<<std::endl;
    std::cout<<deque_a;
    std::cout<<"deque_a.Size() = "<<deque_a.Size()<<std::endl;
    std::cout<<"> deque_a.PopFront()"<<std::endl;
    deque_a.PopFront();
    std::cout<<"> deque_a.PopFront()"<<std::endl;
    deque_a.PopFront();
    std::cout<<"> deque_a.PushRear(11111)"<<std::endl;
    deque_a.PushRear(11111);
    std::cout<<"> deque_a.PushFront(22222)"<<std::endl;
    deque_a.PushFront(22222);
    std::cout<<"> deque_a.PopRear()"<<std::endl;
    deque_a.PopRear();
    std::cout<<deque_a;
    std::cout<<"deque_a.Size() = "<<deque_a.Size()<<std::endl;
    std::cout<<std::endl;

    std::cout<<"|======================================|"<<std::endl;
    std::cout<<"|===========deque_b test===============|"<<std::endl;
    std::cout<<"|======================================|"<<std::endl;
    std::cout<<std::endl;
    Dequeue<float> deque_b(10, "deque_b");

    std::cout<<"------------IsEmpty() Test--------------"<<std::endl;
    if(deque_b.IsEmpty()){
        std::cout<<"deque_b.IsEmpty() = true"<<std::endl;
    }else{
        std::cout<<"deque_b.IsEmpty() = false"<<std::endl;
    }

    std::cout<<std::endl;
    std::cout<<"------------PushRear() Test--------------"<<std::endl;
    std::cout<<"> deque_b.PushRear(2.2)"<<std::endl;
    deque_b.PushRear(2.2);
    std::cout<<"> deque_b.PushRear(1.4)"<<std::endl;
    deque_b.PushRear(1.4);
    std::cout<<"> deque_b.PushRear(20.99)"<<std::endl;
    deque_b.PushRear(20.99);
    std::cout<<"> deque_b.PushRear(999.2)"<<std::endl;
    deque_b.PushRear(999.2);
    std::cout<<std::endl;
    std::cout<<deque_b;
    std::cout<<"deque_b.Size() = "<<deque_b.Size()<<std::endl;
    std::cout<<std::endl;

    std::cout<<"------------PushFront() Test--------------"<<std::endl;
    std::cout<<"> deque_b.PushFront(0.38)"<<std::endl;
    deque_b.PushFront(0.38);
    std::cout<<deque_b;
    std::cout<<"deque_b.Size() = "<<deque_b.Size()<<std::endl;
    std::cout<<std::endl;
    std::cout<<"> deque_b.PushFront(42.2)"<<std::endl;
    deque_b.PushFront(42.2);
    std::cout<<deque_b;
    std::cout<<"deque_b.Size() = "<<deque_b.Size()<<std::endl;
    std::cout<<std::endl;
    std::cout<<"> deque_b.PushFront(89.33)"<<std::endl;
    deque_b.PushFront(89.33);
    std::cout<<deque_b;
    std::cout<<"deque_b.Size() = "<<deque_b.Size()<<std::endl;
    std::cout<<std::endl;
    std::cout<<"> deque_b.PushFront(1.90)"<<std::endl;
    deque_b.PushFront(1.90);
    std::cout<<deque_b;
    std::cout<<"deque_b.Size() = "<<deque_b.Size()<<std::endl;
    std::cout<<std::endl;
    std::cout<<"> deque_b.PushFront(3.91)"<<std::endl;
    deque_b.PushFront(3.91);
    std::cout<<deque_b;
    std::cout<<"deque_b.Size() = "<<deque_b.Size()<<std::endl;
    std::cout<<std::endl;
    std::cout<<"> deque_b.PushFront(0.92)"<<std::endl;
    deque_b.PushFront(0.92);
    std::cout<<deque_b;
    std::cout<<"deque_b.Size() = "<<deque_b.Size()<<std::endl;
    std::cout<<std::endl;

    std::cout<<"------------PopFront() Test--------------"<<std::endl;
    std::cout<<"> deque_b.PopFront()"<<std::endl;
    deque_b.PopFront();
    std::cout<<"> deque_b.PopFront()"<<std::endl;
    deque_b.PopFront();
    std::cout<<"> deque_b.PopFront()"<<std::endl;
    deque_b.PopFront();
    std::cout<<std::endl;
    std::cout<<deque_b;
    std::cout<<"deque_b.Size() = "<<deque_b.Size()<<std::endl;

    std::cout<<"------------PopRear() Test--------------"<<std::endl;
    std::cout<<"> deque_b.PopRear()"<<std::endl;
    deque_b.PopRear();
    std::cout<<"> deque_b.PopRear()"<<std::endl;
    deque_b.PopRear();
    std::cout<<"> deque_b.PopRear()"<<std::endl;
    deque_b.PopRear();
    std::cout<<"> deque_b.PopRear()"<<std::endl;
    deque_b.PopRear();
    std::cout<<std::endl;
    std::cout<<deque_b;
    std::cout<<"deque_b.Size() = "<<deque_b.Size()<<std::endl;

    std::cout<<std::endl;
    std::cout<<"------------Size() Test--------------"<<std::endl;
    std::cout<<deque_b;
    std::cout<<"deque_b.Size() = "<<deque_b.Size()<<std::endl;
    std::cout<<"> deque_b.PopFront()"<<std::endl;
    deque_b.PopFront();
    std::cout<<"> deque_b.PopFront()"<<std::endl;
    deque_b.PopFront();
    std::cout<<"> deque_b.PushRear(11.11)"<<std::endl;
    deque_b.PushRear(11.11);
    std::cout<<"> deque_b.PushFront(22.22)"<<std::endl;
    deque_b.PushFront(22.22);
    std::cout<<"> deque_b.PopRear()"<<std::endl;
    deque_b.PopRear();
    std::cout<<deque_b;
    std::cout<<"deque_b.Size() = "<<deque_b.Size()<<std::endl;
    std::cout<<std::endl;

    return EXIT_SUCCESS;
}
