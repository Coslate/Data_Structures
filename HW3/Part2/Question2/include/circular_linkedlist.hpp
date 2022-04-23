//circular_linkedlist.hpp
#include <circular_linkedlist.h>
#include <cstdlib>

template <class T>
void CircularList<T>::InsertFront(const T &in_data){
    CircularListNode<T> *current_node = first;
    //Find the last node
    while(current_node != NULL){
        current_node = current_node->link;
        if(current_node->link == first){
            break;
        }
    }

    if(first==NULL){
        current_node = new CircularListNode<T> (in_data, current_node);
        first = current_node;
        current_node->link = current_node;
    }else{
        current_node->link = new CircularListNode<T> (in_data, first);
        first = current_node->link;
    }
}

template <class T>
void CircularList<T>::InsertBack(const T &in_data){
    CircularListNode<T> *current_node = first;
    //Find the last node
    while(current_node != NULL){
        current_node = current_node->link;
        if(current_node->link == first){
            break;
        }
    }

    if(first==NULL){
        current_node = new CircularListNode<T> (in_data, current_node);
        first = current_node;
        current_node->link = current_node;
    }else{
        current_node->link = new CircularListNode<T> (in_data, first);
    }
}

template <class T>
void CircularList<T>::DeleteFirst(){
    if(IsEmpty()){
        throw std::runtime_error(std::string("Warning: CircularList "+name+" is empty. Cannot DeleteFirst()."));
    }

    bool only_one_node = (first->link==first);

    CircularListNode<T> *current_node = first;
    //Find the last node
    while(current_node != NULL){
        current_node = current_node->link;
        if(current_node->link == first){
            break;
        }
    }

    CircularListNode<T> *tmp = first;
    first = first->link;
    current_node->link = first;
    tmp->link = NULL;
    delete tmp;

    if(only_one_node){
        first = NULL;
    }
}

template <class T>
void CircularList<T>::DeleteLast(){
    if(IsEmpty()){
        throw std::runtime_error(std::string("Warning: CircularList "+name+" is empty. Cannot DeleteLast()."));
    }

    bool only_one_node = (first->link==first);

    CircularListNode<T> *current_node = first;
    CircularListNode<T> *prev_node = first;
    //Find the last node
    while(current_node != NULL){
        prev_node    = current_node;
        current_node = current_node->link;
        if(current_node->link == first){
            break;
        }
    }

    prev_node->link = first;
    current_node->link = NULL;
    delete current_node;

    if(only_one_node){
        first = NULL;
    }
}

template <class T>
CircularListNode<T>* CircularList<T>::GetNode(const int i) const{
    if(IsEmpty()){
        throw std::runtime_error(std::string("Warning: CircularList "+name+" is empty. Cannot Get(i)."));
    }

    if(i<=0){
        throw std::runtime_error(std::string("Warning: The smallest number of input i of Get(i) shoule be >=1."));
    }

    CircularListNode<T> *last_node = first;
    //Find the last node
    while(last_node != NULL){
        last_node = last_node->link;
        if(last_node->link == first){
            break;
        }
    }

    int count = 1;
    CircularListNode<T> *current_node = first;

    while((count != i) && (current_node != NULL)){
        current_node = current_node->link;
        count++;
        if(current_node==last_node){
            break;
        }
    }

    if((count < i) || (current_node == NULL)){
        throw std::runtime_error(std::string("Warning: "+std::to_string(i)+"th element is not found in CircularList."));
    }

    return current_node;
}

template <class T>
int CircularList<T>::NumOfNodes(){
    if(IsEmpty()){
        return 0;
    }

    int count = 0;
    CircularListNode<T> *current_node = first;

    while(current_node != NULL){
        current_node = current_node->link;
        count++;
        if(current_node==first){
            break;
        }
    }

    return count;
}

