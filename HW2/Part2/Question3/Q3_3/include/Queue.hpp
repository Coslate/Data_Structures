//solution.hpp
#include <Queue.h>
#include <cstdlib>

template <class T>
void Queue<T>::Push(const T &item){
    if(((rear+1)%Bag<T>::capacity) == front){//full condition
        ArrayDoubling();
    }

    rear = (rear+1)%Bag<T>::capacity;
    Bag<T>::array[rear] = item;
    size++;
}

template <class T>
void Queue<T>::Pop(){
    if(IsEmpty()){
        throw std::runtime_error(std::string("Error: Queue "+Bag<T>::name+" is empty, cannot delete."));
    }
    front = (front+1)%Bag<T>::capacity;
    Bag<T>::array[front].~T();//Destructor of the deleted item.
    size--;
}

template <class T>
void Queue<T>::ArrayDoubling(){
    T* new_queue = new T [2*Bag<T>::capacity];
    int start = (front+1)%Bag<T>::capacity;

    if(start < 2){
        std::copy(Bag<T>::array+start, Bag<T>::array+start+Bag<T>::capacity-1, new_queue);
    }else{
        std::copy(Bag<T>::array+start, Bag<T>::array+Bag<T>::capacity, new_queue);
        std::copy(Bag<T>::array, Bag<T>::array+rear+1, new_queue+Bag<T>::capacity-start);
    }

    front = 2*Bag<T>::capacity-1;
    rear  = Bag<T>::capacity-2;

    delete [] Bag<T>::array;
    Bag<T>::array = new_queue;
    new_queue = nullptr;
    Bag<T>::capacity *= 2;
}

template <class T>
T& Queue<T>::Front() const {
    if(IsEmpty()){
        throw std::runtime_error(std::string("Error: Queue "+Bag<T>::name+" is empty. No front element."));
    }else{
        return Bag<T>::array[(front+1)%Bag<T>::capacity]; //front unchanged
    }
}

template <class T>
T& Queue<T>::Rear() const {
    if(IsEmpty()){
        throw std::runtime_error(std::string("Error: Queue "+Bag<T>::name+" is empty. No rear element."));
    }else{
        return Bag<T>::array[rear]; //rear changed
    }
}

template <class T>
void Queue<T>::operator=(const Queue &other){
    if(Bag<T>::capacity > 0){
        delete [] Bag<T>::array;
    }

    front            = other.front;
    rear             = other.rear;
    Bag<T>::capacity = other.Bag<T>::capacity;
    size             = other.size;

    T *temp = new T [Bag<T>::capacity];
    for(int i=0;i<size;++i){
        temp[i] = other.Bag<T>::array[i];
    }

    Bag<T>::array = temp;
    temp = nullptr;
}

