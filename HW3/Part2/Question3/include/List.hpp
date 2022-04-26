//List.hpp
#include <List.h>
#include <cstdlib>

template <class T>
void List<T>::Reverse(){
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
void List<T>::Concatenate(List<T> &b){
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
void List<T>::InsertFront(const T &e){
    first = new Node<T> (e, first);
}

template <class T>
void List<T>::InsertBack(const T &e){
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
void List<T>::Insert(const int i, const T e){
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
                throw std::runtime_error(std::string("Warning: "+std::to_string(i)+"th node is out of range of the List."));
            }else{
                Node<T> *tmp_node = new Node<T> (e, prev_node->link);
                prev_node->link = tmp_node;
            }
        }
    }
}

template <class T>
void List<T>::DeleteFront(){
    if(IsEmpty()){
        throw std::runtime_error(std::string("Warning: List "+name+" is empty. Cannot DeleteFront()."));
    }

    Node<T> *tmp = first;
    first = first->link;
    tmp->link = NULL;
    delete tmp;
}

template <class T>
void List<T>::DeleteBack(){
    if(IsEmpty()){
        throw std::runtime_error(std::string("Warning: List "+name+" is empty. Cannot DeleteBack()."));
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
void List<T>::Delete(const int i){
    if(IsEmpty()){
        throw std::runtime_error(std::string("Warning: List "+name+" is empty. Cannot Delete(i)."));
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
        throw std::runtime_error(std::string("Warning: "+std::to_string(i)+"th element is not found in List."));
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
Node<T>* List<T>::Front() const {
    return first; //front unchanged
}

template <class T>
Node<T>* List<T>::Back() const {
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
Node<T>& List<T>::Get(const int i) const{
    if(IsEmpty()){
        throw std::runtime_error(std::string("Warning: List "+name+" is empty. Cannot Get(i)."));
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
        throw std::runtime_error(std::string("Warning: "+std::to_string(i)+"th element is not found in List."));
    }

    return *current_node;
}

template <class T>
int List<T>::NumOfNodes(){
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
void List<T>::operator=(const List &other){
    first     = other.first;
}

template <class T>
std::ostream & operator<<(std::ostream &os, const List<T> &out_list){
    if(out_list.IsEmpty()){
        throw std::runtime_error(std::string("Warning: Not available. The List is empty."));
        return os;
    }

    Node<T> *current_node = out_list.first;
    os<<out_list.name<<" = [";

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

