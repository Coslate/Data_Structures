//circular_headerlist.hpp
#include <circular_headerlist.h>
#include <cstdlib>

template <typename T>
CHLNode<T>* CircularHeaderList<T>::GetNode(){
    CHLNode<T> *x;
    if(av){
        x = av;
        av = av->link;
    }else{
        T unknown_data;
        x = new CHLNode<T> (unknown_data, NULL);
    }

    return x;
}

template <typename T>
void  CircularHeaderList<T>::RetNode(CHLNode<T> *&x){
    x->link = av;
    av      = x;
    x       = NULL;
}

template <typename T>
void  CircularHeaderList<T>::CleanAV(){
    while(av!=NULL){
        CHLNode<T> *tmp_nxt = av->link;
        av->link = NULL;
        delete av;
        av = tmp_nxt;
    }
}

template <typename T>
void CircularHeaderList<T>::InsertFront(const T &data){
    CHLNode<T> *new_node = GetNode();
    new_node->data   = data;
    new_node->link   = header->link;
    header->link = new_node;
}

template <typename T>
void CircularHeaderList<T>::InsertBack(const T &data){
    CHLNode<T> *last_node = header->link;
    //Find the last node
    while(last_node->link != header){
        last_node = last_node->link;
    }
    CHLNode<T> *new_node = GetNode();
    new_node->data   = data;
    new_node->link   = header;
    last_node->link  = new_node;
}

template <typename T>
void CircularHeaderList<T>::DeleteFirst(){
    if(IsEmpty()){
        throw std::runtime_error(std::string("Warning: CircularHeaderList "+name+" is empty. Cannot DeleteFirst()."));
    }

    CHLNode<T> *first_node = header->link;
    header->link = first_node->link;
    RetNode(first_node);
}

template <typename T>
void CircularHeaderList<T>::DeleteLast(){
    if(IsEmpty()){
        throw std::runtime_error(std::string("Warning: CircularHeaderList "+name+" is empty. Cannot DeleteLast()."));
    }

    CHLNode<T> *current_node = header->link;
    CHLNode<T> *prev_node    = header;
    //Find the last node
    while(current_node->link != header){
        prev_node = current_node;
        current_node = current_node->link;
    }

    prev_node->link = current_node->link;
    RetNode(current_node);
}

template <typename T>
CHLNode<T>* CircularHeaderList<T>::Get(const int i) const{
    if(IsEmpty()){
        throw std::runtime_error(std::string("Warning: CircularHeaderList "+name+" is empty. Cannot Get(i)."));
    }

    if(i<=0){
        throw std::runtime_error(std::string("Warning: The smallest number of input i of Get(i) shoule be >=1."));
    }

    int count = 1;
    CHLNode<T> *current_node = header->link;

    while((count != i) && (current_node != header)){
        current_node = current_node->link;
        count++;
    }

    if(current_node == header){
        throw std::runtime_error(std::string("Warning: "+std::to_string(i)+"th element is not found in CircularHeaderList."));
    }

    return current_node;
}

template <typename T>
int CircularHeaderList<T>::NumOfNodes(){
    if(IsEmpty()){
        return 0;
    }

    int count = 0;
    CHLNode<T> *current_node = header->link;

    while(current_node != header){
        current_node = current_node->link;
        count++;
    }

    return count;
}

template <typename T>
void CircularHeaderList<T>::operator=(const CircularHeaderList &other){
    while(!IsEmpty()){
        DeleteFirst();
    }

    for(Iterator i = other.Begin(); i!=other.End(); i++){
        InsertBack(*i);
    }
}

template <typename T>
std::ostream & operator<<(std::ostream &os, const CircularHeaderList<T> &out_list){
    if(out_list.IsEmpty()){
        throw std::runtime_error(std::string("Warning: Not available. The CircularHeaderList is empty."));
        return os;
    }

    CHLNode<T> *current_node = out_list.header->link;
    os<<out_list.name<<" = [";
    while(current_node != out_list.header){
        if(current_node->link == out_list.header){
            os<<current_node->data<<"]"<<std::endl;
            break;
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

