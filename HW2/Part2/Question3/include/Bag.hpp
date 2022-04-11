//Bag.hpp
#include <Bag.h>
#include <cstdlib>

template <class T>
T& Bag<T>::Element() const {
    if(IsEmpty()){
        throw std::runtime_error(std::string("Error: Bag "+name+" is empty, cannot use Element()."));
    }
    return array[0];
}

template <class T>
void Bag<T>::Push(const T &item){
    if((top+1) == capacity){//full condition
        ArrayDoubling();
    }

    top++;
    array[top] = item;
}

template <class T>
void Bag<T>::Pop(){
    if(IsEmpty()){
        throw std::runtime_error(std::string("Error: Bag "+name+" is empty, cannot delete."));
    }
    int delete_pos = top/2;
    std::copy(array+delete_pos+1, array+top+1, array+delete_pos);
    array[top].~T();//Destructor of the deleted item.
    top--;
}

template <class T>
void Bag<T>::ArrayDoubling(){
    T* new_array = new T [2*capacity];
    std::copy(array, array+capacity, new_array);

    delete [] array;
    array     = new_array;
    new_array = nullptr;
    capacity *= 2;
}

template <class T>
void Bag<T>::operator=(const Bag &other){
    if(capacity > 0){
        delete [] array;
    }

    capacity = other.capacity;
    top      = other.top;

    T *temp = new T [capacity];
    for(int i=0;i<=top;++i){
        temp[i] = other.array[i];
    }

    array = temp;
    temp = nullptr;
}

/*
template <typename CoefType, typename ExpType>
bool Polynomial<CoefType, ExpType>::SortFunction(const Term<CoefType, ExpType> &a, const Term<CoefType, ExpType> &b){
    return (a.exp > b.exp);
}
*/

