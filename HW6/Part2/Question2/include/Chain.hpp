//Chain.hpp
#include <Chain.h>
#include <cstdlib>

template <class T>
void Chain<T>::Reverse(){
    Node<T> *current_node = first;
    Node<T> *prev_node    = NULL;
    Node<T> *r            = NULL;

    while(current_node != NULL){
        r = prev_node;
        prev_node = current_node;
        current_node = current_node->link;
        prev_node->link = r;
    }

    first = prev_node;
}

template <class T>
void Chain<T>::Concatenate(Chain<T> &b){
    Node<T> *last_node   = first;
    //Find the last node
    if(last_node != NULL){
        while(last_node->link != NULL){
            last_node = last_node->link;
        }
    }

    if(first != NULL){
        last_node->link = b.first;
    }else{
        first      = b.first;
    }

    b.first = NULL;
}

template <class T>
void Chain<T>::InsertFront(const T &e){
    first = new Node<T> (e, first);
}

template <class T>
void Chain<T>::InsertBack(const T &e){
    Node<T> *last_node = first;
    //Find the last node
    if(last_node != NULL){
        while(last_node->link != NULL){
            last_node = last_node->link;
        }
        last_node->link = new Node<T> (e, NULL);
    }else{
        first = new Node<T> (e, first);
    }
}

template <class T>
void Chain<T>::Insert(const int i, const T e){
    if(i<=0){
        throw std::runtime_error(std::string("Warning: The smallest number of input i of Insert(i, e) should be >=1."));
    }

    int count = 1;
    Node<T> *current_node = first;
    Node<T> *prev_node = first;

    while((count != i) && (current_node != NULL)){
        prev_node    = current_node;
        current_node = current_node->link;
        count++;
    }

    if(i==1){
        first = new Node<T> (e, first);
    }else{
        if((current_node==NULL) && (prev_node != NULL) && (i==count)){//Insert as the last node
            prev_node->link = new Node<T>(e, NULL);
        }else{
            if((current_node == NULL) && (i>count)){
                throw std::runtime_error(std::string("Warning: "+std::to_string(i)+"th node is out of range of the Chain."));
            }else{
                Node<T> *tmp_node = new Node<T> (e, prev_node->link);
                prev_node->link = tmp_node;
            }
        }
    }
}

template <class T>
void Chain<T>::DeleteFront(){
    if(IsEmpty()){
        throw std::runtime_error(std::string("Warning: Chain "+name+" is empty. Cannot DeleteFront()."));
    }

    Node<T> *tmp = first;
    first = first->link;
    tmp->link = NULL;
    delete tmp;
}

template <class T>
void Chain<T>::DeleteBack(){
    if(IsEmpty()){
        throw std::runtime_error(std::string("Warning: Chain "+name+" is empty. Cannot DeleteBack()."));
    }

    Node<T> *last_node = first;
    Node<T> *prev_node = first;

    //Find the last node
    while(last_node->link != NULL){
        prev_node = last_node;
        last_node = last_node->link;
    }

    prev_node->link = NULL;
    delete last_node;
}

template <class T>
void Chain<T>::Delete(const int i){
    if(IsEmpty()){
        throw std::runtime_error(std::string("Warning: Chain "+name+" is empty. Cannot Delete(i)."));
    }

    if(i<=0){
        throw std::runtime_error(std::string("Warning: The smallest number of input i of Delete(i) should be >=1."));
    }

    int count = 1;
    Node<T> *current_node = first;
    Node<T> *prev_node = first;

    while((count != i) && (current_node != NULL)){
        prev_node    = current_node;
        current_node = current_node->link;
        count++;
    }

    if(current_node == NULL){
        throw std::runtime_error(std::string("Warning: "+std::to_string(i)+"th element is not found in Chain."));
    }

    if(i==1){
        current_node = first;
        first = first->link;
        current_node->link = NULL;
        delete current_node;
    }else{
        prev_node->link = current_node->link;
        current_node->link = NULL;
        delete current_node;
    }
}

template <class T>
Node<T>* Chain<T>::Front() const {
    return first; //front unchanged
}

template <class T>
Node<T>* Chain<T>::Back() const {
    Node<T> *last_node = first;
    //Find the last node
    if(last_node != NULL){
        while(last_node->link != NULL){
            last_node = last_node->link;
        }
    }

    return last_node; //back changed
}

template <class T>
Node<T>& Chain<T>::Get(const int i) const{
    if(IsEmpty()){
        throw std::runtime_error(std::string("Warning: Chain "+name+" is empty. Cannot Get(i)."));
    }

    if(i<=0){
        throw std::runtime_error(std::string("Warning: The smallest number of input i of Get(i) shoule be >=1."));
    }

    int count = 1;
    Node<T> *current_node = first;

    while((count != i) && (current_node != NULL)){
        current_node = current_node->link;
        count++;
    }

    if(current_node == NULL){
        throw std::runtime_error(std::string("Warning: "+std::to_string(i)+"th element is not found in Chain."));
    }

    return *current_node;
}

template <class T>
int Chain<T>::NumOfNodes(){
    if(IsEmpty()){
        return 0;
    }

    int count = 0;
    Node<T> *current_node = first;

    while(current_node != NULL){
        current_node = current_node->link;
        count++;
    }

    return count;
}

template <class T>
void Chain<T>::operator=(const Chain &other){
    first     = other.first;
}

template <class T>
std::ostream & operator<<(std::ostream &os, const Chain<T> &out_chain){
    if(out_chain.IsEmpty()){
        throw std::runtime_error(std::string("Warning: Not available. The Chain is empty."));
        return os;
    }

    Node<T> *current_node = out_chain.first;
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

template <class T>
std::ostream & operator<<(std::ostream &os, const Node<T>* const out_node){
    if(out_node == NULL){
        throw std::runtime_error(std::string("Warning: Not available. The Node does not exist."));
        return os;
    }
    os<<out_node->data;
    return os;
}

/*
template <typename CoefType, typename ExpType>
bool Polynomial<CoefType, ExpType>::SortFunction(const Term<CoefType, ExpType> &a, const Term<CoefType, ExpType> &b){
    return (a.exp > b.exp);
}
*/

