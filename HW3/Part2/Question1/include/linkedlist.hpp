//linkedlist.hpp
#include <linkedlist.h>
#include <cstdlib>

template <class T>
void Chain<T>::InsertFront(const T &in_data){
    first = new ChainNode<T> (in_data, first);
}

template <class T>
void Chain<T>::DeleteFront(){
    if(IsEmpty()){
        throw std::runtime_error(std::string("Error: Chain "+name+" is empty. Cannod DeleteFront()."));
    }

    ChainNode<T> *tmp = first;
    first = first->link;
    tmp->link = NULL;
    delete tmp;
}

template <class T>
T& Chain<T>::Front() const {
    if(IsEmpty()){
        throw std::runtime_error(std::string("Error: Chain "+name+" is empty. No front element."));
    }else{
        return first->data; //front unchanged
    }
}

template <class T>
T& Chain<T>::Back() const {
    if(IsEmpty()){
        throw std::runtime_error(std::string("Error: Chain "+name+" is empty. No back element."));
    }else{
        ChainNode<T> *current_node = first;
        while(current_node->link != NULL){
            current_node = current_node->link;
        }

        return current_node->data; //back changed
    }
}

template <class T>
T& Chain<T>::Get(const int i) const{
    if(IsEmpty()){
        throw std::runtime_error(std::string("Error: Chain "+name+" is empty. Cannod Get(i)."));
    }

    if(i<=0){
        throw std::runtime_error(std::string("Error: The smallest number of input i of Get(i) is 1."));
    }

    int count = 1;
    ChainNode<T> *current_node = first;

    while((count != i) && (current_node != NULL)){
        current_node = current_node->link;
        count++;
    }

    if(current_node == NULL){
        throw std::runtime_error(std::string("Warning: "+std::to_string(i)+"th element is not found in Chain."));
    }

    return current_node->data;
}


/*
template <class T>
Chain<T> Chain<T>::MergeChain(const Chain &input_queue){
    int new_capacity = capacity + input_queue.capacity;
    if(size+input_queue.size < 10){
        new_capacity = 10;
    }
    Chain<T> result_Chain(new_capacity, "temp_result_Chain");

    //start position
    int ptr1 = (front+1)%capacity;
    int ptr2 = (input_queue.front+1)%input_queue.capacity;

    while((ptr1 != (back+1)) && (ptr2 != (input_queue.back+1))){
        result_Chain.Push(queue[ptr1]);
        result_Chain.Push(input_queue.queue[ptr2]);

        ptr1 = (ptr1+1)%capacity;
        ptr2 = (ptr2+1)%input_queue.capacity;
    }

    if(ptr1==(back+1)){
        while(ptr2 != (input_queue.back+1)){
            result_Chain.Push(input_queue.queue[ptr2]);
            ptr2 = (ptr2+1)%input_queue.capacity;
        }
    }else{//ptr2==back
        while(ptr1 != (back+1)){
            result_Chain.Push(queue[ptr1]);
            ptr1 = (ptr1+1)%capacity;
        }
    }

    result_Chain.size = size + input_queue.size;
    return result_Chain;
}
*/

template <class T>
void Chain<T>::operator=(const Chain &other){
    first     = other.first;
}

template <class T>
std::ostream & operator<<(std::ostream &os, const Chain<T> &out_chain){
    if(out_chain.IsEmpty()){
        throw std::runtime_error(std::string("Error: Not available. The Chain is empty."));
        return os;
    }

    ChainNode<T> *current_node = out_chain.first;
    os<<out_chain.name<<" = [";

    while(current_node != NULL){
        if(current_node->link == NULL){
            os<<current_node->data<<"]"<<std::endl;
        }else{
            os<<current_node->data<<" ";
        }
        current_node = current_node->link;
    }

    return os;
}

/*
template <typename CoefType, typename ExpType>
bool Polynomial<CoefType, ExpType>::SortFunction(const Term<CoefType, ExpType> &a, const Term<CoefType, ExpType> &b){
    return (a.exp > b.exp);
}
*/

