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
        throw std::runtime_error(std::string("Warning: Chain "+name+" is empty. Cannot DeleteFront()."));
    }

    ChainNode<T> *tmp = first;
    first = first->link;
    tmp->link = NULL;
    delete tmp;
}

template <class T>
T& Chain<T>::Front() const {
    if(IsEmpty()){
        throw std::runtime_error(std::string("Warning: Chain "+name+" is empty. No front element."));
    }else{
        return first->data; //front unchanged
    }
}

template <class T>
T& Chain<T>::Back() const {
    if(IsEmpty()){
        throw std::runtime_error(std::string("Warning: Chain "+name+" is empty. No back element."));
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
        throw std::runtime_error(std::string("Warning: Chain "+name+" is empty. Cannot Get(i)."));
    }

    if(i<=0){
        throw std::runtime_error(std::string("Warning: The smallest number of input i of Get(i) shoule be >=1."));
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

template <class T>
ChainNode<T>* Chain<T>::GetNode(const int i) const{
    if(IsEmpty()){
        throw std::runtime_error(std::string("Warning: Chain "+name+" is empty. Cannot Get(i)."));
    }

    if(i<=0){
        throw std::runtime_error(std::string("Warning: The smallest number of input i of Get(i) shoule be >=1."));
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

    return current_node;
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
    ChainNode<T> *current_node = first;
    ChainNode<T> *prev_node = first;

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
void Chain<T>::Insert(const int i, const T e){
    if(i<=0){
        throw std::runtime_error(std::string("Warning: The smallest number of input i of Insert(i, e) should be >=1."));
    }

    int count = 1;
    ChainNode<T> *current_node = first;
    ChainNode<T> *prev_node = first;

    while((count != i) && (current_node != NULL)){
        prev_node    = current_node;
        current_node = current_node->link;
        count++;
    }

    if(i==1){
        first = new ChainNode<T> (e, first);
    }else{
        if((current_node==NULL) && (prev_node != NULL) && (i==count)){//Insert as the last node
            prev_node->link = new ChainNode<T>(e, NULL);
        }else{
            if((current_node == NULL) && (i>count)){
                throw std::runtime_error(std::string("Warning: "+std::to_string(i)+"th node is out of range of the chain."));
            }else{
                ChainNode<T> *tmp_node = new ChainNode<T> (e, prev_node->link);
                prev_node->link = tmp_node;
            }
        }
    }
}

template <class T>
int Chain<T>::NumOfNodes(){
    if(IsEmpty()){
        return 0;
    }

    int count = 0;
    ChainNode<T> *current_node = first;

    while(current_node != NULL){
        current_node = current_node->link;
        count++;
    }

    return count;
}

template <class T>
void Chain<T>::ChangeData(const int k, const T &Y){
    if(IsEmpty()){
        throw std::runtime_error(std::string("Warning: Chain "+name+" is empty. Cannot ChangeData(k, Y)."));
    }

    if(k<=0){
        throw std::runtime_error(std::string("Warning: The smallest number of input k of ChangeData(k, Y) shoule be >=1."));
    }

    int count = 1;
    ChainNode<T> *current_node = first;

    while((count != k) && (current_node != NULL)){
        current_node = current_node->link;
        count++;
    }

    if(current_node == NULL){
        throw std::runtime_error(std::string("Warning: "+std::to_string(k)+"th element is not found in Chain."));
    }

    current_node->data = Y;
}

template <class T>
void Chain<T>::InsertBeforeK(const int k, const T &Y){
    if(IsEmpty() && k > 1){
        throw std::runtime_error(std::string("Warning: Chain "+name+" is empty. Cannot InsertBefore(k, Y) with k > 1."));
    }

    if(k<=0){
        throw std::runtime_error(std::string("Warning: The smallest number of input k of InsertBefore(k, Y) shoule be >=1."));
    }

    int count = 1;
    ChainNode<T> *current_node = first;
    ChainNode<T> *prev_node    = first;

    while((count != k) && (current_node != NULL)){
        prev_node    = current_node;
        current_node = current_node->link;
        count++;
    }

    if(current_node == NULL && k > count){
        throw std::runtime_error(std::string("Warning: "+std::to_string(k)+"th element is not found in Chain."));
    }

    if(k==1){
        ChainNode<T> *tmp = new ChainNode<T> (Y, first);
        first = tmp;
    }else{
        ChainNode<T> *tmp = new ChainNode<T> (Y, prev_node->link);
        prev_node->link = tmp;
    }
}

template <class T>
void Chain<T>::DeleteEveryOtherNode(){
    if(IsEmpty()){
        throw std::runtime_error(std::string("Warning: Chain "+name+" is empty. Cannot DeleteEveryOtherNode()."));
    }

    int count = 0;
    ChainNode<T> *current_node = first;

    while(current_node != NULL){
        ChainNode<T> *next_tmp = current_node->link;

        if(count%2 == 0){
            //Delete
            current_node->link = NULL;
            delete current_node;

            if(count == 0){
                first = next_tmp;
            }
        }else{
            //Relink to next of next node
            if(current_node->link != NULL){
                current_node->link = current_node->link->link;
            }
        }
        current_node = next_tmp;
        count++;
    }
}

template <class T>
void Chain<T>::DivideMid(Chain<T> &sub_list){
    if(IsEmpty()){
        throw std::runtime_error(std::string("Warning: Chain "+name+" is empty. Cannot DivideMid()."));
    }

    int total_size = NumOfNodes();
    int mid_pos = total_size/2 - 1;
    int count = 0;
    ChainNode<T> *current_node = first;

    if(total_size==1){
        //do nothing
    }else{
        while(count != mid_pos){
            current_node = current_node->link;
            count++;
        }

        sub_list.first = current_node->link;
        current_node->link = NULL;
    }
}

template <class T>
void Chain<T>::Deconcatenate(ChainNode<T> *split, Chain<T> &sub_list){
    if(IsEmpty()){
        throw std::runtime_error(std::string("Warning: Chain "+name+" is empty. Cannot Deconcatenate(split)."));
    }

    ChainNode<T> *current_node = first;
    ChainNode<T> *prev_node = first;

    while(current_node != NULL){
        if(current_node == split){
            break;
        }
        prev_node    = current_node;
        current_node = current_node->link;
    }

    if(current_node == NULL){
        throw std::runtime_error(std::string("Warning: Chain "+name+" does not have the split node. Cannot Deconcatenate(split)."));
    }

    if(current_node == first){
        sub_list.first = first;
        first = NULL;
    }else{
        prev_node->link = NULL;
        sub_list.first = current_node;
    }
}

template <class T>
void Chain<T>::Merge(Chain<T> &L1, Chain<T> &L2){
    if(!IsEmpty()){
        //Delete all the original nodes.
        ChainNode<T> *current_node = first;

        while(current_node != NULL){
            ChainNode<T> *tmp_next = current_node->link;
            current_node->link = NULL;
            delete current_node;
            current_node = tmp_next;
        }
    }

    ChainNode<T> *current_node_l1 = L1.first;
    ChainNode<T> *current_node_l2 = L2.first;
    ChainNode<T> *current_node    = first;
    int count = 0;

    while((current_node_l1 != NULL) && (current_node_l2 != NULL)){
        ChainNode<T> *tmp_next_node_l1 = current_node_l1->link;
        ChainNode<T> *tmp_next_node_l2 = current_node_l2->link;

        if(count == 0){
            count++;
            first                 = current_node_l1;
            current_node_l1->link = current_node_l2;
            current_node          = current_node_l2;
        }else{
            current_node_l1->link = current_node_l2;
            current_node->link    = current_node_l1;
            current_node          = current_node_l2;
        }

        current_node_l1 = tmp_next_node_l1;
        current_node_l2 = tmp_next_node_l2;
    }

    if(current_node_l1 != NULL){
        current_node->link = current_node_l1;
    }
    if(current_node_l2 != NULL){
        current_node->link = current_node_l2;
    }

    L1.first = NULL;
    L2.first = NULL;
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

