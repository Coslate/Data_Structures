#ifndef _CIRCULAR_LINKEDLIST_H_
#define _CIRCULAR_LINKEDLIST_H_

#include <vector>
#include <string>
#include <cfloat>
#include <climits>
#include <math.h>
#include <unordered_map>
#include <algorithm>
#include <iostream>

template <class T>
class CircularList; //forward declaration

template <typename T>
std::ostream & operator<<(std::ostream &os, const CircularList<T> &out_queue);

template <class T>
class CircularListNode{
    private:
        T             data;
        CircularListNode<T>* link;
    public:
        CircularListNode(const T &in_data, CircularListNode<T>* const in_link=NULL) : data(in_data), link(in_link){}
        ~CircularListNode(){}
        friend class CircularList<T>;
        friend std::ostream & operator<<<T>(std::ostream &os, const CircularList<T> &out_queue);
};

template <class T>
class CircularList{
    private:
        std::string name;
        CircularListNode<T> *first;

    public:
        CircularList(const std::string &name="NULL"):name(name), first(NULL){}

        //Copy consturctor
        CircularList(const CircularList &p){
            name     = p.name;
            first    = p.first;
        }

        //Destructor
        ~CircularList(){
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

        bool                               IsEmpty             () const {return (first==NULL);}
        void                               InsertFront         (const T &in_data);
        void                               InsertBack          (const T &in_data);
        void                               DeleteFirst         ();
        void                               DeleteLast          ();
        void                               DeleteEveryOtherNode();
        void                               Deconcatenate       (CircularListNode<T> *split, CircularList<T> &sub_list);
        void                               Merge               (CircularList<T> &L1, CircularList<T> &L2);
        int                                NumOfNodes          ();
        CircularListNode<T>*               GetNode             (const int i) const;


        std::string                        Name                () const {return name;}
        void                               SetName             (const std::string &in_name)    {name     = in_name;}

        //static bool SortFunction(const Term<CoefType, ExpType> &a, const Term<CoefType, ExpType> &b);
        void operator=(const CircularList &chain);
        friend std::ostream & operator<<<T>(std::ostream &os, const CircularList<T> &out_chain);

};

#include <circular_linkedlist.hpp>
#endif

