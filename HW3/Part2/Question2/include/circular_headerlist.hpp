//circular_headerlist.hpp
#include <circular_headerlist.h>
#include <cstdlib>

template <class T>
void CircularHeaderList<T>::InsertFront(const T &in_data){
    header->link = new CircularHeaderListNode<T> (in_data, header->link);
}

template <class T>
void CircularHeaderList<T>::InsertBack(const T &in_data){
    CircularHeaderListNode<T> *current_node = header->link;
    //Find the last node
    while(current_node->link != header){
        current_node = current_node->link;
    }

    current_node->link = new CircularHeaderListNode<T> (in_data, header);
}

template <class T>
void CircularHeaderList<T>::DeleteFirst(){
    if(IsEmpty()){
        throw std::runtime_error(std::string("Warning: CircularHeaderList "+name+" is empty. Cannot DeleteFirst()."));
    }

    CircularHeaderListNode<T> *first_node = header->link;
    header->link = first_node->link;
    first_node->link = NULL;
    delete first_node;
}

template <class T>
void CircularHeaderList<T>::DeleteLast(){
    if(IsEmpty()){
        throw std::runtime_error(std::string("Warning: CircularHeaderList "+name+" is empty. Cannot DeleteLast()."));
    }

    CircularHeaderListNode<T> *current_node = header->link;
    CircularHeaderListNode<T> *prev_node    = header;
    //Find the last node
    while(current_node->link != header){
        prev_node = current_node;
        current_node = current_node->link;
    }

    prev_node->link = current_node->link;
    current_node->link = NULL;
    delete current_node;
}

template <class T>
CircularHeaderListNode<T>* CircularHeaderList<T>::GetNode(const int i) const{
    if(IsEmpty()){
        throw std::runtime_error(std::string("Warning: CircularHeaderList "+name+" is empty. Cannot Get(i)."));
    }

    if(i<=0){
        throw std::runtime_error(std::string("Warning: The smallest number of input i of Get(i) shoule be >=1."));
    }

    int count = 1;
    CircularHeaderListNode<T> *current_node = header->link;

    while((count != i) && (current_node != header)){
        current_node = current_node->link;
        count++;
    }

    if(current_node == header){
        throw std::runtime_error(std::string("Warning: "+std::to_string(i)+"th element is not found in CircularHeaderList."));
    }

    return current_node;
}

template <class T>
int CircularHeaderList<T>::NumOfNodes(){
    if(IsEmpty()){
        return 0;
    }

    int count = 0;
    CircularHeaderListNode<T> *current_node = header->link;

    while(current_node != header){
        current_node = current_node->link;
        count++;
    }

    return count;
}

template <class T>
void CircularHeaderList<T>::DeleteEveryOtherNode(){
    if(IsEmpty()){
        throw std::runtime_error(std::string("Warning: CircularHeaderList "+name+" is empty. Cannot DeleteEveryOtherNode()."));
    }

    int count = 0;
    CircularHeaderListNode<T> *current_node = header->link;
    CircularHeaderListNode<T> *last_node    = header->link;

    //Find the last node
    while(last_node->link != header){
        last_node = last_node->link;
    }

    while(current_node != header){
        CircularHeaderListNode<T> *tmp_next_node = current_node->link;

        if(count%2 == 0){
            //Delete
            if(count==0){
                header->link = current_node->link;
            }

            current_node->link = NULL;
            delete current_node;
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
        count++;
        current_node = tmp_next_node;
    }
}

template <class T>
void CircularHeaderList<T>::Deconcatenate(CircularHeaderListNode<T> *split, CircularHeaderList<T> &sub_list){
    if(IsEmpty()){
        throw std::runtime_error(std::string("Warning: CircularHeaderList "+name+" is empty. Cannot Deconcatenate(split)."));
    }

    CircularHeaderListNode<T> *current_node = header->link;
    CircularHeaderListNode<T> *prev_node    = header->link;
    CircularHeaderListNode<T> *last_node    = header->link;

    //Find the last node
    while(last_node->link != header){
        last_node = last_node->link;
    }

    while(current_node != header){
        if(current_node == split){
            break;
        }
        prev_node    = current_node;
        current_node = current_node->link;
    }

    if((current_node == header) || (prev_node == last_node)){
        throw std::runtime_error(std::string("Warning: CircularHeaderList "+name+" does not have the split node. Cannot Deconcatenate(split)."));
    }

    prev_node->link       = header;
    sub_list.header->link = current_node;
    last_node->link       = sub_list.header;
}

template <class T>
void CircularHeaderList<T>::Merge(CircularHeaderList<T> &L1, CircularHeaderList<T> &L2){
    if(!IsEmpty()){
        //Delete all the original nodes.
        CircularHeaderListNode<T> *current_node = header->link;
        while(current_node!=header){
            CircularHeaderListNode<T> *tmp_next_node = current_node->link;

            current_node->link = NULL;
            delete current_node;

            current_node = tmp_next_node;
        }
    }

    CircularHeaderListNode<T> *current_node_l1 = L1.header->link;
    CircularHeaderListNode<T> *current_node_l2 = L2.header->link;
    CircularHeaderListNode<T> *last_node_l1    = L1.header->link;
    CircularHeaderListNode<T> *last_node_l2    = L2.header->link;
    CircularHeaderListNode<T> *current_node    = header;

    //Find the last node of L1
    while(last_node_l1->link != L1.header){
        last_node_l1 = last_node_l1->link;
    }

    //Find the last node of L2
    while(last_node_l2->link != L2.header){
        last_node_l2 = last_node_l2->link;
    }

    while((current_node_l1 != L1.header) && (current_node_l2 != L2.header)){
        CircularHeaderListNode<T> *tmp_next_node_l1 = current_node_l1->link;
        CircularHeaderListNode<T> *tmp_next_node_l2 = current_node_l2->link;

        current_node_l1->link = current_node_l2;
        current_node->link    = current_node_l1;
        current_node          = current_node_l2;

        current_node_l1 = tmp_next_node_l1;
        current_node_l2 = tmp_next_node_l2;
        if((current_node_l1==L1.header) || (current_node_l2==L2.header)){
            break;
        }
    }

    if((current_node_l1 == L1.header) && (current_node_l2 != L2.header)){ //L1 end
        current_node->link = current_node_l2;
        last_node_l2->link = header;
    }

    if((current_node_l2 == L2.header) && (current_node_l1 != L1.header)){ //L2 end
        current_node->link = current_node_l1;
        last_node_l1->link = header;
    }

    if((current_node_l1 == L1.header) && (current_node_l2 == L2.header)){
        current_node->link = header;
    }

    L1.header->link = L1.header;
    L2.header->link = L2.header;
}

template <class T>
void CircularHeaderList<T>::operator=(const CircularHeaderList &other){
    header     = other.header;
}

template <class T>
std::ostream & operator<<(std::ostream &os, const CircularHeaderList<T> &out_chain){
    if(out_chain.IsEmpty()){
        throw std::runtime_error(std::string("Warning: Not available. The CircularHeaderList is empty."));
        return os;
    }

    CircularHeaderListNode<T> *current_node = out_chain.header->link;
    os<<out_chain.name<<" = [";

    while(current_node != out_chain.header){
        if(current_node->link == out_chain.header){
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

