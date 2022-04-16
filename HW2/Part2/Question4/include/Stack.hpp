//solution.hpp
#include <Stack.h>
#include <cstdlib>

template <class T>
T& Stack<T>::Top() const {
    if(Bag<T>::IsEmpty()){
        throw std::runtime_error(std::string("Error: Stack "+Bag<T>::name+" is empty, cannot Top()."));
    }
    return Bag<T>::array[Bag<T>::top];
}

template <class T>
void Stack<T>::Pop() {
    if(Bag<T>::IsEmpty()){
        throw std::runtime_error(std::string("Error: Stack "+Bag<T>::name+" is empty, cannot delete."));
    }
    Bag<T>::array[Bag<T>::top].~T();//Destructor of the deleted item.
    Bag<T>::top--;
}

template <class T>
void Stack<T>::operator=(const Stack &other){
    if(Bag<T>::capacity > 0){
        delete [] Bag<T>::array;
    }

    Bag<T>::top      = other.Bag<T>::top;
    Bag<T>::capacity = other.Bag<T>::capacity;

    T *temp = new T [Bag<T>::capacity];
    for(int i=0;i<=Bag<T>::top;++i){
        temp[i] = other.Bag<T>::array[i];
    }

    Bag<T>::array = temp;
    temp = nullptr;
}

template <class T>
void Stack<T>::PrintPath(const int &end_x, const int &end_y){
    for(int i=0;i<=Bag<T>::top;++i){
        if(i==Bag<T>::top){
            std::cout<<Bag<T>::array[i]<<" -> END: ("<<end_x<<", "<<end_y<<")"<<std::endl;
        }else{
            std::cout<<Bag<T>::array[i]<<" -> ";
        }
    }
}

