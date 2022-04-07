//solution.hpp
#include <solution.h>
#include <cstdlib>

template <class T>
void Queue<T>::Push(const T &item){
    if(((rear+1)%capacity) == front){
        ArrayDoubling();
    }

    rear = (rear+1)%capacity;
    queue[rear] = item;
}

template <class T>
void Queue<T>::Pop(){
    if(IsEmpty()){
        throw std::runtime_error(std::string("Error: Queue "+name+" is empty, cannot delete."));
    }
    front = (front+1)%capacity;
    queue[front].~T();//Destructor of the deleted item.
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
void Queue<T>::Front() const {
    if(IsEmpty()){
        throw std::runtime_error(std::string("Error: Queue "+name+" is empty. No front element."));
    }else{
        return queue[(front+1)%capacity]; //front unchanged
    }
}

template <class T>
void Queue<T>::Rear() const {
    if(IsEmpty()){
        throw std::runtime_error(std::string("Error: Queue "+name+" is empty. No rear element."));
    }else{
        return queue[rear]; //rear changed
    }
}

template <typename CoefType, typename ExpType>
void Polynomial<CoefType, ExpType>::NewTerm(const CoefType &in_coef, const ExpType &in_exp){
    if(terms == capacity){
        capacity *= 2;
        Term<CoefType, ExpType> *temp = new Term<CoefType, ExpType> [capacity];
        std::copy(queue, queue+terms, temp);
        delete [] queue;
        queue = temp;
        temp = nullptr;
    }

    queue[terms].coef = in_coef;
    queue[terms].exp  = in_exp;
    terms++;
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