template <class T>
void CircularList<T>::DeleteEveryOtherNode(){
    if(IsEmpty()){
        throw std::runtime_error(std::string("Warning: CircularList "+name+" is empty. Cannot DeleteEveryOtherNode()."));
    }

    int count = 0;
    CircularListNode<T> *current_node = first;
    CircularListNode<T> *last_node    = first;

    while(current_node != NULL){
        bool got_last_node = false;
        CircularListNode<T> *next_tmp = current_node->link;
        if(count == 0){
            while(last_node != NULL){
                last_node = last_node->link;
                if(last_node->link == first){
                    break;
                }
            }
        }

        if(current_node==last_node){
            got_last_node = true;
        }

        if(count%2 == 0){
            //Delete
            current_node->link = NULL;
            delete current_node;

            if((count == 0) && (first->link != first)){
                first = next_tmp;
                last_node->link = first;
            }else if((count==0) && (first->link == first)){
                first = NULL;
            }
        }else{
            //Relink to next of next node
            if(current_node==last_node){
                //do nothing
            }else{
                if(current_node->link != NULL){
                    current_node->link = current_node->link->link;
                }
            }
        }

        current_node = next_tmp;
        count++;
        if(got_last_node){
            break;
        }
    }
}

template <class T>
void CircularList<T>::Deconcatenate(CircularListNode<T> *split, CircularList<T> &sub_list){
    if(IsEmpty()){
        throw std::runtime_error(std::string("Warning: CircularList "+name+" is empty. Cannot Deconcatenate(split)."));
    }

    CircularListNode<T> *current_node = first;
    CircularListNode<T> *prev_node = first;
    CircularListNode<T> *last_node = first;

    //Find the last node
    while(last_node != NULL){
        last_node = last_node->link;
        if(last_node->link == first){
            break;
        }
    }

    while(current_node != NULL){
        if(current_node == split){
            break;
        }
        prev_node    = current_node;
        current_node = current_node->link;

        if(prev_node == last_node){
            break;
        }
    }

    if(((current_node == NULL) || (prev_node == last_node)) && (first->link != first)){
        throw std::runtime_error(std::string("Warning: CircularList "+name+" does not have the split node. Cannot Deconcatenate(split)."));
    }

    if(current_node == first){
        sub_list.first = first;
        first = NULL;
    }else{
        prev_node->link = first;
        sub_list.first = current_node;
        last_node->link = sub_list.first;
    }
}

template <class T>
void CircularList<T>::Merge(CircularList<T> &L1, CircularList<T> &L2){
    if(!IsEmpty()){
        //Delete all the original nodes.
        CircularListNode<T> *current_node = first;
        while(current_node!=NULL){
            CircularListNode<T> *tmp_next_node = current_node->link;

            current_node->link = NULL;
            delete current_node;

            current_node = tmp_next_node;
            if(current_node == first){
                break;
            }
        }

        first = NULL;
    }

    CircularListNode<T> *current_node_l1 = L1.first;
    CircularListNode<T> *current_node_l2 = L2.first;
    CircularListNode<T> *last_node_l1    = L1.first;
    CircularListNode<T> *last_node_l2    = L2.first;
    CircularListNode<T> *current_node    = first;
    int count = 0;

    //Find the last node of L1
    while(last_node_l1 != NULL){
        last_node_l1 = last_node_l1->link;
        if(last_node_l1->link == L1.first){
            break;
        }
    }

    //Find the last node of L2
    while(last_node_l2 != NULL){
        last_node_l2 = last_node_l2->link;
        if(last_node_l2->link == L2.first){
            break;
        }
    }

    while((current_node_l1 != NULL) && (current_node_l2 != NULL)){
        CircularListNode<T> *tmp_next_node_l1 = current_node_l1->link;
        CircularListNode<T> *tmp_next_node_l2 = current_node_l2->link;

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
        if((current_node_l1==L1.first) || (current_node_l2==L2.first)){
            break;
        }
    }

    if((current_node_l1 == L1.first) && (current_node_l2 != L2.first)){ //L1 end
        current_node->link = current_node_l2;
        last_node_l2->link = first;
    }

    if((current_node_l2 == L2.first) && (current_node_l1 != L1.first)){ //L2 end
        current_node->link = current_node_l1;
        last_node_l1->link = first;
    }

    if((current_node_l1 == L1.first) && (current_node_l2 == L2.first)){
        current_node->link = first;
    }

    L1.first = NULL;
    L2.first = NULL;
}

template <class T>
void CircularList<T>::operator=(const CircularList &other){
    first     = other.first;
}

template <class T>
std::ostream & operator<<(std::ostream &os, const CircularList<T> &out_chain){
    if(out_chain.IsEmpty()){
        throw std::runtime_error(std::string("Warning: Not available. The CircularList is empty."));
        return os;
    }

    CircularListNode<T> *current_node = out_chain.first;
    os<<out_chain.name<<" = [";

    while(current_node != NULL){
        if(current_node->link == out_chain.first){
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

