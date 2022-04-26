//solution.hpp
#include <Stack.h>
#include <cstdlib>

template <class T>
T& Stack<T>::Top() const {
    if(List<T>::IsEmpty()){
        throw std::runtime_error(std::string("Error: Stack "+List<T>::name+" is empty, cannot Top()."));
    }
    return List<T>::GetNodeData(*top);
}

template <class T>
void Stack<T>::Pop() {
    if(List<T>::IsEmpty()){
        throw std::runtime_error(std::string("Error: Stack "+List<T>::name+" is empty, cannot delete."));
    }
    List<T>::DeleteBack();
    top = List<T>::Back();
}

template <class T>
void Stack<T>::Push(const T &item) {
    List<T>::InsertBack(item);
    top = List<T>::Back();
}

template <class T>
void Stack<T>::operator=(const Stack &other){
    top = other.top;
}

