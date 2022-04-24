#ifndef _CIRCULAR_HEADERLIST_H_
#define _CIRCULAR_HEADERLIST_H_

#include <vector>
#include <string>
#include <cfloat>
#include <climits>
#include <math.h>
#include <unordered_map>
#include <algorithm>
#include <iostream>

template <class T>
class CircularHeaderList; //forward declaration

template <typename T>
std::ostream & operator<<(std::ostream &os, const CircularHeaderList<T> &out_queue);

template <class T>
class CircularHeaderListNode{
    private:
        T             data;
        CircularHeaderListNode<T>* link;
    public:
        CircularHeaderListNode(const T &in_data, CircularHeaderListNode<T>* const in_link=NULL) : data(in_data), link(in_link){}
        ~CircularHeaderListNode(){}
        friend class CircularHeaderList<T>;
        friend std::ostream & operator<<<T>(std::ostream &os, const CircularHeaderList<T> &out_queue);
};

template <class T>
class CircularHeaderList{
    private:
        std::string name;
        CircularHeaderListNode<T> *header;

    public:
        CircularHeaderList(const std::string &name="NULL"):name(name), header(NULL){
            T unknown_data;
            header = new CircularHeaderListNode<T> (unknown_data, NULL);
            header->link = header;
        }

        CircularHeaderList(const T header_data, const std::string &name="NULL"):name(name), header(NULL){
            header = new CircularHeaderListNode<T> (header_data, NULL);
            header->link = header;
        }

        //Copy consturctor
        CircularHeaderList(const CircularHeaderList &p){
            name     = p.name;
            header   = p.header;
        }

        //Destructor
        ~CircularHeaderList(){
            CircularHeaderListNode<T> *current_node = header->link;
            while(current_node!=header){
                CircularHeaderListNode<T> *tmp_next_node = current_node->link;

                current_node->link = NULL;
                delete current_node;

                current_node = tmp_next_node;
            }
            header->link = header;
        }

        bool                               IsEmpty             () const {return (header->link==header);}
        void                               InsertFront         (const T &in_data);
        void                               InsertBack          (const T &in_data);
        void                               DeleteFirst         ();
        void                               DeleteLast          ();
        void                               DeleteEveryOtherNode();
        void                               Deconcatenate       (CircularHeaderListNode<T> *split, CircularHeaderList<T> &sub_list);
        void                               Merge               (CircularHeaderList<T> &L1, CircularHeaderList<T> &L2);
        int                                NumOfNodes          ();
        CircularHeaderListNode<T>*         GetNode             (const int i) const;


        std::string                        Name                () const {return name;}
        void                               SetName             (const std::string &in_name)    {name     = in_name;}

        //static bool SortFunction(const Term<CoefType, ExpType> &a, const Term<CoefType, ExpType> &b);
        void operator=(const CircularHeaderList &chain);
        friend std::ostream & operator<<<T>(std::ostream &os, const CircularHeaderList<T> &out_chain);

};

#include <circular_headerlist.hpp>
#endif

