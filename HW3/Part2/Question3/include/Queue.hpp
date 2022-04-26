//solution.hpp
#include <Queue.h>
#include <cstdlib>

template <class T>
void Queue<T>::Push(const T &item){
    if(List<T>::IsEmpty()){
        List<T>::InsertBack(item);
        front = List<T>::Front();
        rear  = List<T>::Back();
    }else{
        List<T>::InsertBack(item);
        rear  = List<T>::Back();
    }
}

template <class T>
void Queue<T>::Pop(){
    if(List<T>::IsEmpty()){
        throw std::runtime_error(std::string("Error: Queue "+List<T>::name+" is empty, cannot delete."));
    }
    List<T>::DeleteFront();
    front = List<T>::Front();
}

template <class T>
T& Queue<T>::Front() const {
    if(List<T>::IsEmpty()){
        throw std::runtime_error(std::string("Error: Queue "+List<T>::name+" is empty. No front element."));
    }else{
        return List<T>::GetNodeData(*front);
    }
}

template <class T>
T& Queue<T>::Rear() const {
    if(List<T>::IsEmpty()){
        throw std::runtime_error(std::string("Error: Queue "+List<T>::name+" is empty. No rear element."));
    }else{
        return List<T>::GetNodeData(*rear);
    }
}

template <class T>
void Queue<T>::operator=(const Queue &other){
    front = other.front;
    rear  = other.rear;
}

