//solution.hpp
#include <Dequeue.h>
#include <cstdlib>

template <class T>
void Dequeue<T>::PushFront(const T &item){
    int next_front = (Queue<T>::front-1<0) ? Bag<T>::capacity-1 : Queue<T>::front-1;

    if(next_front == Queue<T>::rear){//full condition
        Queue<T>::ArrayDoubling();
    }

    Bag<T>::array[Queue<T>::front] = item;
    Queue<T>::front = (Queue<T>::front-1<0) ? Bag<T>::capacity-1 : Queue<T>::front-1;
    Queue<T>::size++;
}

template <class T>
void Dequeue<T>::PopRear(){
    if(Queue<T>::IsEmpty()){
        throw std::runtime_error(std::string("Error: Queue "+Bag<T>::name+" is empty, cannot delete."));
    }

    Bag<T>::array[Queue<T>::rear].~T();//Destructor of the deleted item.
    Queue<T>::rear = (Queue<T>::rear-1<0) ? Bag<T>::capacity-1 : Queue<T>::rear-1;
    Queue<T>::size--;
}

template <class T>
void Dequeue<T>::PushRear(const T &item){
    Dequeue<T>::Push(item);
}

template <class T>
void Dequeue<T>::PopFront(){
    Dequeue<T>::Pop();
}
