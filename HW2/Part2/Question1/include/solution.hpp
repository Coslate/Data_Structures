//solution.hpp
#include <solution.h>
#include <cstdlib>

template <class T>
void Queue<T>::Push(const T &item){
    if(((rear+1)%capacity) == front){//full condition
        ArrayDoubling();
    }

    rear = (rear+1)%capacity;
    queue[rear] = item;
    size++;
}

template <class T>
void Queue<T>::Pop(){
    if(IsEmpty()){
        throw std::runtime_error(std::string("Error: Queue "+name+" is empty, cannot delete."));
    }
    front = (front+1)%capacity;
    queue[front].~T();//Destructor of the deleted item.
    size--;
}

template <class T>
void Queue<T>::ArrayDoubling(){
    T* new_queue = new T [2*capacity];
    int start = (front+1)%capacity;

    if(start < 2){
        std::copy(queue+start, queue+start+capacity-1, new_queue);
    }else{
        std::copy(queue+start, queue+capacity, new_queue);
        std::copy(queue, queue+rear+1, new_queue+capacity-start);
    }

    front = 2*capacity-1;
    rear  = capacity-2;

    delete [] queue;
    queue     = new_queue;
    new_queue = nullptr;
    capacity *= 2;
}

template <class T>
T& Queue<T>::Front() const {
    if(IsEmpty()){
        throw std::runtime_error(std::string("Error: Queue "+name+" is empty. No front element."));
    }else{
        return queue[(front+1)%capacity]; //front unchanged
    }
}

template <class T>
T& Queue<T>::Rear() const {
    if(IsEmpty()){
        throw std::runtime_error(std::string("Error: Queue "+name+" is empty. No rear element."));
    }else{
        return queue[rear]; //rear changed
    }
}

template <class T>
Queue<T> Queue<T>::MergeQueue(const Queue &input_queue){
    int new_capacity = capacity + input_queue.capacity;
    if(size+input_queue.size < 10){
        new_capacity = 10;
    }
    Queue<T> result_Queue(new_capacity, "temp_result_Queue");

    //start position
    int ptr1 = (front+1)%capacity;
    int ptr2 = (input_queue.front+1)%input_queue.capacity;

    while((ptr1 != (rear+1)) && (ptr2 != (input_queue.rear+1))){
        result_Queue.Push(queue[ptr1]);
        result_Queue.Push(input_queue.queue[ptr2]);

        ptr1 = (ptr1+1)%capacity;
        ptr2 = (ptr2+1)%input_queue.capacity;
    }

    if(ptr1==(rear+1)){
        while(ptr2 != (input_queue.rear+1)){
            result_Queue.Push(input_queue.queue[ptr2]);
            ptr2 = (ptr2+1)%input_queue.capacity;
        }
    }else{//ptr2==rear
        while(ptr1 != (rear+1)){
            result_Queue.Push(queue[ptr1]);
            ptr1 = (ptr1+1)%capacity;
        }
    }

    result_Queue.size = size + input_queue.size;
    return result_Queue;
}

template <class T>
void Queue<T>::operator=(const Queue &other){
    if(capacity > 0){
        delete [] queue;
    }

    front    = other.front;
    rear     = other.rear;
    capacity = other.capacity;
    size     = other.size;

    T *temp = new T [capacity];
    for(int i=0;i<size;++i){
        temp[i] = other.queue[i];
    }

    queue = temp;
    temp = nullptr;
}

/*
template <typename CoefType, typename ExpType>
bool Polynomial<CoefType, ExpType>::SortFunction(const Term<CoefType, ExpType> &a, const Term<CoefType, ExpType> &b){
    return (a.exp > b.exp);
}
*/

