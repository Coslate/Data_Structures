//solution.hpp
#include <solution.h>
#include <cstdlib>

template <class T>
void Stack<T>::Push(const T &item){
    if((top+1) == capacity){//full condition
        ArrayDoubling();
    }

    top++;
    stack[top] = item;
}

template <class T>
void Stack<T>::Pop(){
    if(IsEmpty()){
        throw std::runtime_error(std::string("Error: Stack "+name+" is empty, cannot delete."));
    }
    stack[top].~T();//Destructor of the deleted item.
    top--;
}

template <class T>
T& Stack<T>::Top() const {
    if(IsEmpty()){
        throw std::runtime_error(std::string("Error: Stack "+name+" is empty, cannot Top()."));
    }
    return stack[top];
}

template <class T>
void Stack<T>::ArrayDoubling(){
    T* new_stack = new T [2*capacity];
    std::copy(stack, stack+capacity, new_stack);

    delete [] stack;
    stack     = new_stack;
    new_stack = nullptr;
    capacity *= 2;
}

template <class T>
void Stack<T>::operator=(const Stack &other){
    if(capacity > 0){
        delete [] stack;
    }

    top      = other.top;
    capacity = other.capacity;

    T *temp = new T [capacity];
    for(int i=0;i<=top;++i){
        temp[i] = other.stack[i];
    }

    stack = temp;
    temp = nullptr;
}

/*
template <class T>
void reverseQueue(Queue<T> &input_queue){
    Stack<T> tmp_stack(10, "tmp_stack");
    while(!input_queue.IsEmpty()){
        tmp_stack.Push(input_queue.Front());
        input_queue.Pop();
    }
    while(!tmp_stack.IsEmpty()){
        input_queue.Push(tmp_stack.Top());
        tmp_stack.Pop();
    }
}
*/


/*
template <typename CoefType, typename ExpType>
bool Polynomial<CoefType, ExpType>::SortFunction(const Term<CoefType, ExpType> &a, const Term<CoefType, ExpType> &b){
    return (a.exp > b.exp);
}
*/

